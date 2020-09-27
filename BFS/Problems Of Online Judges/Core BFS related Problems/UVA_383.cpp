#include <bits/stdc++.h>
using namespace std;
#define INFINITY 10000
#define sz 1000
int adj[sz][sz];
int main() {
    int vertex,edge,query;
    int testcase;
    map < string,int> mymap;
    int caseno = 0 ;
    cin >> testcase;
    while ( testcase--) {
        caseno++;
        cin >> vertex >> edge >> query;
        for ( int i = 0 ; i < vertex ; i++) {
            string letter;
            cin >> letter;
            mymap[letter] = i;
        }
        for(int i=0;i<vertex;i++) fill(adj[i],adj[i]+vertex,INFINITY);

        for(int i=0;i<vertex;i++) adj[i][i]=0;

        for ( int i = 0 ; i < edge ; i++ ) {
            string vertex1,vertex2;
            cin >> vertex1 >> vertex2;
            int node1 = mymap[vertex1];
            int node2 = mymap[vertex2];
            adj[node1][node2] = 1 ;
            adj[node2][node1] = 1 ;
        }

    for ( int k = 0 ; k < vertex ; k++) {
        for ( int i = 0 ; i < vertex ; i++) {
            for ( int j = 0 ; j < vertex ; j++) {
                if ( adj[i][k] + adj[k][j] < adj[i][j] ) adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
    if ( caseno == 1) {
            cout << "SHIPPING ROUTES OUTPUT" << endl;
            cout << endl;
    }
    cout << "DATA SET  " << caseno << endl;
    cout << endl;
    for ( int i = 0 ; i < query ; i++) {
        int baal;
        string source,destination;
        cin >> baal >> source >> destination;
        int start = mymap[source];
        int goal = mymap[destination];
        if ( adj[start][goal] == INFINITY) cout << "NO SHIPMENT POSSIBLE" << endl;
        else cout << "$" << baal*100*adj[start][goal] << endl;
     }
     cout << endl;
     mymap.clear();
    }
    cout << "END OF OUTPUT" << endl;

    return 0 ;
}
