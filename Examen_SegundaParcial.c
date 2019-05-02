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
 int inicio=0;
char palabra[10]=getc(); //enter = 13, espacio =32
char cadena[20];
int num=0;
int i=0;
int j=0;
int a=0;
 
setup_timer_0(RTCC_INTERNAL |RTCC_DIV_128 );
enable_interrupts(INT_TIMER0);//SE HABILITA LA INTERRUPCIÓN NECESARIA
enable_interrupts(GLOBAL); // SE HABILITAN LAS INTERRUPCIONES GLOBALES
set_timer0(122);
while(1){

if (kbhit()){
   if(cadena[i]>=65 && cadena[i]<=122 || cadena == 13)
   {
       printf("%c", cadena[i])
       if(cadena[i]==13)
       {
         inicio =1;
       }
       i++;
   }

}

if(inicio==1){
   while( cadena[i]!= 32 && cadena[i]!=13){
     palabra[j]=cadena[i];
     j++;
     i++;
       
  
     }
     i++;
     while(cadena[i]!=13){
     num = cadena[i];
     
     }
   
   printf("%c", palabra[j]);
   printf("%d", num);
  }
  cadena[i]=0;
  palabra[j]=0;
  a=0;
  num=0;
  inicio=0;




if(contadorled==1){
    output_b(Led1);
   }
   contadorled=0;
   Led1=0;

 }

}
