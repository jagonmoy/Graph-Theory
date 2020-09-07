
/* I am too lazy to write another DFS function that's why I just used another variable named "fact" to serve two purpose in one DFS function . You can write seperate DFS funtion
for more simplicity */

vector < VL > graph ;
ll n,maximumdurotto,treediameter,furthestnode;
ll fact ;
void setting(ll n) {
    graph.clear();
    graph.resize(n+5);
    fact = 0 ;
    distancetob = -1;
    maximumdurotto1 = -1 ;
    treediameter = -1 ;
    furthestnode = -1 ;
}
void dfs(ll node, ll parent ,ll durotto) {
    if ( fact == 1) {
        if ( durotto > maximumdurotto) {
            maximumdurotto = durotto ;
            furthestnode = node ;
        }
    }
    else if ( fact == 2) treediameter = max(treediameter,durotto);

    for ( ll child : graph[node]) {
        if ( child == parent) continue;
        dfs(child,node,durotto+1);
    }
}
int main() {
    cin >> n ;
    setting(n);
    INC(i,1,n-1) {
        ll node1,node2 ;
        cin >> node1 >> node2;
        graph[node1].PB(node2);
        graph[node2].PB(node1);
     }
    fact++ ;
    dfs(a,-1,0);
    fact++ ;
    dfs(furthestnode,-1,0);
    return 0 ;
}
