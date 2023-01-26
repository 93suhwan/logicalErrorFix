#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
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

void build(ll st[], ll arr[], ll l, ll r, ll i)
{
    if(l == r)
    {
        st[i] = arr[l];
        return;
    }
    
    ll mid = (l+r)/2;
    build(st, arr, l, mid, 2*i+1);
    build(st, arr, mid+1, r, 2*i+2);
    
    st[i] = st[2*i+1] + st[2*i+2];
}

ll quemax(ll st[], ll l, ll r, ll l1, ll r1, ll i)
{
    if(l>r1 || l1>r)
        return -inf;
    if(l>=l1 && r<=r1)
        return st[i];
    ll mid = (l+r)/2;
    
    return max(quemax(st,l,mid,l1,r1,2*i+1),quemax(st,mid+1,r,l1,r1,2*i+2));
}

ll quemin(ll st[], ll l, ll r, ll l1, ll r1, ll i)
{
    if(l>r1 || l1>r)
        return inf;
    if(l>=l1 && r<=r1)
        return st[i];
    ll mid = (l+r)/2;
    
    return min(quemin(st,l,mid,l1,r1,2*i+1),quemin(st,mid+1,r,l1,r1,2*i+2));
}
 
void updmax(ll st[], ll l, ll r, ll l1, ll i, ll val)
{
    if(l>l1||r<l1)
        return;
    if(l == r)
    {
        st[i] = val;
        return;
    }
    
    ll mid = (l+r)/2;
    updmax(st,l,mid,l1,2*i+1,val);
    updmax(st,mid+1,r,l1,2*i+2,val);
    
    st[i] = max(st[2*i+1], st[2*i+2]);
}

void updmin(ll st[], ll l, ll r, ll l1, ll i, ll val)
{
    if(l>l1||r<l1)
        return;
    if(l == r)
    {
        st[i] = val;
        return;
    }
    
    ll mid = (l+r)/2;
    updmin(st,l,mid,l1,2*i+1,val);
    updmin(st,mid+1,r,l1,2*i+2,val);
    
    st[i] = min(st[2*i+1], st[2*i+2]);
}


int main()
{
  FAST/**/
  
  ll n,k;
  cin>>n>>k;
  
  ll arr[n], arr1[n];
  rep(n)
        cin>>arr[i];
  rep(n)
        cin>>arr1[i];
  rep(n)
        arr[i] = arr[i] - arr1[i];
  ll pref[n+1];
  pref[0] = 0;
  for(ll i=1;i<=n;i++)
        pref[i] = pref[i-1] - arr[i-1];
  
  ll ht = ceil(log2(n));
  ht = (1ll<<(ht + 1)) - 1;
  ll stmax[ht], stmin[ht];
  rep(ht)
        stmax[i] = -inf, stmin[i] = inf;
  rep(n)
        updmin(stmin, 0, n-1, i, 0, pref[i]);
  rep(n)
        updmax(stmax, 0, n-1, i, 0, abs(pref[i+1]));
  while(k--)
  {
      ll l,r;
      cin>>l>>r;
      l--, r--;
      ll sm = pref[r+1];
      sm -= pref[l];
      if(sm != 0)
      {
          cout<<-1<<'\n';
          continue;
      }
      
      ll tmp = quemin(stmin, 0, n-1, l, r, 0);
      if(tmp - pref[l])
      {
          cout<<-1<<'\n';
          continue;
      }
      
      ll val = quemax(stmax, 0, n-1, l, r, 0);
      cout<<val<<'\n';
  }
  
  
  return 0;
}
   
   
 