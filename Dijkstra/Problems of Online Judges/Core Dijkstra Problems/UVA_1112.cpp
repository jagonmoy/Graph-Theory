#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii ;
#define inf 1000000
#define sz 900
bool visited[sz];
int distant[sz];
vector <int> adj[sz];
vector <int> cost[sz];
int dijkstra( int startingNode, int vertex ,int goal);
int main() {
    int testcase;
    scanf("%d",&testcase);
    while(testcase--) {
    int vertex,goal,time,edges;
    scanf("%d %d %d %d",&vertex,&goal,&time,&edges);
    for ( int i = 0 ; i < edges ; i++) {
        int node1,node2,weight;
        scanf("%d %d %d",&node1,&node2,&weight);
        adj[node1].push_back(node2);
        cost[node1].push_back(weight);
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= vertex ; i++) {
       int result = dijkstra(i,vertex,goal);
       if ( result <= time) cnt++;
    }
    printf("%d\n",cnt);
    if (testcase) printf("\n");
    for ( int i = 0 ; i < sz ; i++) adj[i].clear();
    for ( int i = 0 ; i < sz ; i++) cost[i].clear();
    }

    return 0 ;
}
int dijkstra(int startingNode, int vertex , int goal ) {
    for ( int i = 1 ; i <= vertex ; i++ ) {
        if ( i != startingNode) {
            visited[i] = false ;
            distant[i] = inf ;
        }
    }
    visited[startingNode] = false ;
    distant[startingNode] = 0 ;
    priority_queue < pii , vector <pii> , greater < pii > > Q ;
    Q.push(make_pair(0,startingNode));
    while(!Q.empty()) {
        pii p = Q.top() ;
        Q.pop();
        int x = p.second;
        if ( visited[x] == false) {
            for ( int i = 0 ; i < adj[x].size() ; i++) {
                int p = adj[x][i];
                if ( distant[x] + cost[x][i] < distant[p]) {
                        distant[p] = distant[x]+cost[x][i];
                        Q.push(make_pair(distant[p],p));
                    }
                }
            }
        visited[x] = true ;
    }

    return distant[goal] ;
}
