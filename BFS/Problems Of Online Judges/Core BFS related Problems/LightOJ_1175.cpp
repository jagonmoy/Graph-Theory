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
char grid[205][205];
ll visited[205][205];
ll disFire[205][205];
ll disjane[205][205];
ll dirx[] = {1,0,0,-1};
ll diry[] = {0,1,-1,0};
bool validfire(ll x, ll y, ll val) {
    if ( x < 0 || x > n || y < 0 || y > m || visited[x][y] || grid[x][y] == 'F' || grid[x][y] == '#'|| disFire[x][y] <= val+1 ) return false ;
    else return true ; 
}
bool validjane(ll x, ll y) {
    if ( x < 0 || x > n || y < 0 || y > m || visited[x][y] || grid[x][y] == '#' ) return false ;
    else return true ; 
}

void setting() {
   INC(i,0,204) {
       INC(j,0,204) {
           disFire[i][j] = inf ;
       }
   }
   INC(i,0,204) {
       INC(j,0,204) {
           disjane[i][j] = inf ;
       }
   }
}
void bfsfire( ll x, ll y) {
    memset(visited,0,sizeof(visited));
    visited[x][y] = 1 ;
    queue < pair<PLL,ll> > q ;
    disFire[x][y] = 0 ;
    q.push({{x,y},0});
    while(!q.empty()) {
        pair<PLL,ll> node = q.front();
        q.pop();
        INC(i,0,3) {
            if ( validfire(node.F.F+dirx[i],node.F.S+diry[i],node.S)) {
                disFire[node.F.F+dirx[i]][node.F.S+diry[i]] = node.S+1 ;
                visited[node.F.F+dirx[i]][node.F.S+diry[i]] = 1 ;
                q.push({{node.F.F+dirx[i] ,node.F.S+diry[i] } ,node.S+1});
            }
        }
    }
}
void bfsjane(ll x, ll y) {
    memset(visited,0,sizeof(visited));
    visited[x][y] = 1 ;
    queue < pair<PLL,ll> > q ;
    disjane[x][y] = 0 ;
    q.push({{x,y},0});
    while(!q.empty()) {
        pair<PLL,ll> node = q.front();
        q.pop();
        INC(i,0,3) {
            if ( validjane(node.F.F+dirx[i],node.F.S+diry[i])) {
                disjane[node.F.F+dirx[i]][node.F.S+diry[i]] = node.S + 1 ;
                visited[node.F.F+dirx[i]][node.F.S+diry[i]] = 1 ;
                q.push({{node.F.F+dirx[i],node.F.S+diry[i]},node.S+1});
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
        setting();
        n-- , m-- ;
        INC(i,0,n) scanf("%s",grid[i]);
        ll janex , janey ;
        VLL firestation;
        INC(i,0,n) {
            INC(j,0,m) {
                if ( grid[i][j] == 'F') firestation.PB({i,j});
                else if ( grid[i][j] == 'J') janex = i , janey = j ;   
            }
        }
        if ( firestation.size()) INC(i,0,firestation.size()-1) bfsfire(firestation[i].F,firestation[i].S);
        bfsjane(janex,janey);

        ll minimumescape = inf ;

        INC(i,0,m) if ( disjane[0][i] != inf && (disjane[0][i] < disFire[0][i])) minimumescape = min(minimumescape,disjane[0][i]);
        INC(i,0,m) if ( disjane[n][i] != inf && (disjane[n][i] < disFire[n][i])) minimumescape = min(minimumescape,disjane[n][i]);
        INC(i,0,n) if ( disjane[i][0] != inf && (disjane[i][0] < disFire[i][0])) minimumescape = min(minimumescape,disjane[i][0]);
        INC(i,0,n) if ( disjane[i][m] != inf && (disjane[i][m] < disFire[i][m])) minimumescape = min(minimumescape,disjane[i][m]);

        if ( minimumescape == inf) printf("Case %lld: IMPOSSIBLE\n",++c);
        else printf("Case %lld: %lld\n",++c,minimumescape+1);
    }
    return 0 ;
}
