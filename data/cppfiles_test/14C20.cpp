#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 1;
const long long MOD = 998244353;
long long POW(long long base, long long exponent) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % mod;
    exponent = exponent >> 1;
    base = (base * base) % mod;
  }
  return result;
}
long long Inv(long long x) { return POW(x, mod - 2); }
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> a[i];
    vector<vector<int> > df(n + 1, vector<int>(n + 2, 0)),
        dp(n + 1, vector<int>(n + 1, 0)), mx(n + 1, vector<int>(n + 1, 0));
    for (int diff = 0; diff < n; diff++) {
      for (int i = n; i >= 0; i--) {
        if (i - a[i] == diff)
          df[diff][i] = df[diff][i + 1] + 1;
        else
          df[diff][i] = df[diff][i + 1];
      }
    }
    for (int i = 1; i < n + 1; i++) dp[0][i] = df[0][1], mx[0][i] = df[0][1];
    for (int i = 1; i < n + 1; i++)
      dp[1][i] = df[1][i + 1] + df[0][1] - df[0][i],
      mx[1][i] = max(mx[1][i - 1], dp[1][i]);
    for (int mov = 2; mov < n; mov++) {
      for (int i = 1; i < n + 1; i++) {
        dp[mov][i] = df[mov][i + 1] - df[mov - 1][i];
        dp[mov][i] += mx[mov - 1][i - 1];
        mx[mov][i] = dp[mov][i];
        mx[mov][i] = max(mx[mov][i], mx[mov][i - 1]);
      }
    }
    if (df[0][1] >= k) {
      cout << 0 << '\n';
      continue;
    }
    int ans = -1;
    for (int i = 1; i < n; i++) {
      int f = 0;
      for (int j = 1; j < n + 1; j++) {
        if (dp[i][j] >= k) {
          f = 1;
          break;
        }
      }
      if (f) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
