/*
 ########## Problema do Jantar dos Filosofos ##########
 Cinco Filosofos desejam comer espaguete, no entanto cada um precisa de
 dois garfos para comer. Os Filosofos estão sentados em uma mesa circular,
 e precisam compartilhar os garfos. Cada Filosofo tem um garfo à sua 
 esquerda e à sua direita. OS Filosofos comem e pensam. Para comer, cada
 Filosofo precisa pegar um garfo de cada vez. Um Filosofo só pode comer
 quando ele tem os dois garfos. Se um Filosofo não conseguir  pegar os dois
 garfos, ele deve esperar até que os garfos fiquem disponíveis.

 Problemas a serem resolvidos:
 1. Deadlock – todos os Filosofos pegam um garfo ao mesmo tempo;
 2. Starvation – os Filosofos fiquem indefinidamente pegando garfos
    simultaneamente;
*/

// Solução:
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <vector>
#include <fstream>

using namespace std;

// Definições de variáveis
#define N 5
#define ESQUERDA id % N
#define DIREITA (id + 1) % N

// Definições de funções
void pensar(int id);
void comer(int id);
void pegarGarfos(int id);
void soltarGarfos(int id);

// Definições de variáveis globais
mutex garfos[N];
mutex coutMutex; // Travar impressão para evitar várias threads de imprimir ao mesmo tempo
ofstream myfile;
auto start = chrono::system_clock::now();

// Função principal
int main() {
    vector<thread> filosofos; // Cria um vetor com threads para os filósofos
    myfile.open ("output.csv"); // Cria/Abre arquivo que receberá os dados de saída
    myfile << "Filosofo;Acao;Garfo1;Garfo2;Tempo[ms]\n"; // Preenche o cabeçalho do arquivo

    // Cria uma thread para cada filósofo
    for (int i = 0; i < N; i++) {
        filosofos.push_back(thread(pensar, i));
    }
    // Une as threads e aguarda até que cada uma seja finalizada
    for (int i = 0; i < N; i++) {
        filosofos[i].join();
    }
    // Fecha arquivo que recebeu os dados de saída
    myfile.close();

    return 0;
}

// Função para pensar
void pensar(int id) {
    while (chrono::system_clock::now() - start < chrono::milliseconds(1800*1000)) {
        //int tempo = (rand()*(id + 1)) % 4000 + 500; // Gera tempo diferente para cada thread
        int tempo = (rand()) % 4000 + 500; // Gera tempo igual para todas as threads
        coutMutex.lock();
        cout << "Filosofo " << id << " esta pensando." << endl;
        myfile << id << ";Pensando;;;" << tempo << "\n";
        coutMutex.unlock();
        this_thread::sleep_for(chrono::milliseconds(tempo));
        pegarGarfos(id);
        comer(id);
        soltarGarfos(id);
    }
}

// Função para comer
void comer(int id) {
    //int tempo = (rand()*(id + 1)) % 4000 + 500; // Gera tempo diferente para cada thread
    int tempo = (rand()) % 4000 + 500; // Gera tempo igual para todas as threads
    coutMutex.lock();
    cout << "Filosofo " << id << " esta comendo." << endl;
    myfile << id << ";Comendo;" << ESQUERDA << ";" << DIREITA << ";" << tempo << "\n";
    coutMutex.unlock();
    this_thread::sleep_for(chrono::milliseconds(tempo));
}

// Função para pegar os garfos
void pegarGarfos(int id) {
    coutMutex.lock();
    cout << "Filosofo " << id << " esta com fome." << endl;
    myfile << id << ";Com Fome;;;\n";
    coutMutex.unlock();
    // Bloqueia os garfos até que o filósofo termine de comer 
    garfos[ESQUERDA].lock(); 
    garfos[DIREITA].lock();
    coutMutex.lock();
    cout << "Filosofo " << id << " pegou os garfos " << ESQUERDA << " e " << DIREITA << "." << endl;
    myfile << id << ";Pegou Garfos;" << ESQUERDA << ";" << DIREITA << ";\n";
    coutMutex.unlock();
}

// Função para devolver os garfos
void soltarGarfos(int id) {
    // Desbloqueia os garfos 
    garfos[ESQUERDA].unlock();
    garfos[DIREITA].unlock();
    coutMutex.lock();
    cout << "Filosofo " << id << " devolveu os garfos " << ESQUERDA << " e " << DIREITA <<  "." << endl;
    myfile << id << ";Devolveu Garfos;" << ESQUERDA << ";" << DIREITA << ";\n";
    coutMutex.unlock();

}
