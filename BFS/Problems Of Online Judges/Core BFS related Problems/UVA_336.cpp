#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2
#define sz 50
#define inf 10000

long long adj[sz][sz];
long long  colour[sz];
long long  distant[sz];

long long  caseno = 0 ;

int bfs(long long  vertex , long long source , long long TTL);

int main() {

    while(1) {

    map < long long,long long > mymap ;
    long long  edge ;
    cin >> edge ;
    if ( edge == 0) break ;
    memset(adj,0,sizeof(adj));
    long long mappedvalue = 0;
    long long  node1,node2;
    for ( long long i = 0 ; i < edge ; i++) {
        cin >> node1 >> node2 ;
        if (mymap.find(node1) == mymap.end()) {
            mymap[node1] = mappedvalue;
            mappedvalue++;
        }
        node1 = mymap[node1];
        if (mymap.find(node2) == mymap.end()) {
            mymap[node2] = mappedvalue;
            mappedvalue++;
        }
        node2 = mymap[node2];
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;
    }
    while (1) {
        long long source,TTL;
        cin >> source >> TTL;
        if ( source == 0 && TTL == 0) break ;
        long long snode = mymap[source];
        long long result = bfs(mymap.size(),snode,TTL);
        cout << "Case " << ++caseno << ": " << result << " nodes not reachable from node " << source << " with TTL = " << TTL << "." << endl;
     }
    }

    return 0 ;
}

int bfs( long long vertex , long long snode , long long TTL) {
    long long result = 0 ;
    for ( long long i = 0 ; i < vertex ; i++ ) {
        if ( i != snode) {
            colour[i] = WHITE ;
            distant[i] = inf;
        }
    }
    colour[snode] = GREY ;
    distant[snode] = 0 ;
    queue < long long  > Q ;
    Q.push(snode);
    while ( !Q.empty()) {
        long long u = Q.front();
        Q.pop();
        for ( long long i = 0 ; i < vertex ; i++) {
            if ( adj[u][i] == 1) {
                long long v = i ;
                if ( colour[v] == WHITE) {
                    colour[v] = GREY ;
                    distant[v] = distant[u]+1;
                    Q.push(v);
                }
            }
        }
        colour[u] = BLACK ;
    }

    for ( long long i = 0 ; i < vertex ; i++)
        if (distant[i] > TTL) result = result+1 ;

    return result ;
}
