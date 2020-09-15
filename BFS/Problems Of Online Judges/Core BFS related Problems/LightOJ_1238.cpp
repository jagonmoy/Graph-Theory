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

ll n,m ;
char grid[25][25];
ll visited[25][25],dis[25][25] ;
ll dirx[] = {1,0,-1,0} ;
ll diry[] = {0,1,0,-1} ;

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
bool valid(ll x , ll y) {
    if ( x < 0 || x > n || y < 0 || y > m || visited[x][y] || grid[x][y] == '#' || grid[x][y] == 'm') return false;
    else return true ;
}
void bfs(ll x , ll y) {
    visited[x][y] = 1 ;
    QLL q ;
    q.push({x,y});
    while(!q.empty()) {
        PLL node = q.front();
        q.pop();
        INC(i,0,3) {
            ll childx = node.F + dirx[i];
            ll childy = node.S + diry[i];
            if ( valid(childx,childy) ) {
                visited[childx][childy] = 1 ;
                dis[childx][childy] = dis[node.F][node.S]+1 ;
                q.push({childx,childy});
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld %lld",&n,&m);
        n-- , m-- ;
        INC(i,0,n) scanf("%s",grid[i]);
        VLL girls;
        ll destx,desty ;
        INC(i,0,n) {
            INC(j,0,m) {
                if ( grid[i][j] == 'a' || grid[i][j] == 'b' || grid[i][j] == 'c'  ) girls.PB({i,j});
                if ( grid[i][j] == 'h') {
                    destx = i ;
                    desty = j ;
                }
            }
        }
        ll maximum = -1 ;
        INC(i,0,girls.size()-1) {
            memset(visited,0,sizeof(visited));
            memset(dis,0,sizeof(dis));
            bfs(girls[i].F,girls[i].S);
            maximum = max(maximum,dis[destx][desty]);
        }
        printf("Case %lld: %lld\n",++c,maximum);
    }

    return 0 ;
}
