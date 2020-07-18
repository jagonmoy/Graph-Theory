This Problem is solved using In degree method not DFS .




#include <bits/stdc++.h>
using namespace std;
#define sz 1000

int vertex,edge;

int adj[sz][sz];
int in_degree[sz];
int visited[sz];
vector < string > sorted;
map < string,int> MAP;
map < int,string> MAP2;


void topsort();

int main() {
    int caseno = 0 ;
    //freopen("inputuva.txt","r",stdin);
    while(scanf("%d",&vertex) != EOF ) {
            memset(adj,0,sizeof(adj));
            memset(visited,0,sizeof(visited));
            memset(in_degree,0,sizeof(in_degree));
            int mapper = 0;
            for ( int i = 0 ; i < vertex ; i++) {
                string letter;
                cin >> letter;
                MAP[letter] = mapper;
                MAP2[mapper] = letter;
                mapper++;
           }

        cin >> edge;

        for ( int i = 0 ; i < edge ; i++) {
            string node1;
            string node2;
            cin >> node1 >> node2;
            int vertex1 = MAP[node1];
            int vertex2 = MAP[node2];
            adj[vertex1][vertex2] = 1;
        }

        topsort();

        cout << "Case #" << ++caseno << ": Dilbert should drink beverages in this order:";
        for ( int i = 0 ; i < sorted.size() ; i++ )
            cout << " " << sorted[i];

        cout << "." << endl;
        cout << endl;

        sorted.clear();
        MAP.clear();
        MAP2.clear();
    }

    return 0 ;
}

void topsort() {
        for ( int i = 0 ; i < vertex ; i++) {
            for ( int j = 0 ; j < vertex ; j++) {
                if ( adj[i][j] == 1) in_degree[j] = in_degree[j]+1;
            }
        }

    priority_queue<int, vector<int>, greater<int> > Q;
    for ( int i = 0 ; i < vertex ; i++) {
        if ( in_degree[i] == 0) {
            Q.push(i);
            visited[i] = 1 ;
        }
    }

    while (!Q.empty()) {
        int u = Q.top();
        Q.pop();
        sorted.push_back(MAP2[u]);
        for ( int j = 0 ; j < vertex ; j++) {
            if ( adj[u][j] == 1 && visited[j] == 0) {
                in_degree[j] = in_degree[j] - 1 ;
                if ( in_degree[j] == 0) {
                    visited[j] = 1 ;
                    Q.push(j);
                }
            }
        }
    }
