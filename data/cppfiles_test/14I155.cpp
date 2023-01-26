#include <bits/stdc++.h>
using namespace std;
const double one = 1.0;
const double PI = 3.14159265;
const long long maxn = 1e5 + 10;
const long long maxx = 1e6 + 10;
const long double eps = 1e-14;
const long long max_len = 1e6 + 1;
const long long mod1 = 1000000007;
const long long mod2 = 998244353;
long long dp[2000][2000];
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> vl(n);
  for (long long i = 0; i < long long(n); i++) cin >> vl[i], vl[i]--;
  for (long long i = 0; i < long long(n); i++) {
    for (long long j = 0; j < long long(n); j++) dp[i][j] = 0;
  }
  dp[0][0] = (vl[0] == 0);
  for (long long i = 0; i < long long(n - 1); i++) {
    for (long long j = 0; j < long long(i + 1); j++) {
      dp[i + 1][j + 1] = max(dp[i][j], dp[i + 1][j + 1]);
      dp[i + 1][j] = max(dp[i][j] + (i + 1 - j == vl[i + 1]), dp[i + 1][j]);
    }
  }
  long long ans = 1000000000000000000;
  for (long long i = 0; i < long long(n); i++) {
    for (long long j = 0; j < long long(n); j++) {
      if (dp[i][j] >= k) ans = min(ans, j);
    }
  }
  if (ans >= 1000000000000000000) ans = -1;
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
