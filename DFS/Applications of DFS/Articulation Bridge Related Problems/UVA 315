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
vector < VL > graph;
ll dfsRoot;
ll rootChildren = 0;
ll t = 1;
VL in;
VL low;
VL parent;
VL visited;
SL cutvertices ;
void DFS(int u)
{
    visited[u] = 1 ;
    in[u] = low[u] = t++;
    for ( ll v : graph[u] )
    {
        if (visited[v] == 0)
        {
            parent[v] = u;
            if (u == dfsRoot)
                ++rootChildren;
            DFS(v);
            if (u != dfsRoot && low[v] >= in[u])
                cutvertices.insert(u);

            low[u] = min(low[u],low[v]);
        }
        else if (v != parent[u]) 
            low[u] = min(low[u],in[v]); 
    }
}

int main()
{  
    int N;
    while (cin >> N, N != 0)
    {
        cin.ignore();

        graph.clear();
        graph.resize(N + 5);
        in.clear();
        in.resize(N + 5,0);
        low.clear();
        low.resize(N + 5,0);
        parent.clear();
        parent.resize(N + 1,-1);
        visited.clear();
        visited.resize(N+5,0);
        cutvertices.clear();
        string s;
        while (getline(cin, s), s != "0")
        {
            stringstream ss(s);
            int u, v;
            ss >> u;
            while (ss >> v)
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        for (int p = 1; p < graph.size(); ++p)
        {
            if (!visited[p])
            {
                dfsRoot = p;
                rootChildren = 0;
                DFS(p);
                if (rootChildren > 1)
                    cutvertices.insert(p);
            }
        }
        cout << cutvertices.size() << endl;
    }
    return 0;
}
