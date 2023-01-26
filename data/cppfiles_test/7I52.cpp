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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

ll get(char c, string s)
{
    string s1 = s;
    s1+=c;
    ll n = s.length();
    for(ll taken=n;taken>0;taken--)
    {
        if(s.substr(0, taken) == s1.substr(n+1-taken))
                return taken;
    }
    return 0;
}

int main()
{
  FAST/**/
  
  ll n,m;
  cin>>n>>m;
  
  string a,s;
  cin>>a>>s;
  
  ll pre[m+1];
  memset(pre,0,sizeof(pre));
  
  for(ll len=1;len<m;len++)
  {
      string s1 = s.substr(0,len);
      if(s[len] == '1')
            s1+='0';
      else s1+='1'; 
      ll len1 = s1.length();
      for(ll taken=len1-1;taken>0;taken--)
      {
          if(s1.substr(len1-taken) == s.substr(0,taken))
          {
              pre[len] = taken;
              break;
          }
      }
  }
  
  ll c0 = get('0', s);
  ll c1 = get('1', s);
  
  ll dp[n+3][m+3][n+3];
  rep(n+3)
        repi(j,m+3)
            repi(k,n+3)
                dp[i][j][k] = inf;
  dp[0][0][0] = 0;
  for(ll i=0;i<n;i++)
  {
      for(ll longest=0;longest<=m;longest++)
      {
          for(ll occ=0;occ<=n;occ++)
          {
              //decide s[i], take from i
              if(longest < m)
              {
                  ll smoves, dmoves;
                  if(a[i] == s[longest])
                  {
                      smoves = 0;
                      dmoves = 1;
                  }
                  else 
                  {
                      smoves = 1;
                      dmoves = 0;
                  }
                  //make it same
                  dp[i+1][longest+1][occ+(longest+1 == m)] = min(dp[i+1][longest+1][occ+(longest+1 == m)], dp[i][longest][occ] + smoves);
                  
                  //make them different
                  dp[i+1][pre[longest]][occ] = min(dp[i+1][pre[longest]][occ], dp[i][longest][occ] + dmoves);
              }
              
              else
              {
                  ll zeroes = (a[i] != '0');
                  ll ones = (a[i] != '1');
                  
                  //make it zero
                  dp[i+1][c0][occ + (c0 == m)] = min(dp[i+1][c0][occ + (c0 == m)], dp[i][longest][occ] + zeroes);
                  
                  //make it one
                  dp[i+1][c1][occ + (c1 == m)] = min(dp[i+1][c1][occ + (c1 == m)], dp[i][longest][occ] + ones);
              }
          }
      }
  }
  ll ans[n+2-m];
  rep(n+2-m)
        ans[i] = inf;
  for(ll len=0;len<=m;len++)
  {
      for(ll occ=0;occ<=n;occ++)
      {
          ans[occ] = min(ans[occ], dp[n][len][occ]);
      }
  }
  rep(n+2-m)
  {
      if(ans[i] == inf)
            ans[i] = -1;
      cout<<ans[i]<<" ";        
  }
  
  
  return 0;
}
   
   
 