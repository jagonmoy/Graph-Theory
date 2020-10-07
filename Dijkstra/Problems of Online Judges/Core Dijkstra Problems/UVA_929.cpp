#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii ;
typedef pair<int,pii> tii;
#define sz 1000
#define inf 10000000
int distant[sz][sz];
int visited[sz][sz];
int adj[sz][sz];
void dijkstra(int row, int column);
int main() {
    int testcase;
    scanf("%d",&testcase);
    while(testcase--) {
        int row,column;
        scanf("%d %d",&row,&column);
        adj[row][column];
        for ( int i = 0 ; i < row ; i++) {
            for ( int j = 0 ; j < column ; j++) {
            scanf("%d",&adj[i][j]);
        }
    }
    dijkstra(row,column);
    printf("%d\n",distant[row-1][column-1]);
    }
    return 0 ;
}
 void dijkstra(int row, int column) {
     for ( int i = 0 ; i < row ; i++ ) {
        for ( int j = 0 ; j < column ; j++) {
                    visited[i][j] = false;
                    distant[i][j] = inf ;
                }
        }

     visited[0][0] = false ;
     distant[0][0] = adj[0][0] ;
     int fx[] = {1,-1,0,0};
     int fy[] = {0,0,1,-1};
     priority_queue < tii , vector <tii > , greater <tii> > Q ;
     Q.push(make_pair(distant[0][0],make_pair(0,0)));
     while( !Q.empty()) {
        tii t = Q.top();
        Q.pop();
        pii p = t.second;
        int x = p.first;
        int y = p.second;
        if ( visited[x][y] == false) {
        for ( int k = 0 ; k < 4 ; k++) {
            int tx = x + fx[k];
            int ty = y + fy[k];
            if ( tx >= 0 && tx < row && ty >= 0 && ty < column && (distant[x][y] + adj[tx][ty] < distant[tx][ty])) {
                distant[tx][ty] = distant[x][y] + adj[tx][ty];
                Q.push(make_pair(distant[tx][ty],make_pair(tx,ty)));
            }
        }
     }
     visited[x][y] = true ;
     }
 }
