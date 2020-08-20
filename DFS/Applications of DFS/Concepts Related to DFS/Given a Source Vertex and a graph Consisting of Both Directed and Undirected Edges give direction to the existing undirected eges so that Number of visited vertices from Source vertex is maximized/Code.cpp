vector < vector <PLL> > graph ;
map < ll,char > bidirectional;
VL visited ;
VLL edgesno;
void dfs(ll node) {
    visited[node] = 1 ;
    for ( PLL child : graph[node]) {
         if ( child.S != -1 && bidirectional[child.S] == '=' ) {
             if ( edgesno[child.S].F == node) bidirectional[child.S] = '+' ;
             else bidirectional[child.S] = '-' ;
             if ( !visited[child.F]) dfs(child.F);
         }
         else if ( child.S == -1 && !visited[child.F]) {
            dfs(child.F);
         }
    }    
}

 int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll vertex,edges,source ;
    cin >> vertex >> edges >> source ;
    graph.resize(vertex+2);
    visited.resize(vertex+2,0);
    edgesno.resize(edges+2,{0,0});
    ll x = 0 ;
    INC(i,1,edges) {
        ll type,node1,node2 ;
        cin >> type >> node1 >> node2 ;
        if (type == 1) graph[node1].PB({node2,-1});
        else {
            graph[node1].PB({node2,++x});
            graph[node2].PB({node1,x});
            bidirectional[x] = '=' ;
            edgesno[x] = {node1,node2};
        }
    }
    dfs(source);
    INC(i,1,x) if ( bidirectional[i] == '=') bidirectional[i] = '+' ;
  
    ll cnt = 0 ;
    INC(i,1,edges) if ( visited[i]) cnt++ ;
    cout << cnt << endl; 
    INC(i,1,x) cout << bidirectional[i] ;
    cout << endl;
    return 0 ;
}
