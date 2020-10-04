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
    while(1)
    {
        bool any = false;
        INC(i,0,graphedge.size()-1) {
            ll startnode = graphedge[i].F.F ;
            ll endnode = graphedge[i].F.S ;
            ll weight = graphedge[i].S ;
            if (dis[startnode] != inf)
                if (dis[endnode] > dis[startnode] + weight)
                {
                    dis[endnode] = dis[startnode] + weight ;
                    parent[endnode] = startnode;
                    any = true;
                }
        }
        if (!any)  break;
    }
}

void printpath(ll source, ll dest) {
    if (dis[dest] == inf)
        cout << "No path from " << source << " to " << dest << ".";
    else
    {
        VL path ;
        ll x = dest ;
        while(1) {
            path.PB(x);
            x = parent[x];
            if ( x == -1 ) break ;
        }
        reverse (path.begin(), path.end());
        cout << "Path from " << source << " to " << dest << ": ";
        INC(i,0,path.size()-1) cout << path[i] << ' ';
        cout << endl;
    }
}
 
