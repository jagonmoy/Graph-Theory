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
vector < vector <PLL> > graph ;
map < ll,char > bidirectional1,bidirectional2;
VL visited ;
VLL edges;
void dfs1(ll node) {
    visited[node] = 1 ;
    for ( PLL child : graph[node]) {
         if ( child.S != -1 && bidirectional1[child.S] == '=' ) {
             if ( edges[child.S].F == node) bidirectional1[child.S] = '+' ;
             else bidirectional1[child.S] = '-' ;
             if ( !visited[child.F]) dfs1(child.F);
         }
         else if ( child.S == -1 && !visited[child.F]) {
            dfs1(child.F);
         }
    }    
}
void dfs2(ll node) {
    visited[node] = 1 ;
    for ( PLL child : graph[node]) {
         if ( child.S != -1 && bidirectional2[child.S] == '=' ) {
             if ( edges[child.S].F == node) bidirectional2[child.S] = '-' ;
             else bidirectional2[child.S] = '+' ;
         }
         else if ( child.S == -1 && !visited[child.F]) {
            dfs2(child.F);
         }
    }    
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,s ;
    cin >> n >> m >> s ;
    graph.resize(n+2);
    visited.resize(n+2,0);
    edges.resize(m+2,{0,0});
    ll x = 0 ;
    INC(i,1,m) {
        ll t,node1,node2 ;
        cin >> t >> node1 >> node2 ;
        if (t == 1) graph[node1].PB({node2,-1});
        else {
            graph[node1].PB({node2,++x});
            graph[node2].PB({node1,x});
            bidirectional1[x] = '=' ;
            bidirectional2[x] = '=' ;
            edges[x] = {node1,node2};
        }
    }
    dfs1(s);
    INC(i,1,x) if ( bidirectional1[i] == '=') bidirectional1[i] = '+' ;
  
    ll cnt = 0 ;
    INC(i,1,n) if ( visited[i]) cnt++ ;
    cout << cnt << endl; 
    INC(i,1,x) cout << bidirectional1[i] ;
    cout << endl;
    visited.clear();
    visited.resize(n+2,0);
    dfs2(s);
    INC(i,1,x) if ( bidirectional2[i] == '=') bidirectional2[i] = '+' ;
    cnt = 0 ;
    INC(i,1,n) if ( visited[i]) cnt++ ;
    cout << cnt << endl; 
    INC(i,1,x) cout << bidirectional2[i] ;
    cout << endl;
    return 0 ;
}
