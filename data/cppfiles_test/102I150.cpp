// It's better to do something rather than complaining 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define modi 1000000007 
#define test int abc; cin>>abc; while(abc--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long
#define int long long
#define ll long long
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define yes "YES\n"
#define no "NO\n"
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define endl "\n"
#define ld long double
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
inline void debugMode() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}
int fact[200005];

// void calFact()
// {
//     fact[0]=1;
//     fact[1]=1;
//     fact[2]=1;
//     for(int i=3;i<200005;i++)
//     {
//         fact[i]=(i*fact[i-1])%modi;
//     }
// }


void solve()
{
    int n,m;
    cin>>n>>m;
    int x=0,y=0;
    string s; 
    cin>>s;
    int xp=0,yp=0;
    for(auto i:s)
    {
        if(i=='R')
        {
            yp++;
        }
        else if(i=='D')
        {
            xp++;
        }
        else if(i=='L')
        {
            if(yp-1 <0)
            {
                y++;
            }
            else
            {
                yp--;
            }
        }
        else
        {
            if(xp-1 <0)
            {
                x++;
            }
            else
            {
                xp--;
            }
        }
    }
    cout<<x+1<<" "<<y+1<<endl; 
}
 
int32_t main(){
    debugMode();
    // calFact();
    test
    solve();
    return 0;
}