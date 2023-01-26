#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int N = (1 << 18), G = 3, mod = 998244353;
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
void ntt(vector<int>& a, int op) {
  int len = a.size();
  for (int i = 0; i < len; i++) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int s = 2; s <= len; s <<= 1) {
    int w =
        (op == 1) ? qpow(G, (mod - 1) / s) : qpow(G, (mod - 1) - (mod - 1) / s);
    for (int i = 0, t = s / 2; i < len; i += s)
      for (int j = 0, x = 1; j < t; j++, x = 1LL * x * w % mod) {
        int v1 = a[i + j], v2 = 1LL * a[i + j + t] * x % mod;
        a[i + j] = (v1 + v2) % mod;
        a[i + j + t] = (v1 - v2 + mod) % mod;
      }
  }
  if (!op) return;
  int inv = qpow(len, mod - 2);
  for (int i = 0; i < len; i++) a[i] = 1LL * a[i] * inv % mod;
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
  for (int i = 0; i <= n; i++) {
    if (i % 2)
      ans -= 1LL * f[i] * p[n - i] % mod;
    else
      ans += 1LL * f[i] * p[n - i] % mod;
    ans = (ans % mod + mod) % mod;
  }
  printf("%d\n", ans);
}
