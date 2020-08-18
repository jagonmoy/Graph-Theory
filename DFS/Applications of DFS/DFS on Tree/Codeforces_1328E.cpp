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
 
vector < VL > graph ;
VL visited,intime,endtime,parent;
ll t ;
void dfs( ll node ) {
    visited[node] = 1 ;
    intime[node] = ++t ;
    for ( ll child : graph[node]) {
        if ( !visited[child]) {
            parent[child] = node ;
            dfs(child) ;
        }
    }
    endtime[node] = ++t ;
}
bool cmp(ll x, ll y) {
    return(intime[x] < intime[y]) ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m ;
	cin >> n >> m;
	graph.resize(n+5);
    visited.resize(n+5,0);
	parent.resize(n+5,-1);
    intime.resize(n+5,0);
    endtime.resize(n+5,0);
    parent[1] = 1 ;
	INC(i,0,n-2) {
		ll node1,node2 ;
		cin >> node1 >> node2 ;
		graph[node1].PB(node2);
        graph[node2].PB(node1);
	}
    t = 0 ;
    dfs(1);
    INC(i,1,m) {
        ll t ;
        cin >> t ;
        VL v ;
        INC(j,1,t) {
            ll a ;
            cin >> a ;
            v.PB(parent[a]);
        } 
        if (t == 1) cout << "YES" << endl;
        else {
            sort(v.begin(),v.end(),cmp);
            ll f = 0 ;
            INC(j,0,v.size()-2) {
                if ( endtime[v[j]] < endtime[v[j+1]]) {
                    f = 1 ;
                    break ;
                }
            }
            if (f) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0 ;
}
