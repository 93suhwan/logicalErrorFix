#include <bits/stdc++.h>
using namespace std;
long long solve();
vector<long long> a;
string s;
long long n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
void in(vector<long long> &a, long long n) {
  long long i = 0, x;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back({x});
  }
}
long long dp[500 + 1][500 + 1];
long long Power(long long val, long long p) {
  if (p == 0) return 1;
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * val) % 998244353;
    val = (val * val) % 998244353;
    p = p >> 1;
  }
  return ans;
}
long long solve() {
  a.clear();
  s.clear();
  long long i = 0, j = 0, k = 0;
  long long flag = 0;
  long long x = 0, y = 0, z = 0;
  cin >> n;
  cin >> x;
  memset(dp, 0, sizeof(dp));
  long long comb[n + 1][n + 1];
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        comb[i][j] = 1;
        continue;
      }
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % 998244353;
    }
  }
  for (i = 2; i <= n; i++) {
    for (j = 1; j < i; j++) {
      dp[i][j] = Power(j, i);
    }
  }
  long long val;
  long long p;
  for (i = 2; i <= n; i++) {
    for (j = i; j <= x; j++) {
      p = 1;
      dp[i][j] = 0;
      for (k = 0; k <= i - 2; k++) {
        val = (comb[i][k] * dp[i - k][j - i + 1]) % 998244353;
        val = (val * p) % 998244353;
        dp[i][j] = (dp[i][j] + val) % 998244353;
        p = (p * (i - 1)) % 998244353;
      }
      p = (p * (i - 1)) % 998244353;
      dp[i][j] = (dp[i][j] + p) % 998244353;
    }
  }
  cout << dp[n][x] << endl;
  return 0;
}
