#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 1e2 + 10;
vi g[N];
int ncr[N][N];

void solve()
{
   int n,k;
   cin >> n >> k;
    
   int u,v;
    
   f(i,n-1)
   {
       cin >> u >> v;
       g[u].pb(v);
       g[v].pb(u);
   }
    
   int res = 0;
    
   if(k == 2)
   {
       res = (n*(n-1))/2;
       res %= MOD;
   }
   else 
   {
       for(int i=1;i<=n;i++)
       {
           vector<int> dis(n+1,-1);
           vector<int> fre(n+1,0);
           
           dis[i] = 0;
           fre[0] = 1;
           
           queue<int> q;
           q.push(i);
           
           while(!q.empty())
           {
               auto z = q.front(); q.pop();
               
               for(auto x : g[z])
               {
                   if(dis[x] == -1)
                   {
                       dis[x] = dis[z] + 1;
                       fre[dis[x]]++;
                       q.push(x);
                   }
               }
           }
           
           for(int i=1;i<=n;i++) res += ncr[fre[i]][k];
       }
   }
   
   cout << res << '\n'; 
    
   for(int i=1;i<=n;i++) g[i].clear(); 
}

signed main()
{
    for(int i=0;i<N;i++)
    {
        ncr[i][0] = 1;
        
        for(int j=1;j<=i;j++)
        {
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%MOD;
        }
    }
        
    
    fast;
    
    int t = 1;
    
    cin >> t;
    
    while(t--)
        
    solve();
}
