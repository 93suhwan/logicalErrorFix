#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long P = 27, MAXN = 2e6 + 1, inf = 1e9 + 7;
long long M = 1e9 + 7;
long long f[MAXN + 1], inv[MAXN + 1], inc[MAXN + 1];
long long bin_pow(long long a, long long b) {
  if (b <= 0) return 1;
  if (b % 2 == 0) {
    long long x = bin_pow(a, b / 2);
    return x * x % M;
  } else {
    return bin_pow(a, b - 1) * a % M;
  }
}
long long C(long long n, long long k) {
  if (n < 0 || k > n) return 0;
  return (f[n] * inc[k] % M * inc[n - k] % M + M) % M;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) {
  if (a < 0) return lcm(abs(a), b);
  if (b < 0) return lcm(a, abs(b));
  if (a == 0 && b == 0) return 0;
  return a / gcd(a, b) * b;
}
const long long N = 301;
vector<long long> p;
void init(vector<long long> &a) {
  long long n = (long long)a.size();
  p.resize(n + 1);
  for (long long i = 0; i < n; ++i) p[i + 1] = p[i] + a[i];
}
long long get(long long l, long long r) { return p[r + 1] - p[l]; }
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long k = 0;
  while (k * (k + 1) / 2 <= n) ++k;
  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  init(a);
  dp[n - 1][1] = dp[n - 1][0] = a[n - 1];
  for (long long i = n - 2; i >= 0; --i) {
    for (long long j = 0; j <= k; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (j && i + j - 1 < n && get(i, i + j - 1) < dp[i + j][j - 1]) {
        dp[i][j] = max(dp[i][j], get(i, i + j - 1));
      }
    }
  }
  long long ans = 0;
  for (long long j = 1; j <= k; ++j) {
    if (dp[0][j] > 0) ans = j;
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  f[0] = inv[0] = f[1] = inv[1] = 1;
  for (long long i = 2; i <= MAXN; ++i) {
    f[i] = f[i - 1] * i % M;
    inv[i] = ((-M / i) * inv[M % i] + M) % M;
  }
  inc[0] = 1;
  for (long long i = 1; i <= MAXN; ++i) {
    inc[i] = inc[i - 1] * inv[i] % M;
  }
  long long _ = 1;
  cin >> _;
  while (_--) solve();
}
