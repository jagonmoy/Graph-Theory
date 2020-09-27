#include <bits/stdc++.h>
using namespace std;
#define sz 3000
#define inf 100000
vector <int> adj[sz];
int dis[sz];
int visited[sz];
void bfs(int s , int vertex) {
    queue<int> Q ;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for ( int i = 0 ; i < adj[u].size() ; i++) {
            if ( visited[adj[u][i]] == 0) {
                dis[adj[u][i]] = dis[u]+1 ;
                visited[adj[u][i]] = 1 ;
                Q.push(adj[u][i]);
            }
        }
    }
    vector < int > r ;
    for ( int i = 0 ; i < vertex ; i++) r.push_back(dis[i]);
    sort(r.begin(),r.end());

    //for ( int i = 0 ; i < r.size() ; i++) cout << r[i] << " " ;
    //cout << endl;
    int boomsize = -5 ;
    int boomday = -5 ;
    int cnt = 1 ;
    for ( int i = 1 ; i < vertex-1 ; i++) {
        if ( r[i] != inf ) {
            if ( r[i] == r[i+1]) cnt++ ;
            if ( r[i] != r[i+1]) {
                if ( cnt > boomsize) {
                    boomsize = cnt ;
                    boomday = r[i];
                }
                cnt = 1 ;
            }
        }
    }
    if ( boomsize == - 5 && boomday == -5) printf("0\n");
    else {
    if ( cnt > boomsize) {
        boomsize = cnt ;
        boomday = r[vertex-1];
    }
    printf("%d %d\n",boomsize,boomday);
    }
    return ;

}

int main() {
    int n ;
    scanf("%d",&n);
    int connections;
    for ( int i = 0 ; i < n ; i++) {
        scanf("%d",&connections);
        int c ;
        while(connections--) {
            scanf("%d",&c);
            adj[i].push_back(c);
        }
    }
    int q ;
    scanf("%d",&q);
    int x ;
    while(q--) {
        scanf("%d",&x);
        for ( int i = 0 ; i < n; i++) {
        dis[i] = inf ;
        visited[i] = 0 ;
        }
        dis[x] = 0 ;
        visited[x] = 1 ;
        bfs(x,n);
    }

    return 0 ;
}
