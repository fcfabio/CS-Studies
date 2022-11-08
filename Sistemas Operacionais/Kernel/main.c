#include "kernel.h"
#include <stdio.h>

int countP4 = 0;


char process1(){
  printf("Nome:\t\tFabio Carriao Filho\n");
  return SUCCESS;
}

char process2(){
  printf("Matricula:\txxxxxxx\n");
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
   process P1 =  {process4, 3, "process4"};
   process P2 =  {process3, 2, "process3"};
   process P3 =  {process2, 0, "process2"};
   process P4 =  {process1, 1, "process1"};
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
