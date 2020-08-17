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
char adj[55][55];
ll star_checker[55][55];
ll cross_checker[55][55];
ll visited[55][55];
ll n,m ;
ll crosscheck,starcheck ;
void dfs2( ll x , ll y) {
    if ( x < 0 || x == n || y < 0 ||  y == m || visited[x][y] || adj[x][y] == '.') return ;
    visited[x][y] = 1 ;
    star_checker[x][y] = starcheck ;
    dfs2(x,y+1);
    dfs2(x+1,y);
    dfs2(x-1,y);
    dfs2(x,y-1);
    visited[x][y] = 2 ;  
}

void dfs1(ll x , ll y) {
    if ( x < 0 || x == n || y < 0 ||  y == m || visited[x][y] || adj[x][y] != 'X') return ;
    visited[x][y] = 1 ;
    cross_checker[x][y] = crosscheck ;
    dfs1(x,y+1);
    dfs1(x+1,y);
    dfs1(x-1,y);
    dfs1(x,y-1);
    visited[x][y] = 2 ;   
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll c = 0 ;
    while(1) {
        scanf("%lld %lld",&m,&n);
        if ( n == 0 && m == 0) break;
        INC(i,0,n-1) scanf("%s",adj[i]);
        memset(visited,0,sizeof(visited));
        memset(star_checker,-1,sizeof(star_checker));
        memset(cross_checker,-1,sizeof(cross_checker));
        crosscheck = 0 ;
        INC(i,0,n-1) {
            INC(j,0,m-1) {
                if ( adj[i][j] == 'X' && visited[i][j] == 0) {  
                    dfs1(i,j);
                    crosscheck++ ;
                }
            }
        }
        memset(visited,0,sizeof(visited));
        starcheck = 0 ;
        INC(i,0,n-1) {
            INC(j,0,m-1) {
                if ( adj[i][j] != '.' && visited[i][j] == 0) {  
                    dfs2(i,j);
                    starcheck++ ;
                }
            }
        }
        VL v[starcheck+5] ;
        INC(i,0,n-1) {
            INC(j,0,m-1) {
                if ( star_checker[i][j] != -1) {  
                    if ( cross_checker[i][j] != -1 ) v[star_checker[i][j]].PB(cross_checker[i][j]);
                }
            }
        }
        VL result ;
        INC(i,0,starcheck-1) {
            SL myset ;
            INC(j,0,v[i].size()-1) myset.insert(v[i][j]);
            result.PB(myset.size());
        }
        printf("Throw %lld\n",++c);
        sort(result.begin(),result.end());
        if ( result.size() > 1 ) INC(i,0,result.size()-2) printf("%lld ",result[i]);
        printf("%lld\n\n",result[result.size()-1]); 
    }
    
    return 0 ;
}
