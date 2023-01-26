#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
long long readll() {
  long long x = 0, f = 0;
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
struct edge {
  int from, to, c, t;
  bool operator<(const edge &e2) const { return c > e2.c; }
};
struct qry {
  int v, x, ans, idx, ansi;
  bool operator<(const qry &q2) const { return v > q2.v; }
};
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int n, q, e[N], f[N], mxi[N], mx[N], sz[N], fa[N][20], mxv[N][20], dep[N];
vector<edge> eg;
vector<int> G[N];
qry qy[N];
edge eg2[N];
bool cmp(const qry &q1, const qry &q2) { return q1.idx < q2.idx; }
void dfs(int u, int f, int val, int d) {
  fa[u][0] = f;
  mxv[u][0] = val;
  dep[u] = d;
  for (int i = 1; i <= 19; i++) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
    mxv[u][i] = max(mxv[u][i - 1], mxv[fa[u][i - 1]][i - 1]);
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = eg[G[u][i]].to;
    if (v != f) {
      dfs(v, u, eg[G[u][i]].t, d + 1);
    }
  }
}
int getmx(int u, int v) {
  int ans = 0;
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; i >= 0; i--) {
    if (dep[fa[u][i]] >= dep[v]) {
      ans = max(ans, mxv[u][i]);
      u = fa[u][i];
    }
  }
  if (u == v) return ans;
  for (int i = 19; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      ans = max(ans, mxv[u][i]);
      ans = max(ans, mxv[v][i]);
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  ans = max(ans, mxv[u][0]);
  ans = max(ans, mxv[v][0]);
  u = fa[u][0];
  v = fa[v][0];
  return ans;
}
void addedge(int a, int b, int c, int t) {
  eg.push_back((edge){a, b, c, t});
  G[a].push_back(eg.size() - 1);
  eg.push_back((edge){b, a, c, t});
  G[b].push_back(eg.size() - 1);
}
int find(int u) {
  if (f[u] == u) return u;
  return f[u] = find(f[u]);
}
void merge(int u, int v) {
  int fu = find(u);
  int fv = find(v);
  if (fu == fv) return;
  if (sz[fu] < sz[fv]) swap(fu, fv);
  sz[u] += sz[v];
  if (e[mxi[fu]] > e[mxi[fv]]) {
  } else if (e[mxi[fu]] < e[mxi[fv]]) {
    mxi[fu] = mxi[fv];
    mx[fu] = mx[fv];
  } else {
    mx[fu] = max(mx[fu], mx[fv]);
    mx[fu] = max(mx[fu], getmx(mxi[fu], mxi[fv]));
  }
  f[fv] = fu;
}
void solve() {
  n = read();
  q = read();
  for (int i = 1; i <= n; i++) e[i] = read();
  int a, b, c, t;
  for (int i = 1; i <= n - 1; i++) {
    a = read();
    b = read();
    c = read();
    t = read();
    addedge(a, b, c, t);
    eg2[i] = (edge){a, b, c, t};
  }
  sort(eg2 + 1, eg2 + n);
  for (int i = 1; i <= q; i++) {
    qy[i].v = read();
    qy[i].x = read();
    qy[i].idx = i;
  }
  sort(qy + 1, qy + q + 1);
  dfs(1, 0, 0, 1);
  for (int i = 1; i <= n; i++) f[i] = i, mxi[i] = i, mx[i] = 0, sz[i] = 1;
  int j = 1;
  for (int i = 1; i <= q; i++) {
    while (j <= n - 1 && eg2[j].c >= qy[i].v) {
      merge(eg2[j].from, eg2[j].to);
      j++;
    }
    int fx = find(qy[i].x);
    qy[i].ansi = e[mxi[fx]];
    qy[i].ans = max(getmx(qy[i].x, mxi[fx]), mx[fx]);
  }
  sort(qy + 1, qy + q + 1, cmp);
  for (int i = 1; i <= q; i++) {
    cout << qy[i].ansi << " " << qy[i].ans << endl;
  }
}
int main() {
  solve();
  return 0;
}
