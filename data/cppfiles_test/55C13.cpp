#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getrnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template <typename T1, typename T2>
inline bool relax(T1& a, const T2& b) {
  return a > b ? a = b, true : false;
}
template <typename T1, typename T2>
inline bool strain(T1& a, const T2& b) {
  return a < b ? a = b, true : false;
}
const int N = 6e5 + 5;
pair<int, int> tree[4 * N], lazy[4 * N];
pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) return a;
  return b;
}
void upd(int v, pair<int, int> x) {
  tree[v] = merge(tree[v], x);
  lazy[v] = merge(lazy[v], x);
}
void push(int v) {
  if (lazy[v].first >= 0) {
    upd(2 * v, lazy[v]);
    upd(2 * v + 1, lazy[v]);
    lazy[v].first = -1;
  }
}
void build(int v, int tl, int tr) {
  if (tl == tr)
    tree[v] = {-1, tl}, lazy[v] = {-1, -1};
  else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }
}
void update(int v, int tl, int tr, int l, int r, pair<int, int> x) {
  if (l > r) return;
  if (tl == l && tr == r)
    upd(v, x);
  else {
    int tm = (tl + tr) / 2;
    push(v);
    update(2 * v, tl, tm, l, min(r, tm), x);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, x);
    tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
  }
}
pair<int, int> get(int v, int tl, int tr, int l, int r) {
  if (l > r) return {-1, -1};
  if (tl == l && tr == r)
    return tree[v];
  else {
    int tm = (tl + tr) / 2;
    push(v);
    return merge(get(2 * v, tl, tm, l, min(r, tm)),
                 get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> ids;
  vector<vector<pair<int, int>>> segs(n);
  for (int i = 0; i < m; ++i) {
    int ind, l, r;
    cin >> ind >> l >> r;
    --ind;
    ids.emplace_back(l);
    ids.emplace_back(r);
    segs[ind].emplace_back(l, r);
  }
  sort(ids.begin(), ids.end());
  ids.resize(unique(ids.begin(), ids.end()) - ids.begin());
  auto gid = [&](int x) {
    return lower_bound(ids.begin(), ids.end(), x) - ids.begin();
  };
  int sz = ids.size();
  build(1, 0, sz);
  vector<int> dp(n, 1), from(n, -1);
  for (int i = 0; i < n; ++i) {
    for (auto& [l, r] : segs[i]) {
      l = gid(l);
      r = gid(r);
      auto [val, ind] = get(1, 0, sz, l, r);
      if (strain(dp[i], val + 1)) from[i] = ind;
    }
    for (auto [l, r] : segs[i]) {
      update(1, 0, sz, l, r, {dp[i], i});
    }
  }
  int st = max_element(dp.begin(), dp.end()) - dp.begin();
  cout << n - dp[st] << '\n';
  vector<int> was(n);
  while (st != -1) {
    was[st] = 1;
    st = from[st];
  }
  for (int i = 0; i < n; ++i)
    if (!was[i]) cout << i + 1 << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) solve();
  return 0;
}
