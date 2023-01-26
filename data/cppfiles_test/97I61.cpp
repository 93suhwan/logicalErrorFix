#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
const int P = 998244353;
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
const int MN = 2e5 + 5, B = 1500, S = MN / B;
int n, k, f[MN], ans[MN], g[MN][S + 10];
vector<int> e[MN];
vector<pair<int, int> > qr[MN], qv[MN];
int fat[MN], dfn[MN], id[MN], tot;
void dfs0(int u, int fa) {
  fat[u] = fa;
  id[dfn[u] = ++tot] = u;
  for (auto v : e[u]) {
    if (v == fa) continue;
    dfs0(v, u);
  }
}
void dfs1(int u, int fa) {
  f[u] = 0;
  for (auto v : e[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    f[u] += max(1, f[v] - k);
  }
}
void dfs2(int u, int fa) {
  for (auto v : e[u]) {
    if (v == fa) continue;
    dfs2(v, u);
    for (int x = (0); x <= (S); x++)
      for (int y = (0); y <= (S - x); y++) {
        ckmax(g[u][x + y], g[u][x] + g[v][y]);
      }
  }
  for (auto it : qv[u]) {
    for (int i = (0); i <= (S); i++) {
      ckmax(ans[it.second], g[u][i] - i * it.first);
    }
  }
  for (int i = (S - 1); i >= (0); i--) g[u][i + 1] = g[u][i];
  g[u][0] = 1;
}
signed main() {
  n = read();
  for (int i = (1); i <= (n - 1); i++) {
    int u = read(), v = read();
    e[u].push_back(v), e[v].push_back(u);
  }
  int q = read();
  dfs0(1, 0);
  for (int i = (1); i <= (q); i++) {
    int x = read(), k = read();
    if (k <= B)
      qr[k].push_back(make_pair(x, i));
    else
      qv[x].push_back(make_pair(k, i));
  }
  for (k = 0; k <= B; k++) {
    if (!qr[k].size()) continue;
    memset(f, 0, sizeof(f));
    for (int i = (n); i >= (1); i--) {
      int u = id[i];
      f[dfn[fat[u]]] += max(1, f[i] - k);
    }
    for (auto it : qr[k]) {
      ans[it.second] = f[dfn[it.first]];
    }
  }
  dfs2(1, 0);
  for (int i = (1); i <= (q); i++) {
    FastIO::write(ans[i]);
    FastIO::write('\n');
  }
  return FastIO::Fflush(), 0;
}
