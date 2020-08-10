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
vector <VL> graph ;
VL visited;
VL topsort ;
void dfs1(ll node) {
    visited[node] = 1 ;
    for( ll child : graph[node]) 
        if ( !visited[child]) dfs1(child) ;
    topsort.PB(node);
}
void dfs2(ll node) {
    visited[node] = 1 ;
    for( ll child : graph[node]) 
        if ( !visited[child]) dfs2(child) ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    ll c = 0 ;
    while(t--) {
        ll n,m ;
        cin >> n >> m ;
        graph.resize(n+3);
        visited.resize(n+3,0);
        while(m--) {
            ll node1,node2 ;
            cin >> node1 >> node2 ;
            graph[node1].PB(node2);
        }
        INC(i,1,n) {
            if ( !visited[i]) {
                dfs1(i);
            }
        }
        reverse(topsort.begin(),topsort.end());
        visited.clear();
        visited.resize(n+3,0);
        ll cc = 0 ;
        INC(i,0,topsort.size()-1) {
            if ( !visited[topsort[i]]) {
                cc++ ;
                dfs2(topsort[i]);
            }
        }
        cout << "Case " << ++c << ": " << cc << endl;
        topsort.clear() ;
        graph.clear();
        visited.clear();
    }
 
    return 0 ;
}
