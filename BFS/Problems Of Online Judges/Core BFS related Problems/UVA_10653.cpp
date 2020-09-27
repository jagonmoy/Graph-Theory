#include <bits/stdc++.h>
using namespace std;

#define pii pair <int,int>
#define sz 1005
#define WHITE 0
#define GREY 1
#define BLACK 2
#define inf 100

int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
int adj[sz][sz];
int distant[sz][sz];
int colour[sz][sz];

int bfs(int sourceRow,int sourceCol , int destinationRow , int destinationCol , int row , int col );

int main() {
    while(1){
        int row,col ;
        cin >> row >> col ;
        if ( row == 0 && col == 0) break ;
        memset(adj,0,sizeof(adj));
        int checkerRow;
        cin >> checkerRow;
        for ( int i = 0 ; i < checkerRow ; i++) {
            int posRow ;
            int numberOfblocks;
            cin >> posRow >> numberOfblocks ;
            for ( int i = 0 ; i < numberOfblocks ; i++) {
                int posBlock;
                cin >> posBlock ;
                adj[posRow][posBlock] = 1 ;
            }
        }
        int sourceRow,sourceCol,destinationRow,destinationCol;
        cin >> sourceRow >> sourceCol ;
        cin >> destinationRow >> destinationCol;
        int result = bfs(sourceRow,sourceCol,destinationRow,destinationCol,row,col);
        cout << result << endl ;
       }
     return 0 ;
}

int bfs(int sourceRow,int sourceCol,int destinationRow , int destinationCol,int row , int col) {
    for ( int i = 0 ; i < row ; i++) {
        for ( int j = 0 ; j < col ; j++){
            colour[i][j] = WHITE ;
            distant[i][j] = inf ;
        }
    }

    colour[sourceRow][sourceCol] = GREY ;
    distant[sourceRow][sourceCol] = 0 ;
    queue < pii > q ;
    q.push(pii(sourceRow,sourceCol));
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        for ( int i = 0 ; i < 4 ; i++){
            int tx = top.first+fx[i];
            int ty = top.second+fy[i];
            if ( tx >= 0 && tx < row && ty >= 0 && ty < col && adj[tx][ty] != 1 && colour[tx][ty] == WHITE) {
                colour[tx][ty] = GREY ;
                distant[tx][ty] = distant[top.first][top.second]+1;
                q.push(pii(tx,ty));
            }
        }
        colour[top.first][top.second] = BLACK ;
    }

  return distant[destinationRow][destinationCol];
}
