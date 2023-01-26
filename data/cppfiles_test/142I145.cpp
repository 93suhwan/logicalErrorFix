#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define vec vector<ll>
#define vpl vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define fio ios_base::sync_with_stdio(false)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define forv(i, n, N) for (ll i = n; i < N; i++)
#define ford(i, n, N) for (ll i = n; i >= N; i--)
#define fin cin.tie(NULL)
#define fou cout.tie(NULL)
#define mp make_pair
#define F first
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define S second
#define flush cout<<endl;
#define endl "\n"
#define all(v) v.begin(),v.end()
#define fsb(x) __builtin_ffs(x) - 1 // return index of first setbit in binary of x
#define lob(x) __builtin_clz(x)  // return the number of binary left over ie 32 - index of last set bit 
#define setbits(x) __builtin_popcount(x) // returns no of set bits ie 1s in binary of x
#define trail0(x) __builtin_ctz(x)  // returns number of trailing 0-bits of x  eg 4 of 10000
#define simsort(v) sort(v.begin(), v.end())
#define simsortd(a) sort(a.begin(),a.end(),greater<int>())
#include <ext/pb_ds/assoc_container.hpp>                                      // initialise: pbds Set ;
#include <ext/pb_ds/tree_policy.hpp>                                         // 1.) Set.order_of_key(Val) -> this gives the number of integers strictly less than Val in the Set.
using namespace __gnu_pbds;                                                 // 2.) Set.find_by_order(k-1) -> this will give the pointer to kth smallest number.
#define pbds tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>                                                                                      
#define adjm(adj,m) fo(i,m){ll u,v;cin>>u>>v;adj[u].pb(v);adj[v].pb(u);}
#define mod 1000000007

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
   cerr << ' ' << H;
   dbg_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{
    ll m,n;cin>>m>>n;
    ll joy[m][n];
    fo(i,m)fo(j,n)cin>>joy[i][j];
   

    ll l=0,r=10;

    while (l<r-1)
    {
       ll mid=(l+r)/2;
      

        ll cnt=0;
        set<ll>s;

         bool f1=1,f2=0;
        fo(i,n)
        { f1=0;
           fo(j,m)
           {
               
               if(joy[j][i]>=mid)
               {
                  f1=1;
                  if(s.find(j)!=s.end())f2=1;
                  s.insert(j);
               }
           }
           if(!f1)break;
          
        }
      // cout<<(s.size())<<' ' <<mid<<' '<<endl;
        if(f1&&f2)
        {
           l=mid;
        }
        else r=mid;

    }
    cout<<l<<endl;
    
}

int main()
{
   fio, fin, fou;
   
   ll t=1;
  cin >> t;
   
  for(ll i=1;i<=t;i++)
   {
      solve();
   }
   
}

