#include <bits/stdc++.h>
using namespace std;
int n, qq;
const int MAXN = 1e6 + 10;
int head[MAXN], l;
struct ed {
  int to, nxt;
} e[MAXN];
void add(int u, int v) {
  e[++l].to = v;
  e[l].nxt = head[u];
  head[u] = l;
}
int a[MAXN];
int tot, dfn[MAXN];
struct node {
  int v, l, k, id;
} q[MAXN];
void dfs(int u) {
  dfn[u] = ++tot;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    dfs(v);
  }
}
bool cmp(node a, node b) { return dfn[a.v] < dfn[b.v]; }
int c[MAXN];
int lowbit(int x) { return x & -x; }
void upd(int pos, int num) {
  for (int i = pos; i < MAXN; i += lowbit(i)) {
    c[i] += num;
  }
}
int p;
int ans[MAXN];
int vis[MAXN];
set<int> S[MAXN];
int query(int pos) {
  int num = 0;
  for (int i = pos; i; i -= lowbit(i)) num += c[i];
  return num;
}
void solve(int u) {
  vis[a[u]]++;
  if (vis[a[u]] != 1) upd(vis[a[u]] - 1, -1);
  upd(vis[a[u]], 1);
  if (vis[a[u]] != 1) S[vis[a[u]] - 1].erase(a[u]);
  S[vis[a[u]]].insert(a[u]);
  while (u == q[p].v) {
    int num = query(1000000) - query(q[p].l - 1);
    if (p <= qq && num < q[p].k) {
      ans[q[p].id] = -1;
      p++;
      continue;
    }
    int l = q[p].l;
    int r = 1e6;
    while (l <= r) {
      int mid = l + r >> 1;
      if (query(mid) - query(l - 1) >= q[p].k)
        r = mid - 1;
      else
        l = mid + 1;
    }
    ans[q[p].id] = *(S[l].begin());
    p++;
  }
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    solve(v);
  }
  vis[a[u]]--;
  upd(vis[a[u]] + 1, -1);
  if (vis[a[u]]) upd(vis[a[u]], 1);
  S[vis[a[u]] + 1].erase(a[u]);
  if (vis[a[u]]) S[vis[a[u]]].insert(a[u]);
}
int main() {
  std::ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) {
    cin >> n >> qq;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
      int fa;
      cin >> fa;
      add(fa, i);
    }
    tot = 0;
    dfs(1);
    for (int i = 1; i <= qq; i++) {
      cin >> q[i].v >> q[i].l >> q[i].k;
      q[i].id = i;
    }
    p = 1;
    sort(q + 1, q + qq + 1, cmp);
    solve(1);
    for (int i = 1; i <= qq; i++) cout << ans[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) vis[i] = head[i] = 0, S[i].clear();
    l = 0;
  }
}
