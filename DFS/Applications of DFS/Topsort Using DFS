#define sz 1000000
#define WHITE 0
#define GREY 1
#define BLACK 2

VL graph[sz];
ll parent[sz];
ll state[sz];
ll discovery_time[sz];
ll finshing_time[sz];
ll timecount = 0 ;
VL topsort ;
SKL stk ;

void dfsvisit(ll u , ll vertex) {
   state[u] = GREY ;
   discovery_time[u] = ++timecount ;
   INC(i,0,graph[u].size()-1) {
       ll v = graph[u][i];
       if ( state[v] == WHITE) {
           parent[v] = u ;
           dfsvisit(v,vertex);
       }
   }
   finshing_time[u] = ++timecount;
   stk.P(u);
   state[u] = BLACK ;
   cout << u << " " ;
}

VL dfs( ll vertex) {
    INC(i,1,vertex) state[i] = WHITE ;
    cout << "DFS is " << endl ;
    INC (i,1,vertex)  if (state[i] == WHITE) dfsvisit(i,vertex);
    while(!stk.empty()) {
        ll x = stk.top();
        topsort.PB(x);
        stk.pop();
    }
    return topsort ;
}
