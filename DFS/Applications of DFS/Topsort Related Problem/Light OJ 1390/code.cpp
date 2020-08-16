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
vector < bitset<5005> > reachable ;
VL visited,topsort,priorityarray ;
VLL result ;
ll cnt ;
bool cmp(ll x , ll y) {
    return priorityarray[x] < priorityarray[y] ;
}
void setting(ll n) {
    graph.clear();
    graph.resize(n+3);
    visited.clear();
    visited.resize(n+3,0);
    topsort.clear();
    priorityarray.clear();
    priorityarray.resize(n+3,0);
    result.clear();
    reachable.clear();
    reachable.resize(n+3);
    INC(i,1,n) reachable[i][i] = 1 ;
}
void dfs( ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
        if ( !visited[child]) dfs(child);
        reachable[node] |= reachable[child] ;
    }
    topsort.PB(node);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0;
    scanf("%lld",&t);
    while(t--) {
        ll n,m ;
        scanf("%lld %lld",&n,&m);
        setting(n) ;
        INC(i,1,m) {
            ll node1,node2 ;
            scanf("%lld %lld",&node1,&node2);
            graph[node1].PB(node2);
        }
        INC(i,1,n) if (!visited[i]) dfs(i);
        reverse(topsort.begin(),topsort.end());
        INC(i,0,topsort.size()-1) priorityarray[topsort[i]] = i+1 ;
        visited.clear();
        visited.resize(n+2,0);
        ll cnt = 0;
        INC(i,1,n) {
            bitset < 5005 > reachable_Set_of_from_i ;
            sort(graph[i].begin(),graph[i].end(),cmp);
            for ( ll child : graph[i]) {
                  if ( reachable_Set_of_from_i[child] == 0) result.PB({i,child});
                  reachable_Set_of_from_i |= reachable[child];
            }
        }
        printf("Case %lld: %lld\n",++c,(ll)result.size());
        sort(result.begin(),result.end());
        INC(i,0,result.size()-1) printf("%lld %lld\n",result[i].F,result[i].S); 
    }
 
    return 0 ;
}
