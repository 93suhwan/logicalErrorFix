#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const int inf = 2e9;
const long long linf = 2e18;
const long long mod = 998244353;
const int N = 2e5 + 100;
vector<int> g[N];
struct Elem {
  int value, node, pos;
};
Elem merge(Elem a, Elem b) {
  if (a.value < b.value)
    return b;
  else
    return a;
}
struct T {
  vector<Elem> t;
  vector<int> u;
  T(const vector<Elem> &a) {
    t.assign(4 * a.size(), {0, 0});
    u.assign(4 * a.size(), 0);
    build(a, 0, 0, a.size());
  }
  void build(const vector<Elem> &a, int v, int l, int r) {
    if (r - l == 1) {
      t[v] = a[l];
      return;
    }
    build(a, v * 2 + 1, l, (l + r) >> 1);
    build(a, v * 2 + 2, (l + r) >> 1, r);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
  }
  void push(int v, int l, int r) {
    if (r - l == 1) {
      t[v].value += u[v];
      u[v] = 0;
      return;
    }
    t[v].value += u[v];
    u[v * 2 + 1] += u[v];
    u[v * 2 + 2] += u[v];
    u[v] = 0;
  }
  Elem get(int v, int l, int r, int vl, int vr) {
    push(v, l, r);
    if (vl >= r || vr <= l) return {-inf, -1};
    if (vl <= l && r <= vr) return t[v];
    if (r - l == 1) {
      return t[v];
    }
    return merge(get(v * 2 + 1, l, (l + r) >> 1, vl, vr),
                 get((v * 2 + 2), (l + r) >> 1, r, vl, vr));
  }
  void upd(int v, int l, int r, int vl, int vr, int d) {
    push(v, l, r);
    if (vl >= r || vr <= l) return;
    if (vl <= l && r <= vr) {
      u[v] += d;
      push(v, l, r);
      return;
    }
    int m = (l + r) >> 1;
    upd(v * 2 + 1, l, m, vl, vr, d);
    upd(v * 2 + 2, m, r, vl, vr, d);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
  }
};
vector<Elem> leaves;
pair<int, int> segments[N];
int par[N];
pair<int, int> dfs(int v, int depth = 1) {
  int l = 0, r = g[v].size() - 1;
  if (r == l && par[v] != -1) {
    int pos = leaves.size();
    leaves.push_back({depth, v, pos});
    return {leaves.size() - 1, leaves.size() - 1};
  }
  if ((g[v].size() == 2 && g[v][0] == par[v] || g[v][1] == par[v]) ||
      (par[v] == -1 && g[v].size() == 1)) {
    for (auto u : g[v]) {
      if (u == par[v]) continue;
      par[u] = v;
      auto res = dfs(u, depth + 1);
      segments[v] = res;
      return res;
    }
  }
  if (g[v].size())
    if (par[v] == g[v][l]) l++;
  if (par[v] == g[v][r]) r--;
  par[g[v][l]] = v;
  par[g[v][r]] = v;
  int left_leaf = dfs(g[v][l++], depth + 1).first;
  for (int i = l; i < r; i++) {
    int u = g[v][i];
    if (par[v] == u) continue;
    par[u] = v;
    dfs(u, depth + 1);
  }
  int right_leaf = dfs(g[v][r++], depth + 1).second;
  segments[v] = {left_leaf, right_leaf};
  return {left_leaf, right_leaf};
}
int marked[N];
void solve() {
  int n, k;
  cin >> n >> k;
  fill(par, par + n, -1);
  for (int i = 0; i < n - 1; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    t1--;
    t2--;
    g[t1].push_back(t2);
    g[t2].push_back(t1);
  }
  dfs(0);
  T t(leaves);
  int unmarked = n;
  long long best = -1ll * (n / 2) * (n - n / 2);
  if (n == 136175) cout << leaves.size() << "\n";
  if (leaves.size() <= k) {
    long long rmax = min(k, n / 2);
    cout << rmax * (n - rmax) << "\n";
    return;
  }
  for (int i = 1; i < n; i++)
    if (par[i] == -1) cout << "panic\n";
  for (int i = 1; i <= k; i++) {
    Elem e = t.get(0, 0, leaves.size(), 0, leaves.size());
    t.upd(0, 0, leaves.size(), e.pos, e.pos + 1, -inf);
    int v = e.node;
    marked[v] = true;
    unmarked--;
    v = par[v];
    while (!marked[v]) {
      marked[v] = true;
      unmarked--;
      t.upd(0, 0, leaves.size(), segments[v].first, segments[v].second + 1, -1);
      if (par[v] == -1) break;
      v = par[v];
    }
    long long bmax = min(n / 2, unmarked);
    best = max(best, 1ll * i * (n - i) - bmax * (n - bmax));
  }
  cout << best << "\n";
}
