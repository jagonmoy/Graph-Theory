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
ll dirx[] = {0, 0, 1, 0, 0, -1};
ll diry[] = {0, 1, 0, 0, -1, 0};
ll dirz[] = {1, 0, 0, -1, 0, 0};
ll visited[30][30][30];
ll dis[30][30][30];

void setting() {
    memset(visited,0,sizeof(visited));
    memset(dis,0,sizeof(dis));
}
ll bfs(string source, string dest) {

    visited[source[0]-'a'][source[1]-'a'][source[2]-'a'] = 1 ;

    queue < pair<ll,PLL> > q ;

    q.push({source[0]-'a',{source[1]-'a',source[2]-'a'}});

    while(!q.empty()) {
        pair < ll,PLL > node = q.front();
        q.pop();
        INC(i,0,5) {
            ll x,y,z ;
            x = (node.F+dirx[i])%26 ;
            y = (node.S.F+diry[i])%26 ;
            z = (node.S.S+dirz[i])%26 ;
            if ( x < 0) x += 26 ;
            if ( y < 0) y += 26 ;
            if ( z < 0) z += 26 ;
            if (!visited[x][y][z]) {
                visited[x][y][z] = 1 ;
                dis[x][y][z] = dis[node.F][node.S.F][node.S.S]+1;
                q.push({x,{y,z}});
            }
        }  
    }
    if ( source != dest && dis[dest[0]-'a'][dest[1]-'a'][dest[2]-'a'] == 0) return -1 ;
    else return dis[dest[0]-'a'][dest[1]-'a'][dest[2]-'a'] ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    cin >> t ;
    while(t--) {
        ll restriction ;
        string source,dest ;
        INC(i,1,2) {
            if ( i == 1) cin >> source ;
            else cin >> dest ;
        }
        cin >> restriction ;
        setting();
        while(restriction--) {
            string x,y,z ;
            cin >> x >> y >> z ;
            INC(l,0,x.size()-1) {
                INC(m,0,y.size()-1) {
                    INC(n,0,z.size()-1) {
                        visited[x[l]-'a'][y[m]-'a'][z[n]-'a'] = 1 ;  
                    }
                }
            }
        }
        if ( visited[source[0]-'a'][source[1]-'a'][source[2]-'a'] == 1)  cout << "Case " << ++c << ": -1"<< endl;
        else {
            ll minstep = bfs(source,dest);
            cout << "Case " << ++c << ": " << minstep << endl;
        }
    }
 
 
    return 0 ;
}
