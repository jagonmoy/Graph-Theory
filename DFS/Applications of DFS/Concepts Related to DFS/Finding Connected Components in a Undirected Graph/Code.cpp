VL visited ;
vector < VL > graph ;
VL component ;
void setting(ll n ) {
    graph.clear() ;
    graph.resize(n+3);
    visited.clear();
    visited.resize(n+3,0);
}
void dfs(ll node) {
    visited[node] = 1 ;
    component.PB(node);
    for ( ll child : graph[node]) {
           if ( !visited[child]) dfs(child); 
    }
}
void findingConnectedComponent(ll n ){
    INC(i,1,n) {
        if ( !visited[i]) {
             dfs(i) ;
             INC(j,0,component.size()-1) cout << component[j] << " " ;
             cout << endl;
             component.clear() ;
        }
    }
}
int main() {
    ll vertex,edges ;
    cin >> vertex >> edges ;
    setting(vertex);
    INC(i,1,edges) {
        ll node1,node2 ;
        cin >> node1 >> node2 ;
        graph[node1].PB(node2) ;
        graph[node2].PB(node1) ;
    }
    findingConnectedComponent(vertex) ;
    return 0 ;
}
