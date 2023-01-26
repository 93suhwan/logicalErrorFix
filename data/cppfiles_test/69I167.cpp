#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define int long long int
#define pb push_back
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define setbits(x) __builtin_popcountll(x)
#define md (ll)1e9 + 7
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define f(i, j, n) for (ll i = j; i < n; i++)
#define r(i, j, n) for (ll i = n - 1; i >= j; i--)
int dp[20][20];
string st1, st2;
int fun(int x, int y)
{
  if (x < 0 || y < 0)
    return 0;
  if (dp[x][y] != -1)
    return dp[x][y];
  int t3 = 0;
  if (st1[x] == st2[y])
    t3 = 1 + fun(x - 1, y - 1);
  int t1 = fun(x - 1, y), t2 = fun(x, y - 1);
  return dp[x][y] = max({t1, t2, t3});
}
void solve()
{
  vll v;
  for(int i=0;i<16;i++)
    v.pb(1<<i);
  int n;
  cin>>n;
  int ans=inf;
  for(auto i : v){
    memset(dp,-1,sizeof(dp));
    st1=to_string(n);
    st2=to_string(i);
    int res=st1.length()+st2.length()-2*fun(st1.length()-1,st2.length()-1);
    
    ans=min(ans,res);
  }
  cout<<ans;
}
main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("inpput.txt", "r", stdin); //freopen("op.txt", "w", stdout);
#endif
  ll test_cases = 1;
  cin >> test_cases;
  for (ll t = 1; t <= test_cases; t++)
    solve(), cout << "\n";
  ;
  //cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
}