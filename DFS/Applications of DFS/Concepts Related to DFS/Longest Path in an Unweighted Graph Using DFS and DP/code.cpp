
vector < VL > graph ;
VL visited,dp ;
void dfs( ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
        if ( !visited[child]) dfs(child);
        dp[node] = max(dp[node],1+dp[child]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m ;
    cin >> n >> m ;
    graph.clear();
    graph.resize(n+2);
    visited.clear();
    visited.resize(n+2,0);
    while(m--) {
        ll node1,node2 ;
        cin >> node1 >> node2 ;
        graph[node1].PB(node2);
    }
    dp.clear();
    dp.resize(n+2,0);
    INC(i,1,n) {
        if ( !visited[i]) {
            dfs(i);
        }
    }
    ll maximum = neginf ;
    ll maximumindex = inf ; 
    INC(i,1,n) {
        if ( dp[i] > maximum) {
            maximum = dp[i];
            maximumindex = i ;
        }
        else if ( dp[i] == maximum && i < maximumindex) {
            maximum = dp[i];
            maximumindex = i ;
        }
    }
    cout << maximum << " " << maximumindex << endl;

    return 0 ;
}
