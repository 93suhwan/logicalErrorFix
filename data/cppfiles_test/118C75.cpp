#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
char buf[100000], *p1 = buf, *p2 = buf;
inline int gi() {
  int x = 0, f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  return (f == 1) ? x : -x;
}
const int maxn = 2.5e5 + 5, mod = 998244353;
int n;
vector<int> e[maxn];
namespace Poly {
const int G = 3;
vector<int> rev;
inline int qpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = 1ll * x * ret % mod;
    k >>= 1, x = 1ll * x * x % mod;
  }
  return ret;
}
inline int getbit(int len) {
  int bit = 0;
  while (1 << bit < len) bit++;
  return bit;
}
inline void calcrev(int len) {
  rev.resize(len);
  int bit = getbit(len);
  for (int i = 0; i <= len - 1; ++i)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
}
inline void dft(vector<int> &a) {
  int n = (int)(a.size());
  for (int i = 0; i <= n - 1; ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int l = 1; l < n; l <<= 1) {
    int wn = qpow(G, (mod - 1) / (l << 1));
    for (int i = 0; i < n; i += l << 1) {
      int w = 1;
      for (int j = 0; j < l; ++j, w = 1ll * w * wn % mod) {
        int v1 = a[i + j], v2 = 1ll * a[i + j + l] * w % mod;
        a[i + j] = (v1 + v2) % mod;
        a[i + j + l] = (v1 - v2 + mod) % mod;
      }
    }
  }
}
inline void idft(vector<int> &a) {
  int n = (int)(a.size());
  reverse(a.begin() + 1, a.end());
  dft(a);
  int inv = qpow(n, mod - 2);
  for (int i = 0; i <= n - 1; ++i) a[i] = 1ll * a[i] * inv % mod;
}
inline vector<int> operator*(vector<int> a, vector<int> b) {
  int len = (int)(a.size()) + (int)(b.size()), l = len - 1;
  if (!(int)(a.size()) || !(int)(b.size())) return vector<int>();
  len = 1 << getbit(len);
  calcrev(len);
  a.resize(len), b.resize(len);
  dft(a), dft(b);
  for (int i = 0; i <= len - 1; ++i) a[i] = 1ll * a[i] * b[i] % mod;
  idft(a);
  a.resize(l);
  return a;
}
inline vector<int> operator+(vector<int> a, vector<int> b) {
  if ((int)(a.size()) > (int)(b.size())) swap(a, b);
  for (int i = 0; i <= (int)(a.size()) - 1; ++i) b[i] = (b[i] + a[i]) % mod;
  return b;
}
}  // namespace Poly
using namespace Poly;
int fac[maxn], inv[maxn];
inline void input() {
  n = gi();
  inv[0] = inv[1] = fac[0] = fac[1] = 1;
  for (int i = 2; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 2; i <= n; ++i)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i <= n; ++i) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
  for (int i = 1; i <= n - 1; ++i) {
    int u = gi(), v = gi();
    e[u].push_back(v), e[v].push_back(u);
  }
}
int son[maxn], fa[maxn], tp[maxn], siz[maxn], sons[maxn];
inline void dfs(int u) {
  siz[u] = 1;
  for (int v : e[u]) {
    if (v == fa[u]) continue;
    fa[v] = u;
    dfs(v);
    siz[u] += siz[v];
    sons[u]++;
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
vector<int> dp[maxn];
int f[maxn];
inline vector<int> cdq(vector<vector<int> > &seq, int l, int r) {
  if (l == r) return seq[l];
  int mid = (l + r) >> 1;
  return cdq(seq, l, mid) * cdq(seq, mid + 1, r);
}
inline void dfs2(int u) {
  vector<vector<int> > seq;
  for (int x = u; x; x = son[x]) {
    seq.clear();
    seq.push_back(dp[x]);
    for (int v : e[x]) {
      if (v == fa[x] || v == son[x]) continue;
      dfs2(v);
      seq.push_back(dp[v]);
    }
    dp[x] = cdq(seq, 0, (int)(seq.size()) - 1);
  }
  seq.clear();
  for (int x = u; x; x = son[x]) seq.push_back(dp[x]);
  dp[u] = cdq(seq, 0, (int)(seq.size()) - 1);
}
inline void solve() {
  dfs(1);
  for (int i = 1; i <= n; ++i) dp[i] = {sons[i], 1};
  dfs2(1);
  for (int i = 0; i <= n; ++i) f[i] = 1ll * dp[1][n - i] * fac[n - i] % mod;
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    i & 1 ? ans = (ans + mod - f[i]) % mod : ans = (ans + f[i]) % mod;
  printf("%d\n", ans);
}
int main() {
  input();
  solve();
  return 0;
}
