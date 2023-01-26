#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> cover(n);
  vector<tuple<int, int, int>> endpoints;
  set<int> s{-1, n};
  for (int i = 0; i < m; i++) {
    int x, l, r;
    cin >> x >> l >> r;
    endpoints.emplace_back(l - 1, x - 1, -1);
    endpoints.emplace_back(r - 1, x - 1, 1);
  }
  sort(endpoints.begin(), endpoints.end());
  vector<pair<int, int>> edges;
  vector<int> add, del;
  for (int l = 0, r; l < 2 * m; l = r) {
    r = l;
    while (r < 2 * m && get<0>(endpoints[l]) == get<0>(endpoints[r])) r++;
    add.clear();
    del.clear();
    for (int i = l; i < r; i++) {
      auto [v, x, t] = endpoints[i];
      if (t == -1) {
        if (cover[x] == 0) add.push_back(x);
        cover[x]++;
      } else {
        cover[x]--;
        if (cover[x] == 0) del.push_back(x);
      }
    }
    for (int x : del) s.erase(x);
    for (int x : add) {
      auto it = s.insert(x).first;
      edges.emplace_back(*prev(it), x);
      edges.emplace_back(x, *next(it));
    }
  }
  sort(edges.begin(), edges.end());
  vector<int> dp(n + 2), g(n + 2);
  for (auto [u, v] : edges) {
    if (dp[u + 1] + 1 > dp[v + 1]) {
      dp[v + 1] = dp[u + 1] + 1;
      g[v + 1] = u + 1;
    }
  }
  int res = n + 1 - dp[n + 1];
  cout << res << "\n";
  vector<int> ans;
  for (int i = n + 1; i > 0; i = g[i])
    for (int j = g[i] + 1; j < i; j++) ans.push_back(j);
  for (int i = 0; i < res; i++) cout << ans[i] << " \n"[i == res - 1];
  return 0;
}
