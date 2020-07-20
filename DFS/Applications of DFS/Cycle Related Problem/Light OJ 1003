
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
#define WHITE 0
#define GREY 1
#define BLACK 2

VL graph[20005] ;
ll state[20005] ;

ll f = 0 ;

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

void detecting_cycle(ll u , ll vertex) {
   state[u] = GREY ;
   if ( graph[u].size() != 0 ) {
       INC(i,0,graph[u].size()-1) {
           ll v = graph[u][i];
           if (state[v] == GREY ) f = 1 ;
           if ( state[v] == WHITE) detecting_cycle(v,vertex);
      }
   }
   state[u] = BLACK ;
   return ;
}

void dfs( ll vertex) {
    INC(i,1,vertex) state[i] = WHITE ;
    INC (i,1,vertex) if (state[i] == WHITE) detecting_cycle(i,vertex);
    return ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
     cin >> t ;
    while(t--) {
        ll m ;
        cin >> m ;
        map < string,ll > mymap ;
        f = 0 ;
        INC(i,0,20004)graph[i].clear() ;
        memset(state,0,sizeof(state));
        ll cnt = 0 ;
        while(m--) {
            string s1,s2 ;
            cin >> s1 >> s2 ;
            if ( mymap[s1] == 0) mymap[s1] = ++cnt ;
            if ( mymap[s2] == 0) mymap[s2] = ++cnt ;
            graph[mymap[s1]].PB(mymap[s2]);
        }
        
        dfs(mymap.size());
        if ( f == 0) cout << "Case " << ++c << ": Yes" << endl;
        else cout << "Case " << ++c << ": No" << endl;
    }

    return 0 ;
}
