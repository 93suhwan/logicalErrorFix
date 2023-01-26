#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Query {
  int l, k, id;
};
void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<Query>> queries(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g[p].push_back(i);
  }
  for (int i = 0; i < q; i++) {
    int v, l, k;
    cin >> v >> l >> k;
    v--;
    queries[v].push_back({l, k, i});
  }
  vector<int> ans(q);
  vector<set<int>> kek(n + 1);
  vector<int> f(n + 1);
  vector<int> cnt(n + 1);
  vector<int> cnt_occ(n + 1);
  auto Update = [&](int v, int x) {
    for (; v <= n; v += v & -v) {
      f[v] += x;
    }
  };
  auto GetSum = [&](int v) {
    int ret = 0;
    for (; v; v -= v & -v) {
      ret += f[v];
    }
    return ret;
  };
  auto Add = [&](int x) {
    if (cnt[x]) {
      kek[cnt[x]].erase(x);
      cnt_occ[cnt[x]]--;
      Update(cnt[x], -1);
    }
    cnt[x]++;
    kek[cnt[x]].insert(x);
    Update(cnt[x], 1);
    cnt_occ[cnt[x]]++;
  };
  auto Remove = [&](int x) {
    kek[cnt[x]].erase(x);
    cnt_occ[cnt[x]]--;
    Update(cnt[x], -1);
    cnt[x]--;
    if (cnt[x]) {
      kek[cnt[x]].insert(x);
      Update(cnt[x], 1);
      cnt_occ[cnt[x]]++;
    }
  };
  int lg = 20;
  function<void(int)> dfs = [&](int v) {
    Add(a[v]);
    for (auto &query : queries[v]) {
      int k = query.k;
      int l = query.l;
      int id = query.id;
      ans[id] = -1;
      int can = GetSum(l - 1);
      k += can;
      if (GetSum(n) < k) {
        ans[id] = -1;
        continue;
      }
      int res = 0;
      for (int bit = lg - 1; bit >= 0; bit--) {
        if (res + (1 << bit) <= n && f[res + (1 << bit)] < k) {
          res += 1 << bit;
          k -= f[res];
        }
      }
      ans[id] = *kek[res + 1].begin();
    }
    for (auto u : g[v]) {
      dfs(u);
    }
    Remove(a[v]);
  };
  dfs(0);
  for (int i = 0; i < q; i++) {
    cout << ans[i] << ' ';
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    solve();
  }
}
