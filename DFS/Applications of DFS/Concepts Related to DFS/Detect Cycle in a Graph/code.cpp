
vector < vector <ll> > graph ;
vector < ll > parent ;
vector < ll > state ;

ll f = 0 ;

void detecting_cycle(ll u , ll vertex) {
   state[u] = GREY ;
   INC(i,0,graph[u].size()-1) {
       ll v = graph[u][i];
       if (state[v] == GREY && parent[u] != v) f = 1 ;
       if ( state[v] == WHITE) {
           parent[v] = u ;
           detecting_cycle(v,vertex);
       }
   }
   state[u] = BLACK ;
   return ;
}

void dfs( ll vertex) {
    INC(i,1,vertex) state[i] = WHITE ;
    INC(i,1,vertex) parent[i] = -1 ;
    INC (i,1,vertex) if (state[i] == WHITE) detecting_cycle(i,vertex);
    return ;
}
