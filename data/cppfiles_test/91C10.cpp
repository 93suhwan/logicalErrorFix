#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 7;
const long long MAXA = 1e5 + 7;
const long long MOD = 998244353;
long long mpow(long long x, long long n) {
  long long res = 1;
  for (; n; n >>= 1, x = (x * x) % MOD) {
    if (n & 1) res = (res * x) % MOD;
  }
  return res;
}
long long add(long long a, long long b) { return (a + b) % MOD; }
long long sub(long long a, long long b) { return (a - b + MOD) % MOD; }
long long mul(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
long long del(long long a, long long b) {
  return ((a % MOD) * mpow(b % MOD, MOD - 2)) % MOD;
}
long long a[MAXN];
vector<long long> cur[2];
long long dp[2][MAXA];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  for (long long i = n; i >= 1; --i) {
    long long bt = (i & 1), lst = a[i];
    cur[bt].push_back(a[i]);
    dp[bt][a[i]] = 1;
    for (long long x : cur[bt ^ 1]) {
      long long split = (a[i] + x - 1) / x;
      long long start = a[i] / split;
      ans = add(ans, mul(mul(i, dp[bt ^ 1][x]), split - 1));
      dp[bt][start] = add(dp[bt][start], dp[bt ^ 1][x]);
      if (lst != start) {
        cur[bt].push_back(start);
        lst = start;
      }
    }
    for (long long x : cur[bt ^ 1]) {
      dp[bt ^ 1][x] = 0;
    }
    cur[bt ^ 1].clear();
  }
  cout << ans << '\n';
  for (long long x : cur[0]) dp[0][x] = 0;
  for (long long x : cur[1]) dp[1][x] = 0;
  cur[0].clear();
  cur[1].clear();
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
