
/* Include ------------------------------------------------------------------*/
#include "stm32f10x.h"

/*----------------- Déclaration des structures relatives aux periphs utilisés ---------------*/
GPIO_InitTypeDef  GPIO_InitStructure;

/* ---------------Private functions ---------------*/
void Delay(vu32 nCount);

uint16_t appui; // variable appui pour lire l'etat du bouton

int main(void)
{ /*---------- Activer les horloges des ports utilsés (port A et port C)------------ */ 
 RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOC| RCC_APB2Periph_GPIOA, ENABLE);

/*-------------- Configure the GPIO_LED pin -----------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

/*-------------- Configure the GPIO_ Pushbutton pin -----------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ; // IN Floating
  GPIO_Init(GPIOC,&GPIO_InitStructure);

  
/* ---------  Set one Led ON / one OFF ---------- */
GPIO_SetBits(GPIOA,GPIO_Pin_5);
GPIO_ResetBits(GPIOA,GPIO_Pin_6);


while (1)
 	 {
appui = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13); 

if(appui)	         {
 GPIO_ToggleBits(GPIOA,GPIO_Pin_5 | GPIO_Pin_6);
  	          }
else
                      {
  GPIO_ToggleBits(GPIOA,GPIO_Pin_5 | GPIO_Pin_6);
                       }
          }
   }
/*******************************************************************************
* Function Name  : Delay
* Description    : Inserts a delay time.
* Input          : nCount: specifies the delay time length.
*******************************************************************************/
void Delay(vu32 nCount)
{
  for(; nCount != 0; nCount--);
}
