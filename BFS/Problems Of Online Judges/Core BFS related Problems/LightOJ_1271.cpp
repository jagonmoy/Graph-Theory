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
ll connections ;
map < PLL,ll > edge ;
MLL track ;
VL parent,dis;
void setting() {
    edge.clear();
    graph.clear();
    graph.resize(50005);
    dis.clear();
    dis.resize(50005,-1);
    parent.clear();
    parent.resize(500005,-1);
}
 
void bfs(ll source) {
    queue<ll>q ;
    dis[source] = 0 ;
    q.push(source);
    dis[source] = 0 ;
    while(!q.empty()) {
        ll node = q.front();
        q.pop();
        if ( graph[node].size()) {
            INC(i,0,graph[node].size()-1) {
                ll child = graph[node][i];
                if (dis[child] == -1) {
                    parent[child] = node ;
                    dis[child] = dis[node]+1 ;
                    q.push(child);
                }
            }
        }
    }
 
}
VL printpath(ll source , ll dest) {
    VL path ;
    ll node = dest ;
    while(1) {
        path.PB(node);
        node = parent[node];
        if (node == -1) break ;
    }
    reverse(path.begin(),path.end());
    return path ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&connections);
        setting();
        ll source,dest ;
        scanf("%lld",&source);
        track[source] = 1 ;
        ll prev = source ;
        INC(i,2,connections) {
           ll node ;
           scanf("%lld",&node);
           if (!track.count(node)) track[node] = 1 ;
           if ( node == prev) continue ;
           if ( edge[{node,prev}] == 0) {
               graph[prev].PB(node);
               graph[node].PB(prev);
               edge[{prev,node}] = 1 ;
               edge[{node,prev}] = 1 ;
           }
           prev = node;
           if (i == connections) dest = node ;
        }
        INC(i,1,50000) {
            sort(graph[i].begin(),graph[i].end());
        }
        bfs(source);
        //INC(i,1,cnt) printf("%lld ",dis[i]);
        //printf("\n");
        //INC(i,1,cnt) printf("%lld ",parent[i]);
        //printf("\n");
        VL path = printpath(source,dest);
        printf("Case %lld:\n",++c);
        INC(i,0,path.size()-2) printf("%lld ",path[i]);
        printf("%lld\n",path[path.size()-1]);
    }
 
    return 0 ;
}
