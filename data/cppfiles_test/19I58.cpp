#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii    pair<int,int>
#define iii   pair<int,ii>
#define fi    first
#define se    second 
#define pb    push_back
#define mp    make_pair
#define trash trash
#define ALL(x) x.begin(),x.end()
const int oo=1e9;
const int Mod=998244353;
const long long OO=1e18;
const int N=1e4 + 5;
///////////////////1112<3/////////////////
int n, a[N], dp[N][2005], ans;
void solve()
{
  cin >> n;
  int maxx = 0;
  for(int i=1; i<=n; i++)cin >> a[i], maxx = max(maxx, a[i]);
  for(int i=0; i<=n; i++)
  for(int j=0; j<=2*maxx; j++)dp[i][j] = oo;
  dp[0][0] = 0;
  for(int i=0; i<n; i++)
  for(int j=0; j<=maxx; j++)
  {
    if(dp[i][j] == oo)continue;
    int x = dp[i][j];
    dp[i+1][j+a[i+1]] = min(dp[i+1][j+a[i+1]], max(j+a[i+1],x));
    if(j - a[i+1] >= 0)dp[i+1][j-a[i+1]] = min(dp[i+1][j-a[i+1]], x);
    else dp[i+1][0] = min(dp[i+1][0], x + a[i+1] - j);
  }
  int ans = oo;
  for(int j=0; j<=2*maxx; j++)ans = min(ans, dp[n][j]), cerr<<j<<" "<<dp[n][j]<<'\n';
  cout << ans<<'\n';
}
///////////////////1112<3/////////////////
void file()
{
  if(fopen("trash.inp", "r"))
      freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
    // else freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
}
main()
{
  file();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test; cin >> test;
  while(test--)
  {
    solve();
  }
}