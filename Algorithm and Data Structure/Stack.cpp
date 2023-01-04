/*

Stacks are frequently used in compilers to check, for example, if expressions 
are well-formed. Consider the problem of deciding whether a given sequence of 
parentheses/braces is well-formed.

For example, the following sequence is well-formed:
(  (  )  {  (  )  }  )

While this one is not:
(  {  )  }

Write the entire stack code (push, pop, empty, and top functions) and use it to solve the problem.

*/

#include <iostream>
#include <string>

using namespace std;

// Estrutura de um nó
struct Node {
    char dado;
    Node* next;
};

struct Pilha{
    Node* inicio = nullptr;
    Node* fim = nullptr;
};

// Função para imprimir a pilha
void print(Pilha pilha) {
    Node *aux = pilha.inicio;
    while (aux != nullptr) {
        cout << aux->dado << " -> ";
        aux = aux->next;
    }
    cout << "NULL";
}

// Função para verificar se pilha está vazia
bool empty(Pilha &  pilha){
    if(pilha.inicio == nullptr){
        return true;
    }else{
        return false;
    }
}

// Função para retornar elemento do topo
char top(Pilha &pilha){
    return pilha.inicio->dado;
}

void push(Pilha &pilha, char elemento){
    if(pilha.inicio == nullptr){ // Pilha vazia
        Node* aux = new Node();
        aux -> dado = elemento;
        aux -> next = nullptr;
        pilha.inicio = aux;
        pilha.fim = pilha.inicio;
    } else {
        Node* aux = new Node();
        aux -> dado = elemento;
        aux -> next = pilha.inicio;
        pilha.inicio = aux;
    }
}

void pop(Pilha &pilha){
    if(pilha.inicio != nullptr){
        Node* aux = pilha.inicio;
        pilha.inicio = pilha.inicio->next;
        delete aux;
    }
}


bool verifica(string str){
    Pilha pilha;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '{'){
            push(pilha, str[i]);
        }else if(str[i] == ')'){
            if(empty(pilha)){
                return false;
            }else if(top(pilha) == '('){
                pop(pilha);
            }else{
                return false;
            }
        }else if(str[i] == '}'){
            if(empty(pilha)){
                return false;
            }else if(top(pilha) == '{'){
                pop(pilha);
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    if(empty(pilha)){
        return true;
    } else {
        return false;
    }
}

int main(){
    string seq;
    cout << "Entre com sequecnia:" << endl;
    cin >> seq;

    if (verifica(seq))
    {
        cout << "Expressao bem formada" << endl;
    }else{
        cout << "Expressao mal formada" << endl;
    }
}
