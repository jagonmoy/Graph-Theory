#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2
#define pii pair <int,int>
#define sz 1000
#define inf 10000

int fx[] = {1,-1,2,-2,2,1,-1,-2};
int fy[] = {2,2,1,1,-1,-2,-2,-1};
int adj[sz][sz];
int colour[sz][sz];
int distant[sz][sz];

int bfs(int sourceRow , int sourceCol , int destinationRow , int destinationCol);
int main() {
    char node1[3],node2[3];
    while ( scanf("%s %s",&node1,&node2) != EOF) {
    int mapperCol = 0 ;
    int mapperRow = 0 ;
    map < char,int> col;
    map < char,int> row;
    for ( char i = 'a' ; i <= 'h' ; i++){
       col[i] = mapperCol ;
       mapperCol++ ;
    }
    for ( int i = '1' ; i <= '8' ; i++) {
        row[i] = mapperRow;
        mapperRow++;
    }
    for ( int i = 0 ; i < 8 ; i++)
        for ( int j = 0 ; j < 8 ; j++)
            adj[i][j] = 1 ;

    int sourceCol = col[node1[0]];
    int destinationCol = col[node2[0]];
    int sourceRow = row[node1[1]];
    int destinationRow = row[node2[1]];
    int result = bfs(sourceRow,sourceCol,destinationRow,destinationCol);
    cout << "To get from " << node1 << " to " << node2 <<" takes " << result << " knight moves." << endl;
    }
return 0 ;
}
int bfs(int sourceRow , int sourceCol , int destinationRow , int destinationCol) {
    for ( int i = 0 ; i < 8 ; i++) {
        for ( int j = 0 ; j < 8 ; j++) {
            colour[i][j] = WHITE ;
            distant[i][j] = inf ;
        }
    }
    colour[sourceRow][sourceCol] = GREY ;
    distant[sourceRow][sourceCol] = 0 ;
    queue < pii > q ;
    q.push(pii(sourceRow,sourceCol));
    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        for ( int i = 0 ; i < 8 ; i++) {
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];
            if ( tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && adj[tx][ty] == 1 && colour[tx][ty] == WHITE){
                colour[tx][ty] = GREY ;
                distant[tx][ty] = distant[top.first][top.second]+1;
                q.push(pii(tx,ty));
            }
        }
        colour[top.first][top.second] = BLACK;
    }

    return distant[destinationRow][destinationCol];

}
