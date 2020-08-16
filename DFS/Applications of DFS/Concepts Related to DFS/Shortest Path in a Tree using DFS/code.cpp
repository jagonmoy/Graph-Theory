vector < VL > graph ;
VL visited ;
VL dis;
void dfs( ll x , ll len) {
    visited[x] = 1 ;
    dis[x] = len ;
    if ( graph[x].size() > 0 ) {
        INC(i,0,graph[x].size()-1) {
            if ( !visited[graph[x][i]]) dfs(graph[x][i],len+1);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n ;
	  cin >> n ;
	  graph.resize(n+5);
    visited.resize(n+5,0);
	  dis.resize(n+5,0);
	  INC(i,0,n-2) {
		    ll node1,node2 ;
		    cin >> node1 >> node2 ;
		    graph[node1].PB(node2);
	  }
    dfs(1,0);
    return 0 ;
}
