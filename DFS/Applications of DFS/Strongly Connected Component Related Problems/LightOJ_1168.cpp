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
vector < VL > graph,rgraph ;
vector < VL > SCCgraph ;
VL visited,topsort,StrongComponent,visitedSCC,indegreeSCC,outdegreeSCC;
ll SCC,nodecount;
void setting() {
    indegreeSCC.clear();
    indegreeSCC.resize(1005,0);
    outdegreeSCC.clear();
    outdegreeSCC.resize(1005,0);
    graph.clear();
    graph.resize(1005);
    rgraph.clear();
    rgraph.resize(1005);
    visited.clear();
    visited.resize(1005,0);
    topsort.clear();
    StrongComponent.clear();
    StrongComponent.resize(1005,0);
}
void dfs1(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
        if (!visited[child]) dfs1(child);
    }
    topsort.PB(node);
}
void dfs2(ll node) {
    visited[node] = 1 ;
    nodecount++;
    for ( ll child : graph[node]) {
        if (!visited[child]) dfs2(child);
    }
}
void dfs3(ll node) {
    visited[node] = 1 ;
    StrongComponent[node] = SCC ;
    for ( ll child : rgraph[node]) {
        if (!visited[child]) dfs3(child);
    }
}
void dfs4(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
        if ( StrongComponent[node] != StrongComponent[child] ) {
                SCCgraph[StrongComponent[node]].PB(StrongComponent[child]);
                outdegreeSCC[StrongComponent[node]]++;
                indegreeSCC[StrongComponent[child]]++;
        }
        if ( !visited[child]) {
            dfs4(child);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    scanf("%lld",&t);
    while(t--) {
        setting();
        MLL mymap ;
        ll n ;
        scanf("%lld",&n);
        ll cnt = 0 ;
        while(n--) {
            ll q ;
            scanf("%lld",&q);
            while(q--) {
                ll node1,node2 ;
                scanf("%lld %lld",&node1,&node2);
                if ( mymap[node1] == 0) mymap[node1] = ++cnt ;
                if ( mymap[node2] == 0) mymap[node2] = ++cnt;
                graph[mymap[node1]].PB(mymap[node2]);
                rgraph[mymap[node2]].PB(mymap[node1]);
            }
        }
        if ( !graph[mymap[0]].size()) {
            printf("Case %lld: NO\n",++c);
            continue ;
        }
        if ( cnt > 0) {
            INC(i,1,cnt) {
                if ( !visited[i]){
                     dfs1(i);
                }
            }
            reverse(topsort.begin(),topsort.end()); 

            visited.clear();
            visited.resize(cnt+5,0);
            nodecount = 0 ;
            dfs2(mymap[0]);
            if ( nodecount == cnt) {
                visited.clear();
                visited.resize(cnt+5,0);
                SCC = 0 ;
                INC(i,0,topsort.size()-1) {
                    if (!visited[topsort[i]]) {
                        ++SCC ;
                        dfs3(topsort[i]);
                    }
                }

                visited.clear();
                visited.resize(cnt+5,0);
                SCCgraph.clear();
                SCCgraph.resize(SCC+2);
                INC(i,1,cnt) {
                    if (!visited[i]) {
                       dfs4(i);
                    }
                }
                ll checker  = 1 ;
                ll noindegreenode = 0 ;
                INC(i,1,SCC) {
                    if ( outdegreeSCC[i] >= 2) {
                        checker = 0 ;
                        break ;
                    }
                    if ( indegreeSCC[i] == 0) noindegreenode++ ;
                }
                
                if ( noindegreenode > 1) checker = 0 ; 
                if (checker) printf("Case %lld: YES\n",++c);
                else printf("Case %lld: NO\n",++c);  
               
            }
            else printf("Case %lld: NO\n",++c);
        }
        else printf("Case %lld: YES\n",++c);
    }
 
    return 0 ;
}
