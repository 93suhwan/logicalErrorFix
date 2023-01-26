#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 1, maxa = 600;
long long a[maxn], dp[maxn][maxa];
const long long inf = 1e9;
void solve() {
  long long n;
  cin >> n;
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  for (long long i = (0); i <= (n); i++)
    for (long long j = (1); j < (maxa); j++) dp[i][j] = inf;
  for (long long i = (1); i <= (n); i++) dp[i][0] = -1;
  for (long long i = (1); i <= (n); i++) {
    dp[i][a[i]] = min(dp[i][a[i]], a[i]);
    for (long long j = (0); j < (maxa); j++)
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
    for (long long j = (0); j < (maxa); j++)
      if (dp[i - 1][j] < a[i]) dp[i][j ^ a[i]] = min(dp[i][j ^ a[i]], a[i]);
  }
  vector<long long> ans;
  for (long long x = (0); x < (maxa); x++)
    if (dp[n][x] != inf) ans.push_back(x);
  for (auto x : ans) cout << x << " ";
  cout << '\n';
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long T;
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
