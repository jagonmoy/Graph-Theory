// It's a 6 dimensional BFS Problem .

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
char grid[12][12];
ll dis[12][12][12][12][12][12];
ll dirX[] = {1,0,0,-1};
ll dirY[] = {0,-1,1,0};
map <ll,PLL> dest;
ll n ;

pair<bool,pair<PLL,pair<PLL,PLL> > > valid(ll oneX,ll oneY,ll twoX,ll twoY,ll threeX,ll threeY, ll dirnature) {
    ll dir1,dir2,dir3 ;
    dir1 = dir2 = dir3 = 1;
    if ( oneX < 0 || oneX > n || oneY < 0 || oneY > n || grid[oneX][oneY] == '#' ) {
        oneX -= dirX[dirnature];
        oneY -= dirY[dirnature];
        dir1 = 0 ;
    }
    PLL node1 = {oneX,oneY};
    if ( twoX < 0 || twoX > n || twoY < 0 || twoY > n || grid[twoX][twoY] == '#' ) {
        twoX -= dirX[dirnature];
        twoY -= dirY[dirnature];
        dir2 = 0 ;
    }
    PLL node2 = {twoX,twoY};
    if ( threeX < 0 || threeX > n || threeY < 0 || threeY > n || grid[threeX][threeY] == '#' ) {
        threeX -= dirX[dirnature];
        threeY -= dirY[dirnature];
        dir3 = 0 ;
    }
    PLL node3 = {threeX,threeY};

    if ( node1 == node2) {
        if ( dir1 == 1) {
            oneX -= dirX[dirnature];
            oneY -= dirY[dirnature];
            dir1 = 0 ;
            node1 = {oneX,oneY};
            if (node1 == node3) {
                threeX -= dirX[dirnature];
                threeY -= dirY[dirnature];
                dir3 = 0 ;
                node3 = {threeX,threeY};
            }
        }
        else if ( dir2 == 1) {
            twoX -= dirX[dirnature];
            twoY -= dirY[dirnature];
            dir2 = 0 ;
            node2 = {twoX,twoY};
            if ( node2 == node3) {
                threeX -= dirX[dirnature];
                threeY -= dirY[dirnature];
                dir3 = 0 ;
                node3 = {threeX,threeY};
            }
        }
    }
    else if ( node2 == node3) {
        if ( dir2 == 1) {
            twoX -= dirX[dirnature];
            twoY -= dirY[dirnature];
            dir2 = 0 ;
            node2 = {twoX,twoY};
            if ( node2 == node1) {
                oneX -= dirX[dirnature];
                oneY -= dirY[dirnature];
                dir1 = 0 ;
                node1 = {oneX,oneY};
            }
        }
        else if ( dir3 == 1) {
            threeX -= dirX[dirnature];
            threeY -= dirY[dirnature];
            dir3 = 0 ;
            node3 = {threeX,threeY};
            if ( node3 == node1) {
                oneX -= dirX[dirnature];
                oneY -= dirY[dirnature];
                dir1 = 0 ;
                node1 = {oneX,oneY};
            }
        }
    }
    else if ( node1 == node3) {
        if ( dir1 == 1) {
            oneX -= dirX[dirnature];
            oneY -= dirY[dirnature];
            dir1 = 0 ;
            node1 = {oneX,oneY};
            if ( node1 == node2) {
                twoX -= dirX[dirnature];
                twoY -= dirY[dirnature];
                dir2 = 0 ;
                node2 = {twoX,twoY};
            }
        }
        else if ( dir3 == 1) {
            threeX -= dirX[dirnature];
            threeY -= dirY[dirnature];
            dir3 = 0 ;
            node3 = {threeX,threeY};
            if ( node3 == node2) {
                twoX -= dirX[dirnature];
                twoY -= dirY[dirnature];
                dir2 = 0 ;
                node2 = {twoX,twoY};
            }
        }
    }

    if ( ( dir1+dir2+dir3 == 0)|| dis[oneX][oneY][twoX][twoY][threeX][threeY] != inf ) return {false,{{-1,-1},{{-1,-1},{-1,-1}}}};
    else  return {true,{{oneX,oneY},{{twoX,twoY},{threeX,threeY}}}};
    
}

