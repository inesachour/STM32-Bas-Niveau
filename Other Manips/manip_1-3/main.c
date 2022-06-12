#include <gpio.h>

#define   Reg_Enable_RCC     (uint32_t*) 0x40021018 // adresse du registre APBxENR (pour activer les GPIOs utilsés)

#define   RCC_APB2ENR     (uint32_t*) 0x40021018
uint8_t EtatBouton;

int main ()
{	 
	//Activate GPIOs Clocks
	GPIO_Struct GPIO_InitStruct ;
 
	*RCC_APB2ENR  |=  0x00000014; //Activation de l'horloge du PORT A/C
	
	
	
/*	GPIOA->CRL &= ~((uint32_t) 0xF<<20);
	GPIOA->CRL |= GPIO_Mode_OutputPP2Mhz<<20; 
	
	GPIOC->CRH &= ~((uint32_t) 0xF<<20);
	GPIOC->CRH |= GPIO_Mode_InputFloating<<20;*/
	
	GPIO_InitStruct.GPIO_PIN = GPIO_PIN_13 ; 
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_InputFloating ; 
	GPIO_init(GPIOC, &GPIO_InitStruct) ; 
	GPIO_InitStruct.GPIO_PIN = GPIO_PIN_5 ; 
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OutputPP2Mhz; 
	GPIO_init(GPIOA, &GPIO_InitStruct) ;

	
 while (1)
  {		
		//Test Push Button
 		//Read Oush Button State (0=Pressed, 1=Released)
		EtatBouton=GPIO_TestPin(GPIOC,GPIO_PIN_13);
		
	if (EtatBouton==0)  //If Pressed, Led ON	
	GPIO_SetPin(GPIOA, GPIO_PIN_5);
	else //Released, Led OFF
	GPIO_ResetPin(GPIOA, GPIO_PIN_5);				
}
	}
