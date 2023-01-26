#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long mod = 998244353;
int l[maxn];
int r[maxn];
long long dp[60][maxn];
long long cnt[maxn];
long long sum[maxn];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (int k = 1; k <= m; k++) {
    int top = m / k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      int tl = (l[i] + k - 1) / k;
      int tr = r[i] / k;
      sum[0] = dp[i - 1][0];
      for (int j = 1; j <= top; j++) {
        sum[j] = sum[j - 1] + dp[i - 1][j];
        sum[j] %= mod;
        dp[i - 1][j] = 0;
      }
      for (int j = tl; j <= top; j++) {
        dp[i][j] += sum[j - tl] - ((j - tr - 1 < 0) ? 0 : sum[j - tr - 1]);
        dp[i][j] %= mod;
      }
    }
    for (int i = 1; i <= top; i++) {
      cnt[k] += dp[n][i];
      dp[n][i] = 0;
      cnt[k] %= mod;
    }
  }
  for (int i = m; i > 0; i--) {
    for (int j = 2; i * j <= m; j++) {
      cnt[i] -= cnt[i * j];
      cnt[i] += mod;
      cnt[i] %= mod;
    }
  }
  cout << cnt[1] << endl;
  return 0;
}
