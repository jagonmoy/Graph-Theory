VL visited,topsort ;
vector < VL > graph ;
vector < VL > rgraph;
VL component ;
void setting(ll n ) {
    graph.clear() ;
    graph.resize(n+3);
    rgraph.clear();
    rgraph.resize(n+3);
    visited.clear();
    visited.resize(n+3,0);
    topsort.clear();
}
void dfs1(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
           if ( !visited[child]) dfs1(child); 
    }
    topsort.PB(node);
}
void dfs2(ll node) {
    visited[node] = 1 ;
    component.PB(node);
    for ( ll child : rgraph[node]) {
           if ( !visited[child]) dfs2(child); 
    }
}
void findingStronglyConnectedComponent(ll n) {
      INC(i,1,n) {
          if ( !visited[i]) {
              dfs1(i);
          }
      }
      reverse(topsort.begin(),topsort.end());
      visited.clear();
      visited.resize(n+3,0);
      INC(i,0,topsort.size()-1) {
          if ( !visited[topsort[i]]) {
              dfs2(topsort[i]);
              INC(j,0,component.size()-1) cout << component[j] << " " ;
              cout << endl;
              component.clear();
          }
      }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll vertex,edges ;
    cin >> vertex >> edges ;
    setting(vertex);   
    INC(i,1,edges) {
        ll node1,node2 ;
        cin >> node1 >> node2 ;
        graph[node1].PB(node2);
        rgraph[node2].PB(node1);
    }
    findingStronglyConnectedComponent(vertex);
    return 0 ;
}
