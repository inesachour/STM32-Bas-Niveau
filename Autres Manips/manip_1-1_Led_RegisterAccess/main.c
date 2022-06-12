#include <stdint.h>

#define   Reg_Enable_RCC     (uint32_t*) 0x40021018 // adresse du registre APBxENR (pour activer les GPIOs utilsés)
#define   GPIOA_CRL		     (uint32_t*) 0x40010800 // adresse du registre CRL (GPIO A)
#define   GPIOA_CRH		     (uint32_t*) 0x40010804 // adresse du registre CRH (GPIO A)
#define   Reg_BSRR_Led	     (uint32_t*) 0x40010810 // adresses du registre permettant la mise à 1 des bits du GPIO A
#define   Reg_BRR_Led	     (uint32_t*) 0x40010814 // adresses du registre permettant la mise à 0 des bits du GPIO A



int main ()
{

 int i;
 
 // activer l'horloge du port A (Leds)
 *Reg_Enable_RCC  |= 0x00000004;

 // Configurer les bits reliés aux leds
 *GPIOA_CRL &= ~((uint32_t) 0x0F << 20 ) ;
 *GPIOA_CRL |= 0x01 << 20;
 
 while (1)
  {
    // allumer les deux leds
 *Reg_BSRR_Led = 0x01 << 5;
 
  for(i=0xFFFFF; i != 0; i--); // Delay
  
  // Eteindre les deux leds.
 *Reg_BRR_Led = 0x01 << 5; 
 
 for(i=0xFFFFF; i != 0; i--); // Delay
   }
}
