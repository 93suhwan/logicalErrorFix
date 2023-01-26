#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 2e5 + 5, LG = log2(N) + 1, MOD = 1e9 + 7;
const double PI = acos(-1);
int n;
ll a[100005];
ll sum[100005];
ll dp[450][100005];
void doWork() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    for (int j = 1; j < 450; j++) {
      dp[i][j] = 0;
    }
  }
  int ans = 1;
  for (int i = n; i >= 1; --i) {
    dp[i + 1][0] = 1000000000000000;
    for (int k = 1; i + k * (k + 1) / 2 <= n + 1; k++) {
      dp[i][k] = dp[i + 1][k];
      ll tot = sum[i + k - 1] - sum[i - 1];
      if (tot < dp[i + k][k - 1]) {
        ans = max(ans, k);
        dp[i][k] = max(dp[i][k], tot);
      }
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    doWork();
  }
  return 0;
}
