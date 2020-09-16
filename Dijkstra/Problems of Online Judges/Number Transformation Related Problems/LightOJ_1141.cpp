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
ll source,destination ;
ll leastprime[1600];
ll dis[1600];
void setting() {
    INC(i,1,1100) dis[i] = inf ;    
}
void findingleastprime(ll n) {
    leastprime[1] = 1 ; 
    for ( ll i = 2 ; i <= n ; i = i+2 ) leastprime[i] = 2 ; 
    for ( ll i = 3 ; i <= n ; i = i+2) {
        if ( leastprime[i] == 0) {
            leastprime[i] = i ; 
            for ( ll j = i*i ; j <= n ; j = j+i ) {
                if ( leastprime[j] == 0) leastprime[j] = i ; 
            }
        }
    }
}
VL primefactoraization(ll n) {
    ll copyn = n ;
    MLL mymap ;
    VL primefactors ;
    while( n!=1) {
        primefactors.PB(leastprime[n]);
        n = n/leastprime[n];
    }
    VL onlyfactor ;
    INC(i,0,primefactors.size()-1) {
        if (primefactors[i] != copyn && !mymap[primefactors[i]]) {
            onlyfactor.PB(primefactors[i]);
            mymap[primefactors[i]] = 1 ;
        }
    }
    return onlyfactor ;
}
void dijkstra() {
    priority_queue < PLL , VLL , greater < PLL > > pq ;
    dis[source] = 0 ;
    pq.push({dis[source],source});
    while(!pq.empty()) {
        PLL node = pq.top();
        pq.pop();
        VL primefactors = primefactoraization(node.S);
        if (primefactors.size()) {
            for ( ll factor : primefactors) {
                if ( factor+node.S <= destination && dis[factor+node.S] > dis[node.S]+1) {
                    dis[factor+node.S] = dis[node.S]+1 ;
                    pq.push({dis[factor+node.S],factor+node.S});
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    scanf("%lld",&t);
    findingleastprime(1500);
    while(t--) {
        scanf("%lld %lld",&source,&destination);
        if ( source == 1) {
            if ( source == destination) printf("Case %lld: 0\n",++c);
            else printf("Case %lld: -1\n",++c);
            continue ;
        }
        setting();
        dijkstra();
        if ( dis[destination] == inf) dis[destination] = -1 ;
        printf("Case %lld: %lld\n",++c,dis[destination]);
    }
    return 0 ;
}
