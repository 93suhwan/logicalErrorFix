#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef int ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define pii pair<ll,ll>
#define inf 1000000000000000000
#define bpc(x) __builtin_popcountll(x)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define autoitr(x,it) for(auto it = x.rbegin(); it != x.rend(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)
#define hmap gp_hash_table<ll, ll>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

const ll N = 5005;
ll lcp[N][N];
string s;

ll get(pii &a, pii &b)
{
    ll l1 = a.ss-a.ff+1, l2 = b.ss-b.ff+1;
    ll comm = min({l1, l2, lcp[min(a.ff,b.ff)][max(a.ff,b.ff)]});
    if(comm == l1 && comm == l2)
        return -1;
    if(comm == l1)
        return 1;
    if(comm == l2)
        return 0;
    return s[a.ff + comm] < s[b.ff + comm];    
}

bool comp(pii &a, pii &b)
{
    return get(a,b) > 0;
}

void upd(ll i, ll n, ll ft[], ll val)
{
    if(i<0)
        return;
    if(i>=n)
        return;
    i++;
    while(i<=n)
    {
        ft[i] = max(ft[i],val);
        i+=(i&(-i));
    }
}

ll sum(ll i, ll ft[])
{
    if(i<0)
        return 0;
    i++;
    ll ans = 0;
    while(i>0)
    {
        ans = max(ans, ft[i]);
        i-=(i&(-i));
    }
    return ans;
}

int main()
{
  FAST/**/
  
  ll t;
  cin>>t;
  
  while(t--)
  {
      ll n;
      cin>>n;
      cin>>s;
      rep(n+2)
            for(ll j=i;j<n+2;j++)
                lcp[i][j] = 0;
      
      for(ll fst=n-1;fst>-1;fst--)
            for(ll sec=n-1;sec>=fst;sec--)
            {
                if(fst == sec)
                    lcp[fst][sec] = n-fst+1;
                else if(s[fst] != s[sec])
                    lcp[fst][sec] = 0;
                else lcp[fst][sec] = 1 + lcp[fst+1][sec+1];
            }
      vector<pii> v;
      rep(n)
            for(ll j=i;j<n;j++)
                v.pb({i,j});
      ll siz = v.size();
      ll ft[n+2];
      memset(ft,0,sizeof(ft));
      sort(v.begin(), v.end(), comp);
      ll dp[siz];
      ll ptr = n;
      ll ans = 1;
      for(ll i=n-1;i>-1;i--)
      {
          while(ptr-1>i && get(v[i],v[ptr-1]) == 1)
          {
              ptr--;
              ll val = dp[ptr];
              upd(n-(v[ptr].ff+1), n, ft, val);
          }
          dp[i] = sum(n-v[i].ff-1, ft) + 1;
          ans = max(ans, dp[i]);
      }
      cout<<ans<<"\n";
                  
  }
    
  return 0;
}
   
   
 