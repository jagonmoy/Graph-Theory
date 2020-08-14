

Explanation :
-------------------------------------------------------------------------
A very Good Problem to understand Topic Like Strongly Connected Component , Longest Path in Unweighted Directed Acyclic Graph .
So the Prerequisite for this Problem is :
DFS,Strongly Connected Component , Longest Path in a Unweighted Directed Acyclic Graph ( using DFS and DP ) 

if we simplify the Problem than Then the Question is Actually , A directed Graph is Given We need to find an index From where highest number of Vertices can be visited .
If there is more than one possible answer (There are More than one vertex from where highest Number of vertex can be visited) then we need to pick the vertex which has lower id.

Now, See the Graph can contain Cycles and The graph can also be disconnected . There are various Possiblites . Therefore first we need to find the Strongly Connected Components
of Graph . Because we know in a Strongly Connected Component we can travel from any vertex to another . For every Strongly Connected Component we will give them an Index ,
we will store the size of that Strongly Component and the minimum vertex which is presented in that SCC . Bcause in Question there is a point if There are multiple Possible 
answer we need to find the vertex has less id . 
Here by dfs1 function we will topsort the vertices and then according to the Sorting we will run dfs2 and execute the above steps .

Now we will minimise the Graph That means we will create a new graph where we will treat one SCC as one vertex . to create this SCCgraph we will run dfs3 function .
in this function whenever we find two adjacent vertex which has different SCC number we will create and edge between those two SCC . But to create and Edge first we will
check if there is an edge presented already which was created earlier .

now , we need to find a path from SCC graph which contain maximum number of vertices . 
to find this we will run DFS and use dynamic Programming for Memoraisation .
For this we will first initialize a dpSCC array with the capacity of each SCC . Which indicates intially How many Number of vertex can be visited From Each SCC . Now we
will dun dfs4 function in SCCgraph . Whenever an Adjacent vertex (child) of a parent vertex (node) is not visited we will send him in dfs4 function and if it is visited than we will
add it's dpSCC value to the dpSCC value of parent vertex . 
from this Above method using DFS and DP we can find the final dpSCC value of all the vertices .


Now the final Step , here we will simply run a loop check which SCC has maximum dpSCC value and if there are multiple SCC who has same maximum dpSCC value then we will take that
SCC who has a vertex which id is minimum .

If we summarise the above steps
1. Find SCC's of the graph .
2. Create a SCC graph .
3. Run a DFS on SCC graph and with help of DP find from which SCC highest number of vertex can be visited .


---------------------------------------------------
code :
---------------------------------------------------
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
vector < VL > graph,rgraph ;
vector < VL > SCCgraph ;
MLL SCCcapacity ;
map < PLL,ll > SCCconnectivity ;
VL visited,topsort,StrongComponent,HeadofComponent,visitedSCC,dpSCC ;
ll SCC,head,totalEmail ;
void setting(ll n) {
    graph.clear();
    graph.resize(n+3);
    rgraph.clear();
    rgraph.resize(n+3);
    visited.clear();
    visited.resize(n+3,0);
    topsort.clear();
    StrongComponent.clear();
    StrongComponent.resize(n+3,0);
    HeadofComponent.clear();
    HeadofComponent.resize(n+3,0);
    SCCcapacity.clear();
    SCCconnectivity.clear();
}
void dfs1(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
        if (!visited[child]) dfs1(child);
    }
    topsort.PB(node);
}
void dfs2(ll node) {
    visited[node] = 1 ;
    StrongComponent[node] = SCC ;
    SCCcapacity[SCC]++ ;
    head = min(head,node);
    for ( ll child : rgraph[node]) {
        if (!visited[child]) dfs2(child);
    }
}
void dfs3(ll node) {
    visited[node] = 1 ;
    for ( ll child : graph[node]) {
        if ( StrongComponent[node] != StrongComponent[child] && SCCconnectivity[{StrongComponent[node],StrongComponent[child]}] == 0) {
                SCCgraph[StrongComponent[node]].PB(StrongComponent[child]);
                SCCconnectivity[{StrongComponent[node],StrongComponent[child]}] = 1 ;
        }
        if ( !visited[child]) {
            dfs3(child);
        }
    }
}
void dfs4(ll node) {
     visitedSCC[node] = 1 ;
     for ( ll child : SCCgraph[node]) {
        if (!visitedSCC[child]) dfs4(child);
        dpSCC[node] = max(dpSCC[node],dpSCC[node]+dpSCC[child]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,c = 0 ;
    cin >> t ;
    while(t--) {
        ll n ;
        cin >> n  ;
        setting(n) ;

        INC(i,1,n) {
            ll node1,node2 ;
            cin >> node1 >> node2 ;
            graph[node1].PB(node2);
            rgraph[node2].PB(node1);
        }
        INC(i,1,n) {
            if ( !visited[i]) {
                dfs1(i);
            }
        }

        visited.clear();
        visited.resize(n+3,0);
        reverse(topsort.begin(),topsort.end());
        SCC = 0 ;
        INC(i,0,topsort.size()-1) {
            if (!visited[topsort[i]]) {
                ++SCC ;
                head = inf ;
                dfs2(topsort[i]);
                HeadofComponent[SCC] = head ;
            }
        }
     
        visited.clear();
        visited.resize(n+3,0);
        SCCgraph.clear();
        SCCgraph.resize(SCC+2);
        INC(i,1,n) {
            if (!visited[i]) {
                dfs3(i);
            }
        }
    
        visitedSCC.clear();
        visitedSCC.resize(SCC+2,0);
        dpSCC.clear();
        dpSCC.resize(SCC+2,0);
        INC(i,1,SCC) dpSCC[i] = SCCcapacity[i];   
        INC(i,1,SCC) {
            if (!visitedSCC[i]) {
                dfs4(i);
            }
        }

        ll maximumEmail = neginf ;
        ll maximumemailindex = inf ;
        INC(i,1,SCC) {
            if ( dpSCC[i] > maximumEmail) {
                maximumEmail = dpSCC[i];
                maximumemailindex = HeadofComponent[i];
            }
            else if ( dpSCC[i] == maximumEmail && HeadofComponent[i] < maximumemailindex) {
                maximumEmail = dpSCC[i];
                maximumemailindex = HeadofComponent[i];
            }
        }
        cout << "Case " << ++c << ": " << maximumemailindex << endl;   

    }
 
    return 0 ;
}
