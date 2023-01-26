#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> e[N];
int dfn[N], tot, L[N], R[N], f[N], id[N], dep[N], vis[N];
void dfs(int u, int fath) {
  L[u] = tot + 1, f[u] = fath, dep[u] = dep[fath] + 1;
  if (fath && e[u].size() == 1) dfn[u] = ++tot, id[tot] = u;
  for (int v : e[u])
    if (v != fath) dfs(v, u);
  R[u] = tot;
}
int mx[N << 2], pos[N << 2], tag[N << 2];
void add(int p, int v) { mx[p] += v, tag[p] += v; }
void pushdown(int p) {
  add(p << 1, tag[p]), add(p << 1 | 1, tag[p]), tag[p] = 0;
}
void build(int p, int l, int r) {
  if (l == r) {
    mx[p] = dep[id[l]], pos[p] = id[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
  if (mx[p] == mx[p << 1])
    pos[p] = pos[p << 1];
  else
    pos[p] = pos[p << 1 | 1];
}
void upt(int p, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return add(p, -1);
  pushdown(p);
  int mid = (l + r) >> 1;
  if (ql <= mid) upt(p << 1, l, mid, ql, qr);
  if (mid < qr) upt(p << 1 | 1, mid + 1, r, ql, qr);
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
  if (mx[p] == mx[p << 1])
    pos[p] = pos[p << 1];
  else
    pos[p] = pos[p << 1 | 1];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  if (tot <= k) {
    long long ans = -1e18;
    for (int i = tot; i <= k; ++i) ans = max(ans, 1ll * i * (n - i));
    return cout << ans, 0;
  }
  build(1, 1, tot);
  int ans = 0, x;
  for (int i = 1; i <= k; ++i) {
    ans += mx[1], x = pos[1];
    while (x && !vis[x]) vis[x] = 1, upt(1, 1, tot, L[x], R[x]), x = f[x];
  }
  cout << 1ll * (k - (n - ans)) * (ans - k) << "\n";
}
