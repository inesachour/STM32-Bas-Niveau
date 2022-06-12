//usart_send_polling

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Private typedef -----------------------------------------------------------*/

char password[]="QUANTUM001";
char Receive_Buffer[10]; 
char Transmit_Buffer[]="HELLOWORLD";

uint8_t Nbre_Received_Caracters;//Une variable qui permet d'indiquer si 8 caractères ont été reçus

// Structures

GPIO_InitTypeDef GPIO_InitStructure;
EXTI_InitTypeDef EXTI_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
USART_InitTypeDef USART_InitStructure;
DMA_InitTypeDef DMA_InitStructure;
 
/* Private functions ---------------------------------------------------------*/
void Delay(vu32 nCount);
uint8_t stringCompare(char str1[],char str2[], uint8_t StrLength);

int main(void)
{
/* ================  Configure the Periph Clocks ===================== */

  /* Enable GPIOx and AFIO clocks */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO, ENABLE);

  /* Enable USART2 clocks */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	/* Enable DMA1 clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

	
  /* ================  Configure the GPIO ports ===================== */

    /*Configure PA5 as Output push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  /* Configure USART2 Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure USART2 Rx as input floating */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);


/* ====================  USART1 configuration ======================*/
    /* USART2 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 19200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No ;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART2, &USART_InitStructure);
  
  /*Enable  Rx Interrupt (s) on USART2*/
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	
	/*Enable  Tx DMA Request (s) on USART2*/
		USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);


  /* Enable the USARTx */
  USART_Cmd(USART2, ENABLE);
	
     /* Enable and set USART2 Interrupt */
   NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);	 
	 
/* ====================  DMA configuration ======================*/

		//DMAx channelx (UART1 TX) configuration */
		DMA_DeInit(DMA1_Channel7);
		DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) &USART2->DR;
		DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)Transmit_Buffer;
		DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
		DMA_InitStructure.DMA_BufferSize = 10;
		DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
		DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
		DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
		DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
		DMA_InitStructure.DMA_Priority = DMA_Priority_High;
		DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;	
		
		DMA_Init(DMA1_Channel7, &DMA_InitStructure);

//  /* Enable DMAx Channely Transfer Complete/ Half Transfer interrupts */
	DMA_ITConfig(DMA1_Channel7, DMA_IT_TC|DMA_IT_HT, ENABLE);


//  /* Enable DMA1 Channel6 transfer */
//  DMA_Cmd(DMA..._Channel.., ENABLE);


//     /* Enable and set DMAx Channel y Interrupt  */
   NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel7_IRQn;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
//	 
	 
/*----------------------------------------------------------*/

 while(1)
 {


}//END MAIN

   }                

uint8_t stringCompare(char str1[],char str2[], uint8_t StrLength){
    int i=0;
   
    while(str1[i]!='\0' && str2[i]!='\0' && i<StrLength){
         if(str1[i]!=str2[i]){
             return 0;             
         }
         i++;
    }
         return 1;

}
  
/******************** Function Name  : Delay**************************/
void Delay(vu32 nCount)
{  for(; nCount != 0; nCount--);}


