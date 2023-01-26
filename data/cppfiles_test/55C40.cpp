#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> endpoint;
  for (int i = 0; i < m; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    endpoint.emplace_back(l, id);
    endpoint.emplace_back(r + 1, (~id));
  }
  sort(endpoint.begin(), endpoint.end());
  vector<vector<int>> G(n + 1);
  map<int, int> mp;
  for (int l = 0, r; l < (int)endpoint.size(); l = r) {
    for (r = l + 1;
         r < (int)endpoint.size() and endpoint[r].first == endpoint[l].first;
         r++)
      ;
    for (int i = l; i < r; i++) {
      int id = endpoint[i].second;
      if (id > 0) {
        if (mp.count(id)) {
          auto it = mp.find(id);
          it->second++;
          continue;
        }
        mp[id] = 1;
        auto it = mp.find(id);
        if (it != mp.begin()) {
          int x = prev(it)->first;
          G[x].emplace_back(id);
        }
        if (next(it) != mp.end()) {
          int y = next(it)->first;
          G[id].emplace_back(y);
        }
      } else {
        id = ~id;
        auto it = mp.find(id);
        it->second--;
        if (it != mp.begin() and next(it) != mp.end()) {
          int x = prev(it)->first;
          int y = next(it)->first;
          G[x].emplace_back(y);
        }
        if (it->second == 0) mp.erase(id);
      }
    }
  }
  vector<int> dp(n + 1, 1);
  vector<int> pa(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)G[i].size(); j++) {
      if (dp[i] + 1 > dp[G[i][j]]) {
        dp[G[i][j]] = dp[i] + 1;
        pa[G[i][j]] = i;
      }
    }
  }
  int pos = (int)(max_element(dp.begin() + 1, dp.end()) - dp.begin());
  int ans = n;
  vector<bool> remain(n + 1, 0);
  while (pos > 0) {
    remain[pos] = 1;
    ans--;
    pos = pa[pos];
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    if (!remain[i]) {
      cout << i << " ";
    }
  }
  cout << '\n';
  return 0;
}
