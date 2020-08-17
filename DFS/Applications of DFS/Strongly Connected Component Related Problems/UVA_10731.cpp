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
ll n,m;
vector < VL > graph ;
vector < VL > rgraph ;
string component ;
VL visited ;
VL topsort ;
map < char,ll > mymap1 ;
map < ll,char> mymap2 ;
map < PLL,ll > existence ;
void setting(ll n) {
    graph.clear() ;
    graph.resize(n+3);
    rgraph.clear();
    rgraph.resize(n+3);
    visited.clear();
    visited.resize(n+3,0);
    topsort.clear();
    mymap1.clear() ;
    mymap2.clear();
    existence.clear();
}
void dfs1(ll node) {
    visited[node] = 1 ;
    for( ll child : graph[node]) 
        if ( !visited[child]) dfs1(child) ;
    topsort.PB(node);
}
void dfs2(ll node) {
    visited[node] = 1 ;
    component.PB(mymap2[node]);
    for( ll child : rgraph[node]) 
        if ( !visited[child]) dfs2(child) ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll cases = 0 ;
    while(1) {
        cin >> n ;
        if ( n == 0) break ;
        if(cases) cout << endl;
        setting(100);
        ll cnt = 0 ;
        INC(i,1,n) {
            char c1,c2,c3,c4,c5,u ;
            cin >> c1 >> c2 >> c3 >> c4 >> c5 >> u ;
            if ( mymap1[c1] == 0) {
                mymap1[c1] = ++cnt ;
                mymap2[cnt] = c1 ;
            }
            if ( mymap1[c2] == 0) {
                mymap1[c2] = ++cnt ;
                mymap2[cnt] = c2 ;
            }
            if ( mymap1[c3] == 0) {
                mymap1[c3] = ++cnt ;
                mymap2[cnt] = c3 ;
            }
            if ( mymap1[c4] == 0) {
                mymap1[c4] = ++cnt ;
                mymap2[cnt] = c4 ;
            }
            if ( mymap1[c5] == 0) {
                mymap1[c5] = ++cnt ;
                mymap2[cnt] = c5 ;
            }
            if ( existence[{mymap1[u],mymap1[c1]}] == 0 && u != c1) {
                graph[mymap1[u]].PB(mymap1[c1]);
                rgraph[mymap1[c1]].PB(mymap1[u]);
                existence[{mymap1[u],mymap1[c1]}] = 1 ;
            }
            if ( existence[{mymap1[u],mymap1[c2]}] == 0 && u != c2) {
                graph[mymap1[u]].PB(mymap1[c2]);
                rgraph[mymap1[c2]].PB(mymap1[u]);
                existence[{mymap1[u],mymap1[c2]}] = 1 ;
            }
            if ( existence[{mymap1[u],mymap1[c3]}] == 0 && u != c3) {
                graph[mymap1[u]].PB(mymap1[c3]);
                rgraph[mymap1[c3]].PB(mymap1[u]);
                 existence[{mymap1[u],mymap1[c3]}] = 1 ;
            }
            if ( existence[{mymap1[u],mymap1[c4]}] == 0 && u != c4) {
                graph[mymap1[u]].PB(mymap1[c4]);
                rgraph[mymap1[c4]].PB(mymap1[u]);
                existence[{mymap1[u],mymap1[c4]}] = 1 ; 
            }
            if ( existence[{mymap1[u],mymap1[c5]}] == 0 && u != c5) {
                graph[mymap1[u]].PB(mymap1[c5]);
                rgraph[mymap1[c5]].PB(mymap1[u]);
                existence[{mymap1[u],mymap1[c5]}] = 1 ;
            }
        }
        INC(i,1,cnt) {
            if ( !visited[i]) {
                dfs1(i);
            }
        } 
        reverse(topsort.begin(),topsort.end());
        visited.clear();
        visited.resize(cnt+3,0);
        vector <string > result ;
        INC(i,0,topsort.size()-1) {
            if ( !visited[topsort[i]]) {
                dfs2(topsort[i]);
                sort(component.begin(),component.end());
                result.PB(component);
                component.clear();
            }
        }
        sort(result.begin(),result.end());
        INC(i,0,result.size()-1) {
            if ( result[i].size() > 1) INC(j,0,result[i].size()-2) cout << result[i][j] << " " ;
            cout << result[i][result[i].size()-1] << endl;
        } 
        cases++ ;
    }   
 
    return 0 ;
}