ll bfs(ll oneX,ll oneY,ll twoX,ll twoY,ll threeX,ll threeY) {

    INC(h,0,n)
       INC(i,0,n)
           INC(j,0,n)
               INC(k,0,n)
                   INC(l,0,n)
                      INC(m,0,n)
                          dis[h][i][j][k][l][m] = inf ;

    dis[oneX][oneY][twoX][twoY][threeX][threeY] = 0 ;

    queue < pair<PLL,pair<PLL,PLL> > > q ;

    q.push({{oneX,oneY},{{twoX,twoY},{threeX,threeY}}});

    while(!q.empty()) {
        pair<PLL,pair<PLL,PLL>> node = q.front();
        q.pop();

        ll aX,aY,bX,bY,cX,cY ;
        aX = node.F.F ;
        aY = node.F.S ;
        bX = node.S.F.F;
        bY = node.S.F.S;
        cX = node.S.S.F;
        cY = node.S.S.S;

        INC(i,0,3) {

            pair<bool,pair<PLL,pair<PLL,PLL> > > newAns = valid(aX+dirX[i],aY+dirY[i],bX+dirX[i],bY+dirY[i],cX+dirX[i],cY+dirY[i],i); 

            if ( newAns.F == true ) {

                ll newaX = newAns.S.F.F ;
                ll newaY = newAns.S.F.S ;
                ll newbX = newAns.S.S.F.F;
                ll newbY = newAns.S.S.F.S;
                ll newcX = newAns.S.S.S.F;
                ll newcY = newAns.S.S.S.S;
                
                dis[newaX][newaY][newbX][newbY][newcX][newcY] = dis[aX][aY][bX][bY][cX][cY]+1 ;

                q.push({{newaX,newaY},{{newbX,newbY},{newcX,newcY}}});
            }
        }
    }
    return min(min(dis[dest[1].F][dest[1].S][dest[2].F][dest[2].S][dest[3].F][dest[3].S],

        dis[dest[1].F][dest[1].S][dest[3].F][dest[3].S][dest[2].F][dest[2].S]),

        min(min(dis[dest[2].F][dest[2].S][dest[1].F][dest[1].S][dest[3].F][dest[3].S],

        dis[dest[2].F][dest[2].S][dest[3].F][dest[3].S][dest[1].F][dest[1].S]),

        min(dis[dest[3].F][dest[3].S][dest[1].F][dest[1].S][dest[2].F][dest[2].S],

        dis[dest[3].F][dest[3].S][dest[2].F][dest[2].S][dest[1].F][dest[1].S])));
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,caseno = 0 ;
    scanf("%lld",&t);
    while(t--) {
        dest.clear();
        scanf("%lld",&n);
        n-- ;
        INC(i,0,n) scanf("%s",grid[i]);
        ll oneX,oneY,twoX,twoY,threeX,threeY ;
        ll cnt = 0 ;
        INC(i,0,n) {
            INC(j,0,n) {
                if ( grid[i][j] == 'A') {
                    oneX = i ;
                    oneY = j ;
                }
                else if ( grid[i][j] == 'B') {
                    twoX = i ;
                    twoY = j ;
                }
                else if ( grid[i][j] == 'C') {
                    threeX = i ;
                    threeY = j ;
                }
                else if ( grid[i][j] == 'X') {
                    dest[++cnt] = {i,j};
                }
            }
        }


        ll res =  bfs(oneX,oneY,twoX,twoY,threeX,threeY);
        if ( res == inf) printf("Case %lld: trapped\n",++caseno);
        else printf("Case %lld: %lld\n",++caseno,res);
    }
 
    return 0 ;
}
