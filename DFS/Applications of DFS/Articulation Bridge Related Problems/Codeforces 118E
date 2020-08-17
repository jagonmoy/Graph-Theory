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
ll vertex,NumberOfedges ;
vector < PLL > graph[100005] ;
VL edges_visited , vertex_visited,low,in,edge_direction,parent;
VLL edges ;
ll t ;
ll f ;
void setting(ll n , ll m) {
    INC(i,0,100004) graph[i].clear();
    edges_visited.clear();
    edges_visited.resize(m+5);
    vertex_visited.clear();
    vertex_visited.resize(n+5);
    low.clear();
    low.resize(n+5);
    in.clear();
    in.resize(n+5);
    edges.clear();
    edges.resize(m+5);
    edge_direction.clear();
    edge_direction.resize(m+5);
    parent.clear();
    parent.resize(n+5);
}
void dfs(ll node) {
     vertex_visited[node] = 1;
     low[node] = in[node] = ++t ;
     for ( PLL child : graph[node]) {
         if ( edges_visited[child.S]) continue ; // Checking If the edges is used before .
         edges_visited[child.S] = 1 ;
         if ( edges[child.S].F == node ) edge_direction[child.S] = 1 ; // giving direction from node to child
         else edge_direction[child.S] = -1 ; // giving direction from child to node
         if (!vertex_visited[child.F]) {
             parent[child.F] = node ;
             dfs(child.F);
             low[node] = min(low[node],low[child.F]);
             if ( low[child.F] > in[node]) {
                 f = 1 ;                         // making The edge Bidirectional
             }
         }
        else if ( parent[node] != child.F) {
               low[node] = min(low[node],in[child.F]);
        }
     }

}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> vertex >> NumberOfedges ;
    setting(vertex,NumberOfedges);
    INC(i,1,NumberOfedges) {
        ll node1,node2 ;
        cin >> node1 >> node2 ;
        graph[node1].PB({node2,i});
        graph[node2].PB({node1,i});   
        edges[i] = {node1,node2};
    }
    t = 0 ;
    f = 0 ;
    INC(i,1,vertex) 
        if ( !vertex_visited[i]) dfs(i) ;
    
    if(f) cout << "0" << endl;
    else {
        INC(i,1,NumberOfedges) {
            if ( edge_direction[i] == 1) cout << edges[i].F << " " << edges[i].S << endl;
            else if ( edge_direction[i] == -1) cout << edges[i].S << " " << edges[i].F << endl;       
        }
    }

    return 0 ;
}
