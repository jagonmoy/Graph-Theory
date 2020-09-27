#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2
#define sz 1000
#define inf 10000


int adj[sz][sz];
int colour[sz];
int parent[sz];

void bfs(int source , int destination , int vertex);

int main() {
    //freopen("inputuva.txt","r",stdin);
    int vertex ;
    char garbage;
    string line;
    while ( scanf("%d",&vertex) != EOF){
            memset(adj,0,sizeof(adj));
     for ( int i = 0 ; i < vertex ; i++) {
        int node1;
        cin >> node1;
        getline(cin,line);
        stringstream ss(line);
        int node2;
        while(ss >> garbage >> node2) {
            adj[node1-1][node2-1] =  1;
        }
       }
     int query ;
     cin >> query;
     cout << "-----" << endl;
     for ( int i = 0 ; i < query ; i++) {
        int source ,destination ;
        cin >> source >> destination;
        bfs(source-1,destination-1,vertex);
     }
    }
    return 0 ;
}

void bfs(int source , int destination , int vertex) {
    for ( int i = 0 ; i < vertex ; i++) {
        if ( i != source) {
            colour[i] = WHITE ;
            parent[i] = -1 ;
        }
    }
    colour[source] = GREY ;
    parent[source] = source;
    queue < int > q ;
    q.push(source);
    while ( !q.empty()) {
        int u = q.front();
        q.pop();
        for ( int i = 0 ; i < vertex ; i++) {
            if (adj[u][i] == 1) {
                int v = i ;
                if ( colour[v] == WHITE) {
                    colour[v] = GREY ;
                    parent[v] = u ;
                    q.push(v);
                }
            }
        }
        colour[u] = BLACK ;
    }
    vector < int > vec;
    while ( destination != source) {
        vec.push_back(destination);
        destination = parent[destination];
        if (destination == -1 ) {
            cout << "connection impossible" << endl ;
            return ;
        }
    }
    vec.push_back(source);
    cout << vec[vec.size()-1]+1 ;
    for ( int i = vec.size()-2 ; i >= 0 ; i--)
        cout << ' ' << vec[i]+1 ;
    cout << endl;
    vec.clear();

}
