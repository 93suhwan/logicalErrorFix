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
long long epow(long long val, long long p) {
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
  for (i = 2; i <= n; i++) {
    for (j = 1; j < i; j++) {
      dp[i][j] = epow(j, i) - epow(j - 1, i);
      if (dp[i][j] < 0) dp[i][j] += 998244353;
    }
  }
  long long pos;
  long long val;
  long long cnt = 0;
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
    for (j = 1; j <= x; j++) {
      for (k = i; k <= n; k++) {
        cnt++;
        pos = j + k - 1;
        if (pos > x) continue;
        val = (dp[i][j] * comb[k][i]) % 998244353;
        val = (val * epow(k - 1, k - i)) % 998244353;
        dp[k][pos] = (dp[k][pos] + val) % 998244353;
      }
    }
  }
  long long ans = 0;
  for (i = 1; i <= x; i++) ans = (ans + dp[n][i]) % 998244353;
  cout << ans << endl;
  return 0;
}
