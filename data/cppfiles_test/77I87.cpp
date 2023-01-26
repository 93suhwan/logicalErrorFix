#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define sp ' '

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

inline void fileim(bool usaco,bool cs,bool cs2,char *s,char *s2)
{
   if(usaco)
    {
        #define fin cin
        #define fout cout
    }
   if(cs){freopen( s, "r", stdin );}
   if(cs2){freopen( s2, "w", stdout );}
}

const ll MOD=1e9+7;
const double EPS=1e-11;

ll power(ll x, ll y)
{
   if (y == 0)
    return 1;
   else if (y % 2 == 0)
    return ((power(x, y / 2)%MOD) * (power(x, y / 2)%MOD))%MOD;
    else
    return (x * (power(x, y / 2)%MOD) * (power(x, y / 2)%MOD))%MOD;
}

struct cell{bool N,E,S,W;};
ll t=1,n,m,var=0;
bool vs[2000][2000];
cell a[2000][2000];

void FF(int x,int y)
{
    if(vs[x][y]){return ;}
    vs[x][y]=true;var++;
    if( ! a[x][y].N ){FF(x-1,y);}
    if( ! a[x][y].E ){FF(x,y+1);}
    if( ! a[x][y].S ){FF(x+1,y);}
    if( ! a[x][y].W ){FF(x,y-1);}
}

void solve()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x;cin>>x;
            a[i][j].N=( 8 & x );a[i][j].E=( 4 & x );
            a[i][j].S=( 2 & x );a[i][j].W=( 1 & x );
        }
    }
    vector<int>ans;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(!vs[i][j])
            {
                var=0;FF(i,j);
                ans.push_back(var);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans){cout<<i<<sp;}
}

int main()
{
    ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);//cin>>t;
    //fileim( 0,0,1, "timeline.in","timeline.out" );
    cout<< fixed << setprecision(15) ;
    while(t--){solve();}return 0;
}
