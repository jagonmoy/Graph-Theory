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
ll vertices,edges ;
vector < VLL > graph ;
vector < VL > dist ;

void setting() {
    graph.clear();
    graph.resize(vertices+5);
    dist.clear();
    dist.resize(4,VL (vertices+5,inf));
}
ll dijkstra(ll source) {
    dist[1][source] = 0 ;
    priority_queue < pair <ll,PLL> , vector <pair <ll,PLL>> , greater <pair <ll,PLL>> > q ;
    q.push({1,{dist[1][source],source}});
    while(!q.empty()) {
        pair <ll,PLL> t = q.top();
        ll currentnode = t.S.S ;
        ll currenttype = t.F ;
        ll currentdist = t.S.F;
        q.pop();
        for ( PLL couple : graph[currentnode]) {
            ll currentchild = couple.F ;
            ll edgeweight = couple.S ;
            if ( currentdist + edgeweight < dist[1][currentchild] ) {
                ll temp = dist[1][currentchild] ;
                dist[1][currentchild] = currentdist + edgeweight ;
                dist[2][currentchild] = temp ;
                q.push({1,{dist[1][currentchild],currentchild}});
                if ( temp != inf ) q.push({2,{dist[2][currentchild],currentchild}});
            }
            else if ( currentdist + edgeweight > dist[1][currentchild] && currentdist + edgeweight < dist[2][currentchild] ) {
                dist[2][currentchild] = currentdist + edgeweight ;
                q.push({2,{dist[2][currentchild],currentchild}});
            }
        }
    }
    return dist[2][vertices];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,caseno = 0 ;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld %lld",&vertices,&edges);
        setting();
        INC(i,1,edges) {
            ll node1,node2,weight ;
            scanf("%lld %lld %lld",&node1,&node2,&weight);
            graph[node1].PB({node2,weight});
            graph[node2].PB({node1,weight});
        }
        ll res = dijkstra(1);
        if ( res == inf ) res = -1 ;
        printf("Case %lld: %lld\n",++caseno,res);
    }

    return 0 ;
}
