ll vertex ;
VL dis,parent ;
vector < pair < PLL,ll > > graphedge ;
void bellmanford(ll source)
{
    dis.clear() ;
    dis.resize(vertex+5,inf);
    dis[source] = 0;
    parent.clear();
    parent.resize(vertex+5,-1);
    ll x ;
    INC(i,1,vertex)
    {
        x = -1;
        INC(j,0,graphedge.size()-1) {
            ll startnode = graphedge[j].F.F ;
            ll endnode = graphedge[j].F.S ;
            ll weight = graphedge[j].S ;
            if (dis[startnode] != inf)
                if (dis[endnode] > dis[startnode] + weight)
                {
                    dis[endnode] = max(neginf,dis[startnode] + weight);
                    parent[endnode] = startnode;
                    x = endnode ;
                }
        }
    }
    if ( x == -1 ) cout << "No negative cycle from " << source << endl;
    else {
        INC(i,1,vertex) x = parent[x];
        VL path ;
        ll cur = x ;
        while(1) {
            path.PB(cur);
            cur = parent[cur] ;
            if ( cur == x ) break ;
        }
        reverse (path.begin(), path.end());
        cout << "Negative cycle: ";
        INC(i,0,path.size()-1) cout << path[i] << ' ';
        cout << endl;
    }
}
