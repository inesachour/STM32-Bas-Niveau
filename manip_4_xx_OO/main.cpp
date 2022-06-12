#include "stm32f10x.h"
#include "PinAsInput.h"
#include "PinAsOutput.h"

using namespace OOlayer;


	PinAsInput  MyButton (PC_13);


/* Class Instantiation: Clock and Pins config
	xxDigitalOut GreenLed (PA_5);
	*/

int main ()
{	
	
	//Clock and Pins Config 
	RCC->APB2ENR |=0x04;
	GPIOA->CRL &= ~(0xFu <<20); 
	GPIOA->CRL |=  0x1<<20;
	
	//PA5 ON 
	GPIOA->BSRR=0x1<<5;
	
	// PA5 ON with OO repr
	//GreenLed=1;
	
	

while (1)
	{		

		if (!MyButton){ //button pressed = 0
		
		//Invert PA5 using register access  ( ^: XOR)
		GPIOA->ODR ^= 0x20; 			
		
		/*Invert PA5 using Greenled object
		GreenLed = !GreenLed;
		*/
		
		for (int i=0x7FFFFF; i>0; i--);
		}

	}
}
