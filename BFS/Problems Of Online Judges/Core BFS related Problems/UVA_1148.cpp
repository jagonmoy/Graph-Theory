#include <bits/stdc++.h>
using namespace std;
#define sz 100005
#define inf 10000
int visited[sz];
int dis[sz];
vector <int> adj[sz];
int BFS( int source ,int destination, int vertex) {
    for ( int i = 0 ; i < vertex ; i++ ) {
        visited[i] = 0 ;
        dis[i] = inf ;
    }
    visited[source] = 1 ;
    dis[source] = 0 ;
    queue < int > q ;
    q.push(source);
    while( !q.empty()) {
        int u = q.front();
        q.pop();
        for ( int i = 0 ; i < adj[u].size() ; i++) {
            if ( visited[adj[u][i]] == 0) {
                visited[adj[u][i]] = 1;
                dis[adj[u][i]] = dis[u]+1;
                q.push(adj[u][i]);
            }
        }
    }

    return dis[destination];
}

int main() {
    int t ;
    scanf("%d",&t);
    while(t--) {
        int vertex;
        scanf("%d",&vertex);
        for ( int i = 0 ; i < vertex ; i++) {
            int u,x,v ;
            scanf("%d %d",&u,&x);
            for ( int j = 0 ; j < x ; j++) {
                scanf("%d",&v);
                adj[u].push_back(v);
            }
        }
        int source,destination;
        scanf("%d %d",&source,&destination);
        int result = BFS(source,destination,vertex)-1;
        printf("%d %d %d\n",source,destination,result);
        memset(visited,0,sizeof(visited));
        memset(dis,0,sizeof(dis));
        for ( int i = 0 ; i < sz ; i++) adj[i].clear();
        if (t) printf("\n");
    }
    return 0 ;
}
