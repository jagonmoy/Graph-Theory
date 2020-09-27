vector < VL > graph ;
VL dis,parent ;
void setting(ll vertex) {
    graph.clear();
    graph.resize(vertex+5);
    parent.resize(vertex+5,-1);
    dis.resize(vertex+5,-1);   
}
void bfs(ll source) {
    dis[source] = 0 ;
    queue < ll > q ;
    q.push(source);
    while(!q.empty()) {
        ll node = q.front();
        q.pop();
        for( ll child : graph[node]) {
            if ( dis[child] == -1) {
                dis[child] = dis[node] + 1 ;
                parent[child] = node ;
                q.push(child);
            }
        }
    }
}
VL printpath(ll souce , ll dest) {
    VL path ;
    if ( dis[dest] == -1) return path ;
    else {
        ll node = dest ;
        while(1) {
            path.PB(node);
            node = parent[node];
            if (node == -1) break;
        }
        reverse(path.begin(),path.end());
        return path ;
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
        graph[node2].PB(node1);
    }
    ll source,dest ;
    cin >> source >> dest;
    bfs(source);
    VL path = printpath(source,dest);
    if (path.size()) {
        for ( ll i : path) cout << i << " " ;
        cout << endl;
    }
    else cout << "No path Exist" << endl;

    return 0 ;
}
