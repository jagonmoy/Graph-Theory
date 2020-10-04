
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
VL nodecost,dis;
ll vertex,edges;
void setting(ll cnt) {
    if (cnt == 1) {
       nodecost.clear();
       nodecost.resize(vertex+5,0);
       dis.clear();
       dis.resize(vertex+5,inf);
    }
    else graphedge.clear();
}
void bellmanford(ll source){
    dis[source] = 0 ;
    ll x ;
    VL markednode ;
    INC(i,1,vertex) {
          x = -1 ;
          INC(j,0,edges-1) {
              ll startnode = graphedge[j].F.F ;
              ll endnode = graphedge[j].F.S ;
              ll weight = graphedge[j].S ;
              if ( dis[startnode] != inf ) {
                  if ( dis[endnode] > dis[startnode] + weight) {
                      dis[endnode] = dis[startnode] + weight ;
                      if ( i == vertex ) markednode.PB(endnode);
                  }
              }
          }
    }
    if(markednode.size())INC(i,0,markednode.size()-1) dis[markednode[i]] = inf ;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll caseno = 0 ;
    while(scanf("%lld",&vertex)) {
        setting(1);
        if (vertex) INC(i,1,vertex) scanf("%lld",&nodecost[i]);
        scanf("%lld",&edges);
        setting(2);
        if(edges) {
            INC(i,1,edges) {
                ll node1,node2 ;
                scanf("%lld %lld",&node1,&node2);
                ll val = nodecost[node2]-nodecost[node1];
                val *= (val*val);
                graphedge.PB({{node1,node2},val});
            }
        }
        if(vertex != 0 && edges != 0 ) bellmanford(1);
        ll query ;
        scanf("%lld",&query);
        printf("Set #%lld\n",++caseno);
        while(query--) {
            ll node ;
            scanf("%lld",&node);
            if ( dis[node] < 3 || dis[node] == inf) printf("?\n");
            else printf("%lld\n",dis[node]);
        }
    }

    return 0 ;
}
