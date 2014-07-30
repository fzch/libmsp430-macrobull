
#ifndef __PERIP_H
#define __PERIP_H

#include <msp430.h>

//#include "hw_obj.h"

//////////////uart////////////////////
#define __CHIP_SUPPORT_UART__

#define	_PERIP_UART_CNT	2

#define _PERIP_UART0_XD_PORT_SEL_ADDR	&P3SEL
#define _PERIP_UART0_XD_PORT_SEL2_ADDR	NULL_ADDR

#define _PERIP_UART0_TXD	BIT3
#define _PERIP_UART0_RXD	BIT4


#define _PERIP_UART0_CTL0_ADDR	&UCA0CTL0
#define _PERIP_UART0_CTL1_ADDR	&UCA0CTL1
#define _PERIP_UART0_BR0_ADDR	&UCA0BR0
#define _PERIP_UART0_BR1_ADDR	&UCA0BR1
#define _PERIP_UART0_MCTL_ADDR	&UCA0MCTL

#define _PERIP_UART0_IE_ADDR	&UCA0IE
#define _PERIP_UART0_IFG_ADDR	&UCA0IFG

#define _PERIP_UART0_RXIE	UCRXIE
#define _PERIP_UART0_TXIFG	UCTXIFG
#define _PERIP_UART0_RXIFG	UCRXIFG

#define _PERIP_UART0_TXBUF_ADDR	&UCA0TXBUF
#define _PERIP_UART0_RXBUF_ADDR	&UCA0RXBUF

#define _PERIP_UART0_ISR_VECTOR	USCI_A0_VECTOR


#define _PERIP_UART1_XD_PORT_SEL_ADDR	&P4SEL
#define _PERIP_UART1_XD_PORT_SEL2_ADDR	NULL_ADDR

#define _PERIP_UART1_TXD	BIT4
#define _PERIP_UART1_RXD	BIT5


#define _PERIP_UART1_CTL0_ADDR	&UCA1CTL0
#define _PERIP_UART1_CTL1_ADDR	&UCA1CTL1
#define _PERIP_UART1_BR0_ADDR	&UCA1BR0
#define _PERIP_UART1_BR1_ADDR	&UCA1BR1
#define _PERIP_UART1_MCTL_ADDR	&UCA1MCTL

#define _PERIP_UART1_IE_ADDR	&UCA1IE
#define _PERIP_UART1_IFG_ADDR	&UCA1IFG

#define _PERIP_UART1_RXIE	UCRXIE
#define _PERIP_UART1_TXIFG	UCTXIFG
#define _PERIP_UART1_RXIFG	UCRXIFG

#define _PERIP_UART1_TXBUF_ADDR	&UCA1TXBUF
#define _PERIP_UART1_RXBUF_ADDR	&UCA1RXBUF

#define _PERIP_UART1_ISR_VECTOR	USCI_A1_VECTOR

///////////////spi////////////////////
#define __CHIP_SUPPORT_SPI__

#define	_PERIP_SPI_CNT	4

#define _PERIP_SPI0_CLK_PORT_SEL_ADDR	&P2SEL
#define _PERIP_SPI0_CLK_PORT_SEL2_ADDR	NULL_ADDR
#define _PERIP_SPI0_XD_PORT_SEL_ADDR	&P3SEL
#define _PERIP_SPI0_XD_PORT_SEL2_ADDR	NULL_ADDR

#define _PERIP_SPI0_CLK	BIT7	// P2.7
#define _PERIP_SPI0_STE	BIT2	// P3.2
#define _PERIP_SPI0_SIMO	BIT3	// P3.3
#define _PERIP_SPI0_SOMI	BIT4	// P3.4


#define _PERIP_SPI0_CTL0_ADDR	&UCA0CTL0
#define _PERIP_SPI0_CTL1_ADDR	&UCA0CTL1
#define _PERIP_SPI0_BR0_ADDR	&UCA0BR0
#define _PERIP_SPI0_BR1_ADDR	&UCA0BR1
#define _PERIP_SPI0_MCTL_ADDR	&UCA0MCTL

