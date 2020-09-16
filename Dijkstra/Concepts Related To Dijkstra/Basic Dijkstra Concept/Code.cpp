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
VL dis,parent ;
vector < VL > graphedge,graphcost ;
ll vertex,edges ;
void setting() {
    dis.clear();
    parent.clear();
    graphedge.clear();
    graphcost.clear();
    graphedge.resize(vertex+5);
    graphcost.resize(vertex+5);
    dis.resize(vertex+5,inf);
    parent.resize(vertex+5,-1);
}
void dijkstra(ll source) {
    dis[source] = 0 ;
    parent[source] = source;
    priority_queue < PLL , vector<PLL> , greater <PLL> > pq ;
    pq.push({dis[source],source});
    while(!pq.empty()) {
        PLL node = pq.top();
        pq.pop();
        if ( graphedge[node.S].size()) {
            INC(i,0,graphedge[node.S].size()-1) {
                ll child = graphedge[node.S][i];
                ll edgecost = graphcost[node.S][i];
                if ( edgecost+dis[node.S] < dis[child]) {
                    dis[child] = edgecost+dis[node.S];
                    parent[child] = node.S ;
                    pq.push(make_pair(dis[child],child));
                }
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> vertex >> edges;
    ll node1,node2,weight;
    setting();
    INC(i,1,edges) {
        cin >> node1 >> node2 >> weight;
        graphedge[node1].push_back(node2);
        graphcost[node1].push_back(weight);
        graphedge[node2].push_back(node1);
        graphcost[node2].push_back(weight);
    }

   cout << "Source Vertex : " << endl;
   ll source ;
   cin >> source;
   dijkstra(source);
   cout << "VERTEX\tCOST\tPARENT" << endl;
   INC(i,1,vertex) cout << i << " \t" << dis[i] << "\t" << parent[i] << endl ;
   cout << endl;
   return 0 ;
}
