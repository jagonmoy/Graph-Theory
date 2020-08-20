vector < VL >  graph ;
VL visited,topsort ;
ll kahini = 0 ;
void dfs(ll node) {
    if ( kahini == 2) visited[node] = 2 ;
    else visited[node] = 1 ;
    for ( ll child : graph[node]) {
        if (!visited[child]) dfs(child);
    } 
    if ( kahini == 2) topsort.PB(node);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll vertex,edges,source ;
    cin >> vertex >> edges >> source ;
    graph.resize(vertex+2);
    visited.resize(vertex+2,0);
    INC(i,0,edges-1) {
        ll node1,node2 ;
        cin >> node1 >> node2 ;
        graph[node1].PB(node2);
    }
    kahini = 1 ;
    dfs(source);
    ll f = 0 ;
    kahini++ ;
    INC(i,1,vertex) {
        if (!visited[i]) {
            dfs(i);
            f = 1 ;
        }
    }
    if (!f) cout <<  "0" << endl;
    else {
        kahini++ ;
        INC(i,1,vertex) if (visited[i] == 2) visited[i] = 0 ;
        reverse(topsort.begin(),topsort.end());
        ll cnt = 0 ;
        for ( ll node : topsort) {
            if (!visited[node]) {
                cnt++ ;
                dfs(node);
            }
        }       
        cout << cnt << endl;
    }
    return 0 ;
}
