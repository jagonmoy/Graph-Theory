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
char graph[105][105];
ll visited[105][105];
ll n  ;
ll m  ;
ll csize ;

void dfs( ll x, ll y) {
    if ( x < 0 || x == n || y < 0 || y == m || visited[x][y]  || graph[x][y] == 'L') return ;
    visited[x][y] = 1 ;
    csize++ ;
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x+1,y+1);
    dfs(x-1,y-1);
    dfs(x+1,y-1);
    dfs(x-1,y+1);
    visited[x][y] = 2 ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    scanf("%lld",&t);
    getchar (); getchar ();
    bool blank = false;
    while(t--) {
          char s[1000] ;
          n = m = 0 ;
          if ( blank ) printf ("\n"); blank = true;
          while(gets(s) && strlen(s) > 0) {
               if ( s[0] == 'W' || s[0] == 'L') {
                    strcpy(graph[n],s);
                    n++ ;
                    m = strlen(s); 
               }
               else {  
                  ll r,c ;
                  memset(visited,0,sizeof(visited)); 
                  sscanf(s,"%lld %lld",&r,&c);
                  csize = 0 ;
                  dfs(r-1,c-1);
                  printf("%lld\n",csize); 
               }
          }
    }
    
 
    return 0 ;
}
