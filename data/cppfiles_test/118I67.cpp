#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int N = (1 << 18), G = 3, mod = 998244353, gg = (mod + 1) / G;
int d[N], p[N], ans, n, rev[N];
int qpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
    y /= 2;
  }
  return res % mod;
}
void init() {
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = 1LL * p[i - 1] * i % mod;
  }
}
void ntt(vector<int>& f, int op) {
  int n = f.size();
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(f[i], f[rev[i]]);
  for (int i = 1; i < n; i = i * 2) {
    int w = qpow(op == 1 ? G : gg, (mod - 1) / 2 / i);
    for (int j = 0; j < n; j += i + i) {
      int wn = 1;
      for (int k = 0; k < i; k++) {
        int x = f[k + j], y = 1ll * wn * f[i + k + j] % mod;
        f[k + j] = (x + y) % mod, f[k + j + i] = (x - y + mod) % mod;
        wn = 1ll * wn * w % mod;
      }
    }
  }
  if (!op) return;
  int inv = qpow(n, mod - 2);
  for (int i = 0; i < n; i++) f[i] = 1LL * f[i] * inv % mod;
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  int n = 1;
  vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  while (n < (int)(a.size() + b.size())) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  for (int i = 0; i < n; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
  ntt(fa, 0);
  ntt(fb, 0);
  for (int i = 0; i < n; i++) fa[i] = 1LL * fa[i] * fb[i] % mod;
  ntt(fa, 1);
  return fa;
}
vector<int> solve(int l, int r) {
  if (l == r) return {1, d[l] - (l != 1)};
  int mid = (l + r) >> 1;
  return multiply(solve(l, mid), solve(mid + 1, r));
}
int main() {
  scanf("%d", &n);
  init();
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    d[u]++;
    d[v]++;
  }
  vector<int> f = solve(1, n);
  for (int i = 0; i < n; i++) {
    if (i % 2)
      ans -= 1LL * f[i] * p[n - i] % mod;
    else
      ans += 1LL * f[i] * p[n - i] % mod;
    ans = (ans % mod + mod) % mod;
  }
  printf("%d\n", ans);
}
