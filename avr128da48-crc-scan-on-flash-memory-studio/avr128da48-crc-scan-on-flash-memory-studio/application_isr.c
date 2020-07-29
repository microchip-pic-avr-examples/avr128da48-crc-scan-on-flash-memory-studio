/*
 * application_isr.c
 *
 * Created: 5/8/2020 10:52:20 AM
 *  Author: I51005
 */
#include "application_isr.h"

extern uint8_t switchPressInterruptFlag;
extern uint8_t pitInterruptFlag;

/**
  @Param
  none
  @Returns
   none
  @Description
  PIT Interrupt handler. Interrupt in every 8 sec
 **/
ISR(RTC_PIT_vect)
{
	/* Insert your PIT interrupt handling code here */

	/* The interrupt flag has to be cleared manually */
	RTC.PITINTFLAGS = RTC_PI_bm;

	// Set this flag after the timer interval of 8secs
	pitInterruptFlag = 1;
}

/**
  @Param
  none
  @Returns
   none
  @Description
  IOC handler for pin PC7. Interrupt upon switch press
 **/
ISR(PORTC_PORT_vect)
{
	/* Insert your PORTC interrupt handling code here */

	/* Clear interrupt flags */
	VPORTC_INTFLAGS = (1 << 7);

	// Set this flag when switch press event occurs
	switchPressInterruptFlag = 1;
}
