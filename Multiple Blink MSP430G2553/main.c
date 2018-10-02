#include <msp430.h> 

/*
 * @author Nick Setaro
 * @version 9.14.2018
 */

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1SEL &= ~(BIT0 + BIT6);    //select LED
	P1SEL2 &= ~(BIT0 + BIT6);   //select other LED
	P1DIR |= (BIT0 + BIT6);     //set P1.0 and 1.6 to output

	P1OUT |= BIT0;              //set LED on
	P1OUT &= ~BIT6;             //set other LED off
	
	//timer setup
	TA0CCTL = TASSEL_1 + MC_1;
	TA0CCR0 = 1000;
	
	
	while (1) {
	    unsigned int i, j;      //counters for delays

	    i++;                    //increment delay counter
	    j++;                    //increment delay counter

	    if(i>3000)   {             //if i LED has waited long enough to blink
	        i=0;                //reset i counter
	        P1OUT ^= BIT0;       //toggle LED
	    }

	    if (j>30000) {          //if j LED has waited long enough to blink
	        j=0;                //reset j counter
	        P1OUT ^= BIT6;      //toggle LED
	    }
	}
	return 0;
}

#pragma vector=TIMER0_A3_VECTOR
__interrupt_ void Timer_A(void) {
	
}
