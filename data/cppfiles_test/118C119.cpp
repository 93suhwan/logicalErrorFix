#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int mod = 998244353;
const int G = 3, Gi = 332748118;
int add(int x, int y) {
  if ((x += y) >= mod) x -= mod;
  return x;
}
int sub(int x, int y) {
  if ((x -= y) < 0) x += mod;
  return x;
}
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
namespace Poly {
vector<int> Rev, W;
int lim, L;
void getR(int len) {
  lim = 1, L = 0;
  while (lim <= len) lim <<= 1, L++;
  Rev.resize(lim), W.resize(lim), W[0] = 1;
  for (int i = 0; i < lim; i++)
    Rev[i] = (Rev[i >> 1] >> 1) | ((i & 1) << L - 1);
}
void wf(vector<int> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) a[i] = 1ll * (i + 1) * a[i + 1] % mod;
  a[n - 1] = 0;
}
void jf(vector<int> &a) {
  int n = a.size();
  for (int i = n - 1; i >= 1; i--) a[i] = 1ll * a[i - 1] * qpow(i) % mod;
  a[0] = 0;
}
void NTT(vector<int> &a, int opt) {
  for (int i = 0; i < lim; i++)
    if (i < Rev[i]) swap(a[i], a[Rev[i]]);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int Wn = qpow(opt == 1 ? G : Gi, (mod - 1) / (mid << 1));
    for (int k = 1; k < mid; k++) W[k] = 1ll * W[k - 1] * Wn % mod;
    for (int j = 0; j < lim; j += mid << 1) {
      for (int k = 0; k < mid; k++) {
        int x = a[j + k], y = 1ll * W[k] * a[j + k + mid] % mod;
        a[j + k] = add(x, y);
        a[j + k + mid] = sub(x, y);
      }
    }
  }
  if (opt == -1) {
    int linv = qpow(lim);
    for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * linv % mod;
  }
}
vector<int> operator*(vector<int> a, vector<int> b) {
  int len = a.size() + b.size() - 1;
  getR(len);
  a.resize(lim), b.resize(lim);
  NTT(a, 1), NTT(b, 1);
  for (int i = 0; i < lim; i++) a[i] = 1ll * a[i] * b[i] % mod;
  NTT(a, -1);
  a.resize(len);
  return a;
}
vector<int> Inv(vector<int> a) {
  if ((int(a.size())) == 1) return vector<int>(1, qpow(a[0]));
  int len = a.size();
  vector<int> ta = a;
  ta.resize((len + 1) / 2);
  vector<int> tb = Inv(ta);
  getR(2 * len), a.resize(lim), tb.resize(lim);
  NTT(a, 1), NTT(tb, 1);
  for (int i = 0; i < lim; i++)
    tb[i] = 1ll * tb[i] * (mod + 2 - 1ll * a[i] * tb[i] % mod) % mod;
  NTT(tb, -1);
  tb.resize(len);
  return tb;
}
vector<int> Ln(vector<int> a) {
  vector<int> ta = a;
  wf(ta);
  int len = a.size();
  a = ta * Inv(a), jf(a);
  a.resize(len);
  return a;
}
vector<int> Exp(vector<int> a) {
  if ((int(a.size())) == 1) return vector<int>(1, 1);
  int len = a.size();
  vector<int> ta = a;
  ta.resize((len + 1) / 2);
  vector<int> tb = Exp(ta);
  tb.resize(len);
  vector<int> Lnb = Ln(tb);
  assert(Lnb.size() == len);
  for (int i = 0; i < len; i++) Lnb[i] = (a[i] - Lnb[i] + mod) % mod;
  Lnb[0] = (Lnb[0] + 1) % mod;
  tb = tb * Lnb;
  tb.resize(len);
  return tb;
}
}  // namespace Poly
using namespace Poly;
const int N = 250005;
const int B = 30;
vector<int> adj[N];
int n;
int son[N];
void dfs1(int u, int fa) {
  for (auto v : adj[u]) {
    if (v == fa) continue;
    son[u]++;
    dfs1(v, u);
  }
}
int two[N], len;
vector<int> solve(int l, int r) {
  if (l > r) return {1};
  if (l == r) return {1, mod - two[l]};
  int mid = l + r >> 1;
  return solve(l, mid) * solve(mid + 1, r);
}
int fac[N], inv[N];
int fuck[N];
int main() {
  n = read();
  inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = 1ull * (mod - mod / i) * inv[mod % i] % mod;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ull * fac[i - 1] * i % mod;
  for (int i = 1; i <= n - 1; i++) {
    int u = read(), v = read();
    adj[u].push_back(v), adj[v].push_back(u);
  }
  dfs1(1, 0);
  vector<int> ONE(n + 1);
  for (int i = 1; i <= n; i++) {
    if (son[i] > B) {
      two[++len] = son[i];
    } else {
      fuck[son[i]]++;
    }
  }
  for (int i = 1; i <= B; i++) {
    int coef = 1;
    for (int j = 1; j <= n; j++) {
      coef = 1ull * coef * i % mod;
      ONE[j] = sub(ONE[j], 1ull * fuck[i] * coef % mod * inv[j] % mod);
    }
  }
  ONE = Exp(ONE);
  vector<int> TWO = solve(1, len);
  vector<int> f = ONE * TWO;
  int ans = 0;
  for (int i = 0; i <= n - 1; i++) ans = (ans + 1ll * fac[n - i] * f[i]) % mod;
  print(ans, '\n');
  return 0;
}
