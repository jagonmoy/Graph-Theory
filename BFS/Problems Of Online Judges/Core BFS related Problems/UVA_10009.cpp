#include <bits/stdc++.h>
using namespace std;
#define sz 100000
map < char,int > mymap;
map < int,char > mymap2;
vector <int> adj[sz];
int dis[sz];
int visited[sz];
int parent[sz];
int printpath(int start , int goal,int index) {
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
    string path ;
    int crawl = goal;
    path.push_back(mymap2[crawl]);
    while (parent[crawl] != -1) {
        path.push_back(mymap2[parent[crawl]]);
        crawl = parent[crawl];
    }
    reverse(path.begin(),path.end());

    cout << path << endl;

    return 0 ;
}
int main() {
    int t ;
    scanf("%d",&t);
    while(t--) {
        int n,q;
        scanf("%d %d",&n,&q);
        string a,b;
        int index = 0 ;
        for ( int i = 0 ; i < n ; i++) {
            cin >> a >> b ;
            if (mymap.find(a[0]) == mymap.end()) {
                mymap[a[0]] = index;
                mymap2[index] = a[0];
                index++ ;
            }
            if ( mymap.find(b[0]) == mymap.end()) {
                mymap[b[0]] = index;
                mymap2[index] = b[0];
                index++;
            }
            adj[mymap[a[0]]].push_back(mymap[b[0]]);
            adj[mymap[b[0]]].push_back(mymap[a[0]]);
        }
        for ( int i = 0 ; i < q ; i++) {
            cin >> a >> b ;
            printpath(mymap[a[0]],mymap[b[0]],index);
        }
        mymap.clear();
        mymap2.clear();
        for ( int i = 0 ; i < sz ; i++) adj[i].clear();
        memset(dis,0,sizeof(dis));
        memset(visited,0,sizeof(visited));
        memset(parent,0,sizeof(parent));
        	if(t != 0) printf("\n");
    }
    return 0 ;
}
