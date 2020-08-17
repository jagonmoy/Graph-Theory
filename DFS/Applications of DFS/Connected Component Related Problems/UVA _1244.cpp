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
vector < vector <char> > adj ;
vector < vector < ll > > visited;
ll n,m,cnt ;
bool myfunc( PCL x , PCL y) {
    if ( x.S > y.S || (x.S == y.S && x.F < y.F)) return true ;
    else return false ;
}
void dfs( ll x , ll y) {
    if ( x < 0 || x == n || y < 0 || y == m || visited[x][y] || adj[x][y] != '*') return ;
    visited[x][y] = 1 ;
    cnt++ ;
    dfs(x,y+1);
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x+1,y+1);
    dfs(x+1,y-1);
    dfs(x-1,y+1);
    dfs(x-1,y-1);
    visited[x][y] = 2 ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll c = 0 ;
    while(1) {
        scanf("%lld %lld",&n,&m);
        if ( n == 0 && m == 0) break ;
        adj.resize(n+4,vector<char>(m+5));
        visited.resize(n+4,vector<ll> (m+5,0));
        INC(i,0,n-1) {
            getchar();
            INC(j,0,m-1) {
                char c ;
                scanf("%c",&c);
                adj[i][j] = c;
            }
        }
        ll total = 0 ;
        INC(i,0,n-1) {
            INC(j,0,m-1) {
                 if ( !visited[i][j] && adj[i][j] == '*') {
                     cnt = 0 ;
                     dfs(i,j);
                     if ( cnt == 1) total++ ;
                 }
            }
        }
        printf("%lld\n",total);
        adj.clear();
        visited.clear();
    }
    
    return 0 ;
}
