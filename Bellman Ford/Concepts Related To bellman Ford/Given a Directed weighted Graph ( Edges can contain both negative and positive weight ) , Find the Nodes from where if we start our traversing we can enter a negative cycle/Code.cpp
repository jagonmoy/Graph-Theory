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
ll vertex,edges ;
vector<pair<PLL,ll>>graphedge;
vector < VL > reversegraph;
VL dist,parent,markednode,visited,targetnode;
 
void setting() {
    reversegraph.clear();
    reversegraph.resize(vertex+5);
    graphedge.clear();
    markednode.clear();
    markednode.resize(vertex+5);
    visited.clear();
    visited.resize(vertex+5,0);
    targetnode.clear();
    targetnode.resize(vertex+5,0);
}
void dfs(ll node, ll par) {
    visited[node] = 1 ;
    if ( par != -1) markednode[node] = markednode[par];
    for ( ll child : reversegraph[node]) {
        if (!visited[child]) dfs(child,node);
    }
}
void bellmanford() {
    dist.clear();
    dist.resize(vertex+5,0);
    parent.clear();
    parent.resize(vertex+5,-1);
    INC(i,1,vertex) {
        INC(j,0,graphedge.size()-1) {
            ll startnode = graphedge[j].F.F;
            ll endnode = graphedge[j].F.S;
            ll weight = graphedge[j].S;
            if ( dist[startnode] + weight < dist[endnode]) {
                dist[endnode] = max(neginf,dist[startnode] + weight);
                parent[endnode] = startnode;
                if ( i == vertex) targetnode[endnode] = 1 ;
            }
        }
    }
    INC(i,1,vertex) {
        if (targetnode[i] == 1 && markednode[i] == 0) {
            ll x = i ;
            INC(j,1,vertex) x = parent[x];
            ll cur = x ;
            while(1) {
                markednode[cur] = 1 ;
                cur = parent[cur];
                if ( cur == x) break ;
            }
        }
    }
    INC(i,0,vertex-1) if( markednode[i] == 1 && visited[i] == 0) dfs(i,parent[i]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,caseno = 0 ;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld %lld",&vertex,&edges);
        setting();
        INC(i,1,edges) {
            ll node1,node2,val ;
            scanf("%lld %lld %lld",&node1,&node2,&val);
            graphedge.PB({{node2,node1},val});
            reversegraph[node2].PB(node1);
        }
        if (edges) bellmanford();
        VL result ;
        INC(i,0,vertex) if ( markednode[i] == 1) result.PB(i);
        if (result.size() > 0) {
            printf("Case %lld:",++caseno);
            INC(i,0,result.size()-1)
            printf(" %lld",result[i]);
            printf("\n");
        }
        else printf("Case %lld: impossible\n",++caseno);
    }
 
    return 0 ;
}
 
