#include <bits/stdc++.h>
using namespace std;
#define sz 300
typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > TII ;
int fx[] = {1,-1,0,0} ;
int fy[] = {0,0,1,-1} ;
int dis[sz][sz];
int visited[sz][sz];
int adj[sz][sz];
vector < TII > vec ;
bool check (int Vx, int Vy) {
    int fact = 0 ;
    for ( int i = 0 ; i < vec.size() ; i++) {
        int p = vec[i].first - Vx ;
        int q = vec[i].second.first - Vy ;
        int l = p*p + q*q;
        double x = sqrt(l);
        //cout << "Distance : " << x << endl;
        if ( x <= vec[i].second.second) fact = 1 ;
    }
    //cout << "fact is " << fact << endl;
    if ( fact == 0) return true ;
    else return false ;
}
void BFS(int m,int n) {
    for ( int i = 0 ; i < m ; i++) {
        for ( int j = 0 ; j < n ; j++) {
            dis[i][j] = -1 ;
            visited[i][j] = 0 ;
        }
    }
    visited[0][0] = 1 ;
    dis[0][0] = 0 ;
    queue <PII> Q ;
    Q.push(make_pair(0,0));
    while(!Q.empty()) {
        PII u = Q.front();
        //cout << u.first << " " << u.second << endl;
        //cout << Q.size() << endl;
        Q.pop();
        for ( int i = 0 ; i < 4 ; i++) {
            int Vx = u.first + fx[i];
            int Vy = u.second + fy[i];
            if ( Vx >= 0 && Vx < m && Vy >= 0 && Vy < n && adj[Vx][Vy] != 2 && visited[Vx][Vy] == 0 ) {
                if (check(Vx,Vy)) {
                    //cout << "Vx " << Vx << " Vy " << Vy << endl;
                    visited[Vx][Vy] = 1 ;
                    dis[Vx][Vy] = dis[u.first][u.second]+1;
                    Q.push(make_pair(Vx,Vy));
                }
            }
        }
    }

    if ( dis[m-1][n-1] == -1 ) printf("Impossible.\n");
    else printf("%d\n",dis[m-1][n-1]);
    return ;
}

int main() {
    int m,n ;
    while(1) {
        scanf("%d %d",&m,&n);
        if ( m == 0 && n == 0) break ;
        int b ;
        for ( int i = 0 ; i < m ; i++) {
            for ( int j = 0 ; j < n ; j++) {
                adj[i][j] = 1 ;
            }
        }
        scanf("%d",&b);
        int node1,node2;
        for ( int i = 0 ; i < b ; i++) {
            scanf("%d %d",&node1,&node2);
            adj[node1-1][node2-1] = 2 ;
        }
       /*  for ( int i = 0 ; i < m ; i++) {
            for ( int j = 0 ; j < n ; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        } */

        int c ;
        scanf("%d",&c);
        int d,e,l ;
        for ( int i = 0 ; i < c ; i++) {
                scanf("%d %d %d",&d,&e,&l);
                vec.push_back(make_pair(d-1,make_pair(e-1,l)));
        }

        //for ( int k = 0 ; k < vec.size() ; k++) cout << vec[k].first << " " << vec[k].second.first << " " << vec[k].second.second << endl;

        BFS(m,n);
        memset(dis,0,sizeof(dis));
        memset(visited,0,sizeof(visited));
        memset(adj,0,sizeof(adj));
        vec.clear();
    }
    return 0 ;
}
