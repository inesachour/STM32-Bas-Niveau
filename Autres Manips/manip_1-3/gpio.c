#include <gpio.h>

int GPIO_TestPin(GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{
	int test = GPIOx->IDR & GPIO_PIN;
	
	if (test==0)
		return 0;
	else
	return 1;
	
	}

void GPIO_SetPin(GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BSRR = GPIO_PIN ;	
}

void GPIO_ResetPin (GPIO_Typedef *GPIOx, uint16_t GPIO_PIN)
{
	GPIOx->BRR = GPIO_PIN ;		
}


void GPIO_init (GPIO_Typedef* GPIOx, GPIO_Struct * GPIO_InitStruct) 
{
	uint16_t pos;
	uint32_t mask1 = 0,mask2 = 0,mode1 = 0,mode2 =0 ;
	int i;
	for(i=0;i<16;i++){
		pos = GPIO_InitStruct->GPIO_PIN & (0x1<<i);
		if(pos <= 0x80 ) {
			mask1 |= 0xF<<(4*i);	
			mode1 |= GPIO_InitStruct->GPIO_Mode<<(4*i);
	  }
		else {
			mask2 |= 0xF<<((i-8)*4);
			mode2 |= GPIO_InitStruct->GPIO_Mode<<((i-8)*4);
		}
	}
	GPIOx->CRL &= ~mask1;
	GPIOx->CRH &= ~mask2;
	GPIOx->CRL |= mode1;
	GPIOx->CRH |= mode2;
	
}
