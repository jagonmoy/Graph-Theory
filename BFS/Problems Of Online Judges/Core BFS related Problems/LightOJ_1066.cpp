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
ll n,total ;
char grid[15][15];
char targetletter ;
ll visited[15][15],dis[15][15];
ll dirx[] = {1,0,-1,0};
ll diry[] = {0,1,0,-1};
bool valid(ll x, ll y) {
    if ( x < 0 || x > n || y < 0 || y > n || visited[x][y] || grid[x][y] == '#' || (grid[x][y] >= 'A' && grid[x][y] <= 'Z' && grid[x][y] != targetletter)) return false ;
    else return true ;
}
bool bfs(ll sourcex, ll sourcey , ll destx , ll desty) {
    memset(visited,0,sizeof(visited));
    memset(dis,0,sizeof(dis));
    visited[sourcex][sourcey] = 1 ;
    QLL q ;
    q.push({sourcex,sourcey});
    while(!q.empty()) {
        PLL node = q.front();
        q.pop();
        INC(i,0,3) {
            if (valid(node.F+dirx[i],node.S+diry[i])) {
                visited[node.F+dirx[i]][node.S+diry[i]] = 1 ;
                dis[node.F+dirx[i]][node.S+diry[i]] = dis[node.F][node.S]+1 ;
                q.push({node.F+dirx[i],node.S+diry[i]});
            }
        }    
    }
    total += dis[destx][desty];
    return dis[destx][desty];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        n-- ;
        INC(i,0,n) scanf("%s",grid[i]);
        vector < pair <char,PLL> > v ;
        INC(i,0,n) {
            INC(j,0,n) {
                if ( grid[i][j] != '.' && grid[i][j] != '#') v.PB({grid[i][j],{i,j}});
            }
        }
        sort(v.begin(),v.end());
        if (v.size() > 1) {
            bool fact = true ;
            total = 0 ;
            grid[v[0].S.F][v[0].S.S] = '.' ;
            INC(i,0,v.size()-2) {
                targetletter = v[i+1].F ;
                if(!bfs(v[i].S.F,v[i].S.S,v[i+1].S.F,v[i+1].S.S)) {
                    fact = false ;
                    break ;
                }
                else grid[v[i+1].S.F][v[i+1].S.S] = '.' ;
            }
            if (fact) printf("Case %lld: %lld\n",++c,total);
            else printf("Case %lld: Impossible\n",++c);
        }
        else printf("Case %lld: 0\n",++c);    
    }

    return 0 ;
}
