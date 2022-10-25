// Dijkstra

#include<iostream>
#define INF 1000000
#define GRAPH_SIZE 7

using namespace std;

int custo[GRAPH_SIZE];
int anterior[GRAPH_SIZE];
bool fechado[GRAPH_SIZE];

int grafo[GRAPH_SIZE][GRAPH_SIZE] = {
    {0,       2,    INF,    1,   INF,    INF, INF},
    {INF,     0,    INF,    3,    10,    INF, INF},
    {4,     INF,      0,  INF,   INF,      5, INF},
    {INF,   INF,      2,    0,     3,      8,   4},
    {INF,   INF,    INF,  INF,     0,    INF,   6},
    {INF,   INF,    INF,  INF,   INF,      0, INF},
    {INF,   INF,    INF,  INF,   INF,      1,   0},
};

void dijkstra(int origem){
    int vcm = -1;

    for(int i = 0; i < GRAPH_SIZE; i++){
        custo[i] = INF;
        anterior[i] = -1;
        fechado[i] = false;
    }

    custo[origem] = 0;

    while(true){
        vcm = -1;
        for(int i = 0; i < GRAPH_SIZE; i++){
            if(!fechado[i] && (vcm == -1 || custo[i] < custo[vcm])){
                vcm = i;
            }
        }

        if (vcm < 0) break;
        fechado[vcm] = true;

        for(int i = 0; i < GRAPH_SIZE; i++){
            if((grafo[vcm][i] != 0) && (custo[i] > custo[vcm] + grafo[vcm][i])){
                custo[i] = custo[vcm] + grafo[vcm][i];
                anterior[i] = vcm;
            }
        }
    }
}

int main(){
    
    dijkstra(0);
    for(int i = 0; i < GRAPH_SIZE; i++){
        cout << "Custo de 0 a " << i << ": " << custo[i] << endl;
    }

    return 0;
}
