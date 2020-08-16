vector < VL > graph ;
ll vertex ;
VL visited ;
ll f = 0 ;
bool valid(ll node) {
    for ( ll child : graph[node])
        if ( visited[child]) return false ;
    return true ;
}
void dfs(VL v) {
    if ( v.size() == vertex) {
        INC(i,0,v.size()-1) cout << v[i] << " " ;
        cout << endl;
        f = 1 ;
    }
    else {
        INC(i,1,vertex) {
            if ( !visited[i] && valid(i)) {
                visited[i] = 1 ;
                v.PB(i);
                dfs(v);
                v.erase(v.end()-1);
                visited[i] = 0 ;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll edges ;
    cin >> vertex >> edges ;
    graph.resize(vertex+3);
    visited.resize(vertex+3,0);
    INC(i,1,edges) {
        ll node1,node2 ;
        cin >> node1 >> node2 ;
        graph[node1+1].PB(node2+1);
    }
    
    VL v ;
    dfs(v);
 
    return 0 ;
}
