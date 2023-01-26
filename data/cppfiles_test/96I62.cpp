#include <bits/stdc++.h>
using namespace std;
long long solve();
vector<long long> a;
string s;
long long n;
long long fact[5000];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  fact[0] = 1;
  for (long long i = 1; i < 5000; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
  }
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
  if (p & 1) return (val * epow((val * val) % 998244353, p / 2)) % 998244353;
  return epow((val * val) % 998244353, p / 2) % 998244353;
}
long long modinv(long long val) { return epow(val, 998244353 - 2); }
long long ncr(long long n, long long r) {
  if (n == r || r == 0) return 1;
  return ((fact[n] * modinv(fact[r]) % 998244353) * modinv(fact[n - r])) %
         998244353;
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
  for (i = 2; i <= n; i++) {
    for (j = 1; j <= x; j++) {
      for (k = i; k <= n; k++) {
        pos = j + k - 1;
        if (pos > x) continue;
        val = (dp[i][j] * ncr(k, i)) % 998244353;
        val = (val * epow(k - 1, k - i)) % 998244353;
        dp[k][pos] += val;
      }
    }
  }
  long long ans = 0;
  for (i = 1; i <= x; i++) ans = (ans + dp[n][i]) % 998244353;
  cout << ans << endl;
  return 0;
}
