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
ll n,a,b,da,db,distancetob ,maximumdurotto1,treediameter,furthestnode;
ll fact ;
void setting(ll n) {
    graph.clear();
    graph.resize(n+5);
    fact = 0 ;
    distancetob = -1;
    maximumdurotto1 = -1 ;
    treediameter = -1 ;
    furthestnode = -1 ;
}
void dfs(ll node, ll parent ,ll durotto) {
    if ( fact == 1) {
        if ( node == b) distancetob = durotto ;
        if ( durotto > maximumdurotto1) {
            maximumdurotto1 = durotto ;
            furthestnode = node ;
        }
    }
    else if ( fact == 2) treediameter = max(treediameter,durotto);
 
    for ( ll child : graph[node]) {
        if ( child == parent) continue;
        dfs(child,node,durotto+1);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    while(t--) {
        cin >> n >> a >> b >> da >> db ;
        setting(n);
        INC(i,1,n-1) {
            ll node1,node2 ;
            cin >> node1 >> node2;
            graph[node1].PB(node2);
            graph[node2].PB(node1);
        }
        fact++ ;
        dfs(a,-1,0);
        if (distancetob <= da ) {
            cout << "Alice" << endl;
            continue ;
        }
        fact++ ;
        dfs(furthestnode,-1,0);
        if ( treediameter <= 2*da || db <= 2*da  )  {
            cout << "Alice" << endl;
            continue ;
        }
        cout << "Bob" << endl;
    }   
 
    return 0 ;
}
