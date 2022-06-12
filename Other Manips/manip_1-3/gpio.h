#include <stm32map.h>

typedef struct { 
uint16_t GPIO_PIN ; 
uint8_t GPIO_Mode ; 
} GPIO_Struct ;

//1- Define the GPIO Pins
#define GPIO_PIN_0                 ((uint16_t)0x0001)  
#define GPIO_PIN_1                 ((uint16_t)0x0002) 
#define GPIO_PIN_2                 ((uint16_t)0x0004) 
#define GPIO_PIN_3                 ((uint16_t)0x0008)
#define GPIO_PIN_4                 ((uint16_t)0x0010)
#define GPIO_PIN_5                 ((uint16_t)0x0020)
#define GPIO_PIN_6                 ((uint16_t)0x0020)
#define GPIO_PIN_7                 ((uint16_t)0x0020)
#define GPIO_PIN_8                 ((uint16_t)0x0100)
#define GPIO_PIN_9                 ((uint16_t)0x0200)
#define GPIO_PIN_10                 ((uint16_t)0x0020)
#define GPIO_PIN_11                 ((uint16_t)0x0020)
#define GPIO_PIN_12                 ((uint16_t)0x0020)
#define GPIO_PIN_13                 ((uint16_t)0x2000)
#define GPIO_PIN_14                 ((uint16_t)0x0020)
#define GPIO_PIN_15                 ((uint16_t)0x0020)

//2 - Define The Mode Values
#define GPIO_Mode_InputFloating   0x4
#define GPIO_Mode_OutputPP2Mhz  	0x2
#define GPIO_Mode_OutputPP10Mhz  0x14
#define GPIO_Mode_OutputPP50Mhz  0x18

//3- Functions Proyotypes

int GPIO_TestPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_SetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_ResetPin (GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_init (GPIO_Typedef* GPIOx,  GPIO_Struct  * GPIO_InitStruct);

