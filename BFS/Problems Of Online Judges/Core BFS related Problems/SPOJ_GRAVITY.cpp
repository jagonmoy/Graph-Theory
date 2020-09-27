clude <bits/stdc++.h>
using namespace std;
#define sz 105
#define inf 10000
typedef pair<int,int> PII ;
int fx[] ={1,-1,0,0,1,-1,-1,1};
int fy[] ={0,0,-1,1,1,1,-1,-1};
int arr[sz][sz];
int dis[sz][sz];
int visited[sz][sz];
int Sx,Sy,Tx,Ty,o,m,n;
void BFS() {
    for ( int i = 0 ; i < m ; i++) {
        for ( int j = 0 ; j < n ; j++) {
            dis[i][j] = inf ;
            visited[i][j] = 0 ;
        }
    }
    visited[Sx][Sy] = 1 ;
    dis[Sx][Sy] = 0 ;
    queue < PII > Q ;
    Q.push(make_pair(Sx,Sy));
    //cout << Sx << " " << Sy << endl;
    while(!Q.empty()) {
        PII u = Q.front();
        //cout << u.first << " " << u.second << endl;
        Q.pop();
        for ( int k = 0 ; k < 8 ; k++ ) {
            int Vx = u.first + fx[k];
            int Vy = u.second + fy[k];
            //cout << "Vx : " << Vx << " Vy : " << Vy << endl;
            if ( Vx >= 0 && Vx < m && Vy >= 0 && Vy < n &&  visited[Vx][Vy] == 0 && arr[Vx][Vy] != 2 ) {
               // cout << "Warning: " << arr[Vx][Vy] << endl;
                dis[Vx][Vy] = dis[u.first][u.second] + 1 ;
                visited[Vx][Vy] = 1 ;
               // cout << "Result " << Vx << " " << Vy << endl;
                Q.push(make_pair(Vx,Vy));
                }
            }
        }
    //cout << dis[Tx][Ty] << endl;
    if ( dis[Tx][Ty] <= o ) printf("Possible\n");
    else printf("Impossible\n");
    return ;
}
 
int main() {
    int t ;
    scanf("%d",&t);
    while(t--) {
        char a ;
        Sx = -1 , Sy = -1 , Tx = -1 , Ty = -1 ;
        scanf("%d %d %d",&o,&m,&n);
        getchar();
        for ( int i = 0 ; i < m ; i++) {
            for( int j = 0 ; j < n ; j++) {
                scanf("%c",&a);
                if (a == 'S') {
                    Sx = i ;
                    Sy = j ;
                    arr[i][j] = 1 ;
                }
                else if ( a == 'T') {
                    Tx = i ;
                    Ty = j ;
                    arr[i][j] = 1 ;
                }
                else if ( a == '#') arr[i][j] = 2 ;
                else arr[i][j] = 1 ;
            }
            getchar();
        }
        // cout << Sx << " " << Sy << " " << Tx << " " << Ty << endl;
         /*  for ( int i = 0 ; i < m ; i++) {
            for ( int j = 0 ; j < n ; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        } */
        if ( Sx == -1 || Sy == -1 || Tx == -1 || Ty == -1) printf("Impossible\n");
        else BFS();
        memset(arr,0,sizeof(arr));
        memset(dis,0,sizeof(dis));
        memset(visited,0,sizeof(visited));
    }
    return 0 ;
} 
