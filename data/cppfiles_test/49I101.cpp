#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline bool ckmax(A& a, B b) {
  return a < b ? a = b, true : false;
}
template <typename A, typename B>
inline bool ckmin(A& a, B b) {
  return a > b ? a = b, true : false;
}
const int MOD = 1000000007;
const int inf = 1061109567;
const int64_t INF = 4557430888798830399;
const int maxn = 1e6 + 5;
struct Segtree {
  int n;
  vector<int> tree;
  void init(int _n) {
    n = _n;
    tree.resize((n << 2) + 5, 0);
  }
  void update(int node, int l, int r, int k, int val) {
    if (l > k || r < k) return;
    if (l == r) {
      tree[node] += val;
      return;
    }
    update((node << 1), l, ((l + r) >> 1), k, val);
    update((node << 1 | 1), ((l + r) >> 1) + 1, r, k, val);
    tree[node] = tree[(node << 1)] + tree[(node << 1 | 1)];
  }
  int get(int node, int l, int r, int k) {
    if (l == r) return l;
    if (tree[(node << 1)] < k)
      return get((node << 1 | 1), ((l + r) >> 1) + 1, r, k - tree[(node << 1)]);
    return get((node << 1), l, ((l + r) >> 1), k);
  }
  int get(int node, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return tree[node];
    return get((node << 1), l, ((l + r) >> 1), u, v) +
           get((node << 1 | 1), ((l + r) >> 1) + 1, r, u, v);
  }
  void update(int k, int val) { update(1, 1, n, k, val); }
  int get(int k) { return get(1, 1, n, k); }
  int get(int l, int r) { return get(1, 1, n, l, r); }
} sgt;
int n, q, a[maxn];
vector<int> adj[maxn], qry[maxn];
int l[maxn], k[maxn], ans[maxn];
int cnt[maxn];
set<pair<int, int>> s;
void clear_data() {
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
    qry[i].clear();
    cnt[i] = 0;
  }
  s.clear();
}
void dfs(int u) {
  s.erase({cnt[a[u]], a[u]});
  sgt.update(cnt[a[u]], -1);
  ++cnt[a[u]];
  sgt.update(cnt[a[u]], 1);
  s.insert({cnt[a[u]], a[u]});
  for (auto& id : qry[u]) {
    int less = sgt.get(1, l[id] - 1);
    if (k[id] + less > ((int)(s).size())) {
      ans[id] = -1;
      continue;
    }
    int tmp = sgt.get(k[id] + less);
    auto it = s.lower_bound({tmp, -inf});
    ans[id] = (*it).second;
  }
  for (int& v : adj[u]) dfs(v);
  s.erase({cnt[a[u]], a[u]});
  sgt.update(cnt[a[u]], -1);
  --cnt[a[u]];
  s.insert({cnt[a[u]], a[u]});
  sgt.update(cnt[a[u]], 1);
}
void gogo() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s.insert({0, a[i]});
  }
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    adj[x].push_back(i);
  }
  for (int i = 1; i <= q; ++i) {
    int u;
    cin >> u >> l[i] >> k[i];
    qry[u].push_back(i);
  }
  sgt.init(n);
  dfs(1);
  for (int i = 1; i <= q; ++i) cout << ans[i] << " ";
  cout << '\n';
  clear_data();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  if (fopen("main"
            ".inp",
            "r")) {
    freopen(
        "main"
        ".inp",
        "r", stdin);
    freopen(
        "main"
        ".out",
        "w", stdout);
  }
  int ntest;
  cin >> ntest;
  while (ntest--) gogo();
  return 0;
}
