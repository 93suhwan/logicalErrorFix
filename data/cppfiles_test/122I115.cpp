#include <bits/stdc++.h>
using namespace std;
int read();
const int N = 2e5 + 5;
int t, n, m;
int f[N], d[N];
int getf(int x) {
  if (x == f[x]) return x;
  int rt = getf(f[x]);
  d[x] ^= d[f[x]];
  return f[x] = rt;
}
int merge(int u, int v, int w) {
  int fu = getf(u), fv = getf(v);
  if (fu != fv) return f[fu] = fv, d[fu] = d[u] ^ d[v] ^ w, 0;
  return d[u] ^ d[v] ^ w;
}
int fir[N], to[N << 1], nxt[N << 1], eds, wei[N << 1];
void addedge(int u, int v, int w) {
  to[++eds] = v;
  wei[eds] = w;
  nxt[eds] = fir[u];
  fir[u] = eds;
}
int bad;
int ans[N], val[N], fa[N];
void dfs(int u) {
  for (int i = fir[u], v; v = to[i], i; i = nxt[i])
    if (v != fa[u]) {
      val[v] = wei[i];
      if (wei[i] != -1) bad |= merge(u, v, __builtin_parity(wei[i]));
      fa[v] = u;
      dfs(v);
    }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = (1); i <= (n); ++i) fir[i] = 0;
    eds = 0;
    for (int i = (1); i <= (n); ++i) f[i] = i, d[i] = 0;
    for (int i = 1, u, v, w; i < n; ++i) {
      cin >> u >> v >> w;
      addedge(u, v, w);
      addedge(v, u, w);
    }
    bad = 0;
    dfs(1);
    for (int i = 1, u, v, w; i <= m; ++i) {
      cin >> u >> v >> w;
      bad |= merge(u, v, w);
    }
    if (bad) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = (2); i <= (n); ++i)
      if (getf(i) == getf(1))
        ans[i] = d[i] ^ d[1];
      else
        ans[i] = d[i];
    for (int i = (2); i <= (n); ++i)
      cout << fa[i] << ' ' << i << ' ' << (val[i] != -1 ? val[i] : ans[i])
           << endl;
  }
  return 0;
}
const int S = 1 << 21;
char p0[S], *p1, *p2;
inline int read() {
  static int x, c, f;
  x = 0;
  f = 1;
  do
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++),
    c == '-' && (f = -1);
  while (!isdigit(c));
  do
    x = x * 10 + (c & 15),
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++);
  while (isdigit(c));
  return x * f;
}
