#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int N = 1e6 + 6;
int n, q, a[N], p[N], inv[N], lb[N], cnt[N], ans[N];
vector<int> g[N];
vector<tuple<int, int, int>> queries[N];
void increase(int x) {
  int y = inv[lb[cnt[x] + 1] - 1];
  swap(p[x], p[y]);
  swap(inv[p[x]], inv[p[y]]);
  ++cnt[x];
  --lb[cnt[x]];
}
void decrease(int x) {
  int y = inv[lb[cnt[x]]];
  swap(p[x], p[y]);
  swap(inv[p[x]], inv[p[y]]);
  ++lb[cnt[x]];
  --cnt[x];
}
void dfs(int u) {
  increase(a[u]);
  for (auto [id, l, k] : queries[u]) {
    int x = lb[l] + k - 1;
    ans[id] = (x > n) ? -1 : inv[x];
  }
  for (int v : g[u]) {
    dfs(v);
  }
  decrease(a[u]);
}
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    g[i].clear();
    queries[i].clear();
    p[i] = i;
    inv[i] = i;
    lb[i] = n + 1;
    cnt[i] = 0;
  }
  for (int i = 2, p; i <= n; ++i) {
    cin >> p;
    g[p].emplace_back(i);
  }
  for (int i = 1, v, l, k; i <= q; ++i) {
    cin >> v >> l >> k;
    queries[v].emplace_back(i, l, k);
  }
  dfs(1);
  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << " \n"[i == q];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
