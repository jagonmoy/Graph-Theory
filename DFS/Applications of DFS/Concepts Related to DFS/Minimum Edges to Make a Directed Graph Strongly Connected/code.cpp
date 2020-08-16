VL visited,topsort ;
vector < VL > graph ;
vector < VL > rgraph;
VL component,indegree,outdegree ;
ll SCC ;
void setting(ll n ) {
    graph.clear() ;
    graph.resize(n+3);
    rgraph.clear();
    rgraph.resize(n+3);
    visited.clear();
    visited.resize(n+3,0);
    topsort.clear();
    component.clear();
    component.resize(n+3,0);
    indegree.clear();
    indegree.resize(n+3,0);
    outdegree.clear();
    outdegree.resize(n+3,0);
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
    component[node] = SCC ;
    for ( ll child : rgraph[node]) {
           if ( !visited[child]) dfs2(child); 
    }
}
void dfs3(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node] ) {
        if ( component[node] != component[child]) {
            outdegree[component[node]]++ ;
            indegree[component[child]]++  ;
        }
        if ( !visited[child]) dfs3(child);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    cin >> t ;
    while(t--) {
        ll vertex,edges ;
        cin >> vertex >> edges ;
        setting(vertex);   
        INC(i,1,edges) {
            ll node1,node2 ;
            cin >> node1 >> node2 ;
            graph[node1].PB(node2);
            rgraph[node2].PB(node1);
        }
        INC(i,1,vertex) {
            if ( !visited[i]) {
                dfs1(i);
            }
        }
        reverse(topsort.begin(),topsort.end());
        visited.clear();
        visited.resize(vertex+3,0);
        SCC = 0 ;
        INC(i,0,topsort.size()-1) {
            if ( !visited[topsort[i]]) {
                ++SCC ;
                dfs2(topsort[i]);
            }
        }
        visited.clear();
        visited.resize(vertex+3,0);
        INC(i,1,vertex) {
            if (!visited[i]) {
                dfs3(i);
            }
        }
        if ( SCC == 1) cout << "Case " << ++c << ": " << 0 << endl;
        else {
           ll insum  = 0 ;
           ll outsum = 0 ;
           INC(i,1,SCC) {
               if (!indegree[i]) insum++ ;
               if (!outdegree[i]) outsum++ ;
           }
           cout << "Case " << ++c << ": " << max(insum,outsum) << endl;
        }
    }
    return 0 ;
}
