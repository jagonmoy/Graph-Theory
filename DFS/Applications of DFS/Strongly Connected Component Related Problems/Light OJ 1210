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
VL visited,topsort ;
vector < VL > graph ;
vector < VL > rgraph;
VL component,indegree,outdegree ;
ll SCC ;
void setting(ll n ) {
    graph.clear() ;
    graph.resize(n+3);
    rgraph.clear();
    rgraph.resize(n+3);
    visited.clear();
    visited.resize(n+3,0);
    topsort.clear();
    component.clear();
    component.resize(n+3,0);
    indegree.clear();
    indegree.resize(n+3,0);
    outdegree.clear();
    outdegree.resize(n+3,0);
}
void dfs1(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
           if ( !visited[child]) dfs1(child); 
    }
    topsort.PB(node);
}
void dfs2(ll node) {
    visited[node] = 1 ;
    component[node] = SCC ;
    for ( ll child : rgraph[node]) {
           if ( !visited[child]) dfs2(child); 
    }
}
void dfs3(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node] ) {
        if ( component[node] != component[child]) {
            outdegree[component[node]]++ ;
            indegree[component[child]]++  ;
        }
        if ( !visited[child]) dfs3(child);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    cin >> t ;
    while(t--) {
        ll vertex,edges ;
        cin >> vertex >> edges ;
        setting(vertex);   
        INC(i,1,edges) {
            ll node1,node2 ;
            cin >> node1 >> node2 ;
            graph[node1].PB(node2);
            rgraph[node2].PB(node1);
        }
        INC(i,1,vertex) {
            if ( !visited[i]) {
                dfs1(i);
            }
        }
        reverse(topsort.begin(),topsort.end());
        visited.clear();
        visited.resize(vertex+3,0);
        SCC = 0 ;
        INC(i,0,topsort.size()-1) {
            if ( !visited[topsort[i]]) {
                ++SCC ;
                dfs2(topsort[i]);
            }
        }
        visited.clear();
        visited.resize(vertex+3,0);
        INC(i,1,vertex) {
            if (!visited[i]) {
                dfs3(i);
            }
        }
        if ( SCC == 1) cout << "Case " << ++c << ": " << 0 << endl;
        else {
           ll insum  = 0 ;
           ll outsum = 0 ;
           INC(i,1,SCC) {
               if (!indegree[i]) insum++ ;
               if (!outdegree[i]) outsum++ ;
           }
           cout << "Case " << ++c << ": " << max(insum,outsum) << endl;
        }
    }
    return 0 ;
}
