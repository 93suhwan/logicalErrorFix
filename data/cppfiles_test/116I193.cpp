
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lli int
typedef long long ll;
#define rep(i,n) for(lli i = 0; i < n; i++)
#define reps(i,a,n) for(lli i = a; i < n; i++)
#define reps1(i,a,n) for(int i = a; i>=n; i--)
#define s(n) cin >> n
#define MAXN 2000010
#define MOD 998244353
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rsz(x,n) x.clear(); x.resize(n)
#define rrsz(x,a,n) x.clear(); x.resize(n,a)
#define wt while(true)
#define all(x) x.begin(),x.end()
#define pb push_back
#define pp pair
#define ff first
#define ss second
#define ls(x) ((2*(x)) + 1)
#define rs(x) ((ls(x)) + 1)
#define md(a,b) (((a) + (b))/2)
#define INF (1e9 + 7)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
vector<lli> primes;
void Sieve(lli n)
{
    vector<bool>prime(n+1,true);
    for(lli p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (lli i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (lli p=2; p<=n; p++)
       if (prime[p])
          primes.push_back(p);
}
lli add(lli a,lli b)
{
    return (((a+b)%MOD)+MOD)%MOD;
}
lli product(lli a,lli b)
{
    return (((ll)a*(ll)b%MOD)+MOD)%MOD;
}
lli f[MAXN+1],inv[MAXN+1];
lli dnc(lli bas,lli power,lli mod) {
  if(power==0)  return 1;
  if(power%2==0) {
    int res=dnc(bas,power/2,mod);
    return product(res,res);
  }
  return product(bas,dnc(bas,power-1,mod));
}
void precalc() {
  f[0] = inv[0]=1;
  for(lli temp=1;temp<=MAXN;temp++) {
    f[temp]=product(temp,f[temp-1]);
    inv[temp]=product(dnc(temp,MOD-2,MOD),inv[temp-1]);
  }
}
lli comb(lli n,lli k) {
  if(k>n || k<0) return 0;
  return 1ll*f[n]*inv[k]%MOD*inv[n-k]%MOD;
}
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)

int main()
{
  //precalc();
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    int dp[n+10][2];
    memset(dp,0,sizeof(dp));
    vector<int>a(n+1);
    rep(i,n)cin>>a[i];
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        dp[a[i]+1][0]=(dp[a[i]+1][0]+(dp[a[i]+1][0]+dp[a[i]][0]))%MOD;
        dp[a[i]+1][1]=(dp[a[i]+1][1]+dp[a[i]+1][1])%MOD;
        if(a[i])
        dp[a[i]-1][1]=(dp[a[i]-1][1]+(dp[a[i]-1][1]+dp[a[i]-1][0])%MOD)%MOD;
        if(a[i]==1&&dp[a[i]-1][1]==0)dp[a[i]-1][1]=1;
        if(a[i]==0&&dp[a[i]+1][0]==0)dp[a[i]+1][0]=1;
    }
    int ans=0;
    for(int i=0;i<=n+1;i++)ans=(ans+(dp[i][0]+dp[i][1])%MOD)%MOD;
    cout<<(ans-1+MOD)%MOD<<endl;
  }
    return 0;
}