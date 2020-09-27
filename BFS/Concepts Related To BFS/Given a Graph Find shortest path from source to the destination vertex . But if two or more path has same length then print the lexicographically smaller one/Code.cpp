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
vector < VL > graph ;
VL dis,parent ;
void setting(ll vertex) {
    graph.clear();
    graph.resize(vertex+5);
    parent.resize(vertex+5,-1);
    dis.resize(vertex+5,-1);   
}
void bfs(ll source) {
    dis[source] = 0 ;
    queue < ll > q ;
    q.push(source);
    while(!q.empty()) {
        ll node = q.front();
        q.pop();
        for( ll child : graph[node]) {
            if ( dis[child] == -1) {
                dis[child] = dis[node] + 1 ;
                parent[child] = node ;
                q.push(child);
            }
        }
    }
}
VL printpath(ll souce , ll dest) {
    VL path ;
    if ( dis[dest] == -1) return path ;
    else {
        ll node = dest ;
        while(1) {
            path.PB(node);
            node = parent[node];
            if (node == -1) break;
        }
        reverse(path.begin(),path.end());
        return path ;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll vertex,edges ; 
    cin >> vertex >> edges ;
    setting(vertex);
    INC(i,1,edges) {
        ll node1,node2 ;
        cin >> node1 >> node2 ;
        graph[node1].PB(node2);
        graph[node2].PB(node1);
    }
    INC(i,1,vertex) sort(graph[i].begin(),graph[i].end());
    ll source,dest ;
    cin >> source >> dest;
    bfs(source);
    VL path = printpath(source,dest);
    if (path.size()) {
        for ( ll i : path) cout << i << " " ;
        cout << endl;
    }
    else cout << "No path Exist" << endl;

    return 0 ;
}
