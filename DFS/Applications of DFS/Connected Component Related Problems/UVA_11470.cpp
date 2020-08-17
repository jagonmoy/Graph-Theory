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
vector < VL > visited ;
vector < VL > adj ;
ll n ;
ll sum ;
ll f ;
ll  checkpoint1x,checkpoint1y,checkpoint2x ,checkpoint2y ,checkpoint3x ,checkpoint3y  ;

void dfs(ll x, ll y) {
    if ( visited[x][y] ) return ;
    sum += adj[x][y];
    visited[x][y] = 1  ;
    if ( f == 1 && x == checkpoint1x && y == checkpoint1y) f = 2 ;
    else if ( f == 2 && x == checkpoint2x && y == checkpoint2y) f = 3 ;
    else if ( f == 3 && x == checkpoint3x && y == checkpoint3y) f = 4 ;

    if ( f == 1 && x == checkpoint1x && y < checkpoint1y) dfs(x,y+1);
    else if ( f == 2 && y == checkpoint2y && x < checkpoint2x) dfs(x+1,y);
    else if ( f == 3 && x == checkpoint3x && y > checkpoint3y) dfs(x,y-1);
    else if ( f == 4) dfs(x-1,y);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll c  = 0 ;
    while(1) {
        scanf("%lld",&n);
        if ( n == 0) break ;
        ll mid ;
        if ( n % 2 == 1) mid = n/2+1 ;
        else mid = n/2 ;
        visited.resize(n+2,VL (n+2,0));
        adj.resize(n+2,VL (n+2,0));

        INC(i,0,n-1) {
            INC(j,0,n-1) {
                scanf("%lld",&adj[i][j]);
            }
        }

        printf("Case %lld:",++c);
        INC(i,0,mid-1) {
            sum = 0 ;
            f = 1 ;
            checkpoint1x = i ;
            checkpoint1y = (n-1)-i ;
            checkpoint2x = (n-1)-i ;
            checkpoint2y = (n-1)-i ;
            checkpoint3x = (n-1)-i;
            checkpoint3y = i ;
            dfs(i,i);
            printf(" %lld",sum);
        }
        printf("\n");
        adj.clear();
        visited.clear();
    }
 
    return 0 ;
}
