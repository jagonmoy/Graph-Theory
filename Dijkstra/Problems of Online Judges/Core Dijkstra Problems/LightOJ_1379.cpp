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
ll vertices,edges;
vector < VLL > graph ;
vector < VLL > reversegraph ;
map < PLL,ll > edgelist ;
VL dist1,dist2;
void setting() {
    edgelist.clear();
    graph.clear();
    graph.resize(vertices+5);
    reversegraph.clear();
    reversegraph.resize(vertices+5);
    dist1.clear();
    dist1.resize(vertices+5,inf);
    dist2.clear();
    dist2.resize(vertices+5,inf);
}
void dijkstra1(ll source) {
    dist1[source] = 0 ;
    priority_queue < PLL , vector < PLL > , greater <PLL> > q ;
    q.push({dist1[source],source});
    while(!q.empty()) {
        PLL jura = q.top();
        ll parentnode = jura.S ;
        q.pop();
        for ( PLL child : graph[parentnode]) {
            ll childnode = child.F ;
            ll edgeweight = child.S ;
            if ( dist1[parentnode] + edgeweight < dist1[childnode]) {
                dist1[childnode] = dist1[parentnode] + edgeweight ;
                q.push({dist1[childnode],childnode});
            }
        }
    }
}
void dijkstra2(ll source) {
    dist2[source] = 0 ;
    priority_queue < PLL , vector < PLL > , greater <PLL> > q ;
    q.push({dist2[source],source});
    while(!q.empty()) {
        PLL jura = q.top();
        ll parentnode = jura.S ;
        q.pop();
        for ( PLL child : reversegraph[parentnode]) {
            ll childnode = child.F ;
            ll edgeweight = child.S ;
            if ( dist2[parentnode] + edgeweight < dist2[childnode]) {
                dist2[childnode] = dist2[parentnode] + edgeweight ;
                q.push({dist2[childnode],childnode});
            }
        }
    }
}
ll findingmaxedge(ll range) {
    ll ans = -1 ;
    for ( auto it = edgelist.begin() ; it != edgelist.end() ; it++) {
         ll firstnode = (it->first).F ;
         ll secondnode = (it->first).S;
         ll weight = it->second ;
         ll sum = 0 ;
         ll cnt = 0 ;
         if (dist1[firstnode] != inf) {
             cnt++ ;
             sum += dist1[firstnode];
         }
         if (dist2[secondnode] != inf) {
             cnt++ ;
             sum += dist2[secondnode];
         }
         if ( cnt == 2) {
             if ( sum + weight <= range) ans = max(ans,weight);
         }
    }
    return ans ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,caseno = 0 ;
    scanf("%lld",&t);
    while(t--) {
        ll source,destination,range ;
        scanf("%lld %lld %lld %lld %lld",&vertices,&edges,&source,&destination,&range);
        setting();
        INC(i,1,edges) {
            ll node1,node2,weight ;
            scanf("%lld %lld %lld",&node1,&node2,&weight);
            graph[node1].PB({node2,weight});
            reversegraph[node2].PB({node1,weight});
            edgelist[{node1,node2}] = weight ;
        }
        dijkstra1(source);
        dijkstra2(destination);
        printf("Case %lld: %lld\n",++caseno,findingmaxedge(range));
    }

    return 0 ;
}
