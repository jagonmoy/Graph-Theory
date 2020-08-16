vector < VL > graph ;
VL visited ,parent,in,low ;
VL ccvalue ;
ll root ;
ll rootchild ;
ll t  ;
void dfs(ll node) {
    visited[node] = 1 ;
    low[node] = in[node] = ++t ;
    for ( ll child : graph[node]) {
        if ( !visited[child]) {
            parent[child] = node ;
            if ( node == root) rootchild++ ;
            dfs(child);
            low[node] = min(low[node],low[child]);
            if ( low[child] >= in[node] && node != root) {
                ccvalue[node]++ ;
            }
        }
        else if ( parent[node] != child) {
               low[node] = min(low[node],in[child]);
        }
    }
}
int main() {
 ccvalue.resize(n+2,1);
 INC(i,0,n-1) {
            if (!visited[i]) {
                t = 0 ;
                root = i ;
                rootchild = 0 ;
                dfs(i) ;
                if ( rootchild > 1) ccvalue[i]++ ;
            }
        }
}
