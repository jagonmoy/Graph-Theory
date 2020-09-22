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
VL happinesspoint,peoplepoint,visited,goodpeople ;
bool fact ;

void setting(ll n) {
    happinesspoint.clear();
    peoplepoint.clear();
    graph.clear();
    happinesspoint.resize(n+5,0);
    peoplepoint.resize(n+5,0);
    graph.resize(n+5);
    visited.clear();
    visited.resize(n+5,0);
    goodpeople.clear();
    goodpeople.resize(n+5,0);
}
ll dfs1(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
        if (!visited[child]) {
           peoplepoint[node] += dfs1(child);
        }
    }
    return peoplepoint[node]; 
}
bool No_of__good_people_in_each_node(ll nodes) {
     ll cnt = 0 ;
     INC(i,1,nodes) {
         ll val = peoplepoint[i] - happinesspoint[i];
         if ( val >= 0 && val % 2 == 0) {
             cnt++ ;
             goodpeople[i] = peoplepoint[i] - val/2 ;
         }
     }
     if ( cnt == nodes) return true ;
     else return false ;
}
void dfs2(ll node) {
    visited[node] = 1 ;
    ll goodpeoplecount = 0 ;
    for ( ll child : graph[node]) {
        if (!visited[child]) {
            goodpeoplecount += goodpeople[child];
            dfs2(child);
        }
    }
    if ( goodpeoplecount > goodpeople[node]) fact = false ;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t ;
    cin >> t ;
    while(t--) {
        ll nodes,people ;
        cin >> nodes >> people ;
        setting(nodes);
        INC(i,1,nodes) cin >> peoplepoint[i];
        INC(i,1,nodes) cin >> happinesspoint[i];
        INC(i,1,nodes-1) {
            ll node1,node2 ;
            cin >> node1 >> node2 ;
            graph[node1].PB(node2);
            graph[node2].PB(node1);
        }
        dfs1(1);
        fact = No_of__good_people_in_each_node(nodes);
        if (!fact) cout << "NO" << endl;
        else {
            visited.clear();
            visited.resize(nodes+5,0);
            dfs2(1);
            if (fact) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }  
 
    return 0 ;
}
