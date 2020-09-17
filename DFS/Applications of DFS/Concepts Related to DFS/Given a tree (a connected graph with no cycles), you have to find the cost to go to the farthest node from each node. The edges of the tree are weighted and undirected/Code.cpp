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
ll n  ;
vector < VL > graphedge,graphcost;
VL visited,dis1,dis2,dis3 ;
void setting() {
    graphedge.clear();
    graphcost.clear();
    graphedge.resize(n+5);
    graphcost.resize(n+5);
    visited.clear();
    visited.resize(n+5,0);
    dis1.clear();
    dis1.resize(n+5,0);
    dis2.clear();
    dis2.resize(n+5,0);
    dis3.clear();
    dis3.resize(n+5,0);
}
void dfs1(ll node) {
    visited[node] = 1 ;
    if ( graphedge[node].size()) {
        INC(i,0,graphedge[node].size()-1) {
            ll child = graphedge[node][i];
            ll cost = graphcost[node][i];
            if ( !visited[child]) {
                dis1[child] = dis1[node] + cost ;
                dfs1(child);
            }
        }
    }
}
void dfs2(ll node) {
    visited[node] = 1 ;
    if ( graphedge[node].size()) {
        INC(i,0,graphedge[node].size()-1) {
            ll child = graphedge[node][i];
            ll cost = graphcost[node][i];
            if ( !visited[child]) {
                dis2[child] = dis2[node] + cost ;
                dfs2(child);
            }
        }
    }
}
void dfs3(ll node) {
    visited[node] = 1 ;
    if ( graphedge[node].size()) {
        INC(i,0,graphedge[node].size()-1) {
            ll child = graphedge[node][i];
            ll cost = graphcost[node][i];
            if ( !visited[child]) {
                dis3[child] = dis3[node] + cost ;
                dfs3(child);
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
        INC(i,1,n-1) {
            ll node1,node2,cost ;
            scanf("%lld %lld %lld",&node1,&node2,&cost);
            graphedge[node1].PB(node2);
            graphcost[node1].PB(cost);
            graphedge[node2].PB(node1);
            graphcost[node2].PB(cost);
        }

        dfs1(0);
        ll firstfurthestnode = -1 ;
        ll maximumdis = -1 ;
        INC(i,0,n-1) {
            if ( dis1[i] > maximumdis) {
                maximumdis = dis1[i];
                firstfurthestnode = i ;
            }
        }

        visited.clear();
        visited.resize(n+5,0);
        dfs2(firstfurthestnode);
        ll secondfurthestnode = -1 ;
        maximumdis = -1 ;
        INC(i,0,n-1) {
            if ( dis2[i] > maximumdis) {
                maximumdis = dis2[i];
                secondfurthestnode = i ;
            }
        }

        visited.clear();
        visited.resize(n+5,0);
        dfs3(secondfurthestnode);
        
        printf("Case %lld:\n",++c);
        INC(i,0,n-1) printf("%lld\n",max(dis2[i],dis3[i]));
        
    }
 
    return 0 ;
}
