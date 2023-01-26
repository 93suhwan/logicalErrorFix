#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
int n, q, a[N], ans[N], c[N];
vector<int> G[N];
struct node {
  int l, k, id;
};
vector<node> Q[N];
struct BIT {
  int c[N];
  int lowbit(int x) { return x & (-x); }
  void add(int i) {
    if (!i) return;
    for (; i <= n; i += lowbit(i)) {
      c[i]++;
    }
  }
  void del(int i) {
    if (!i) return;
    for (; i <= n; i += lowbit(i)) {
      c[i]--;
    }
  }
  int ask(int x, int ans = 0) {
    for (int i = x; i; i -= lowbit(i)) {
      ans += c[i];
    }
    return ans;
  }
} B;
set<int> se[N];
int calc(int x, int y) {
  int t = B.ask(x - 1);
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (B.ask(mid) - t >= y) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (ans == -1) return ans;
  return *se[ans].begin();
}
void dfs(int u) {
  B.del(c[a[u]]);
  se[c[a[u]]].erase(a[u]);
  c[a[u]]++;
  se[c[a[u]]].insert(a[u]);
  B.add(c[a[u]]);
  if (Q[u].size()) {
    for (auto i : Q[u]) {
      ans[i.id] = calc(i.l, i.k);
    }
  }
  for (auto v : G[u]) {
    dfs(v);
  }
  B.del(c[a[u]]);
  se[c[a[u]]].erase(a[u]);
  c[a[u]]--;
  se[c[a[u]]].insert(a[u]);
  B.add(c[a[u]]);
}
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    G[i].clear();
    c[i] = 0;
    Q[i].clear();
    cin >> a[i];
  }
  for (int i = 2, t; i <= n; i++) {
    cin >> t;
    G[t].push_back(i);
  }
  for (int i = 1, v, l, k; i <= q; i++) {
    cin >> v >> l >> k;
    Q[v].push_back({l, k, i});
  }
  dfs(1);
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << " \n"[i == q];
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
