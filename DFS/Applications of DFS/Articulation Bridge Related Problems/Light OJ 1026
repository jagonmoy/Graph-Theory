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
map < PLL,ll > mymap ;
vector < VL > graph ;
VL visited ,parent,in,low ;
VL edges ;
ll root ;
VLL bridges ;
ll t  ;
void setting(ll n) {
    visited.clear();
    visited.resize(n+2,0);
    graph.clear();
    graph.resize(n+2);
    parent.clear();
    parent.resize(n+2,-1);
    in.clear();
    in.resize(n+2,0);
    low.clear();
    low.resize(n+2,0);
    bridges.clear();
    mymap.clear();
}
void dfs(ll node) {
    visited[node] = 1 ;
    low[node] = in[node] = ++t ;
    for ( ll child : graph[node]) {
        if ( !visited[child]) {
            parent[child] = node ;
            dfs(child);
            low[node] = min(low[node],low[child]);
            if ( low[child] > in[node]) {
                bridges.PB({min(node,child),max(node,child)});
            }
        }
        else if ( parent[node] != child) {
               low[node] = min(low[node],in[child]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll test,c = 0 ;
    cin >> test ;
    while(test--) {
        ll n ;
        cin >> n ;
        cin.ignore() ;
        setting(n);
        if(n) {
            INC(i,0,n-1) {
                ll u,edges;
                cin >> u;
                char c ;
                cin >> c >> edges >> c ;
                //cout << edges << endl;
                INC(m,0,edges-1) {
                    ll v ;
                    cin >> v ;
                    if ( mymap[{min(u,v),max(u,v)}] == 0){
                        graph[u].push_back(v);
                        graph[v].push_back(u);
                        mymap[{min(u,v),max(u,v)}] = 1 ;
                    }
                }
            }
            INC(i,0,n-1) {
                if ( !visited[i]) {
                    t = 0 ;
                    root = i ;
                    dfs(i);
                }
            }
            sort(bridges.begin(),bridges.end());
        }
        cout << "Case " << ++c << ":" << endl;
        cout << bridges.size() << " critical links" << endl;
        for ( PLL x : bridges) cout << x.F << " - " << x.S << endl;
    }
 
    return 0 ;
}
