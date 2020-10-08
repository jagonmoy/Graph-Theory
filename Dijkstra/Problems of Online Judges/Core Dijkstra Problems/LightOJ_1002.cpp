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
vector < VLL > graph ;
ll vertices,edges;
VL dist;
map < PLL,ll > edgeno ;
MLL edgeweight;
void setting() {
    edgeweight.clear();
    edgeno.clear();
    graph.clear();
    graph.resize(vertices+5);
    dist.clear();
    dist.resize(vertices+5,inf);
}
void dijkstra(ll source) {
    dist[source] = 0 ;
    priority_queue < PLL , vector<PLL> , greater <PLL> > q ;
    q.push({0,source});
    while(!q.empty()) {
        ll node  = q.top().S ;
        ll nodeval = q.top().F ;
        q.pop();
        for ( PLL adjacent : graph[node]) {
            ll edgeno = adjacent.S ;
            ll child = adjacent.F ;
            if ( max(dist[node],edgeweight[edgeno]) < dist[child] ) {
                dist[child] = max(dist[node],edgeweight[edgeno]);
                q.push({dist[child],child});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,caseno = 0 ;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld %lld",&vertices,&edges);
        setting();
        INC(i,1,edges) {
            ll node1,node2,weight ;
            scanf("%lld %lld %lld",&node1,&node2,&weight);
            if (edgeno[{min(node1,node2),max(node1,node2)}] != 0 ) {
                edgeweight[edgeno[{min(node1,node2),max(node1,node2)}]] = min(edgeweight[edgeno[{min(node1,node2),max(node1,node2)}]],weight);
            }
            else {
                edgeno[{min(node1,node2),max(node1,node2)}] = i ;
                edgeweight[i] = weight ;
                graph[node1].PB({node2,edgeno[{min(node1,node2),max(node1,node2)}]});
                graph[node2].PB({node1,edgeno[{min(node1,node2),max(node1,node2)}]});
            }
        }

        ll source ;
        scanf("%lld",&source);
        dijkstra(source);
        printf("Case %lld:\n",++caseno);
        INC(i,0,vertices-1) {
            if ( dist[i] != inf) printf("%lld\n",dist[i]);
            else printf("Impossible\n");
        }
    }

    return 0 ;
}
