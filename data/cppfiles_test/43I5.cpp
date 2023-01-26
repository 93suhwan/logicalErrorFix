#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
using LL = long long;
using PII = std::pair<int, int>;
constexpr int N(4e5 + 5);
struct Edge {
  int a, b, c, d;
} e[N];
int n, m, a[N], b[N], bn;
int fa[N];
int find(int x) {
  while (x != fa[x]) x = fa[x] = fa[fa[x]];
  return x;
}
std::vector<int> g1[N], g2[N];
int f1[19][N], f2[19][N], v1[N], v2[N];
int in1[N], out1[N], in2[N], out2[N], st[19][N], lg[N];
int askMax(int l, int r) {
  int k = lg[r - l + 1];
  return std::max(st[k][r], st[k][l + (1 << k) - 1]);
}
void dfs1(int x) {
  in1[x] = in1[0] + 1;
  if (x <= n) {
    in1[0]++;
    st[0][in1[0]] = a[x];
  }
  for (int y : g1[x]) {
    dfs1(y);
  }
  out1[x] = in1[0];
}
struct Node {
  Node *ls, *rs;
  int w;
} * Null;
void ins(Node *&o, int l, int r, int x) {
  o = new Node(*o);
  o->w++;
  if (l == r) {
    return;
  }
  int m = l + r >> 1;
  x <= m ? ins(o->ls, l, m, x) : ins(o->rs, m + 1, r, x);
}
int ask(Node *p, Node *q, int l, int r, int x, int y) {
  if (r < x || y < l) return 0;
  if (x <= l && r <= y) return q->w - p->w;
  int m = l + r >> 1;
  return ask(p->ls, q->ls, l, m, x, y) + ask(p->rs, q->rs, m + 1, r, x, y);
}
std::map<int, Node *> root[N];
void dfs2(int x) {
  in2[x] = in2[0] + 1;
  if (x <= n) {
    in2[0]++;
    Node *p = root[a[x]].rbegin()->second;
    ins(p, 1, n, in1[x]);
    root[a[x]][in2[x]] = p;
  }
  for (int y : g2[x]) {
    dfs2(y);
  }
  out2[x] = in2[0];
}
void init() {
  std::sort(e + 1, e + n, [](Edge u, Edge v) { return u.c > v.c; });
  for (int i = 1; i <= n; i++) fa[i] = i;
  int t = n;
  for (int i = 1; i < n; i++) {
    int x = find(e[i].a), y = find(e[i].b);
    if (x == y) continue;
    t++;
    fa[x] = fa[y] = fa[t] = t;
    f1[0][x] = f1[0][y] = t;
    g1[t].push_back(x);
    g1[t].push_back(y);
    v1[t] = e[i].c;
  }
  assert(t == n * 2 - 1);
  for (int i = 1; i < 19; i++) {
    for (int j = 1; j <= t; j++) {
      f1[i][j] = f1[i - 1][f1[i - 1][j]];
    }
  }
  dfs1(t);
  assert(in1[0] == n);
  for (int i = 1; i < 18; i++) {
    for (int j = 1 << i; j <= n; j++) {
      st[i][j] = std::max(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
    }
  }
  for (int i = 2; i <= n; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  std::sort(e + 1, e + n, [](Edge u, Edge v) { return u.d < v.d; });
  for (int i = 1; i <= n; i++) fa[i] = i;
  t = n;
  for (int i = 1; i < n; i++) {
    int x = find(e[i].a), y = find(e[i].b);
    if (x == y) continue;
    t++;
    fa[x] = fa[y] = fa[t] = t;
    f2[0][x] = f2[0][y] = t;
    g2[t].push_back(x);
    g2[t].push_back(y);
    v2[t] = e[i].d;
  }
  for (int i = 1; i < 19; i++) {
    for (int j = 1; j <= t; j++) {
      f2[i][j] = f2[i - 1][f2[i - 1][j]];
    }
  }
  Null = new Node;
  *Null = {Null, Null, 0};
  for (int i = 0; i < bn; i++) {
    root[i][0] = Null;
  }
  dfs2(t);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i], b[i - 1] = a[i];
  std::sort(b, b + n);
  bn = std::unique(b, b + n) - b;
  for (int i = 1; i <= n; i++) {
    a[i] = std::lower_bound(b, b + bn, a[i]) - b;
  }
  for (int i = 1; i < n; i++) {
    std::cin >> e[i].a >> e[i].b >> e[i].c >> e[i].d;
  }
  init();
  for (int i = 1; i <= m; i++) {
    int v, u, x;
    std::cin >> v >> u;
    x = u;
    for (int j = 18; j >= 0; j--) {
      if (f1[j][x] && v1[f1[j][x]] >= v) {
        x = f1[j][x];
      }
    }
    int l = in1[x], r = out1[x], max = askMax(l, r);
    if (x == u) {
      std::cout << b[max] << " 0\n";
      continue;
    }
    Node *p = Null, *q = root[max].rbegin()->second;
    int cnt = ask(p, q, 1, n, l, r);
    x = u;
    for (int j = 18; j >= 0; j--) {
      int y = f2[j][x];
      if (!y) continue;
      p = (--root[max].lower_bound(in2[y]))->second;
      q = (--root[max].upper_bound(out2[y]))->second;
      if (ask(p, q, 1, n, l, r) != cnt) {
        x = y;
      }
    }
    std::cout << b[max] << " " << v2[f2[0][x]] << "\n";
  }
  return 0;
}
