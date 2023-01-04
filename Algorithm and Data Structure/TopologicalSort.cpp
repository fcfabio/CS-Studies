// Ordenação topológica

// Topological ordering of a graph that defines the best order
// to wear clothes.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define VERT 9

class dict{
    public:
        int key;
        string value;
        dict(int k, string v){
            key = k;
            value = v;
        }
};

vector<int> adj[VERT]; // adjacency list
vector<bool> visited(VERT, false);
vector<int> order; // output order

// Function to go through the graph
void dfs(int u){
    if(visited[u]) return;
    visited[u] = true;

    for(int i = 0; i< adj[u].size(); i++){
        dfs(adj[u][i]);
    }
    order.push_back(u);
}

// Function to call recursive dfs and go through all the vertices 
// of the graph
void dfs_explore(){
    for(int i=0; i<VERT; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}


int main(){
    // Initialize dictionary
    vector<dict> dicionario;
    dicionario.push_back(dict(0, "undershorts"));
    dicionario.push_back(dict(1, "pants"));
    dicionario.push_back(dict(2, "belt"));
    dicionario.push_back(dict(3, "shoes"));
    dicionario.push_back(dict(4, "socks"));
    dicionario.push_back(dict(5, "shirt"));
    dicionario.push_back(dict(6, "tie"));
    dicionario.push_back(dict(7, "jacket"));
    dicionario.push_back(dict(8, "watch"));


    // Initialize adjacency list
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(3);
    adj[1].push_back(2);
    adj[2].push_back(7);
    adj[4].push_back(3);
    adj[5].push_back(2);
    adj[5].push_back(6);
    adj[6].push_back(7);

    // DFS
    dfs_explore();

    // Print results
    for(int i=order.size()-1; i>=0; i--){
        cout << dicionario[order[i]].value << endl;
    }
}
