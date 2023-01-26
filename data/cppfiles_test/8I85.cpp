#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const long long lim = 1e18;
inline int rd() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 2e5 + 10;
vector<int> g[N];
int f[25][N], d[N];
void dfs(int p, int fa) {
  f[0][p] = fa;
  d[p] = d[fa] + 1;
  for (int i = 1; i <= 20; ++i) f[i][p] = f[i - 1][f[i - 1][p]];
  for (int x : g[p])
    if (x != fa) dfs(x, p);
}
int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  for (int i = 20; ~i; --i)
    if (d[x] - d[y] >> i & 1) x = f[i][x];
  if (x == y) return x;
  for (int i = 20; ~i; --i)
    if (f[i][x] != f[i][y]) x = f[i][x], y = f[i][y];
  return f[0][x];
}
int dfn[N], len = 0, pos[N];
int cnt[N];
int n, q;
int C[N];
int lowbit(int x) { return x & (-x); }
void update(int x, int num) {
  while (x < N) {
    C[x] += num;
    x += lowbit(x);
  }
}
long long query(int x) {
  long long num = 0;
  while (x) {
    num += C[x];
    x -= lowbit(x);
  }
  return num;
}
void dfs2(int u, int fa) {
  dfn[u] = ++len;
  for (auto to : g[u]) {
    if (to == fa) continue;
    dfs2(to, u);
  }
  pos[u] = len + 1;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &cnt[i]);
    cnt[i] = abs(cnt[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) {
    update(dfn[i], cnt[i]);
    update(pos[i], -cnt[i]);
  }
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      y = abs(y);
      update(dfn[x], y - cnt[x]);
      update(pos[x], -(y - cnt[x]));
      cnt[x] = y;
    } else {
      long long ans;
      ans = (query(dfn[x]) + query(dfn[y]) - query(dfn[lca(x, y)]) -
             query(dfn[f[0][lca(x, y)]])) *
                2 -
            cnt[x] - cnt[y];
      printf("%lld\n", ans);
    }
  }
}
