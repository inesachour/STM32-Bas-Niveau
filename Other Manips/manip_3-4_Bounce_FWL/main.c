
// Interrupts EXTI Project

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Private typedef -----------------------------------------------------------*/
GPIO_InitTypeDef GPIO_InitStructure;
EXTI_InitTypeDef EXTI_InitStructure;//EXTI
NVIC_InitTypeDef NVIC_InitStructure; // NVIC
 
/* Private functions ---------------------------------------------------------*/
void Delay(vu32 nCount);

  int i;
	int tmpRebond;;
  int nbrRebond ; 
	int appui[10];
  int main(void)
{

  
/* Activer les horloges des ports utilisés */
  
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);

	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE);

 /* Configure PC.08 and PC.09 as Output push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  /* Configure PA.00 as Input push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;; //PD;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
 
  
      /* Connect Button EXTI Line to Button GPIO Pin */
     GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);

    /* Configure Button EXTI line */
   EXTI_InitStructure.EXTI_Line = EXTI_Line0;
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;
   EXTI_Init(&EXTI_InitStructure);


   /* Enable and set Button EXTI Interrupt to the lowest priority */

   NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
    

    /* Turn on led connected to PB.08 pin */
    GPIO_SetBits(GPIOC, GPIO_Pin_8|GPIO_Pin_9);
    /* Insert delay */
    Delay(0xFFFFF);

	//Activate SysTick Interrupts: 10 msec period --> 100HZ
	
	if (SysTick_Config(SystemCoreClock/ 1000)) {  // systemcoreclock=Default SysTick Frequency
		     /* Capture error */ 
			while (1);  
	}

	
  /* Infinite loop */
  while (1)  
    { 
      }
}

/******************** Function Name  : Delay**************************/
void Delay(vu32 nCount)
{  for(; nCount != 0; nCount--);}
