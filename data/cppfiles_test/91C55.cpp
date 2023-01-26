#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long N = 1e5 + 10, mod = 998244353;
long long dp[2][N];
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i += 1) {
    cin >> a[i];
  }
  long long ans = 0;
  vector<long long> b[2];
  for (long long i = n - 1; i >= 0; i -= 1) {
    long long k = i & 1;
    b[k].push_back(a[i]);
    dp[k][a[i]] = 1;
    long long e = a[i];
    for (auto x : b[k ^ 1]) {
      long long y = dp[k ^ 1][x];
      long long m = (a[i] - 1) / x + 1;
      long long z = a[i] / m;
      ans += y * (m - 1) * (i + 1);
      ans %= mod;
      dp[k][z] += y;
      if (e != z) {
        b[k].push_back(z);
        e = z;
      }
    }
    for (auto x : b[k ^ 1]) dp[k ^ 1][x] = 0;
    b[k ^ 1].clear();
  }
  cout << ans << "\n";
  for (auto x : b[0]) dp[0][x] = 0;
  for (auto x : b[1]) dp[1][x] = 0;
  b[0].clear();
  b[1].clear();
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
