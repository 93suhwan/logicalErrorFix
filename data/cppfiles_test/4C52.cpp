#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n, k;
int a[maxn];
vector<pair<int, int> > gr[maxn];
bool del[maxn];
int sub[maxn];
int f[maxn];
int sum[maxn];
int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
int mns(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
struct fenwick_tree {
  int sum[maxn], cnt[maxn];
  void Add(int x, int a) {
    for (; x < maxn; x += x & -x) {
      sum[x] = add(sum[x], a);
      ++cnt[x];
    }
  }
  void Del(int x, int a) {
    for (; x < maxn; x += x & -x) {
      sum[x] = mns(sum[x], a);
      --cnt[x];
    }
  }
  int get_sum(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) {
      res = add(res, sum[x]);
    }
    return res;
  }
  int get_cnt(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) {
      res += cnt[x];
    }
    return res;
  }
} tree[2];
int ans = 0;
void read_input() {
  cin >> n >> k;
  ++k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    gr[u].push_back(pair<int, int>(v, t));
    gr[v].push_back(pair<int, int>(u, t));
  }
}
void dfs_prep(int u, int p) {
  sub[u] = 1;
  for (auto& to : gr[u]) {
    int v = to.first;
    if (v == p || del[v]) continue;
    dfs_prep(v, u);
    sub[u] += sub[v];
  }
}
void dfs_init(int u, int p, int lst_cl) {
  if (p == 0) {
    sum[u] = a[u];
    f[u] = 0;
  }
  if (f[u] <= k) ans = add(ans, sum[u]);
  for (auto& to : gr[u]) {
    int v = to.first, t = to.second;
    if (v == p || del[v]) continue;
    f[v] = f[u] + (lst_cl == t ? 0 : 1);
    sum[v] = add(sum[u], a[v]);
    dfs_init(v, u, t);
  }
}
void dfs_calc(int u, int p, const int& r, const int& cl) {
  ans =
      add(ans, (sum[u] * 1LL * tree[cl].get_cnt(k + 1 - f[u]) +
                tree[cl].get_sum(k + 1 - f[u]) -
                a[r] * 1LL * tree[cl].get_cnt(k + 1 - f[u]) + mod * 1LL * mod) %
                   mod);
  ans =
      add(ans, (sum[u] * 1LL * tree[cl ^ 1].get_cnt(k - f[u]) +
                tree[cl ^ 1].get_sum(k - f[u]) -
                a[r] * 1LL * tree[cl ^ 1].get_cnt(k - f[u]) + mod * 1LL * mod) %
                   mod);
  for (auto& to : gr[u]) {
    int v = to.first;
    if (v == p || del[v]) continue;
    dfs_calc(v, u, r, cl);
  }
}
void dfs_add(int u, int p, const int& cl) {
  tree[cl].Add(f[u], sum[u]);
  for (auto& to : gr[u]) {
    int v = to.first;
    if (v == p || del[v]) continue;
    dfs_add(v, u, cl);
  }
}
void dfs_del(int u, int p, const int& cl) {
  tree[cl].Del(f[u], sum[u]);
  for (auto& to : gr[u]) {
    int v = to.first;
    if (v == p || del[v]) continue;
    dfs_del(v, u, cl);
  }
}
int centroid(int u, int p, int all) {
  for (auto& to : gr[u]) {
    int v = to.first;
    if (v != p && !del[v] && sub[v] * 2 > all) {
      return centroid(v, u, all);
    }
  }
  return u;
}
void dfs_centroid(int s) {
  dfs_prep(s, 0);
  s = centroid(s, 0, sub[s]);
  dfs_init(s, 0, -1);
  for (auto& to : gr[s]) {
    int u = to.first, t = to.second;
    if (del[u]) continue;
    dfs_calc(u, s, s, t);
    dfs_add(u, s, t);
  }
  for (auto& to : gr[s]) {
    int u = to.first, t = to.second;
    if (del[u]) continue;
    dfs_del(u, s, t);
  }
  del[s] = true;
  for (auto& to : gr[s]) {
    int u = to.first;
    if (del[u]) continue;
    dfs_centroid(u);
  }
}
void solve() {
  dfs_centroid(1);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  read_input();
  solve();
}
