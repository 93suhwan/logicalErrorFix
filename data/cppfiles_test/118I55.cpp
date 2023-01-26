#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18) + 5;
const int p = 998244353;
const int G = 3;
const int gi = ((p + 1) / G);
inline int inc(int x, int y) {
  if ((x += y) >= p) x -= p;
  return x;
}
inline int dec(int x, int y) {
  if ((x -= y) < 0) x += p;
  return x;
}
inline void Inc(int &x, int y) { x = inc(x, y); }
inline void Dec(int &x, int y) { x = dec(x, y); }
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % p)
    if (b & 1) ans = 1ll * a * ans % p;
  return ans;
}
int fac[N], inv[N], ans;
inline void init() {
  fac[0] = fac[1] = inv[0] = inv[1] = 1;
  for (int i = (2); i <= (N - 5); i++)
    fac[i] = 1ll * i * fac[i - 1] % p, inv[i] = ksm(fac[i], p - 2);
}
inline int C(int a, int b) {
  if (a < b || a < 0 || b < 0) return 0;
  return 1ll * fac[a] * inv[b] % p * inv[a - b] % p;
}
int rev[N], Wn[20][2], pw[20];
inline void getWn() {
  for (int ct = 0, mid = 1; ct < 20; ct++, mid <<= 1)
    Wn[ct][0] = ksm(gi, (p - 1) / (mid << 1)),
    Wn[ct][1] = ksm(G, (p - 1) / (mid << 1)), pw[ct] = ksm(mid, p - 2);
}
inline int get(int x) {
  int limit = 1;
  while (limit <= x) limit <<= 1;
  for (int i = (1); i <= (limit - 1); i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (limit >> 1) : (0));
  return limit;
}
inline void NTT(int *a, int type, int lim) {
  for (int i = (0); i <= (lim - 1); i++)
    if (i > rev[i]) swap(a[i], a[rev[i]]);
  int inv = pw[0];
  for (int mid = 1, ct = 0; mid < lim; mid <<= 1, ct++, inv = pw[ct])
    for (int j = 0; j < lim; j += (mid << 1))
      for (int k = 0, w = 1; k < mid; k++, w = 1ll * w * Wn[ct][type] % p) {
        int x = a[j + k], y = 1ll * a[j + k + mid] * w % p;
        a[j + k] = (x + y) % p;
        a[j + k + mid] = (x - y + p) % p;
      }
  if (!type)
    for (int i = (0); i <= (lim - 1); i++) a[i] = 1ll * a[i] * inv % p;
}
vector<int> e[N];
int n, f[N], sn[N], cnt[N];
inline void dfs1(int x, int fa) {
  for (int v : e[x])
    if (v != fa) dfs1(v, x), sn[x]++;
  cnt[sn[x]]++;
}
int ca[N], cb[N], cc[N];
inline vector<int> mul(vector<int> a, vector<int> b) {
  int A = a.size(), B = b.size();
  if (A * B <= 5000) {
    vector<int> c;
    c.resize(A + B - 1);
    for (int i = (0); i <= (A - 1); i++)
      for (int j = (0); j <= (B - 1); j++) Inc(c[i + j], 1ll * a[i] * b[j] % p);
    return c;
  }
  int lim = get(A + B - 2);
  for (int i = (0); i <= (A - 1); i++) ca[i] = a[i];
  for (int i = (A); i <= (lim - 1); i++) ca[i] = 0;
  for (int i = (0); i <= (B - 1); i++) cb[i] = b[i];
  for (int i = (B); i <= (lim - 1); i++) cb[i] = 0;
  NTT(ca, 1, lim);
  NTT(cb, 1, lim);
  for (int i = (0); i <= (lim - 1); i++) cc[i] = 1ll * ca[i] * cb[i] % p;
  NTT(cc, 0, lim);
  vector<int> c;
  for (int i = (0); i <= (A + B - 2); i++) c.emplace_back(cc[i]);
  return c;
}
vector<int> as;
inline int Get(int x) {
  if (x >= as.size()) return 0;
  return as[x];
}
inline void solve() {
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }
  dfs1(1, 0);
  as.emplace_back(1);
  for (int i = (n - 1); i >= (1); i--)
    if (cnt[i]) {
      vector<int> ml;
      int aml = 1;
      ml.emplace_back(1);
      for (int j = (1); j <= (cnt[i]); j++) {
        aml = 1ll * aml * i % p;
        ml.emplace_back(1ll * aml * C(cnt[i], j) % p);
      }
      as = mul(as, ml);
    }
  for (int i = (0); i <= (n - 1); i++) {
    if (i & 1)
      Dec(ans, 1ll * Get(i) * fac[n - i] % p);
    else
      Inc(ans, 1ll * Get(i) * fac[n - i] % p);
  }
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
}
