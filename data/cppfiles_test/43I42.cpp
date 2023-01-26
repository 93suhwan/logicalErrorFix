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
const int MN = 2e5 + 5;
struct ele {
  int x, y, z;
  ele() {}
  ele(int X, int Y, int Z) : x(X), y(Y), z(Z) {}
  bool operator<(const ele &b) const { return z > b.z; }
};
int n, q, a[MN];
namespace Tree {
vector<pair<int, int> > e[MN];
int f[MN][20], mx[MN][20], dep[MN];
void dfs(int u, int fa, int fr) {
  f[u][0] = fa, mx[u][0] = fr, dep[u] = dep[fa] + 1;
  for (int i = 1; i <= 19; i++)
    f[u][i] = f[f[u][i - 1]][i - 1],
    mx[u][i] = max(mx[u][i - 1], mx[f[u][i - 1]][i - 1]);
  for (auto it : e[u]) {
    int v = it.first, w = it.second;
    if (v == fa) continue;
    dfs(v, u, w);
  }
}
int qry(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int ans = 0;
  for (int i = 19; i >= 0; i--)
    if (dep[f[u][i]] >= dep[v]) ckmax(ans, mx[u][i]), u = f[u][i];
  if (u == v) return ans;
  for (int i = 19; i >= 0; i--)
    if (f[u][i] != f[v][i])
      ckmax(ans, max(mx[u][i], mx[v][i])), u = f[u][i], v = f[v][i];
  ckmax(ans, max(mx[u][0], mx[v][0]));
  return ans;
}
void init() { dfs(1, 0, 0); }
}  // namespace Tree
ele e[MN], qr[MN];
pair<int, int> ans[MN];
int f[MN], mx[MN];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
int merge(int x, int y) {
  int ox = x, oy = y;
  x = find(x), y = find(y);
  if (x == y) return 0;
  if (a[x] < a[y]) swap(x, y);
  if (a[x] == a[y]) ckmax(mx[x], max(mx[y], Tree::qry(ox, oy)));
  f[y] = x;
  return 1;
}
signed main() {
  n = read(), q = read();
  for (int i = (1); i <= (n); i++) {
    a[i] = read();
  }
  for (int i = (1); i <= (n - 1); i++) {
    int u = read(), v = read(), c = read(), t = read();
    e[i].x = u, e[i].y = v, e[i].z = c;
    Tree::e[u].push_back(make_pair(v, t)),
        Tree::e[v].push_back(make_pair(u, t));
  }
  sort(e + 1, e + n);
  Tree::init();
  for (int i = (1); i <= (n); i++) f[i] = i, mx[i] = 0;
  for (int i = (1); i <= (q); i++) {
    int v = read(), x = read();
    qr[i].x = i, qr[i].y = x, qr[i].z = v;
  }
  sort(qr + 1, qr + 1 + q);
  e[0].z = ((1 << 30) - 1);
  int now = 0;
  for (int i = (0); i <= (n - 1); i++) {
    int u = e[i].x, v = e[i].y;
    merge(u, v);
    while (now < q && qr[now + 1].z <= e[i].z && qr[now + 1].z > e[i + 1].z) {
      now++;
      int x = qr[now].y, fx = find(qr[now].y);
      ans[qr[now].x] = make_pair(a[fx], max(Tree::qry(x, fx), mx[fx]));
    }
  }
  for (int i = (1); i <= (q); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return FastIO::Fflush(), 0;
}
