//GPIO_LEDS PROJECT

#include "stm32f10x.h"

/* declaration des structures relatives aux periphs utilis�s -----------------------------------------------------------*/
GPIO_InitTypeDef  GPIO_InitStructure;


/* Private functions ---------------------------------------------------------*/
void Delay(vu32 nCount);


int main(void)
{  /* activer l'horloge du port  connect� aux leds */
    RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOA, ENABLE );

    /* Configurer les pins reli�s aux Leds */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;// output Push Pull
  GPIO_Init(GPIOA, &GPIO_InitStructure);

while (1)
     {
       //allumer les leds
 GPIO_SetBits(GPIOA, GPIO_Pin_5);
 Delay (0xFFFFF);
	 
        // les �teindre
 GPIO_ResetBits (GPIOA, GPIO_Pin_5);  
 Delay (0xFFFFF);
     }
}
/************** Function Name  : Delay  *****************/
void Delay(vu32 nCount)
{
  for(; nCount != 0; nCount--);
}
