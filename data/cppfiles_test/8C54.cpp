#include <bits/stdc++.h>
using namespace std;
inline void chmax(long long &x, long long y) { x = max(x, y); }
inline void chmin(long long &x, long long y) { x = min(x, y); }
inline void pls(long long &x, long long y, long long Mod) {
  x = (x + y >= Mod) ? (x + y - Mod) : (x + y);
}
inline void sub(long long &x, long long y, long long Mod) {
  x = (x - y < 0) ? (x - y + Mod) : (x - y);
}
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
long long lowbit(long long x) { return x & (-x); }
long long prime(long long x) {
  if (x <= 1) return 0;
  for (int i = 2; i <= int(sqrt(x)); i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
bool cmp(long long a, long long b) { return a > b; }
long long gcd(long long a, long long b) {
  long long r;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
inline int readint() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
inline long long readll() {
  long long f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
void fl(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
          dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
struct EDGE {
  int nxt, to;
} edge[100010 << 1];
int n, m, head[100010], tot, a[100010], in[100010];
void add_edge(int u, int v) {
  edge[++tot].nxt = head[u];
  edge[tot].to = v;
  head[u] = tot;
}
int fa[100010], son[100010], dep[100010], t[100010];
int top[100010], siz[100010], dfn[100010], tick;
void dfs1(int u, int ff) {
  fa[u] = ff;
  dep[u] = dep[ff] + 1;
  siz[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == ff) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[son[u]] < siz[v]) {
      son[u] = v;
    }
  }
}
int calc(int u, int v) { return max(abs(u + v), abs(u - v)); }
void dfs2(int u, int ff) {
  dfn[u] = ++tick;
  t[dfn[u]] = calc(a[u], a[fa[u]]);
  top[u] = ff;
  if (son[u]) dfs2(son[u], ff);
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}
long long sum[100010];
void add(int x, int k) {
  for (; x <= n; sum[x] += k, x += lowbit(x))
    ;
}
long long query(int x) {
  long long ans = 0;
  for (; x; ans += sum[x], x ^= lowbit(x))
    ;
  return ans;
}
void modify(int x, int k) {
  a[x] = k;
  int qwq = calc(a[x], a[fa[x]]);
  add(dfn[x], qwq - t[dfn[x]]);
  t[dfn[x]] = qwq;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa[x]) continue;
    qwq = calc(a[x], a[v]);
    add(dfn[v], qwq - t[dfn[v]]);
    t[dfn[v]] = qwq;
  }
}
long long Query(int x, int y) {
  long long ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) {
      swap(x, y);
    }
    if (x != top[x]) ans += query(dfn[x]) - query(dfn[top[x]]);
    t[dfn[top[x]]] = calc(a[top[x]], a[fa[top[x]]]);
    ans += t[dfn[top[x]]];
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) {
    swap(x, y);
  }
  if (x != y) ans += query(dfn[y]) - query(dfn[x]);
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
    add_edge(v, u);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) add(i, t[i]);
  for (int i = 1; i <= m; i++) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1)
      modify(x, y);
    else
      cout << Query(x, y) << endl;
  }
  return 0;
}
