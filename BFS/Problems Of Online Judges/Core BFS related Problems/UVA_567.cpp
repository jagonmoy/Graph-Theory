#include <bits/stdc++.h>
using namespace std ;
#define sz 30
#define minimum -1000
#define WHITE 0
#define GREY 1
#define BLACK 2

int adj[sz][sz];
int parent[sz];
int distant[sz];
int colour[sz];
int add = 0 ;

vector < int > vec ;

void bfs(int vertex , int snode) ;
void printpath(int snode , int enode);

int main() {
    int a,b,c,d,e,n ;
    while(scanf("%d",&a) != EOF )
{
    add++ ;

    memset(adj,0,sizeof(adj));

    for ( int j = 0 ; j < a ; j++) {
        scanf("%d",&b);
        adj[1][b] = 1 ;
        adj[b][1] = 1 ;
    }

    for ( int i = 2 ; i <= 19 ; i++) {
        scanf("%d",&a);
    for ( int j = 0 ; j < a ; j++) {
        scanf("%d",&b);
        adj[i][b] = 1 ;
        adj[b][i] = 1 ;
      }
    }
     scanf("%d",&c);

     printf("Test Set #%d\n",add);

    for ( int i = 0 ; i < c ; i++) {
        scanf("%d%d",&d,&e);

        if ( d <= e) {
            bfs(20,d);
            printpath(d,e);
            printf("%2d to %2d: %d\n",d,e,vec.size() -1);
        }
        else {
            bfs(20,e);
            printpath(e,d);
           printf("%2d to %2d: %d\n",d,e,vec.size() -1);
        }
        vec.clear();
    }
    printf("\n");
}

    return 0 ;
}
void bfs(int vertex , int snode) {
    for ( int i = 1 ; i <= vertex ; i++) {
        if  ( i != snode) {
            parent[i] = -1 ;
            colour[i] = WHITE ;
            distant[i] = minimum ;
        }
    }

    parent[snode] = -1 ;
    colour[snode] = GREY ;
    distant[snode] = 0 ;

    queue < int > q ;
    q.push(snode);
    while ( !q.empty()) {
        int u = q.front() ;
        q.pop() ;
        for ( int i = 1 ; i <= vertex ; i++ ) {
            if ( adj[u][i] != 0) {
                int v = i ;
                if ( colour[v] == WHITE) {
                    parent[v] = u ;
                    distant[v] = distant[u] + 1 ;
                    colour[v] = GREY ;
                    q.push(v);
                }
            }
        }
        colour[u] = BLACK ;
    }
}

void printpath(int snode , int enode) {
    if ( snode == enode) vec.push_back(snode);
    else if ( parent[enode] == -1) cout << "No Path exist" ;
    else {
        printpath(snode,parent[enode]);
        vec.push_back(enode); }
}
