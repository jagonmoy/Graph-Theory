#include <bits/stdc++.h>
using namespace std;

#define sz 1000
#define WHITE 0
#define GREY 1
#define BLACK 2
#define inf 10000

int adj[sz][sz];
int distant[sz];
int colour[sz];

map < string,int> mymap ;
vector < string > vec ;

int bfs ( int start , int goal , int vertex);
int stringCompare(string mappedString , string  node);

int main(){
    int testcase;
    cin >> testcase ;
    while ( testcase--){
        int mapped = 0 ;
        memset(adj,0,sizeof(adj));
        while(1){
            string node;
            cin >> node ;
            if ( node[0] == '*') break ;
            if ( mymap.find(node) == mymap.end()){
                mymap[node] = mapped;
                mapped++ ;
            }
            vec.push_back(node);
            for ( int i = 0 ; i < vec.size() ; i++)
                if ( stringCompare(vec[i],node) == 1) {
                        adj[mymap[node]][mymap[vec[i]]] = 1;
                        adj[mymap[vec[i]]][mymap[node]] = 1;
          }
    }
    cin.ignore();
    char s[200] ;
    while ( gets(s) ) {
       if (s[0] == '\0') break;
       char source[200];
       char destination[200];
       sscanf(s,"%s %s",source,destination);
       int result = bfs(mymap[source],mymap[destination],mymap.size());
       cout << source << " " << destination << " " << result << endl;
    }
    mymap.clear();
    vec.clear();
    if (testcase) cout << endl ;
    }
    return 0;
}

int stringCompare(string mappedString, string node) {
    int omil = 0 ;
    if ( mappedString.size() != node.size()) return 0 ;
    else if ( mappedString.size() == node.size()){
        for ( int i = 0 ; i < mappedString.size() ; i++)
            if ( mappedString[i] != node[i]) omil = omil + 1;
        if ( omil > 1) return 0 ;
        else if ( omil == 1) return 1 ;
    }
}
int bfs( int start , int goal , int vertex) {
    for ( int i = 0 ; i < vertex ; i++) {
        if ( i != start) {
            colour[i] = WHITE ;
            distant[i] = inf ;
        }
    }
    colour[start] = GREY ;
    distant[start] = 0 ;
    queue < int > q ;
    q.push(start);
    while ( !q.empty()){
        int u = q.front();
        q.pop();
        for ( int i = 0 ; i < vertex ; i++){
            if ( adj[u][i] == 1) {
                int v = i ;
                if ( colour[v] == WHITE) {
                    colour[v] = GREY ;
                    distant[v] = distant[u]+1 ;
                    q.push(v);
                }
            }
        }
        colour[u] = BLACK ;
    }
    return distant[goal];
}
