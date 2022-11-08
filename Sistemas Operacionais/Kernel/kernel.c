//compilar tudo 
// gcc kernel.c -fPIC -shared -o libkernel.so
//compilar main
// gcc -o main .\main.c .\libkernel.so

#include "kernel.h"

#define POOL_SIZE 10
process * pool[POOL_SIZE];
int start, end;
char kernelInit(void){
	start = 0;
	end = 0;
	return SUCCESS;
}
char kernelAddProc(process * newProc){
	//checking for free space
	if ( ((end+1)%POOL_SIZE) != start){
		pool[end] = newProc;
		end = (end+1)%POOL_SIZE;
		return SUCCESS;
	}
	return FAIL;
}

void kernelLoop(void){
  int idx, index, first;
  //for(;;){
  for (int j = 0; j < 15; j++){
    //Do we have any process to execute?
      index = start;
      if (start != end){
        // select the process with the highest priority
        first = pool[start]->priority;
        // Loop through all processes
        for(int i = 0; i < POOL_SIZE; i++){
          idx = (i + start)%POOL_SIZE; // cycle through the pool
          if (start == end){ //there is only one process in the pool
            break;
          } else if(end < start){ // the pool was completed and the last processes are in the beginning of the pool
            if (idx < end || idx > start){              
              first = pool[idx]->priority;
              index = idx;
            }
          }else{
            if (idx < end && idx >= start){
              if (pool[idx]->priority < first){
                first = pool[idx]->priority;
                index = idx;
              }
            }else{
              break;
            }
          }
        }
        // if the index of the proces is different from the start, we swap the processes
        if(index != start){
          process * temp = pool[start];
          pool[start] = pool[index];
          pool[index] = temp;
        }
        
        //check if there is need to reschedule
        if (pool[start]->func() == REPEAT){
          //reschedule
          kernelAddProc(pool[start]);
        }
        //prepare to get the next process
        start = (start+1)%POOL_SIZE;
      }
   }
}
