#include <bits/stdc++.h>
using namespace std;

#define sz 100000
#define inf 100000000
typedef pair<int,int> pii;

void dijkstra(int startingNode,int vertex);

vector <int> adj[sz];
vector <int> cost[sz];
int distant[sz];
int visited[sz];
int parent[sz];

int main() {
    int testcase;
    scanf("%d",&testcase);
    int caseno = 0 ;
    while(testcase--) {
        int n,m,s,t ;
        scanf("%d %d %d %d",&n,&m,&s,&t);
        for ( int i = 0 ; i < m ; i++) {
            int node1,node2,weight;
            scanf("%d %d %d",&node1,&node2,&weight);
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
            cost[node1].push_back(weight);
            cost[node2].push_back(weight);
        }
        dijkstra(s,n);
        if ( parent[t] == -1) printf("Case #%d: unreachable\n",++caseno);
        else printf("Case #%d: %d\n",++caseno,distant[t]);

        for ( int i = 0 ; i < sz ; i++) {
            adj[i].clear();
            cost[i].clear();
        }
    }
    return 0 ;
}


void dijkstra(int startingNode, int vertex) {
    for ( int i = 0 ; i < vertex ; i++) {
        if ( i != startingNode) {
            distant[i] = inf ;
            parent[i] = -1 ;
            visited[i] = false;
        }
    }
    distant[startingNode] = 0 ;
    parent[startingNode] = startingNode;
    visited[startingNode] = false;
    priority_queue < pii , vector <pii> , greater <pii > > Q ;
    Q.push(make_pair(distant[startingNode],startingNode));
    while(!Q.empty()) {
        pii p = Q.top();
        Q.pop();
        int v = p.second;
        if ( visited[v] == false) {
            for ( int i = 0 ; i < adj[v].size() ; i++) {
                int x = adj[v][i];
                if ( cost[v][i] + distant[v] < distant[x]) {
                    distant[x] = cost[v][i] + distant[v];
                    parent[x] = v ;
                    Q.push(make_pair(distant[x],x));
                }
            }
        }
        visited[v] = true;
    }
}
