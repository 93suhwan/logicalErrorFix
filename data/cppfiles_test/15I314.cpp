#include <bits/stdc++.h>
using namespace std;
const long long Mod = (long long)1e9 + 7;
const long long MAXFAC = (long long)2e6 + 10;
long long fac[MAXFAC];
inline long long pw(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1ll) res = res * x % Mod;
    x = x * x % Mod;
    y /= 2;
  }
  return res;
}
void init_fac(long long maxn = MAXFAC) {
  fac[0] = 1;
  for (long long i = 1; i < maxn; ++i) {
    fac[i] = fac[i - 1] * i % Mod;
  }
}
inline long long inv(long long x) { return pw(x, Mod - 2); };
inline long long choose(long long n, long long r) {
  return fac[n] * (inv(fac[n - r]) * inv(fac[r]) % Mod) % Mod;
}
void preproc() { init_fac(); }
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<vector<long long>> w(n + 1, vector<long long>(n + 1, INT_MAX));
  for (long long i = 1; i <= n; ++i) w[i][i] = 0;
  for (long long e = 1; e <= n - 1; ++e) {
    long long u, v;
    cin >> u >> v;
    w[u][v] = 1, w[v][u] = 1;
  }
  for (long long k = 1; k <= n; ++k)
    for (long long u = 1; u <= n; ++u)
      for (long long v = 1; v <= n; ++v)
        if (w[u][k] != INT_MAX and w[k][v] != INT_MAX)
          w[u][v] = w[v][u] = min(w[u][v], w[u][k] + w[k][v]);
  long long res = 0;
  for (long long u = 1; u <= n; ++u) {
    for (long long c = 1; c <= n; ++c) {
      long long cnt = 0;
      for (long long v = 1; v <= n; ++v) cnt += (w[u][v] == c);
      if (cnt >= k) res = (res + choose(cnt, k)) % Mod;
    }
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  preproc();
  long long tc = 1;
  cin >> tc;
  for (long long Tt = 1; Tt <= tc; ++Tt) {
    ;
    solve();
  }
  return EXIT_SUCCESS;
}
