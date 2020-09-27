#include <bits/stdc++.h>
using namespace std;
#define sz 10000000
map < string,int > mymap;
map < int,string > mymap2;
map < string,int > mark;
vector <int> adj[sz];
int dis[sz];
int visited[sz];
int parent[sz];

int printpath(int start , int goal ,int index) {
    for ( int i = 0 ; i < index ; i++) {
        if ( i != start) {
        dis[i] = 10000;
        parent[i] = -1;
        visited[i] = 0 ;
        }
    }
    visited[start] = 1 ;
    dis[start] = 0 ;
    parent[start] = -1;
    queue < int > q ;
    q.push(start);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for ( int i = 0 ; i < adj[u].size() ; i++) {
            if ( visited[adj[u][i]] == 0) {
                visited[adj[u][i]] = 1 ;
                parent[adj[u][i]] = u ;
                dis[adj[u][i]] = dis[u]+1;
                q.push(adj[u][i]);
            }
        }
    }
    vector <int> path ;
    int crawl = goal;
    path.push_back(crawl);
    while (parent[crawl] != -1) {
        path.push_back(parent[crawl]);
        crawl = parent[crawl];
    }
    int fact = 0 ;
    for ( int i = 0 ; i < path.size() ; i++) {
        if ( path[i] == -1 ) fact = 1 ;
    }
    if ( path.size() <= 1) fact = 1 ;
    if ( fact == 1)  printf("No route\n");
    else {
        reverse(path.begin(),path.end());
        for ( int i = 0 ; i < path.size()-1 ; i++) {
            cout << mymap2[path[i]] << " " << mymap2[path[i+1]] << endl;
        }
    }
    return 0 ;
}

int main() {
    int caseno = 0 ;
    int n ;
    while(scanf("%d ",&n)!= EOF) {
        if ( caseno != 0) printf("\n");
        string a,b ;
        int index = 0 ;
        for ( int i = 0 ; i < n ; i++) {
            cin >> a >> b ;
            mark[a] = 1;
            mark[b] = 1;
            if ( mymap.find(a) == mymap.end()) {
                mymap[a] = index ;
                mymap2[index] = a;
                index++ ;
            }
            if ( mymap.find(b) == mymap.end()) {
                mymap[b] = index ;
                mymap2[index] = b ;
                index++ ;
            }
            adj[mymap[a]].push_back(mymap[b]);
            adj[mymap[b]].push_back(mymap[a]);
        }
        string source,destination;
        cin >> source >> destination;
        if ( caseno != 0) printf("\n");
        if ( mark[source] != 1 || mark[destination] != 1) printf("No route\n");
        else printpath(mymap[source],mymap[destination],index);
        caseno++;
        mymap.clear();
        mymap2.clear();
        mark.clear();
        for ( int i = 0 ; i < sz ; i++) adj[i].clear();
        memset(dis,0,sizeof(dis));
        memset(visited,0,sizeof(visited));
        memset(parent,0,sizeof(parent));
    }
    return 0 ;
}
