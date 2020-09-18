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
char grid[12][12];
ll visited[12][12];
ll jumpcount[12][12];
ll ridercount[12][12];
ll dirx[] = {1,1,2,2,-1,-1,-2,-2};
ll diry[] = {2,-2,1,-1,2,-2,1,-1};
bool valid(ll x , ll y) {
    if ( x < 0 || x > n || y < 0 || y > m || visited[x][y]) return false ;
    else return true ;
}

void bfs(ll x, ll y , ll capa) {
    memset(visited,0,sizeof(visited));
    visited[x][y] = 1 ;
    queue < pair < PLL,ll> > q ;
    q.push({{x,y},0});
    while(!q.empty()) {
        pair < PLL,ll > node = q.front();
        q.pop();
        INC(i,0,7) {
            ll childx = node.F.F+dirx[i];
            ll childy = node.F.S+diry[i];
            if (valid(childx,childy)) {
                ridercount[childx][childy]++ ;
                visited[childx][childy] = 1 ;
                jumpcount[childx][childy] += ceil((node.S+1+0.0)/(capa+0.0));
                q.push({{childx,childy},node.S+1});
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
        memset(jumpcount,0,sizeof(jumpcount));
        memset(ridercount,0,sizeof(ridercount));
        INC(i,0,n) scanf("%s",grid[i]);
        vector < pair<PLL,ll> > riderpoint;
        INC(i,0,n) {
            INC(j,0,m) {
                if ( grid[i][j] >= '1' && grid[i][j] <= '9') {
                    ridercount[i][j] = 1 ;
                    ll num = grid[i][j]-'0' ;
                    riderpoint.PB({{i,j},num});
                }    
            }
        }
        if ( riderpoint.size()) {
            INC(i,0,riderpoint.size()-1) bfs(riderpoint[i].F.F,riderpoint[i].F.S, riderpoint[i].S);
        }
        ll minimumstep = inf ;
        INC(i,0,n) {
            INC(j,0,m) {
                if (ridercount[i][j] == riderpoint.size()) minimumstep = min(minimumstep,jumpcount[i][j]);
            }
        }
        if ( minimumstep == inf) minimumstep = -1 ;
        printf("Case %lld: %lld\n",++c,minimumstep);
    }   
 
    return 0 ;
}
