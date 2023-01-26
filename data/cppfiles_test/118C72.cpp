#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
struct NTT {
  long long up, l;
  vector<long long> pos;
  void init(int n, int m) {
    up = 1, l = 0;
    while (up < (n + m)) up <<= 1, l++;
    pos.resize(0);
    pos.resize(up, 0ll);
    for (int i = 0; i <= up - 1; i++)
      pos[i] = (pos[i >> 1] >> 1) | ((i & 1) << (l - 1));
  }
  void solve(vector<long long> &a, int mode) {
    for (int i = 0; i <= up - 1; i++)
      if (i < pos[i]) swap(a[i], a[pos[i]]);
    for (int i = 1; i < up; i <<= 1) {
      long long gn = qpow(3, (mod - 1) / (i << 1));
      if (mode == -1) gn = qpow(gn, mod - 2);
      for (int j = 0; j < up; j += (i << 1)) {
        long long g = 1;
        for (int k = 0; k < i; k++, g = g * gn % mod) {
          long long x = a[j + k], y = g * a[j + k + i] % mod;
          a[j + k] = (x + y) % mod, a[j + k + i] = (x - y + mod) % mod;
        }
      }
    }
    if (mode == -1) {
      long long invup = qpow(up, mod - 2);
      for (int i = 0; i <= up - 1; i++) a[i] = a[i] * invup % mod;
    }
  }
} ntt;
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<int> siz(n + 1, 0);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  function<void(int, int)> dfs0 = [&](int fa, int u) {
    for (auto v : g[u]) {
      if (v == fa) continue;
      siz[u]++;
      dfs0(u, v);
    }
  };
  dfs0(1, 1);
  auto mul = [&](vector<long long> a, vector<long long> b) {
    int len1 = a.size();
    int len2 = b.size();
    ntt.init(len1, len2);
    a.resize(ntt.up, 0ll);
    b.resize(ntt.up, 0ll);
    vector<long long> c(ntt.up, 0ll);
    ntt.solve(a, 1);
    ntt.solve(b, 1);
    for (int i = 0; i <= ntt.up - 1; i++) c[i] = a[i] * b[i] % mod;
    ntt.solve(c, -1);
    return c;
  };
  function<vector<long long>(int, int)> dfs = [&](int l, int r) {
    if (l == r) {
      vector<long long> v = {1, siz[l]};
      return v;
    }
    int mid = (l + r) / 2;
    return mul(dfs(l, mid), dfs(mid + 1, r));
  };
  vector<long long> fac(n + 1, 1ll);
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  vector<long long> t = dfs(1, n);
  long long res = 0;
  for (int i = 0; i <= n - 1; i++) {
    if (i % 2 == 0)
      res += t[i] * fac[n - i] % mod;
    else
      res += mod - t[i] * fac[n - i] % mod;
    res %= mod;
  }
  cout << res << '\n';
  return 0;
}
