// Implementação de um buffer circular com 10 posições e ponteiro de funções

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ponteiro de função
typedef void (*Function)(void);

typedef struct{
    // nome do processo
    char *ProcessName;
    // tempo
    int Time;
    // ponteiro para a função
    Function function;
}Process;

// Definição do buffer circular
#define BUFFERSIZE 10

Process buffer[BUFFERSIZE];

//Definição de ponteiros de acesso
int start, end;

// Função para adição de processos no buffer	
void addProc(char *nnome, int ntime, Function nfunction){
    // checagem de espaço disponível
    if(((end+1)%BUFFERSIZE) != start){
        //Atualização da posição atual
        buffer[end].ProcessName = nnome;
        buffer[end].Time = ntime;
        buffer[end].function = nfunction;
        printf("Processo %s adicionado com sucesso!\n", nnome);
        end = (end+1)%BUFFERSIZE;
    } 
}

// Função para remoção de processos do buffer
void removeProc(){
    // checagem de processos disponíveis
    if(start != end){
        printf("Processo %s removido com sucesso!\n", buffer[start].ProcessName);
        //Atualização da posição atual
        start = (start+1)%BUFFERSIZE;
    }
}

void exeProc(){
    // checa processos disponíveis
    if(start != end){
        // executa o processo
        buffer[start].function();
    }
}

void func1(){
    printf("func1 executado com sucesso!\n");
}

void func2(){
    printf("func2 executado\n");
}

void func3(){
    printf("func3 executado\n");
}

int main (void){
	addProc("func1", 1, func1);
	addProc("func2", 2, func2);
	addProc("func3", 3, func3);
	exeProc();
	removeProc();
	exeProc();
	removeProc();
	exeProc();
	removeProc();
}
