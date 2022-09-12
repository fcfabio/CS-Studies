//Listas Duplamente Encadeadas


// Listas Dinamicas Encadeadas

// Bibliotecas
#include <iostream>

using namespace std;

// Estrutura de um nó
struct Node {
    int dado;
    Node* next;
    Node* prev;
};

struct Lista{
    Node* inicio = nullptr;
    Node* fim = nullptr;
};

// Função para imprimir a lista
void print(Lista lista) {
    Node *aux = lista.inicio;
    while (aux != nullptr) {
        cout << aux->dado << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Função para inserir no início
void insert(Lista &lista, int elemento){
    if(lista.inicio == nullptr){ // Lista vazia
        Node* aux = new Node();
        aux -> dado = elemento;
        aux -> next = nullptr;
        aux -> prev = nullptr;
        lista.inicio = aux;
        lista.fim = lista.inicio;
    } else {
        Node* aux = new Node();
        aux -> dado = elemento;
        lista.inicio -> prev = aux;
        aux -> next = lista.inicio;
        aux -> prev = nullptr;
        lista.inicio = aux;
    }
}

// Função para inserir no final
void insertEnd(Lista &lista, int elemento){
    if(lista.inicio == nullptr){ // Lista vazia
        Node* aux = new Node();
        aux -> dado = elemento;
        aux -> next = nullptr;
        aux -> prev = nullptr;
        lista.inicio = aux;
        lista.fim = lista.inicio;
    } else {
        Node* aux = new Node();
        aux -> dado = elemento;
        aux -> next = nullptr;
        aux -> prev = lista.fim;
        lista.fim -> next = aux;
        lista.fim = aux;
    }
}

// Função para remover do início
void remove(Lista &lista){
    if(lista.inicio == nullptr){ // Lista vazia
        cout << "Lista vazia" << endl;
    } else {
        if (lista.inicio -> next == nullptr){ // Lista com um elemento
            delete lista.inicio;
            lista.inicio = nullptr;
        } else {
            Node* aux = lista.inicio;
            lista.inicio = lista.inicio -> next;
            lista.inicio -> prev = nullptr;
            delete aux;
        }
    }
}

// Função para remover do final
void removeEnd(Lista lista){
    if(lista.inicio == nullptr || lista.fim == nullptr){ // Lista vazia
        cout << "Lista vazia" << endl;
    } else {
        if(lista.inicio == lista.fim){ // Lista com um elemento
            delete lista.inicio;
            lista.inicio = nullptr;
            lista.fim = nullptr;
        } else {
            Node* aux = lista.fim;
            lista.fim = lista.fim -> prev;
            lista.fim -> next = nullptr;
            delete aux;
        }
    }
}

// Função para remover um elemento
void removeElement(Lista &lista, int elemento){
    bool flag = false;
    if(lista.inicio == nullptr){ // Lista vazia
        cout << "Lista vazia" << endl;
    } else {
        Node* aux = lista.inicio;
        while(aux != nullptr){
            if(aux -> dado == elemento){
                if(aux == lista.inicio){ // Remover do início
                    remove(lista);
                    flag = true;
                    break;
                } else if(aux == lista.fim){ // Remover do final
                    removeEnd(lista);
                    flag = true;
                    break;
                } else { // Remover do meio
                    aux -> prev -> next = aux -> next;
                    aux -> next -> prev = aux -> prev;
                    delete aux;
                    flag = true;
                    break;
                }
            }
            aux = aux -> next;
        }
        if(!flag){
            cout << "Elemento não encontrado" << endl;
        }
    }
}

// Função para remover todos os elementos
void removeAll(Lista &lista){
    if(lista.inicio == nullptr){ // Lista vazia
        cout << "Lista vazia" << endl;
    } else {
        Node* aux = lista.inicio;
        while(aux != nullptr){
            lista.inicio = lista.inicio -> next;
            delete aux;
            aux = lista.inicio;
        }
        lista.inicio = nullptr;
        lista.fim = nullptr;
    }
}

// Função para buscar um elemento
void search(Lista lista, int elemento){
    Node* aux = lista.inicio;
    int i = 0;
    while (aux != nullptr){
        if (aux -> dado == elemento){
            //return i;
            cout << "Elemento encontrado na posicao " << i << endl;
            print(lista);
            return;
        }
        aux = aux -> next;
        i++;
    }
    cout << "Elemento nao encontrado" << endl;        
}



// Função principal
int main(){
    Lista lista;

    int key = 0;

    // Descrição de Listas Encadeadas
    cout << endl << endl;
    cout << "------------------------ Listas Encadeadas Dinamicas ------------------------" << endl << endl;
    cout << "Uma lista encadeada dinamica e uma estrutura de dados que armazena elementos" << endl;
    cout << "em nos, onde cada no armazena um valor e um ponteiro para o proximo no, caso" << endl;
    cout << " seja uma lista encadeada simples." << endl;
    cout << "Caso seja uma lista duplamente encadeada, cada no armazena um valor e dois" << endl;
    cout << " ponteiros, um para o proximo no e outro para o no anterior." << endl;
    cout << "A lista e denominada dinamica pois seu tamanho pode ser alterado durante a" << endl;
    cout << "execucao do programa." << endl;
    cout << " ----------------------------------------------------------------------------" << endl;
    cout << " " << endl;

    // Menu
    while(key != 9){
        cout << "1 - Inserir no inicio" << endl;
        cout << "2 - Inserir no final" << endl;
        cout << "3 - Remover do inicio" << endl;
        cout << "4 - Remover do final" << endl;
        cout << "5 - Remover um elemento" << endl;
        cout << "6 - Remover todos os elementos" << endl;
        cout << "7 - Buscar um elemento" << endl;
        cout << "8 - Imprimir a lista" << endl;
        cout << "9 - Sair" << endl;
        cout << " " << endl;
        cout << "Digite a opcao desejada: ";
        cin >> key;
        cout << " " << endl;

        switch(key){
            case 1:
                int elemento;
                cout << "Digite o elemento a ser inserido: ";
                cin >> elemento;
                insert(lista, elemento);
                print(lista);
                system("pause");
                break;
            case 2:
                int elemento2;
                cout << "Digite o elemento a ser inserido: ";
                cin >> elemento2;
                insertEnd(lista, elemento2);
                print(lista);
                system("pause");
                break;
            case 3:
                remove(lista);
                print(lista);
                system("pause");
                break;
            case 4:
                removeEnd(lista);
                print(lista);
                system("pause");
                break;
            case 5:
                int elemento3;
                cout << "Digite o elemento a ser removido: ";
                cin >> elemento3;
                removeElement(lista, elemento3);
                print(lista);
                system("pause");
                break;
            case 6:
                removeAll(lista);
                cout << "A lista foi esvaziada" << endl;
                print(lista);
                break;
            case 7:
                int elemento4;
                cout << "Digite o elemento a ser buscado: ";
                cin >> elemento4;
                search(lista, elemento4);
                system("pause");
                break;
            case 8:
                print(lista);
                system("pause");
                break;
            case 9:
                break;
            default:
                cout << "Opcao invalida" << endl;
                break;
        }
        cout << " " << endl;
    }
}
