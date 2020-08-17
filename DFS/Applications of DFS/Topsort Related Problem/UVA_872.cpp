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
VC characters ;
vector < VL > graph ;
VL visited ;
MCL m ;
ll f ;
bool valid( ll c) {
    if ( graph[c].size() > 0) {
        INC(i,0,graph[c].size()-1) {
            if ( visited[graph[c][i]]) return false ;
        }
    }
    return true ;
}

void dfs(VC res) {
    if ( res.size() == characters.size()) {
        if ( res.size() > 1) INC(i,0,res.size()-2) printf("%c ",res[i]);
        printf("%c\n",res[res.size()-1]);
        f = 1 ;
    }
    else {
        INC(i,0,characters.size()-1) {
            if ( !visited[i] && valid(m[characters[i]])) {
                visited[i] = 1 ;
                res.PB(characters[i]);
                dfs(res);
                res.erase(res.end()-1);
                visited[i] = 0 ;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char str[500];
    ll t ;
    scanf("%lld",&t);
    getchar();
    while(t--) {
        getchar();
        gets(str);
        ll d = strlen(str);
        INC(i,0,d-1) if ( str[i] != ' ') characters.PB(str[i]);
        ll sz = characters.size() ;
        sort(characters.begin(),characters.end());
        INC(i,0,sz-1) m[characters[i]] = i ;
        gets(str);
        graph.resize(sz+5) ;
        visited.resize(sz+5);
        d = strlen(str);
        INC(i,1,d-2) {
            if ( str[i] == '<') {
                graph[m[str[i-1]]].PB(m[str[i+1]]);
            }
        }
        f = 0 ;
        VC res ;
        dfs(res);
        if (!f) printf("NO\n");
        if(t) printf("\n");   
        characters.clear() ;
        graph.clear() ;
        visited.clear();
        m.clear() ;
    }
 
    return 0 ;
}
