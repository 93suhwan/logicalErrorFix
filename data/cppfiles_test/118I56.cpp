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
vector<int> rev, rt;
const int G = 3;
vector<int> operator+(vector<int> a, vector<int> b) {
  int n = max(a.size(), b.size());
  a.resize(n), b.resize(n);
  for (int i = 0; i < n; i++) a[i] = add(a[i], b[i]);
  return a;
}
vector<int> operator-(vector<int> a, vector<int> b) {
  int n = max(a.size(), b.size());
  a.resize(n), b.resize(n);
  for (int i = 0; i < n; i++) a[i] = sub(a[i], b[i]);
  return a;
}
void Init_Inv() {
  int lim = 1 << 19;
  rt.resize(lim);
  for (int mid = 1; mid < lim; mid <<= 1) {
    int w = ksm(G, (P - 1) / (mid << 1));
    rt[mid] = 1;
    for (int i = 1; i < mid; i++) rt[mid + i] = mul(rt[mid + i - 1], w);
  }
}
void init(int B) {
  int n = 1 << B;
  rev.resize(n);
  for (int i = 1; i < n; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (B - 1));
}
void ntt(vector<int> &a, int B) {
  for (int i = 0; i < (int)a.size(); i++)
    if (rev[i] > i) swap(a[rev[i]], a[i]);
  for (int i = 1; i < 1 << B; i <<= 1) {
    for (int j = 0; j < 1 << B; j += i << 1) {
      for (int k = 0; k < i; k++) {
        int x = a[j + k], y = mul(a[i + j + k], rt[i + k]);
        a[j + k] = add(x, y), a[i + j + k] = sub(x, y);
      }
    }
  }
}
void idft(vector<int> &a, int B) {
  reverse(a.begin() + 1, a.end());
  ntt(a, B);
  int I = P - (P / (1 << B));
  for (int i = 0; i < (int)a.size(); i++) a[i] = mul(a[i], I);
}
vector<int> operator*(vector<int> x, vector<int> y) {
  int n = x.size() + y.size() - 1;
  if (n <= 256) {
    vector<int> ans(n);
    for (int i = 0; i < (int)x.size(); i++)
      for (int j = 0; j < (int)y.size(); j++)
        ans[i + j] = add(ans[i + j], mul(x[i], y[j]));
    return ans;
  }
  qwq += n;
  int B = 0;
  while (1 << B < n) B++;
  x.resize(1 << B), y.resize(1 << B);
  init(B);
  ntt(x, B), ntt(y, B);
  for (int i = 0; i < 1 << B; i++) x[i] = mul(x[i], y[i]);
  idft(x, B);
  x.resize(n);
  return x;
}
vector<int> shift(vector<int> v) {
  int n = v.size();
  vector<int> ans(n + 1);
  for (int i = 0; i < n; i++) ans[i + 1] = v[i];
  return ans;
}
};  // namespace Poly
using namespace Poly;
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
  freopen("in.txt", "r", stdin);
  Init_Inv();
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
