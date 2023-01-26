#include <bits/stdc++.h>
int P = 998244353;
using namespace std;
template <typename T>
inline void ckmax(T &a, T b) {
  (a < b) && (a = b);
}
template <typename T>
inline void ckmin(T &a, T b) {
  (a > b) && (a = b);
}
inline int mul(int a, int b) { return 1ull * a * b % P; }
inline int mul(int a, int b, int c) { return mul(a, mul(b, c)); }
inline int add(int a, int b) { return a + b >= P ? a + b - P : a + b; }
inline int sub(int a, int b) { return a - b >= 0 ? a - b : a - b + P; }
inline void mulmod(int &a, int b) { a = mul(a, b); }
inline void addmod(int &a, int b) { ((a += b) >= P) && (a -= P); }
inline void submod(int &a, int b) { ((a -= b) < 0) && (a += P); }
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = 1ll * ans * a % P;
    a = 1ll * a * a % P;
  }
  return ans;
}
inline void fprint(const int &x, char c = ' ') {
  fprintf(stderr, "%d%c", x, c);
}
inline void fprint(const pair<int, int> &x, char c = '\n') {
  fprintf(stderr, "%d %d%c", x.first, x.second, c);
}
inline void fprint(const int *f, const int &n, char c = '\n') {
  for (int i = 1; i <= n; i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline void fprint(const vector<int> &f, char c = '\n') {
  for (int i = 0; i < (int)f.size(); i++) fprint(f[i]);
  fprintf(stderr, "%c", c);
}
inline int inv(int a) { return ksm(a, P - 2); }
namespace FastIO {
const int SIZE = 1 << 16;
char buf[SIZE], obuf[SIZE], str[64];
int bi = SIZE, bn = SIZE, opt;
int read(char *s) {
  while (bn) {
    for (; bi < bn && buf[bi] <= ' '; bi++)
      ;
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  int sn = 0;
  while (bn) {
    for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  s[sn] = 0;
  return sn;
}
bool read(int &x) {
  if (x) x = 0;
  int bf = 0, n = read(str);
  if (!n) return 0;
  int i = 0;
  if (str[i] == '-') bf = 1, i = 1;
  for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
  if (bf) x = -x;
  return 1;
}
void write(int x) {
  if (!x)
    obuf[opt++] = '0';
  else {
    if (x < 0) obuf[opt++] = '-', x = -x;
    int sn = 0;
    while (x) str[sn++] = x % 10 + '0', x /= 10;
    for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
  }
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void write(char x) {
  obuf[opt++] = x;
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void Fflush() {
  if (opt) fwrite(obuf, 1, opt, stdout);
  opt = 0;
}
};  // namespace FastIO
inline int read() {
  int x = 0;
  FastIO::read(x);
  return x;
}
const int MN = 5e5 + 5;
int n, fac[MN], ifac[MN], Inv[MN];
void init() {
  fac[0] = 1;
  for (int i = 1; i < MN; i++) fac[i] = mul(fac[i - 1], i);
  Inv[0] = Inv[1] = 1;
  for (int i = 2; i < MN; i++) Inv[i] = mul(P - P / i, Inv[P % i]);
  ifac[0] = 1;
  for (int i = 1; i < MN; i++) ifac[i] = mul(ifac[i - 1], Inv[i]);
}
int C(int x, int y) { return x >= y ? mul(fac[x], ifac[x - y], ifac[y]) : 0; }
vector<int> e[MN];
int qwq;
namespace Poly {
const int max_len = 1 << 20, N = max_len + 5, mod = 998244353;
template <typename _Tp1, typename _Tp2>
inline void add(_Tp1 &a, _Tp2 b) {
  (a += b) >= mod && (a -= mod);
}
template <typename _Tp1, typename _Tp2>
inline void sub(_Tp1 &a, _Tp2 b) {
  (a -= b) < 0 && (a += mod);
}
template <typename _Tp>
inline _Tp _sub(_Tp a, const _Tp &b) {
  (a += mod - b) >= mod && (a -= mod);
  return a;
}
long long ksm(long long a, long long b = mod - 2) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return res;
}
inline vector<int> operator<<(vector<int> a, unsigned b) {
  return a.insert(a.begin(), b, 0), a;
}
inline vector<int> operator<<=(vector<int> &a, unsigned b) {
  return a.insert(a.begin(), b, 0), a;
}
inline vector<int> operator>>(const vector<int> &a, unsigned b) {
  return b >= a.size() ? vector<int>() : vector<int>{a.begin() + b, a.end()};
}
inline vector<int> operator>>=(vector<int> &a, unsigned b) {
  return a = b >= a.size() ? vector<int>()
                           : vector<int>{a.begin() + b, a.end()};
}
vector<int> operator+=(vector<int> &a, const vector<int> &b) {
  if (((int)b.size()) > ((int)a.size())) a.resize(((int)b.size()));
  for (unsigned i = 0; i < b.size(); ++i) add(a[i], b[i]);
  return a;
}
inline vector<int> operator+(const vector<int> &a, const vector<int> &b) {
  vector<int> tmp(a);
  tmp += b;
  return tmp;
}
vector<int> operator-=(vector<int> &a, const vector<int> &b) {
  if (((int)b.size()) > ((int)a.size())) a.resize(((int)b.size()));
  for (unsigned i = 0; i < b.size(); ++i) sub(a[i], b[i]);
  return a;
}
inline vector<int> operator-(const vector<int> &a, const vector<int> &b) {
  vector<int> tmp(a);
  tmp -= b;
  return tmp;
}
unsigned long long Omgs[N];
int r[N];
const unsigned long long Omg = ksm(3, (mod - 1) / max_len);
int getlen(int len) {
  int limit = 1;
  while (limit < len) limit <<= 1;
  for (int i = 0; i < limit; ++i)
    r[i] = (r[i >> 1] >> 1) | (i & 1 ? limit >> 1 : 0);
  return limit;
}
void setup() {
  Omgs[max_len >> 1] = 1;
  for (int i = (max_len >> 1) + 1; i < max_len; ++i)
    Omgs[i] = Omgs[i - 1] * Omg % mod;
  for (int i = (max_len >> 1) - 1; i > 0; --i) Omgs[i] = Omgs[i << 1];
}
void dft(unsigned long long *A, int limit) {
  for (int i = 0; i < limit; ++i)
    if (i < r[i]) std::swap(A[i], A[r[i]]);
  for (int len = 1; len < limit; len <<= 1) {
    if (len == 262144)
      for (int i = 0; i < limit; ++i) A[i] %= mod;
    for (int i = 0; i < limit; i += len << 1) {
      unsigned long long *p = A + i, *q = A + i + len, *w = Omgs + len;
      for (int _ = 0; _ < len; ++_, ++p, ++q, ++w) {
        unsigned long long tmp = *q * *w % mod;
        *q = *p + mod - tmp, *p += tmp;
      }
    }
  }
  for (int i = 0; i < limit; ++i) A[i] %= mod;
}
void idft(unsigned long long *A, int limit) {
  std::reverse(A + 1, A + limit), dft(A, limit);
  unsigned long long inv = mod - (mod - 1) / limit;
  for (int i = 0; i < limit; ++i) A[i] = inv * A[i] % mod;
}
unsigned long long _f[N], _g[N];
vector<int> operator*(const vector<int> &a, const vector<int> &b) {
  unsigned len = a.size() + b.size() - 1;
  if (a.size() <= 64u || b.size() <= 64u) {
    vector<int> c(len);
    for (unsigned i = 0; i < len; ++i) {
      int j = min(((int)a.size()) - 1, (int)i),
          ed = max(0, (int)i - ((int)b.size()) + 1);
      unsigned long long v = 0;
      for (; j - 17 >= ed; j -= 18)
        v = (v + 1ULL * a[j - 0] * b[i - j + 0] +
             1ULL * a[j - 1] * b[i - j + 1] + 1ULL * a[j - 2] * b[i - j + 2] +
             1ULL * a[j - 3] * b[i - j + 3] + 1ULL * a[j - 4] * b[i - j + 4] +
             1ULL * a[j - 5] * b[i - j + 5] + 1ULL * a[j - 6] * b[i - j + 6] +
             1ULL * a[j - 7] * b[i - j + 7] + 1ULL * a[j - 8] * b[i - j + 8] +
             1ULL * a[j - 9] * b[i - j + 9] + 1ULL * a[j - 10] * b[i - j + 10] +
             1ULL * a[j - 11] * b[i - j + 11] +
             1ULL * a[j - 12] * b[i - j + 12] +
             1ULL * a[j - 13] * b[i - j + 13] +
             1ULL * a[j - 14] * b[i - j + 14] +
             1ULL * a[j - 15] * b[i - j + 15] +
             1ULL * a[j - 16] * b[i - j + 16] +
             1ULL * a[j - 17] * b[i - j + 17]) %
            mod;
      for (; j >= ed; --j) v += 1ULL * a[j] * b[i - j];
      c[i] = v % mod;
    }
    return c;
  }
  int limit = getlen(len);
  memset(_f, 0, limit << 3);
  for (unsigned i = 0; i < a.size(); ++i) _f[i] = a[i];
  memset(_g, 0, limit << 3);
  for (unsigned i = 0; i < b.size(); ++i) _g[i] = b[i];
  dft(_f, limit), dft(_g, limit);
  for (int i = 0; i < limit; ++i) _f[i] = 1ULL * _f[i] * _g[i] % mod;
  idft(_f, limit);
  vector<int> ans(len);
  for (unsigned i = 0; i < len; ++i) ans[i] = _f[i];
  return ans;
}
vector<int> mul(const vector<int> &a, const vector<int> &b, unsigned len,
                bool need = true) {
  if (a.size() <= 64u || b.size() <= 64u) {
    vector<int> c(len);
    for (unsigned i = 0; i < len; ++i) {
      int j = min(((int)a.size()) - 1, (int)i),
          ed = max(0, (int)i - ((int)b.size()) + 1);
      unsigned long long v = 0;
      for (; j - 17 >= ed; j -= 18)
        v = (v + 1ULL * a[j - 0] * b[i - j + 0] +
             1ULL * a[j - 1] * b[i - j + 1] + 1ULL * a[j - 2] * b[i - j + 2] +
             1ULL * a[j - 3] * b[i - j + 3] + 1ULL * a[j - 4] * b[i - j + 4] +
             1ULL * a[j - 5] * b[i - j + 5] + 1ULL * a[j - 6] * b[i - j + 6] +
             1ULL * a[j - 7] * b[i - j + 7] + 1ULL * a[j - 8] * b[i - j + 8] +
             1ULL * a[j - 9] * b[i - j + 9] + 1ULL * a[j - 10] * b[i - j + 10] +
             1ULL * a[j - 11] * b[i - j + 11] +
             1ULL * a[j - 12] * b[i - j + 12] +
             1ULL * a[j - 13] * b[i - j + 13] +
             1ULL * a[j - 14] * b[i - j + 14] +
             1ULL * a[j - 15] * b[i - j + 15] +
             1ULL * a[j - 16] * b[i - j + 16] +
             1ULL * a[j - 17] * b[i - j + 17]) %
            mod;
      for (; j >= ed; --j) v += 1ULL * a[j] * b[i - j];
      c[i] = v % mod;
    }
    return c;
  }
  int limit = getlen(len);
  memset(_f, 0, limit << 3);
  for (unsigned i = 0; i < a.size(); ++i) _f[i] = a[i];
  dft(_f, limit);
  if (need) {
    memset(_g, 0, limit << 3);
    for (unsigned i = 0; i < b.size(); ++i) _g[i] = b[i];
    dft(_g, limit);
  }
  for (int i = 0; i < limit; ++i) _f[i] = 1ULL * _f[i] * _g[i] % mod;
  idft(_f, limit);
  vector<int> ans(len);
  for (unsigned i = 0; i < len; ++i) ans[i] = _f[i];
  return ans;
}
inline vector<int> operator*=(vector<int> &a, const vector<int> &b) {
  return a = a * b;
}
template <typename _Tp>
inline vector<int> operator*=(vector<int> &a, const _Tp &b) {
  for (auto &&it : a) it = 1ll * it * b % mod;
  return a;
}
template <typename _Tp>
inline vector<int> operator*(vector<int> a, const _Tp &b) {
  return a *= b;
}
template <typename _Tp>
inline vector<int> operator*(const _Tp &b, vector<int> a) {
  return a *= b;
}
template <typename _Tp>
inline vector<int> operator/=(vector<int> &a, const _Tp &b) {
  unsigned long long inv = ksm(b);
  for (auto &&it : a) it = 1ll * it * inv % mod;
  return a;
}
template <typename _Tp>
inline vector<int> operator/(vector<int> a, const _Tp &b) {
  return a /= b;
}
template <typename _Tp>
inline vector<int> operator/(const _Tp &b, vector<int> a) {
  return a /= b;
}
};  // namespace Poly
using Poly::operator*;
using Poly::operator+;
vector<int> shift(vector<int> v) {
  int n = v.size();
  vector<int> ans(n + 1);
  for (int i = 0; i < n; i++) ans[i + 1] = v[i];
  return ans;
}
struct Node {
  mutable vector<int> f, g;
  Node(vector<int> tf = {0}, vector<int> tg = {1}) { f = tf, g = tg; }
};
vector<int> one = {0, 1};
Node operator+(const Node &x, const Node &y) {
  vector<int> tmp = y.f + y.g;
  vector<int> qwq = x.g * tmp;
  vector<int> f = x.f * tmp + shift(qwq), g = qwq;
  return (Node){f, g};
}
Node operator*(const Node &x, const Node &y) {
  vector<int> f = (x.f + x.g) * y.f + shift(x.g * y.f),
              g = (x.f + x.g) * y.g + shift(x.g * y.g);
  return (Node){f, g};
}
Node f[MN];
int dep[MN], siz[MN], son[MN], fa[MN];
void dfs1(int u, int f) {
  fa[u] = f, dep[u] = dep[f] + 1, siz[u] = 1;
  for (int v : e[u]) {
    if (v == f) continue;
    dfs1(v, u), siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
Node tmp[MN];
int cnt;
vector<int> res[MN];
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
Node solve(int l, int r) {
  if (l == r) return tmp[l];
  int mid = (l + r) / 2;
  return solve(l, mid) * solve(mid + 1, r);
}
pair<vector<int>, vector<int> > solve2(int l, int r) {
  if (l == r) return {shift(res[l]), res[l]};
  int mid = (l + r) / 2;
  auto [lf, lg] = solve2(l, mid);
  auto [rf, rg] = solve2(mid + 1, r);
  vector<int> A = lf * rg + lg * rf, B = lg * rg;
  return {A, B};
}
void dfs2(int u, int tp) {
  for (int v : e[u]) {
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
  cnt = 0;
  for (int v : e[u]) {
    if (v == fa[u] || v == son[u]) continue;
    res[++cnt] = f[v].f + f[v].g;
  }
  if (cnt) {
    auto [qx, qy] = solve2(1, cnt);
    f[u] = {qx, qy};
  }
  if (!son[u]) return;
  dfs2(son[u], tp);
  if (u != tp) return;
  int cur = u;
  cnt = 0;
  for (; cur; cur = son[cur]) tmp[++cnt] = f[cur];
  f[u] = solve(1, cnt);
}
signed main() {
  Poly::setup();
  init();
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    e[u].push_back(v), e[v].push_back(u);
  }
  dfs1(1, 0), dfs2(1, 1);
  vector<int> res = f[1].f + f[1].g;
  int ans = fac[n];
  for (int i = 1; i < (int)res.size(); i++) {
    int r = mul(res[i], fac[n - i]);
    if (i & 1)
      ans = sub(ans, r);
    else
      ans = add(ans, r);
  }
  cout << ans << endl;
  cerr << qwq << endl;
  cerr << clock() << endl;
  return FastIO::Fflush(), 0;
}
