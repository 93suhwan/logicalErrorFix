#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int inf = 1e9;
const long long mod = 998244353;
int n, m, num;
int a[N], lp[N], rp[N], val[N], dep[N], fa[N], wh[N];
bool vis[N];
vector<int> adj[N];
void dfs(int x, int ff) {
  bool flg = 1;
  lp[x] = inf, rp[x] = -inf;
  fa[x] = ff;
  for (auto v : adj[x]) {
    if (v == ff) continue;
    flg = 0;
    dep[v] = dep[x] + 1, dfs(v, x);
    lp[x] = min(lp[x], lp[v]);
    rp[x] = max(rp[x], rp[v]);
  }
  if (flg) {
    ++num;
    lp[x] = rp[x] = num;
    val[num] = dep[x];
    wh[num] = x;
    return;
  }
}
int seg[N], laz[N];
void push_up(int k) { seg[k] = max(seg[(k << 1)], seg[(k << 1 | 1)]); }
void push_down(int k) {
  if (laz[k]) {
    seg[(k << 1)] += laz[k];
    seg[(k << 1 | 1)] += laz[k];
    laz[(k << 1)] += laz[k];
    laz[(k << 1 | 1)] += laz[k];
    laz[k] = 0;
  }
}
void build(int l = 1, int r = num, int k = 1) {
  if (l == r) return (void)(seg[k] = val[l]);
  build(l, ((l + r) >> 1), (k << 1));
  build(((l + r) >> 1) + 1, r, (k << 1 | 1));
  push_up(k);
}
int find(int l = 1, int r = num, int k = 1) {
  if (l == r) return l;
  push_down(k);
  if (seg[(k << 1 | 1)] < seg[(k << 1)])
    return find(l, ((l + r) >> 1), (k << 1));
  return find(((l + r) >> 1) + 1, r, (k << 1 | 1));
}
void upd(int L, int R, int val, int l = 1, int r = num, int k = 1) {
  if (l > R || r < L) return;
  if (L <= l && r <= R) {
    seg[k] += val;
    laz[k] += val;
    return;
  }
  push_down(k);
  upd(L, R, val, l, ((l + r) >> 1), (k << 1));
  upd(L, R, val, ((l + r) >> 1) + 1, r, (k << 1 | 1));
  push_up(k);
}
void sol() {
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dep[1] = 1, dfs(1, 0);
  if (num <= m) {
    long long ans = -1e18;
    for (int i = num; i <= m; i++) {
      ans = max(ans, 1LL * i * (n - i));
    }
    cout << ans << '\n';
  } else {
    build();
    for (int i = 1; i <= m; i++) {
      int x = find();
      x = wh[x];
      while (x != 0 && !vis[x]) {
        vis[x] = 1;
        upd(lp[x], rp[x], -1);
        x = fa[x];
      }
    }
    int blue = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) ++blue;
    }
    cout << 1LL * (n - m - blue) * (m - blue) << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  sol();
}
