#include <bits/stdc++.h>
using namespace std;
const int maxn = 600005;
const int inf = 1 << 30;
struct BIT {
  int c[maxn];
  void update(int x, int val, int n) {
    for (int i = x; i <= n; i += i & -i) {
      c[i] += val;
    }
  }
  int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= i & -i) {
      ans += c[i];
    }
    return ans;
  }
} T;
struct Edge {
  int to, next, val;
  Edge(int to = 0, int next = 0, int val = 0) : to(to), next(next), val(val) {}
} a[maxn * 2];
struct Question {
  int x, y, val;
} e[maxn];
int n, m;
int cnt;
int tot;
int top;
int h[maxn];
int fa[maxn];
int lg[maxn];
int ans[maxn];
int pre[maxn];
int fir[maxn];
int lst[maxn];
int depth[maxn];
int st[20][maxn * 2];
int xor_val[maxn * 2];
bool vis[maxn];
void add(int x, int y, int val) {
  a[++cnt] = Edge(y, h[x], val);
  h[x] = cnt;
}
int f(int x) { return fa[x] == x ? x : fa[x] = f(fa[x]); }
void dfs(int x) {
  vis[x] = 1;
  st[0][++top] = x;
  pre[x] = top;
  fir[x] = ++tot;
  for (int i = h[x]; i; i = a[i].next) {
    if (vis[a[i].to]) {
      continue;
    }
    xor_val[a[i].to] = xor_val[x] ^ a[i].val;
    depth[a[i].to] = depth[x] + 1;
    fa[a[i].to] = x;
    dfs(a[i].to);
    st[0][++top] = x;
  }
  lst[x] = tot;
}
int getmin(int x, int y) { return depth[x] < depth[y] ? x : y; }
int lca(int x, int y) {
  x = pre[x], y = pre[y];
  if (x > y) {
    swap(x, y);
  }
  int k = lg[y - x + 1];
  return getmin(st[k][x], st[k][y - (1 << k) + 1]);
}
int xor_dist(int x, int y) { return xor_val[x] ^ xor_val[y]; }
int check(int x, int y, int p) {
  return T.ask(fir[x]) + T.ask(fir[y]) - 2 * T.ask(fir[p]);
}
void update(int x, int p) {
  if (x == p) {
    return;
  }
  while (x != p) {
    T.update(fir[x], 1, n);
    T.update(lst[x] + 1, -1, n);
    x = fa[x];
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> e[i].x >> e[i].y >> e[i].val;
    int x = f(e[i].x), y = f(e[i].y);
    if (x != y) {
      add(e[i].x, e[i].y, e[i].val);
      add(e[i].y, e[i].x, e[i].val);
      fa[x] = y;
      ans[i] = 1;
    }
  }
  memset(fa, 0, sizeof(fa));
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  for (int i = 2; i <= top; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; (1 << i) <= top; i++) {
    for (int j = 1; j + (1 << i) - 1 <= top; j++) {
      st[i][j] = getmin(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (ans[i]) {
      continue;
    }
    int x = e[i].x, y = e[i].y, val = e[i].val;
    if ((xor_dist(x, y) ^ val) == 0) {
      continue;
    }
    int p = lca(x, y);
    if (check(x, y, p)) {
      continue;
    }
    update(x, p);
    update(y, p);
    ans[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    cout << (ans[i] ? "YES" : "NO") << "\n";
  }
}