#define _PERIP_SPI0_IE_ADDR	&UCA0IE
#define _PERIP_SPI0_IFG_ADDR	&UCA0IFG

#define _PERIP_SPI0_RXIE	UCRXIE
#define _PERIP_SPI0_TXIFG	UCTXIFG
#define _PERIP_SPI0_RXIFG	UCRXIFG

#define _PERIP_SPI0_TXBUF_ADDR	&UCA0TXBUF
#define _PERIP_SPI0_RXBUF_ADDR	&UCA0RXBUF

#define _PERIP_SPI0_ISR_VECTOR	USCI_A0_VECTOR


#define _PERIP_SPI1_CLK_PORT_SEL_ADDR	&P4SEL
#define _PERIP_SPI1_CLK_PORT_SEL2_ADDR	NULL_ADDR
#define _PERIP_SPI1_XD_PORT_SEL_ADDR	&P4SEL
#define _PERIP_SPI1_XD_PORT_SEL2_ADDR	NULL_ADDR

#define _PERIP_SPI1_CLK	BIT0	// P4.0
#define _PERIP_SPI1_STE	BIT3	// P4.3
#define _PERIP_SPI1_SIMO	BIT4	// P4.4
#define _PERIP_SPI1_SOMI	BIT5	// P4.5


#define _PERIP_SPI1_CTL0_ADDR	&UCA1CTL0
#define _PERIP_SPI1_CTL1_ADDR	&UCA1CTL1
#define _PERIP_SPI1_BR0_ADDR	&UCA1BR0
#define _PERIP_SPI1_BR1_ADDR	&UCA1BR1
#define _PERIP_SPI1_MCTL_ADDR	&UCA1MCTL

#define _PERIP_SPI1_IE_ADDR	&UCA1IE
#define _PERIP_SPI1_IFG_ADDR	&UCA1IFG

#define _PERIP_SPI1_RXIE	UCRXIE
#define _PERIP_SPI1_TXIFG	UCTXIFG
#define _PERIP_SPI1_RXIFG	UCRXIFG

#define _PERIP_SPI1_TXBUF_ADDR	&UCA1TXBUF
#define _PERIP_SPI1_RXBUF_ADDR	&UCA1RXBUF

#define _PERIP_SPI1_ISR_VECTOR	USCI_A1_VECTOR


#define _PERIP_SPI2_CLK_PORT_SEL_ADDR	&P3SEL
#define _PERIP_SPI2_CLK_PORT_SEL2_ADDR	NULL_ADDR
#define _PERIP_SPI2_XD_PORT_SEL_ADDR	&P3SEL
#define _PERIP_SPI2_XD_PORT_SEL2_ADDR	NULL_ADDR

#define _PERIP_SPI2_CLK	BIT2	// P3.2
//#define _PERIP_SPI2_STE	BIT7	// P2.7
#define _PERIP_SPI2_SIMO	BIT0	// P3.0
#define _PERIP_SPI2_SOMI	BIT1	// P3.1


#define _PERIP_SPI2_CTL0_ADDR	&UCB0CTL0
#define _PERIP_SPI2_CTL1_ADDR	&UCB0CTL1
#define _PERIP_SPI2_BR0_ADDR	&UCB0BR0
#define _PERIP_SPI2_BR1_ADDR	&UCB0BR1
#define _PERIP_SPI2_MCTL_ADDR	NULL_ADDR

#define _PERIP_SPI2_IE_ADDR	&UCB0IE
#define _PERIP_SPI2_IFG_ADDR	&UCB0IFG

#define _PERIP_SPI2_RXIE	UCRXIE
#define _PERIP_SPI2_TXIFG	UCTXIFG
#define _PERIP_SPI2_RXIFG	UCRXIFG

