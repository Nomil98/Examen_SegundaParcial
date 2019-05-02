#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

int Led1=0, contadorled=0;
#INT_TIMER0
void TIMER0(){
contadorled++;
Led1++;
set_timer0(122);
}

void main(){
 setup_oscillator(OSC_16MHZ);
 set_tris_c(0x00);
 set_tris_b(0x00);
 
setup_timer_0(RTCC_INTERNAL |RTCC_DIV_128 );
enable_interrupts(INT_TIMER0);//SE HABILITA LA INTERRUPCIÓN NECESARIA
enable_interrupts(GLOBAL); // SE HABILITAN LAS INTERRUPCIONES GLOBALES
set_timer0(122);
   
while(1){

if(contadorled==1){
    output_b(Led1);
   }
   contadorled=0;
   Led1=0;

 }

}
