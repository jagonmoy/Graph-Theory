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
ll n ;
vector < VL > graph,rgraph ;
VL edgecost,edgeval,visited,edgevisit;
map < PLL,ll > mymap ;
void setting() {
    graph.clear();
    rgraph.clear();
    edgecost.clear();
    edgeval.clear();
    visited.clear();
    mymap.clear();
    edgevisit.clear();
    edgevisit.resize(n+5,0);
    graph.resize(n+5);
    rgraph.resize(n+5);
    edgecost.resize(n+5,0);
    edgeval.resize(n+5,0);
    visited.resize(n+5,0);
}
void dfs(ll node) {
    visited[node] = 1 ;
    ll f = 0 ;
    for ( ll child : graph[node]) {
        if (!edgevisit[mymap[{node,child}]]) {
            edgeval[mymap[{node,child}]] = 0 ;
            edgevisit[mymap[{node,child}]] = 1 ;
            f = 1 ;
            dfs(child);
        }
    }
    if (!f) {
        for ( ll child : rgraph[node]) {
           if (!edgevisit[mymap[{child,node}]]) {
               edgeval[mymap[{child,node}]] = 1 ;
               edgevisit[mymap[{child,node}]] = 1 ; 
               dfs(child);
           }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n); 
        setting();
        INC(i,1,n) {
            ll node1,node2,cost ;
            scanf("%lld %lld %lld",&node1,&node2,&cost);
            graph[node1].PB(node2);
            rgraph[node2].PB(node1);
            mymap[{node1,node2}] = i;
            edgecost[i]=cost ;
        }
        dfs(1);
        ll sumL = 0 , sumR = 0 ;
        INC(i,1,n) {
            if ( !edgeval[i]) sumL += edgecost[i];
            else sumR += edgecost[i];
        }
        printf("Case %lld: %lld\n",++c,min(sumL,sumR));
    }
 
    return 0 ;
}