#define _PERIP_SPI2_TXBUF_ADDR	&UCB0TXBUF
#define _PERIP_SPI2_RXBUF_ADDR	&UCB0RXBUF

#define _PERIP_SPI2_ISR_VECTOR	USCI_B0_VECTOR


#define _PERIP_SPI3_CLK_PORT_SEL_ADDR	&P4SEL
#define _PERIP_SPI3_CLK_PORT_SEL2_ADDR	NULL_ADDR
#define _PERIP_SPI3_XD_PORT_SEL_ADDR	&P4SEL
#define _PERIP_SPI3_XD_PORT_SEL2_ADDR	NULL_ADDR

#define _PERIP_SPI3_CLK	BIT3	// P4.3
#define _PERIP_SPI3_STE	BIT0	// P4.0
#define _PERIP_SPI3_SIMO	BIT1	// P4.1
#define _PERIP_SPI3_SOMI	BIT2	// P4.2


#define _PERIP_SPI3_CTL0_ADDR	&UCB1CTL0
#define _PERIP_SPI3_CTL1_ADDR	&UCB1CTL1
#define _PERIP_SPI3_BR0_ADDR	&UCB1BR0
#define _PERIP_SPI3_BR1_ADDR	&UCB1BR1
#define _PERIP_SPI3_MCTL_ADDR	NULL_ADDR

#define _PERIP_SPI3_IE_ADDR	&UCB1IE
#define _PERIP_SPI3_IFG_ADDR	&UCB1IFG

#define _PERIP_SPI3_RXIE	UCRXIE
#define _PERIP_SPI3_TXIFG	UCTXIFG
#define _PERIP_SPI3_RXIFG	UCRXIFG

#define _PERIP_SPI3_TXBUF_ADDR	&UCB1TXBUF
#define _PERIP_SPI3_RXBUF_ADDR	&UCB1RXBUF

#define _PERIP_SPI3_ISR_VECTOR	USCI_B1_VECTOR

//////////////////////pwm////////////////////////////
#define __CHIP_SUPPORT_PWM__

#define _PERIP_PWM_CNT 4

#define _PERIP_PWM0_PORT_SEL_ADDR	&P1SEL
#define _PERIP_PWM0_PORT_SEL2_ADDR	NULL_ADDR
#define _PERIP_PWM0_PORT_DIR_ADDR	&P1DIR

#define _PERIP_PWM0_OUT1	2

#define _PERIP_PWM0_CTL_ADDR	&TA0CTL
#define _PERIP_PWM0_CCTL0_ADDR	&TA0CCTL0
#define _PERIP_PWM0_CCTL1_ADDR	&TA0CCTL1
#define _PERIP_PWM0_CCTL2_ADDR	&TA0CCTL2
#define _PERIP_PWM0_CCTL3_ADDR	&TA0CCTL3
#define _PERIP_PWM0_CCTL4_ADDR	&TA0CCTL4

#define _PERIP_PWM0_CCR0_ADDR	&TA0CCR0
#define _PERIP_PWM0_CCR1_ADDR	&TA0CCR1
#define _PERIP_PWM0_CCR2_ADDR	&TA0CCR2
#define _PERIP_PWM0_CCR3_ADDR	&TA0CCR3
#define _PERIP_PWM0_CCR4_ADDR	&TA0CCR4


#define _PERIP_PWM1_PORT_SEL_ADDR	&P2SEL
#define _PERIP_PWM1_PORT_SEL2_ADDR	NULL_ADDR
#define _PERIP_PWM1_PORT_DIR_ADDR	&P2DIR

#define _PERIP_PWM1_OUT1	0

#define _PERIP_PWM1_CTL_ADDR	&TA1CTL
#define _PERIP_PWM1_CCTL0_ADDR	&TA1CCTL0
#define _PERIP_PWM1_CCTL1_ADDR	&TA1CCTL1
#define _PERIP_PWM1_CCTL2_ADDR	&TA1CCTL2

