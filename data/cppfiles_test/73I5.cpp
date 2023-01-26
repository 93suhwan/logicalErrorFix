#include <bits/stdc++.h>
const int N = 1e6 + 10;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int n, m, ans, u[N], v[N], a[N];
int cov[N], cnt[N], val[N], Max[N], par[N], rev[N], ch[N][2];
inline int get(int u) { return ch[par[u]][1] == u; }
inline int rot(int u) { return ch[par[u]][0] != u && ch[par[u]][1] != u; }
inline void upd(int u) {
  Max[u] = std::max({Max[ch[u][0]], Max[ch[u][1]], (u > n) * val[u]});
  cnt[u] = cnt[ch[u][0]] + cnt[ch[u][1]] + (u > n);
}
inline void Rev(int u) { rev[u] ^= 1, std::swap(ch[u][0], ch[u][1]); }
inline void Cov(int u, int w) {
  cov[u] = val[u] = w, Max[u] = (cnt[u] > 0) * w;
}
inline void down(int u) {
  if (rev[u]) Rev(ch[u][0]), Rev(ch[u][1]), rev[u] ^= 1;
  if (cov[u] != -1) Cov(ch[u][0], cov[u]), Cov(ch[u][1], cov[u]), cov[u] = -1;
}
inline void Down(int u) {
  if (!rot(u)) Down(par[u]);
  down(u);
}
inline void rotate(int u) {
  int v = par[u], w = par[v], k = get(u);
  if (!rot(v)) ch[w][ch[w][1] == v] = u;
  par[ch[v][k] = ch[u][k ^ 1]] = v;
  par[ch[u][k ^ 1] = v] = u, par[u] = w, upd(v), upd(u);
}
inline void splay(int u) {
  Down(u);
  for (int f; f = par[u], !rot(u); rotate(u))
    if (!rot(f)) rotate(get(u) == get(f) ? f : u);
}
inline void access(int u) {
  for (int v = 0; u; u = par[v = u]) splay(u), ch[u][1] = v, upd(u);
}
inline void mkt(int u) {
  access(u);
  splay(u);
  Rev(u);
}
inline void split(int u, int v) {
  mkt(u);
  access(v);
  splay(v);
}
inline int find(int u) {
  access(u), splay(u);
  while (ch[u][0]) down(u), u = ch[u][0];
  return splay(u), u;
}
inline int add(int u, int v, int w) {
  mkt(u), mkt(v);
  if (rot(u) && rot(v)) return par[u] = par[v] = w, a[w - n] = 1;
  split(u, v);
  if (Max[v]) return 0;
  return Cov(v, w), 1;
}
inline void del(int u, int v, int w) {
  split(u, v), splay(w);
  if (a[w - n]) {
    a[w - n] = 0;
    int id = Max[w];
    if (id) {
      split(::u[id - n], ::v[id - n]), Cov(v, 0);
      split(u, v), splay(w);
    }
    par[u] = par[v] = ch[w][0] = ch[w][1] = 0;
    if (id) add(::u[id - n], ::v[id - n], id);
  } else
    Cov(v, 0);
}
int main() {
  n = read(), m = read(), ans = 0;
  for (int i = 1; i <= n + m; ++i) cov[i] = -1;
  for (int i = 1, p = 1; i <= m; ++i) {
    u[i] = read(), v[i] = read();
    while (!add(u[i], v[i], i + n)) del(u[p], v[p], p + n), ++p;
    ans += i - p + 1;
  }
  std::cout << ans << std::endl;
  return 0;
}
