#include <bits/stdc++.h>
using namespace std;
#define sz 10000
vector <int> adj[sz];
int dis[sz];
int visited[sz];
void BFS (int start ,int vertex) {
    for ( int i = 0 ; i < vertex ; i++) {
        if ( i != start) {
        dis[i] = 10000;
        visited[i] = 0 ;
        }
    }
    visited[start] = 1 ;
    dis[start] = 0 ;
    queue < int > q ;
    q.push(start);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for ( int i = 0 ; i < adj[u].size() ; i++) {
            if ( visited[adj[u][i]] == 0) {
                visited[adj[u][i]] = 1 ;
                dis[adj[u][i]] = dis[u]+1;
                q.push(adj[u][i]);
            }
        }
    }
    for ( int i = 1 ; i < vertex ; i++) {
        printf("%d\n",dis[i]);
    }
    return ;
}
int main() {
    int t ;
    bool isBlank = false;
    scanf("%d",&t);
    while(t--) {
        int vertex,edge;
        scanf("%d %d",&vertex,&edge);
        int node1,node2;
        for ( int i = 0 ; i < edge ; i++) {
            scanf("%d %d",&node1,&node2);
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        if(isBlank)printf("\n");
        BFS(0,vertex);
        isBlank = true;
        for ( int i = 0 ; i < sz ; i++ ) adj[i].clear();
        memset(dis,0,sizeof(dis));
        memset(visited,0,sizeof(dis));
    }
    return 0 ;
}
