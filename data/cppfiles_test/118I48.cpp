#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
const int mod = 998244353;
int n;
int ord[N], dfc;
int fa[N], cson[N];
int fir[N], to[N << 1], nex[N << 1], ecnt;
int fac[N], ifac[N];
inline int fpm(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod, y >>= 1;
  }
  return res;
}
void addE(int u, int v) {
  nex[++ecnt] = fir[u], to[ecnt] = v, fir[u] = ecnt;
  nex[++ecnt] = fir[v], to[ecnt] = u, fir[v] = ecnt;
}
void dfs(int u) {
  for (int i = fir[u], v; i; i = nex[i]) {
    v = to[i];
    if (v == fa[u]) continue;
    ++cson[u], fa[v] = u;
    dfs(v);
  }
  ord[++dfc] = u;
}
vector<int> f[N];
int len, lim, hib, rev[N];
void getRev() {
  lim = 1, hib = -1;
  while (lim < len) lim <<= 1, ++hib;
  for (int i = 0; i < lim; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << hib);
}
void DFT(vector<int> &a) {
  for (int i = 0; i < lim; ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int len = mid << 1, wn = fpm(3, (mod - 1) / len);
    for (int i = 0; i < lim; i += len) {
      int w = 1;
      for (int j = 0, x, y; j < mid; ++j, w = 1LL * w * wn % mod) {
        x = a[i + j], y = 1LL * w * a[i + mid + j] % mod;
        a[i + j] = (x + y) % mod, a[i + mid + j] = (x - y + mod) % mod;
      }
    }
  }
}
void IDFT(vector<int> &a) {
  reverse(a.begin() + 1, a.end());
  DFT(a);
  for (int i = 0, inv = fpm(lim, mod - 2); i < lim; ++i)
    a[i] = 1LL * a[i] * inv % mod;
}
void solve(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  solve(l, mid), solve(mid + 1, r);
  getRev();
  f[l].resize(lim), f[mid + 1].resize(lim);
  DFT(f[l]), DFT(f[mid + 1]);
  for (int i = 0; i < lim; ++i) f[l][i] = 1LL * f[l][i] * f[mid + 1][i] % mod;
  IDFT(f[l]);
  f[l].resize(len);
}
int main() {
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * i * fac[i - 1] % mod;
  ifac[n] = fpm(fac[n], mod - 2);
  for (int i = n; i; --i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    addE(u, v);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i)
    f[i].resize(2), f[i][0] = cson[ord[i]], f[i][1] = 1;
  solve(1, n);
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if ((n - i) & 1)
      ans = (ans - 1LL * fac[i] * f[1][i] % mod + mod) % mod;
    else
      ans = (ans + 1LL * fac[i] * f[1][i]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
