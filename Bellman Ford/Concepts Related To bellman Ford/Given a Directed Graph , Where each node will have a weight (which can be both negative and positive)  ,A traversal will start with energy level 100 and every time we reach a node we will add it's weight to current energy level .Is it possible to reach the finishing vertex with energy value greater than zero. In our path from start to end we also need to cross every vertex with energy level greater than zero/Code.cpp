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
VL dist,nodecost,parent,bfsdis;
VLL graphedge ;
vector < VL > reversegraph ;
void setting() {
    reversegraph.clear();
    reversegraph.resize(105);
    dist.clear();
    dist.resize(105,neginf);
    nodecost.clear();
    nodecost.resize(105,0);
    graphedge.clear();
}
void bfs(ll source) {
    bfsdis.clear();
    bfsdis.resize(105,-1);
    bfsdis[source] = 0 ;
    queue <ll> q ;
    q.push(source);
    while(!q.empty()) {
        ll node = q.front();
        q.pop();
        for ( ll child : reversegraph[node]) {
            if (bfsdis[child] == -1) {
                bfsdis[child] = bfsdis[node]+1 ;
                q.push(child);
            }
        }
    }
}
bool bellmanford(ll source) {
    if ( vertex == 1) return true ;
    dist[source] = 100 ;
    MLL markednode ;
    INC(i,1,vertex) {
        INC(j,0,graphedge.size()-1) {
            ll startnode = graphedge[j].F ;
            ll endnode = graphedge[j].S ;
            if ( dist[startnode] != neginf) {
               if ( dist[startnode] + nodecost[endnode] > 0 && dist[startnode]+nodecost[endnode] > dist[endnode]) {
                   dist[endnode] = dist[startnode] + nodecost[endnode];
                   if ( i == vertex ) markednode[endnode] = 1 ;
               }
            }
        }
    }
    MLL reachablenode;
    INC(i,1,100) if ( dist[i] != neginf) reachablenode[i] = 1 ;
    bfs(vertex);
    if ( dist[vertex] != neginf) return true ;
    else {
        bool fact = false ;
        INC(i,0,graphedge.size()-1) {
             ll startnode = graphedge[i].F ;
             ll endnode = graphedge[i].S ;
             if (markednode[endnode] && bfsdis[endnode] != -1 && reachablenode[startnode]) {
                 fact = true ;
                 break ;
             }
        }
        return fact ;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        scanf("%lld",&vertex);
        if ( vertex == -1) break ;
        setting();
        INC(i,1,vertex) {
            ll val,connections ;
            scanf("%lld %lld",&val,&connections);
            nodecost[i] = val ;
            while(connections--) {
                ll node ;
                scanf("%lld",&node);
                graphedge.PB({i,node});
                reversegraph[node].PB(i);
            }
        }
        if(bellmanford(1)) printf("winnable\n");
        else printf("hopeless\n");
    }

    return 0 ;
}
