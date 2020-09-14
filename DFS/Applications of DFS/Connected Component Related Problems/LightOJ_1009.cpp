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
ll vertex,edges,cntone,cntzero ;
vector < VL > graph ;
VL visited,mark ;
MLL mymap ;
void setting() {
    graph.clear();
    graph.resize(20005);
    mymap.clear();
    visited.clear();
    visited.resize(20005,0);
    mark.clear();
    mark.resize(200005,0);
}
void dfs(ll node) {
    visited[node] = 1 ;
    if ( !mark[node]) cntzero++ ;
    else cntone++ ;
    for ( ll child : graph[node]) {
        if (!visited[child]) {
                mark[child] = !mark[node];
                dfs(child);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c =0 ;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&edges);
        setting();
        vertex = 0 ;
        while(edges--) {
            ll node1,node2;
            scanf("%lld %lld",&node1,&node2);
            if (!mymap[node1]) {
                vertex++ ;
                mymap[node1] = vertex ;
            }
            if ( !mymap[node2]) {
                vertex++ ;
                mymap[node2] = vertex ;
            }
            graph[mymap[node1]].PB(mymap[node2]);
            graph[mymap[node2]].PB(mymap[node1]);
        }
        ll total = 0 ;
        INC(i,1,vertex) {
            if (!visited[i]){
                 cntone = 0 ,cntzero = 0 ;
                 dfs(i);
                 total += max(cntzero,cntone);
            }
        }
        printf("Case %lld: %lld\n",++c,total);
    }
 
    return 0 ;
}
