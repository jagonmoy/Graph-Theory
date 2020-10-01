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
vector < VC > grid ;
vector < VC > result ;
vector < VL > visited;
map <ll,char> mymap ;
ll n,m,k,kompabe,besipabe,vagfol,khabarcnt,chickcnt;
void setting() {
    grid.clear();
    grid.resize(n+5);
    visited.clear();
    visited.resize(n+5,VL (m+5));
    result.clear();
    result.resize(n+5);
}
void dfs(ll x, ll y) {
    if ( x < 0 || x > n || y < 0 || y > m || visited[x][y]) return ;
    visited[x][y] = 1 ;
    if ( grid[x][y] == 'R') {
        khabarcnt++ ;
        if ( kompabe != 0 && khabarcnt == vagfol) {
             kompabe-- ;
             khabarcnt = 0 ;
             result[x][y] = mymap[chickcnt];
             chickcnt++ ;
        }
        else if ( kompabe == 0 && besipabe != 0 && khabarcnt == vagfol+1) {
            besipabe-- ;
            khabarcnt = 0 ;
            result[x][y] = mymap[chickcnt];
            chickcnt++ ;
        }
        else result[x][y] = mymap[chickcnt];
    }
    else {
        if (kompabe == 0 && besipabe == 0 ) result[x][y] = mymap[chickcnt-1];
        else result[x][y] = mymap[chickcnt];
    }
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
    return  ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll charcnt = 0;
    for ( char c = 'a' ; c <= 'z' ; c++) {
        mymap[++charcnt] = c ;
    }
    for ( char c = 'A' ; c <= 'Z' ; c++) {
        mymap[++charcnt] = c ;
    }
    for ( char c = '0' ; c <= '9' ; c++) {
        mymap[++charcnt] = c ;
    }
    ll t ;
    cin >> t ;
    while(t--) {
        cin >> n >> m >> k ;
        setting();
        n-- ;
        m-- ;
        ll khabar = 0 ;
        INC(i,0,n) {
            string s ;
            cin >> s ;
            INC(j,0,m) {
                if ( s[j] == 'R') khabar++ ;
                grid[i].PB(s[j]);
                result[i].PB('+');
            }
        }
        vagfol = khabar/k ;
        besipabe = khabar%k ;
        kompabe = k-besipabe;
        khabarcnt = 0 ;
        chickcnt = 1 ;
        dfs(0,0);   
        INC(i,0,n) {
            INC(j,0,m) {
                cout << result[i][j];
            }
            cout << endl;
        }
    }
 
    return 0 ;
}
