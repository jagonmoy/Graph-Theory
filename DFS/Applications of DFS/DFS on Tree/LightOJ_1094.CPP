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
ll vertex ;
vector < VL > edges,cost ;
VL visited,dist;
void setting(ll n) {
    visited.clear();
    visited.resize(n+5,0);
    dist.clear();
    dist.resize(n+5,0);
    edges.clear();
    cost.clear();
    edges.resize(n+5);
    cost.resize(n+5);
} 
void dfs(ll node) {
    visited[node] = 1 ;
    if ( edges[node].size()) {
        INC(i,0,edges[node].size()-1) {
            ll child = edges[node][i];
            ll weight = cost[node][i]; 
            if (!visited[child]) {
                dist[child] = dist[node]+weight;
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
        scanf("%lld",&vertex);
        //printf("Kita");
        setting(vertex);
        INC(i,1,vertex-1) {
            ll node1,node2,val;
            scanf("%lld %lld %lld",&node1,&node2,&val);
            edges[node1].PB(node2);
            edges[node2].PB(node1);
            cost[node1].PB(val);
            cost[node2].PB(val);
        }
        dfs(0);
        ll maximum = neginf ;
        ll furthestnode = -1 ;
        INC(i,0,vertex-1) {
            if ( dist[i] > maximum) {
                maximum = dist[i];
                furthestnode = i ;
            }
        }
        visited.clear();
        visited.resize(vertex+5,0);
        dist.clear();
        dist.resize(vertex+5,0);
        dfs(furthestnode);
        ll furhtestdistance = neginf ;
        INC(i,0,vertex-1) furhtestdistance = max(furhtestdistance,dist[i]);
        printf("Case %lld: %lld\n",++c,furhtestdistance);
    }
 
    return 0 ;
}
