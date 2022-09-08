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

// Função para imprimir a lista
void print(Node *ini) {
    Node *aux = ini;
    while (aux != nullptr) {
        cout << aux->dado << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Função para inserir no início
void insert(Node* &ini, int elemento, Node* &fim){
    if(ini == nullptr){ // Lista vazia
        Node* aux = new Node();
        aux -> dado = elemento;
        aux -> next = nullptr;
        aux -> prev = nullptr;
        ini = aux;
        fim = ini;
    } else {
        Node* aux = new Node();
        aux -> dado = elemento;
        ini -> prev = aux;
        aux -> next = ini;
        aux -> prev = nullptr;
        ini = aux;
    }
}

// Função para inserir no final
void insertEnd(Node* &ini, int elemento, Node* &fim){
    if(ini == nullptr){ // Lista vazia
        Node* aux = new Node();
        aux -> dado = elemento;
        aux -> next = nullptr;
        aux -> prev = nullptr;
        ini = aux;
        fim = ini;
    } else {
        Node* aux = new Node();
        aux -> dado = elemento;
        aux -> next = nullptr;
        aux -> prev = fim;
        fim -> next = aux;
        fim = aux;
    }
}

// Função para remover do início
void remove(Node* &ini){
    if(ini == nullptr){ // Lista vazia
        cout << "Lista vazia" << endl;
    } else {
        if (ini -> next == nullptr){ // Lista com um elemento
            delete ini;
            ini = nullptr;
        } else {
            Node* aux = ini;
            ini = ini -> next;
            ini -> prev = nullptr;
            delete aux;
        }
    }
}

// Função para remover do final
void removeEnd(Node* &ini, Node* &fim){
    if(ini == nullptr || fim == nullptr){ // Lista vazia
        cout << "Lista vazia" << endl;
    } else {
        if(ini == fim){ // Lista com um elemento
            delete ini;
            ini = nullptr;
            fim = nullptr;
        } else {
            Node* aux = fim;
            fim = fim -> prev;
            fim -> next = nullptr;
            delete aux;
        }
    }
}

// Função para remover um elemento
void removeElement(Node* &ini, int elemento, Node* &fim){
    bool flag = false;
    if(ini == nullptr){ // Lista vazia
        cout << "Lista vazia" << endl;
    } else {
        Node* aux = ini;
        while(aux != nullptr){
            if(aux -> dado == elemento){
                if(aux == ini){ // Remover do início
                    remove(ini);
                    flag = true;
                } else if(aux == fim){ // Remover do final
                    removeEnd(ini, fim);
                    flag = true;
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
void removeAll(Node* &ini, Node* &fim){
    if(ini == nullptr){ // Lista vazia
        cout << "Lista vazia" << endl;
    } else {
        Node* aux = ini;
        while(aux != nullptr){
            ini = ini -> next;
            delete aux;
            aux = ini;
        }
        ini = nullptr;
        fim = nullptr;
    }
}

// Função para buscar um elemento
void search(Node* ini, int elemento){
    Node* aux = ini;
    int i = 0;
    while (aux != nullptr){
        if (aux -> dado == elemento){
            //return i;
            cout << "Elemento encontrado na posicao " << i << endl;
            print(ini);
            return;
        }
        aux = aux -> next;
        i++;
    }
    cout << "Elemento nao encontrado" << endl;        
}



// Função principal
int main(){
    Node* inicio;
    Node* fim;
    inicio = nullptr;
    fim = nullptr;

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
                insert(inicio, elemento, fim);
                print(inicio);
                break;
            case 2:
                int elemento2;
                cout << "Digite o elemento a ser inserido: ";
                cin >> elemento2;
                insertEnd(inicio, elemento2, fim);
                print(inicio);
                break;
            case 3:
                remove(inicio);
                print(inicio);
                break;
            case 4:
                removeEnd(inicio, fim);
                print(inicio);
                break;
            case 5:
                int elemento3;
                cout << "Digite o elemento a ser removido: ";
                cin >> elemento3;
                removeElement(inicio, elemento3, fim);
                print(inicio);
                break;
            case 6:
                removeAll(inicio, fim);
                print(inicio);
                break;
            case 7:
                int elemento4;
                cout << "Digite o elemento a ser buscado: ";
                cin >> elemento4;
                search(inicio, elemento4);
                break;
            case 8:
                print(inicio);
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
