#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long gen_random(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
int recur_depth = 0;
const long long mod = 1e9 + 7, sz = 1e5 + 10;
long long p, np, n, m, rb, cb, rd, cd, pr, cyc, dr = 1, dc = 1, cnt;
vector<bool> vis[sz][3][3];
long long fastPow(long long x, long long n, long long MOD) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return ret % MOD;
}
long long dfs(long long rb, long long cb) {
  long long ret = 0;
  if (rb == rd || cb == cd) {
    if (rb + dr > n || rb + dr < 1) dr *= -1;
    if (cb + dc > m || cb + dc < 1) dc *= -1;
    if (vis[rb][dr + 1][dc + 1][cb]) return 0;
    vis[rb][dr + 1][dc + 1][cb] = 1;
    rb += dr, cb += dc;
    cnt++;
    ret = (np * (1 + dfs(rb, cb))) % mod;
  } else {
    if (rb + dr > n || rb + dr < 1) dr *= -1;
    if (cb + dc > m || cb + dc < 1) dc *= -1;
    if (vis[rb][dr + 1][dc + 1][cb]) return 0;
    vis[rb][dr + 1][dc + 1][cb] = 1;
    rb += dr, cb += dc;
    ret = (1 + dfs(rb, cb)) % mod;
  }
  return ret;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> rb >> cb >> rd >> cd >> pr;
    p = (pr * fastPow(100, mod - 2, mod)) % mod;
    np = 1 - p;
    if (np < 0) np += mod;
    long long ext = 0, sr = rb, sc = cb;
    dr = 1, dc = 1;
    while (rb != rd && cb != cd) {
      if (rb + dr > n || rb + dr < 1) dr *= -1;
      if (cb + dc > m || cb + dc < 1) dc *= -1;
      rb += dr, cb += dc;
      ext++;
    }
    for (long long i = 1; i <= n; ++i) {
      for (long long j = 0; j < 3; ++j)
        for (long long k = 0; k < 3; ++k) {
          vis[i][j][k].resize(m + 1);
          for (long long q = 1; q <= m; ++q) vis[i][j][k][q] = 0;
        }
    }
    cnt = 0;
    long long ans = dfs(rb, cb);
    long long pwr = 1;
    for (long long i = 1; i <= cnt; ++i) pwr = (pwr * np) % mod;
    long long dv = 1 - pwr;
    if (dv < 0) dv += mod;
    ans = (ans * fastPow(dv, mod - 2, mod)) % mod;
    ans = (ans + ext) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
