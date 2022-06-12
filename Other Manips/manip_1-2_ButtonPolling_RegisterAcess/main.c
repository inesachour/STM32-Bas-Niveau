#include <stdint.h>


#define   Reg_Enable_RCC     (uint32_t*) 0x40021018 // adresse du registre assurant l'activation des horloges (RCC) des ports A et C
#define   Reg_Config_Led     (uint32_t*) 0x40010800 // adresse du registre de configuration du Port A (Leds)
#define   Reg_BSRR_Led	     (uint32_t*) 0x40010810 // adresses du registre permettant la mise à 1 des bits du port A
#define   Reg_BRR_Led	     (uint32_t*) 0x40010814 // adresses du registre permettant la mise à 0 des bits du port A

#define   Reg_Config_Bouton  (uint32_t*) 0x40011004// adresse du registre de configuration du port C (relié au bouton: PC13)
#define   Reg_Bouton         (uint32_t*) 0x40011008 //adresse du registre en entrée (IDR) du port C


 int etat_bouton; // variable permettant de lire l'etat du bouton

int main ()
{


 
 // activer les horloges des ports reliés aux leds et au bouton
 *Reg_Enable_RCC  = 0x14;

 // Configurer les bits reliés aux leds
 *Reg_Config_Led &= ~ ((uint32_t) 0x0F << 20);
	*Reg_Config_Led |= (uint32_t) 0x2 <<20 ;
 
 // configurer le bit relié au bouton
 *Reg_Config_Bouton &= ~ ((uint32_t) 0x0F << 20); // Input Floating
	*Reg_Config_Bouton |= (uint32_t) 0x4 <<20;
 


//Testet Bouton et allumer si appuyé sinon éteindre

while (1)
{
  etat_bouton = *Reg_Bouton & ((uint32_t)0x1<<13); // lire l'etat du bit relié au bouton (bit PA0)
  
if (etat_bouton == 0x0000) // si appui

{
 *Reg_BSRR_Led = 0x1 <<5;// allumer leds

}
else //sinon

{
  // Eteindre les deux leds.
 *Reg_BRR_Led = 0x1 <<5; 

   }
}
}