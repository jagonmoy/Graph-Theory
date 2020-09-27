#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2
#define sz 1000

int adj[sz][sz];
int colour[sz];

bool bfs(int vertex , int source);

int main() {
    while(1) {
        int vertex,edge ;
        cin >> vertex ;
        if ( vertex == 0) break ;
        memset(adj,0,sizeof(adj));
        cin >> edge ;
        int node1,node2;
        for ( int i = 0 ; i < edge ; i++) {
            cin >> node1 >> node2;
            adj[node1][node2] = 1 ;
            adj[node2][node1] = 1 ;
        }
        if ( bfs(vertex,0)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");

    }
    return 0 ;
}
bool bfs(int vertex, int source) {
    for ( int i = 0 ; i < vertex ; i++ ) if ( i != source) colour[i] = WHITE ;
    colour[source] = RED ;
    queue < int  > Q ;
    Q.push(source);
    while ( !Q.empty()){
        int u = Q.front();
        Q.pop();
        for ( int i = 0 ; i < vertex ; i++) {
            if ( adj[u][i] == 1) {
                int v = i ;
                if ( colour[v] == WHITE) {
                    if ( colour[u] == RED) colour[v] = BLUE ;
                    else colour[v] = RED;
                    Q.push(v);
                }
                if ( colour[u] == colour[v]) return false ;
            }
        }
    }
    return true ;
    }
