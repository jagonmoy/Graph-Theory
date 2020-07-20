Explanation : first we did topsort to know the dependancy of vertices .then we just ran simple DFS accorfing to the index of topsort to know how many DFS we will have to run .

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

VL graph[10005] ;
ll state[10005] ;

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
VL topsort ;
void dependant_switch(ll u , ll vertex) {
   state[u] = GREY ;
   if ( graph[u].size() != 0 ) {
       INC(i,0,graph[u].size()-1) {
           ll v = graph[u][i];
           if ( state[v] == WHITE) dependant_switch(v,vertex);
      }
   }
   state[u] = BLACK ;
   topsort.PB(u);
}

void dfs( ll vertex) {
    INC(i,1,vertex) state[i] = WHITE ;
    INC (i,1,vertex) if (state[i] == WHITE) dependant_switch(i,vertex);
    return ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    scanf("%lld",&t);
    while(t--) {
        ll n,m ;
        scanf("%lld %lld",&n,&m);
        INC(i,0,10004)graph[i].clear() ;
        memset(state,0,sizeof(state));
        while(m--) {
            ll node1,node2 ;
            scanf("%lld %lld",&node1,&node2);
            graph[node1].PB(node2);
        }
        dfs(n);
        reverse(topsort.begin(),topsort.end());
        ll cnt = 0 ;
        memset(state,0,sizeof(state));
        INC(i,0,topsort.size()-1) if ( state[topsort[i]] == WHITE) {
            dependant_switch(topsort[i],n);
            cnt++ ;
        }
        printf ("Case %lld: %lld\n", ++c,cnt);
        topsort.clear();
    }

    return 0 ;
}
