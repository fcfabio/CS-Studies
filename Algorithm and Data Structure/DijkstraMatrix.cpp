// Dijkstra

#include<iostream>
#define INF 1000000
#define GRAPH_SIZE 7

using namespace std;

int cost[GRAPH_SIZE];
int previous[GRAPH_SIZE];
bool closed[GRAPH_SIZE];

int graph[GRAPH_SIZE][GRAPH_SIZE] = {
{0, 2, INF, 1, INF, INF, INF},
{INF, 0, INF, 3, 10, INF, INF},
{4, INF, 0, INF, INF, 5, INF},
{INF, INF, 2, 0, 3, 8, 4},
{INF, INF, INF, INF, 0, INF, 6},
{INF, INF, INF, INF, INF, 0, INF},
{INF, INF, INF, INF, INF, 1, 0},
};

void dijkstra(int source){
    int vcm = -1;
    for(int i = 0; i < GRAPH_SIZE; i++){
        cost[i] = INF;
        previous[i] = -1;
        closed[i] = false;
    }

    cost[source] = 0;

    while(true){
        vcm = -1;
        for(int i = 0; i < GRAPH_SIZE; i++){
            if(!closed[i] && (vcm == -1 || cost[i] < cost[vcm])){
                vcm = i;
            }
        }

        if (vcm < 0) break;
        closed[vcm] = true;

        for(int i = 0; i < GRAPH_SIZE; i++){
            if((graph[vcm][i] != 0) && (cost[i] > cost[vcm] + graph[vcm][i])){
                cost[i] = cost[vcm] + graph[vcm][i];
                previous[i] = vcm;
            }
        }
    }
}

int main(){
    
    dijkstra(0);
    for(int i = 0; i < GRAPH_SIZE; i++){
        cout << "Cost from 0 to " << i << ": " << cost[i] << endl;
    }

    return 0;
}
