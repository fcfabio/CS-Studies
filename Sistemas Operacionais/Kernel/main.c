// Adicionar 4 processos, primeiro imprime nome e retorna SUCCESS
// Segundo imprime matricula e retorna SUCCESS
// Terceiro imprime "UNIFEI" e retorna REPEAT
// Quarto imprime "PCO003" e quantidade de vezes executado e retorna REPEAT

#include "kernel.h"
#include <stdio.h>

int countP4 = 0;


char process1(){
  printf("Nome:\t\t fulano \n");
  return SUCCESS;
}

char process2(){
  printf("Matricula:\t xxxxxxxxx \n");
  return SUCCESS;
}

char process3(){
  printf("UNIFEI\n");
  return REPEAT;
}

char process4(){
  printf("PCO003 Executado : %d vezes.\n", countP4);
  countP4++;
  return REPEAT;
}



void main(void){
   process P1 =  {process1};
   process P2 =  {process2};
   process P3 =  {process3};
   process P4 =  {process4};
  //initialize the kernel
  kernelInit();
  //add processes to the kernel
  kernelAddProc(&P1);
  kernelAddProc(&P2);
  kernelAddProc(&P3);
  kernelAddProc(&P4);
  //start the kernel
  kernelLoop();
}
