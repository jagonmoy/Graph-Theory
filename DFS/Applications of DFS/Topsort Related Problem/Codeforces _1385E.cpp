Explanation :
In this problem we first Checked if there is a cycle along with this we implement topsort algorithm . 
if there is a cycle then the answer is NO .
else We check the order of undirected edges which vertex comes first in topsortical order according to it we gave a direction .

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
#define sz 
#define WHITE 0
#define GREY 1
#define BLACK 2
ll f = 0 ;

vector < vector <ll> > graph ;
vector < ll > parent ;
vector < ll > state ;
VL topsort ;
SKL stk ;
 
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


void dfsvisit(ll u , ll vertex) {
   state[u] = GREY ;
   if ( graph[u].size() != 0 ) {
       INC(i,0,graph[u].size()-1) {
           ll v = graph[u][i];
           if ( state[v] == GREY && parent[u] != v ) f = 1 ;
           else if ( state[v] == WHITE) {
               parent[v] = u ;
               dfsvisit(v,vertex);
           }
        }
   }
   stk.P(u);
   state[u] = BLACK ;
   return ;
}

void dfs( ll vertex) {
    INC(i,1,vertex) state[i] = WHITE ;
    INC(i,1,vertex) parent[i] = -1 ;
    INC (i,1,vertex)  if (state[i] == WHITE) dfsvisit(i,vertex);
    while(!stk.empty()) {
        ll x = stk.top();
        topsort.PB(x);
        stk.pop();
    }
    return ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    while(t--) {
        f = 0 ;
        ll n,m ;
        cin >> n >> m ;
        graph = vector < vector <ll > > (n+5) ;
        parent = vector < ll > (n+5);
        state = vector < ll > (n+5) ;
        topsort.clear();
        while(stk.size() != 0) stk.pop();
        VLL edges ;
        INC(i,1,m) {
            ll t,node1,node2 ;
            cin >> t >> node1 >> node2;
            if ( t == 1) graph[node1].PB(node2);
            edges.PB({node1,node2});
        }
        dfs(n) ;
        if ( f == 1) cout << "NO" << endl;
        else {
            MLL m ;
            INC(i,0,topsort.size()-1) m[topsort[i]] = i ;
            cout << "YES" << endl;
            INC(i,0,edges.size()-1) {
                if ( m[edges[i].F] < m[edges[i].S]) cout << edges[i].F << " " << edges[i].S << endl;
                else cout << edges[i].S << " " << edges[i].F << endl;
            }
        }
    }
 
    return 0 ;
}
