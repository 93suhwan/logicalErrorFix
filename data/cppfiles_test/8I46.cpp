#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-8;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int maxn = 200005;
int cnt;
int l[maxn], r[maxn], a[maxn], dfn[maxn], d[maxn];
int deep[maxn], lg[maxn], fa[maxn][22];
vector<int> e[maxn];
void dfs(int cur, int par, int dis) {
  l[cur] = ++cnt;
  deep[cur] = deep[par] + 1;
  fa[cur][0] = par;
  d[cur] = dis + a[cur];
  for (int i = 1; i <= lg[deep[cur]]; ++i) {
    fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
  }
  for (auto it : e[cur]) {
    if (it == par) continue;
    dfs(it, cur, d[cur]);
  }
  r[cur] = ++cnt;
  dfn[l[cur]] = dfn[r[cur]] = d[cur];
}
struct node {
  int l, r, val, addv;
} tree[maxn << 2];
void build(int o, int l, int r) {
  tree[o].l = l;
  tree[o].r = r;
  if (l == r) {
    tree[o].val = dfn[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(o * 2, l, mid);
  build(o * 2 + 1, mid + 1, r);
}
void pushdown(int o) {
  if (tree[o].addv) {
    tree[o * 2].val += tree[o].addv * (tree[o * 2].r - tree[o * 2].l + 1);
    tree[o * 2 + 1].val +=
        tree[o].addv * (tree[o * 2 + 1].r - tree[o * 2 + 1].l + 1);
    tree[o * 2].addv += tree[o].addv;
    tree[o * 2 + 1].addv += tree[o].addv;
    tree[o].addv = 0;
  }
}
void change(int o, int l, int r, int k) {
  if (tree[o].l >= l && tree[o].r <= r) {
    tree[o].val += k * (tree[o].r - tree[o].l + 1);
    tree[o].addv += k;
    return;
  }
  pushdown(o);
  int mid = (tree[o].l + tree[o].r) >> 1;
  if (mid >= l) change(o * 2, l, r, k);
  if (mid < r) change(o * 2 + 1, l, r, k);
  tree[o].val = tree[o * 2].val + tree[o * 2 + 1].val;
}
int ask(int o, int l, int r) {
  if (tree[o].l >= l && tree[o].r <= r) {
    return tree[o].val;
  }
  pushdown(o);
  int mid = (tree[o].l + tree[o].r) >> 1;
  int ans = 0;
  if (mid >= l) ans += ask(o * 2, l, r);
  if (mid < r) ans += ask(o * 2 + 1, l, r);
  return ans;
}
int lca(int x, int y) {
  if (deep[x] < deep[y]) {
    swap(x, y);
  }
  while (deep[x] > deep[y]) {
    x = fa[x][lg[deep[x] - deep[y]] - 1];
  }
  if (x == y) return x;
  for (int k = lg[deep[x]] - 1; k >= (0); --k) {
    if (fa[x][k] != fa[y][k]) {
      x = fa[x][k], y = fa[y][k];
    }
  }
  return fa[x][0];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0, 0);
  build(1, 1, 2 * n);
  while (q--) {
    int op, u, v;
    cin >> op >> u >> v;
    if (op == 1) {
      v = abs(v);
      change(1, l[u], r[u], v - a[u]);
      a[u] = v;
    } else {
      int x = lca(u, v);
      int ans = ask(1, l[u], l[u]) + ask(1, l[v], l[v]) -
                2 * ask(1, l[x], l[x]) + a[x];
      ans = ans * 2 - a[u] - a[v];
      cout << ans << endl;
    }
  }
  return 0;
}
