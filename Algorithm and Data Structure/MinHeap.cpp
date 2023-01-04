/*
   HEAP is a complete binary tree, that is, a binary tree where each level
   is filled from left to right and must be complete before the next level 
   is filled. There is a special constraint: each node in the heap must 
   contain a value greater (or smaller) than all the values contained by
   its descendant nodes.

   It can be used in:
      - Simulations
      - Data compression
      - Graph algorithms
      - AI
      - Statistics
      - OS

   Due to the fact that the HEAP is "predictable", it is possible to 
   represent it using a single vector.
   Parent: [(j-1)/2]
   Children: [2j+1] and [2j+2]

   First node with children, considering reading from bottom to top and 
   from right to left: n/2 - 1

*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define INFINITY 100000000000
#define SIZE 15

using namespace std;

int last; //ultimo elemento da heap


void print(int *vet){
    for(int i = 0; i < last; i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}


void heapfy_menor(int *vet, int n, int pai){
    int esq = 2*pai + 1; //filho esquerdo
    int dir = 2*pai + 2; //filho direito
    int menor, aux;

    //Escolhe menor valor entre filhos
    menor = pai;
    if((esq < n) && (vet[esq] < vet[menor])){
        menor = esq;
    }  
    if((dir < n) && (vet[dir] < vet[menor])){
        menor = dir;
    }

    // se um dos filhos for menor que o pai, troca
    if(menor != pai){
        aux = vet[menor];
        vet[menor] = vet[pai];
        vet[pai] = aux;

        //continua descida
        heapfy_menor(vet, n, menor);
    }
}

void create_heap_menor(int *vet, int n){
    //for(int i = n/2-1; i >= 0; i--){ //para cada nó que não é folha
    for(int i = n; i >= 0; i--){ // Garantir ajuste mesmo que itens estejam 100% desordenados
        heapfy_menor(vet, n, i); // ajusta a heap de baixo pra cima
    }
}

void heapsort(int *vet, int n){
    int aux;
    create_heap_menor(vet, n);
    for(int i=n-1; i>0; i--){
        //troca o maior elemento com o ultimo
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        n--; // diminui o tamanho da heap (ultimo elemento ja ordenado)
        heapfy_menor(vet, n, 0); //ajusta a heap
    }
}

bool empty(int *vet){
    return last == 0;
}

bool full(int *vet){
    return last == SIZE;
}

void push(int *vet, int elemento){
    if (!full(vet)){
        vet[last] = elemento;
        last++;
        create_heap_menor(vet, last);
    }else{
        cout << "Heap cheia" << endl;
    }
    print(vet);
}

int pop(int *vet){
    int aux = -1;
    if (empty(vet)){
        cout << "Heap vazia" << endl;
    }else{
        aux = vet[0];
        vet[0] = vet[last-1];
        last--;
        create_heap_menor(vet, last);
    }
    print(vet);
    return aux;
}

int top(int *vet){
    return vet[0];
}



int main(){
    int vetor[SIZE]; //HEAP
    last = 0;
    int elemento = 0;
    while(elemento != -1){
        cout << "Entre com os elementos da heap (-1 para sair): ";
        cin >> elemento;
        if (elemento != -1){
            push(vetor, elemento);
        }
    }
    cout << "\nHeap criada: ";
    print(vetor);

    cout << "Escolha uma opcao:" << endl;
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Remover elemento" << endl;
    cout << "3 - Mostrar elemento do topo" << endl;
    cout << "4 - Verificar se a Heap esta vazia" << endl;
    cout << "5 - Verificar se a Heap esta cheia" << endl;
    cout << "6 - Imprimir Heap" << endl;
    cout << "7 - Sair" << endl;

    int opcao = 0;
    while(opcao != 7){
        cout << "Opcao: ";
        cin >> opcao;
        switch(opcao){
            case 1:
                cout << "Entre com o elemento a ser inserido: ";
                cin >> elemento;
                push(vetor, elemento);
                break;
            case 2:
                cout << "Elemento removido: " << pop(vetor) << endl;
                break;
            case 3:
                cout << "Elemento do topo: " << top(vetor) << endl;
                break;
            case 4:
                if(empty(vetor)){
                    cout << "A Heap esta vazia" << endl;
                }else{
                    cout << "A Heap nao esta vazia" << endl;
                }
                break;
            case 5:
                if(full(vetor)){
                    cout << "A Heap esta cheia" << endl;
                }else{
                    cout << "A Heap nao esta cheia" << endl;
                }
                break;
            case 6:
                print(vetor);
                break;
            case 7:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
                break;
        }
    }

    return 0;
}
