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
ll n,m ;
char adj[25][25];
ll visited[25][25];
ll ccsize ;
char indicator ;

void dfs( ll i , ll j) {
    if ( j >= m) j = 0 ;
    if ( j < 0) j = m-1 ; 
    if ( i < 0 || i == n ||adj[i][j] != indicator || visited[i][j] != 0) return ;
    visited[i][j] = 1 ;
    ccsize++ ;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
    visited[i][j] = 2 ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(scanf("%lld %lld",&n,&m) == 2) {
        INC(i,0,n-1) {
            scanf("%s",adj[i]);
        }
        ll x,y ;
        scanf("%lld %lld",&x,&y);
        indicator = adj[x][y];
        memset(visited,0,sizeof(visited));
        ll maximum = 0 ;
        INC(i,0,n-1) {
            INC(j,0,m-1) {
               if ( visited[i][j] == 0 && adj[i][j] == indicator) {
                   ccsize = 0 ;
                   ll f = 0 ;
                   if ( visited[x][y] == 0) f++;
                   dfs(i,j) ;
                   if ( visited[x][y] == 2) f++ ; 
                   if ( f != 2) maximum = max(maximum,ccsize);
               }    
            }    
        }
        printf("%lld\n",maximum);
    }
    return 0 ;
}
