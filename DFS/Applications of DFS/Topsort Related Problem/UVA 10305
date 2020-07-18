#include <bits/stdc++.h>
using namespace std ;

#define mx 1000
#define WHITE 0
#define GREY 1
#define BLACK 2
#define sz 1000

int adj[sz][sz];
int parent[sz];
int colour[sz];
int distant[sz];
stack <int> STACK ;

void dfs(int vertex) ;
void dfsvisit(int u , int vertex);

int main() {
    while(1) {
        int vertex,edge ;
        cin >> vertex >> edge ;
        if ( vertex == 0 && edge == 0) break ;
        int node1,node2 ;
        for ( int i = 0 ; i < edge ; i++) {
            cin >> node1 >> node2 ;

            adj[node1 - 1][node2 - 1] = 1 ;
        }

        dfs(vertex);

        while ( !STACK.empty()) {
            cout << STACK.top()+1 << " " ;
            STACK.pop();
        }
        cout << endl ;
    }
    return 0 ;
}
void dfs( int vertex ) {
    for ( int i = 0 ; i < vertex ; i++) colour[i] = WHITE ;
    for ( int i = 0 ; i < vertex ; i++ ) {
        if ( colour[i] == WHITE) dfsvisit(i,vertex);
    }
}
void dfsvisit( int u , int vertex ) {
    colour[u] = GREY ;

    for ( int i = 0 ; i < vertex ; i++) {
        if (adj[u][i] == 1) {
            int v = i ;
            if ( colour[v] == WHITE) {
                dfsvisit(v,vertex);
            }
        }
    }
   colour[u] = BLACK ;
   STACK.push(u);
}