#define _PERIP_PWM1_CCR0_ADDR	&TA1CCR0
#define _PERIP_PWM1_CCR1_ADDR	&TA1CCR1
#define _PERIP_PWM1_CCR2_ADDR	&TA1CCR2


#define _PERIP_PWM2_PORT_SEL_ADDR	&P2SEL
#define _PERIP_PWM2_PORT_SEL2_ADDR	NULL_ADDR
#define _PERIP_PWM2_PORT_DIR_ADDR	&P2DIR

#define _PERIP_PWM2_OUT1	4

#define _PERIP_PWM2_CTL_ADDR	&TA2CTL
#define _PERIP_PWM2_CCTL0_ADDR	&TA2CCTL0
#define _PERIP_PWM2_CCTL1_ADDR	&TA2CCTL1
#define _PERIP_PWM2_CCTL2_ADDR	&TA2CCTL2

#define _PERIP_PWM2_CCR0_ADDR	&TA2CCR0
#define _PERIP_PWM2_CCR1_ADDR	&TA2CCR1
#define _PERIP_PWM2_CCR2_ADDR	&TA2CCR2


#define _PERIP_PWM3_PORT_SEL_ADDR	&P7SEL
#define _PERIP_PWM3_PORT_SEL2_ADDR	NULL_ADDR
#define _PERIP_PWM3_PORT_DIR_ADDR	&P7DIR

#define _PERIP_PWM3_OUT1	3

#define _PERIP_PWM3_CTL_ADDR	&TB0CTL
#define _PERIP_PWM3_CCTL0_ADDR	&TB0CCTL0
#define _PERIP_PWM3_CCTL1_ADDR	&TB0CCTL1
#define _PERIP_PWM3_CCTL2_ADDR	&TB0CCTL2
#define _PERIP_PWM3_CCTL3_ADDR	&TB0CCTL3
#define _PERIP_PWM3_CCTL4_ADDR	&TB0CCTL4
#define _PERIP_PWM3_CCTL5_ADDR	&TB0CCTL5
#define _PERIP_PWM3_CCTL6_ADDR	&TB0CCTL6

#define _PERIP_PWM3_CCR0_ADDR	&TB0CCR0
#define _PERIP_PWM3_CCR1_ADDR	&TB0CCR1
#define _PERIP_PWM3_CCR2_ADDR	&TB0CCR2
#define _PERIP_PWM3_CCR3_ADDR	&TB0CCR3
#define _PERIP_PWM3_CCR4_ADDR	&TB0CCR4
#define _PERIP_PWM3_CCR5_ADDR	&TB0CCR5
#define _PERIP_PWM3_CCR6_ADDR	&TB0CCR6




/////////////////i2c//////////////////////
#define __CHIP_SUPPORT_I2C__

#define _PERIP_I2C0_XD_PORT_SEL_ADDR	&P3SEL
#define _PERIP_I2C0_XD_PORT_SEL2_ADDR	NULL_ADDR

#define _PERIP_I2C0_SCL	BIT1
#define _PERIP_I2C0_SDA	BIT0


#define _PERIP_I2C0_CTL0_ADDR	&UCB0CTL0
#define _PERIP_I2C0_CTL1_ADDR	&UCB0CTL1
#define _PERIP_I2C0_BR0_ADDR	&UCB0BR0
#define _PERIP_I2C0_BR1_ADDR	&UCB0BR1

#define _PERIP_I2C0_IE_ADDR	&UCB0IE
#define _PERIP_I2C0_IFG_ADDR	&UCB0IFG
#define _PERIP_I2C0_STAT_ADDR	&UCB0STAT


#define _PERIP_I2C0_OA_ADDR &UCB0I2COA
#define _PERIP_I2C0_SA_ADDR &UCB0I2CSA

