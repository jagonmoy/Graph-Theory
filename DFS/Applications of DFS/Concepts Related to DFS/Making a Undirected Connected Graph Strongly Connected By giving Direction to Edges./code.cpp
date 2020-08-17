ll vertex,NumberOfedges ;
vector < PLL > graph[1005] ;
VL edges_visited , vertex_visited,low,in,edge_direction,parent;
VLL edges ;
ll t = 0 ;
void setting(ll n , ll m) {
    INC(i,0,1004) graph[i].clear();
    edges_visited.clear();
    edges_visited.resize(m+5);
    vertex_visited.clear();
    vertex_visited.resize(n+5);
    low.clear();
    low.resize(n+5);
    in.clear();
    in.resize(n+5);
    edges.clear();
    edges.resize(m+5);
    edge_direction.clear();
    edge_direction.resize(m+5);
    parent.clear();
    parent.resize(n+5);
}
void dfs(ll node) {
     vertex_visited[node] = 1;
     low[node] = in[node] = ++t ;
     for ( PLL child : graph[node]) {
         if ( edges_visited[child.S]) continue ; // Checking If the edges is used before .
         edges_visited[child.S] = 1 ;
         if ( edges[child.S].F == node ) edge_direction[child.S] = 1 ; // giving direction from node to child
         else edge_direction[child.S] = -1 ; // giving direction from child to node
         if (!vertex_visited[child.F]) {
             parent[child.F] = node ;
             dfs(child.F);
             low[node] = min(low[node],low[child.F]);
             if ( low[child.F] > in[node]) {
                 edge_direction[child.S] = 2 ;                         // making The edge Bidirectional
             }
         }
        else if ( parent[node] != child.F) {
               low[node] = min(low[node],in[child.F]);
        }
     }

}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> vertex >> NumberOfedges ;
    setting(vertex,NumberOfedges);
    INC(i,1,NumberOfedges) {
        ll node1,node2 ;
        cin >> node1 >> node2 ;
        graph[node1].PB({node2,i});
        graph[node2].PB({node1,i});   
        edges[i] = {node1,node2};
    } 
    dfs(1) ;
    cout << "Direction Of edges from 1 to NumberOfedges : " << endl;
    INC(i,1,NumberOfedges) {
        if ( edge_direction[i] == 1) cout << edges[i].F << " --> " << edges[i].S << endl;
        else if ( edge_direction[i] == -1) cout << edges[i].F << " <-- " << edges[i].S << endl;
        else cout << edges[i].F << " <--> " << edges[i].S << endl;                                 //bidirectional Edge        
    }

    return 0 ;
}
