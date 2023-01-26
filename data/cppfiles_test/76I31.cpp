// -----------------------om_patel--------------------------------//
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F(i,a,b) for(i=a;i<b;i++)
#define RF(i,b,a) for(i=b;i>=a;i--)
#define NL cout<<"\n";
#define SP cout<<" ";
#define PR(x) cout<<x;
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define endl "\n"

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long int ll;
typedef long double ld;
const ll mod=1e9+7;
bool comp(ll a,ll b)
{     
   return a<b;
}
ll spow(ll a,ll b)
{
  ll res=1;
  while(b>0)
  {
     if(b&1)
     {
        res=(res*a)%mod;
     }
     a=(a*a)%mod;
     b=b>>1;
  }
  return res;
}

// segmented sieve return prime number between l to r

vector<ll> sieve(ll l,ll r)
{
  bool isPrime[r - l + 1];
  for(ll i=0;i<=r;i++)
  isPrime[i]=true;
  vector<ll>v;
  for (ll i = 2; i * i <= r; ++i) {
    for (ll j = max(i * i, (l + (i - 1)) / i  * i); j <= r; j += i) {
        isPrime[j - l] = false;
    }
}

  for (ll i = max((int)l, 2); i <= r; ++i) {
    if (isPrime[i - l]) {
        //then i is prime
        v.push_back(i);
    }
    
    }
    return v;
  
}

int Eul_Toi(int n)
{
  bool a[n+1];
  for(int i=0;i<=n;i++)
    a[i]=true;
  a[0]=false;
  a[1]=false;

  for(int i=2;i*i<=n;i++)
  {
     if(a[i])
     {
    for(int j=i*i;j<=n;j+=i)
       a[j]=false;
     }
  }
  float pro=n;
  for(int i=2;i<=n;i++)
  {
     if(a[i]==true && n%i==0)
    {
           pro=pro*(1-1/(float)i);
    }
  }
  return ((int)ceil(pro));
}



void solve()
{
   ll n,m;
   cin>>n>>m;
   
   ll dp[n+1]={0};
   dp[1]=1;
   
   ll pre=dp[1];
   for(ll i=2;i<=n;i++)
   {
       dp[i]+=pre;
       ll k=i;
       for(ll j=2;j<=k;j++)
       {
           dp[i]+=dp[k/j];
       }
       
       pre+=dp[i];
   }
   
   cout<<dp[n]%m<<endl;
   
}

signed main(void)
{
   fast;
   ll t=1;
//   cin>>t;
   while(t--)
   {
    solve();
   }
    
}