#define _PERIP_I2C0_RXIE	UCRXIE
#define _PERIP_I2C0_TXIFG	UCTXIFG
#define _PERIP_I2C0_RXIFG	UCRXIFG

#define _PERIP_I2C0_TXBUF_ADDR	&UCB0TXBUF
#define _PERIP_I2C0_RXBUF_ADDR	&UCB0RXBUF

#define _PERIP_I2C0_ISR_VECTOR	USCI_B0_VECTOR


#define _PERIP_I2C1_XD_PORT_SEL_ADDR	&P4SEL
#define _PERIP_I2C1_XD_PORT_SEL2_ADDR	NULL_ADDR

#define _PERIP_I2C1_SCL	BIT2
#define _PERIP_I2C1_SDA	BIT1


#define _PERIP_I2C1_CTL0_ADDR	&UCB1CTL0
#define _PERIP_I2C1_CTL1_ADDR	&UCB1CTL1
#define _PERIP_I2C1_BR0_ADDR	&UCB1BR0
#define _PERIP_I2C1_BR1_ADDR	&UCB1BR1

#define _PERIP_I2C1_IE_ADDR	&UCB1IE
#define _PERIP_I2C1_IFG_ADDR	&UCB1IFG
#define _PERIP_I2C1_STAT_ADDR	&UCB1STAT


#define _PERIP_I2C1_OA_ADDR &UCB1I2COA
#define _PERIP_I2C1_SA_ADDR &UCB1I2CSA

#define _PERIP_I2C1_RXIE	UCRXIE
#define _PERIP_I2C1_TXIFG	UCTXIFG
#define _PERIP_I2C1_RXIFG	UCRXIFG

#define _PERIP_I2C1_TXBUF_ADDR	&UCB1TXBUF
#define _PERIP_I2C1_RXBUF_ADDR	&UCB1RXBUF

#define _PERIP_I2C1_ISR_VECTOR	USCI_B1_VECTOR


///////////////////timer ////////////////////
#define __CHIP_SUPPORT_TIMER__

#define _PERIP_TIMER_CNT 4

#ifndef TIOV
// const unsigned int TIOV = 14;
#define TIOV (14)
#endif

#define _PERIP_TIMER0_CTL_ADDR &TA0CTL
#define _PERIP_TIMER0_CCR0_ADDR &TA0CCR0

#define _PERIP_TIMER0_IE TAIE
#define _PERIP_TIMER0_OV_ISR_VECTOR TIMER0_A1_VECTOR
// extern const .... _PERIP_TIMER0_OV_ISR_CALLBACKS_ADDR &TIMER0_A1_ISR_callbacks

#define _PERIP_TIMER1_CTL_ADDR &TA1CTL
#define _PERIP_TIMER1_CCR0_ADDR &TA1CCR0

#define _PERIP_TIMER1_IE TAIE
#define _PERIP_TIMER1_OV_ISR_VECTOR TIMER1_A1_VECTOR
// #define _PERIP_TIMER1_OV_ISR_CALLBACKS_ADDR &TIMER1_A1_ISR_callbacks

#define _PERIP_TIMER2_CTL_ADDR &TA2CTL
#define _PERIP_TIMER2_CCR0_ADDR &TA2CCR0

#define _PERIP_TIMER2_IE TAIE
#define _PERIP_TIMER2_OV_ISR_VECTOR TIMER2_A1_VECTOR
// #define _PERIP_TIMER2_OV_ISR_CALLBACKS_ADDR &TIMER2_A1_ISR_callbacks

#define _PERIP_TIMER3_CTL_ADDR &TB0CTL
#define _PERIP_TIMER3_CCR0_ADDR &TB0CCR0

#define _PERIP_TIMER3_IE TBIE
#define _PERIP_TIMER3_OV_ISR_VECTOR TIMERB1_VECTOR
// #define _PERIP_TIMER3_OV_ISR_CALLBACKS_ADDR &TIMERB1_ISR_callbacks



#endif
