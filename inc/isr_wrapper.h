
#ifndef __ISR_WRAPPER_H
#define __ISR_WRAPPER_H


#include <msp430.h>
#include <stdint.h>

#include "misc.h"


typedef int16_t (*_ISR_callback)(uint16_t isr_vector);
typedef int16_t (*_ISR_callback_8)(uint16_t isr_vector, int8_t p0);
typedef int16_t (*_ISR_callback_16)(uint16_t isr_vector, int16_t p0);

// typedef _ISR_callback_8 *_ISR_callback_8_list;


#ifdef USCI_A0_VECTOR
extern _ISR_callback_8 *USCI_A0_ISR_callbacks;
#endif

#ifdef USCI_A1_VECTOR
extern _ISR_callback_8 *USCI_A1_ISR_callbacks;
#endif

#ifdef TIMER0_A0_VECTOR
extern _ISR_callback_16 *TIMER0_A0_ISR_callbacks;
extern _ISR_callback_16 *TIMER0_A1_ISR_callbacks;
#endif
#ifdef TIMER1_A0_VECTOR
extern _ISR_callback_16 *TIMER1_A0_ISR_callbacks;
extern _ISR_callback_16 *TIMER1_A1_ISR_callbacks;
#endif
#ifdef TIMER2_A0_VECTOR
extern _ISR_callback_16 *TIMER2_A0_ISR_callbacks;
extern _ISR_callback_16 *TIMER2_A1_ISR_callbacks;
#endif
#ifdef TIMERB0_VECTOR
extern _ISR_callback_16 *TIMERB0_ISR_callbacks;
extern _ISR_callback_16 *TIMERB1_ISR_callbacks;
#endif

#endif
