/******************************************************************************
 * Software UART example for MSP430.
 *
 * Stefan Wendler
 * sw@kaltpost.de
 * http://gpio.kaltpost.de
 *
 * ****************************************************************************
 * The original code is taken form Nicholas J. Conn example:
 *
 * http://www.msp430launchpad.com/2010/08/half-duplex-software-uart-on-launchpad.html
 *
 * Origial Description from Nicholas:
 *
 * Half Duplex Software UART on the LaunchPad
 *
 * Description: This code provides a simple Bi-Directional Half Duplex
 * Software UART. The timing is dependant on SMCLK, which
 * is set to 1MHz. The transmit function is based off of
 * the example code provided by TI with the LaunchPad.
 * This code was originally created for "NJC's MSP430
 * LaunchPad Blog".
 *
 * Author: Nicholas J. Conn - http://msp430launchpad.com
 * Email: webmaster at msp430launchpad.com
 * Date: 08-17-10
 * ****************************************************************************
 * Includes also improvements from Joby Taffey and fixes from Colin Funnell
 * as posted here:
 *
 * http://blog.hodgepig.org/tag/msp430/
 ******************************************************************************/

#include <msp430.h>
#include <legacymsp430.h>
#include <stdbool.h>

#include "uart.h"
#include "uart_obj.h"

/**
 * TXD on P1.1
 */
#define TXD BIT1

/**
 * RXD on P1.2
 */
#define RXD BIT2

/**
 * CPU freq.
 */
#define FCPU 			1000000

/**
 * Baudrate
 */
#define BAUDRATE 		9600

/**
 * Bit time
 */
#define BIT_TIME        (FCPU / BAUDRATE)

/**
 * Half bit time
 */
#define HALF_BIT_TIME   (BIT_TIME / 2)

#define SOFTUART_CLK_PRESET TASSEL_2 + MC_2
#define SOFTUART_CC_PRESET CCIS_0 + OUTMOD_0 + CCIE + OUT


/**
 * Bit count, used when transmitting byte
 */
static volatile uint8_t bitCount;

/**
 * Value sent over UART when uart_putc() is called
 */
static volatile unsigned int TXBUF;

/**
 * Value recieved once hasRecieved is set
 */
static volatile unsigned int RXByte;

/**
 * Status for when the device is receiving
 */
static volatile bool isReceiving = false;

/**
 * Lets the program know when a byte is received
 */
static volatile bool hasReceived = false;


inline void uart_XD_enable(uart_handle this){
// 	*this->XD_PORT_SEL = *this->XD_PORT_SEL2 |= this->TXD | this->RXD;
	 P1SEL |= TXD;
     P1DIR |= TXD;

     P1IES |= RXD; 		// RXD Hi/lo edge interrupt
     P1IFG &= ~RXD; 		// Clear RXD (flag) before enabling interrupt
     P1IE  |= RXD; 		// Enable RXD interrupt
}


inline void softUart_TX_wait(uart_handle this){
	while (this->isReceiving);
}

inline void softUart_RX_wait(uart_handle this){
	while (!this->hasReceived);
}


/////////main functions//////////////////
void softUart_init(uart_handle this, uint32_t freq, uint32_t baud){ 
	/*init uart interface "this", set buadrate by calculating from frequency
	 */
	uint8_t tmp;
	uart_XD_enable(this);  //enble port for special function
	
	freq = ((freq << 3) + 4) / baud;
	tmp = freq >> 11;
	*this->BR1= tmp; //BR1 <10, no overflow
	freq -= (tmp << 11);
	tmp = freq >> 3;
	*this->BR0= tmp;
	*this->MCTL = _UCBR[ freq - (tmp << 3) ];
	
	
}

inline void uart__putchar(uart_handle this, char c){
	softUart_TX_wait(this);
	*this->TXBUF = c;
	
	*this->CCTL0 = OUT; 							// TXD Idle as Mark
	*this->TACTL = SOFTUART_CLK_PRESET; 				// SMCLK, continuous mode

	*this->bitCount = 0xA; 						// Load Bit counter, 8 bits + ST/SP
	*this->CCR0 = BIT_TIME + *this->TAR; 							// Initialize compare register

	*this->TXBUF |= 0x100; 						// Add stop bit to TXBUF (which is logical 1)
	*this->TXBUF <<= 1; 					// Add start bit (which is logical 0)

	*this->CCTL0 = SOFTUART_CC_PRESET; // Set signal, intial value, enable interrupts

}

inline char softUart__getchar(uart_handle this){
	softUart_RX_wait(this);
	return *this->RXBUF;
}


#pragma vector=PORT1_VECTOR
__interrupt void sofUart_recieveData(){
{
     this->isReceiving = true;

     P1IE &= ~RXD; 					// Disable RXD interrupt
     P1IFG &= ~RXD; 					// Clear RXD IFG (interrupt flag)

     *this->TACTL = SOFTUART_CLK_PRESET; 		// SMCLK, continuous mode
     *this->CCR0 = HALF_BIT_TIME + *this->TAR; 			// Set time till first bit
     *this->CCTL0 = OUTMOD_1 + CCIE; 		// Disable TX and enable interrupts

     *this->RXBUF = 0; 					// Initialize RXByte
     *this->bitCount = 9; 					// Load Bit counter, 8 bits + start bit
}


#pragma vector=PORT1_VECTOR
__interrupt void sofUart_recieveSendData(){
{
     if(!this->isReceiving) {
          *this->CCR0 += BIT_TIME; 						// Add Offset to CCR0
          if ( *this->bitCount == 0) { 					// If all bits TXed
               *this->TACTL = TASSEL_2; 					// SMCLK, timer off (for power consumption)
               *this->CCTL0 &= ~ this->CCIE ; 					// Disable interrupt
          } else {
               if (*this->TXBUF & 0x01) {
                    *this->CCTL0 = ((CCTL0 & ~OUTMOD_7 ) | OUTMOD_1);  //OUTMOD_7 defines the 'window' of the field.
               } else {
                    *this->CCTL0 = ((CCTL0 & ~OUTMOD_7 ) | OUTMOD_5);  //OUTMOD_7 defines the 'window' of the field.
               }

               this->TXBUF = TXBUF >> 1;
               this->bitCount --;
          }
     } else {
          CCR0 += BIT_TIME; 						// Add Offset to CCR0

          if ( bitCount == 0) {

               TACTL = TASSEL_2; 					// SMCLK, timer off (for power consumption)
               CCTL0 &= ~ CCIE ; 					// Disable interrupt

               isReceiving = false;

               P1IFG &= ~RXD; 						// clear RXD IFG (interrupt flag)
               P1IE |= RXD; 						// enabled RXD interrupt

               if ( (RXByte & 0x201) == 0x200) { 	// Validate the start and stop bits are correct
                    RXByte = RXByte >> 1; 			// Remove start bit
                    RXByte &= 0xFF; 				// Remove stop bit
                    hasReceived = true;
               }
          } else {
               if ( (P1IN & RXD) == RXD) { 		// If bit is set?
                    RXByte |= 0x400; 				// Set the value in the RXByte
               }
               RXByte = RXByte >> 1; 				// Shift the bits down
               bitCount --;
          }
     }
}

