#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define PF push_front
#define P push
#define INC(i,a,b) for (ll i = a; i <= b; i++)
#define DEC(i,b,a) for (ll i = b; i >= a ; i--)
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define mod  1000000007
#define eps 1e-9
typedef ostringstream OS ;
typedef stringstream SS ;
typedef long long ll ;
typedef unsigned long long ull;
typedef pair < ll , ll > PLL ;
typedef pair < char,ll > PCL ;
typedef deque < double > DD ;
typedef deque < PCL > DCL ;
typedef deque < ll > DL ;
typedef deque < PLL > DLL ;
typedef deque < char > DC ;
typedef deque < string > DS ;
typedef vector < double > VD;
typedef vector < PCL > VCL ;
typedef vector < ll > VL;
typedef vector < PLL > VLL ;
typedef vector < char > VC ;
typedef vector < string > VS ;
typedef map < ll ,ll > MLL ;
typedef map < char,ll > MCL;
typedef map < ll,char > MLC;
typedef map < string,ll> MSL;
typedef priority_queue < PLL > PQLL ;
typedef priority_queue < ll > PQL ;
typedef stack < ll > SKL ;
typedef stack < PLL > SKLL ;
typedef queue < ll > QL ;
typedef queue < PLL > QLL ;
typedef set < ll > SL ;
typedef set < PLL > SLL ;
typedef set < char > SC ;
 
string numtostr(ll n) {
     OS str1 ;
     str1 << n ;
     return str1.str();
}
ll strtonum(string s) {
     ll x ;
     SS str1(s);
     str1 >> x ;
     return x ;
}
ll GCD(ll a, ll b) {
    if ( b == 0 ) return a ;
    else return GCD(b,a%b);
}
ll LCM(ll a , ll b) {
    ll gcd = GCD(a,b);
     return (a/gcd)*b ;
}
vector < pair < PLL,ll > > graphedge ;
vector < VL > graph ;
VL nodecost,dis,reachable_from_negative_cycle,visited,parent;
ll vertex,edges;
void setting(ll cnt) {
    if (cnt == 1) {
       nodecost.clear();
       nodecost.resize(vertex+5,0);
       graph.clear();
       graph.resize(vertex+5);
    }
    else graphedge.clear();
}
void dfs(ll node , ll par) {
    visited[node] = 1 ;
    if ( par != -1) reachable_from_negative_cycle[node] = reachable_from_negative_cycle[par];
    for (ll child : graph[node]) {
        if (!visited[child]) {
             dfs(child,node);
        }
    }
}
void bellmanford(ll source){
    dis.clear();
    dis.resize(vertex+5,inf);
    parent.clear();
    parent.resize(vertex+5,-1);
    dis[source] = 0 ;
    reachable_from_negative_cycle.clear();
    reachable_from_negative_cycle.resize(vertex+5,0);
    ll x ;
    INC(i,1,vertex) {
          x = -1 ;
          INC(j,0,edges-1) {
              ll startnode = graphedge[j].F.F ;
              ll endnode = graphedge[j].F.S ;
              ll weight = graphedge[j].S ;
              if ( dis[startnode] != inf ) {
                  if ( dis[endnode] > dis[startnode] + weight) {
                      dis[endnode] = dis[startnode] + weight ;
                      parent[endnode] = startnode ;
                      x = endnode ;
                  }
              }
          }
    }
    if (x != -1) {
         INC(i,1,vertex) x = parent[x];
         ll cur = x ;
         while(1){
              reachable_from_negative_cycle[cur] = 1 ;
              cur = parent[cur];
              if(cur == x) break ;
         }
         visited.clear();
         visited.resize(vertex+5);
         dfs(1,-1);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,caseno = 0 ;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&vertex);
        setting(1);
        INC(i,1,vertex) scanf("%lld",&nodecost[i]);
        scanf("%lld",&edges);
        setting(2);
        INC(i,1,edges) {
            ll node1,node2 ;
            scanf("%lld %lld",&node1,&node2);
            ll val = nodecost[node2]-nodecost[node1];
            val *= (val*val);
            graphedge.PB({{node1,node2},val});
            graph[node1].PB(node2);
        }
        bellmanford(1);
        ll query ;
        scanf("%lld",&query);
        printf("Case %lld:\n",++caseno);
        while(query--) {
            ll node ;
            scanf("%lld",&node);
            if ( dis[node] < 3 || reachable_from_negative_cycle[node] == 1 || dis[node] == inf) printf("?\n");
            else printf("%lld\n",dis[node]);
        }
    }
 
    return 0 ;
}
 
