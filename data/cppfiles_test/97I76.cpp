#include <bits/stdc++.h>
using namespace std;
vector<int> e[200005], dp[200005];
int n;
inline int query(int x, int y) {
  y = min(y, (int)dp[x].size() - 1);
  return dp[x][y];
}
inline void dfs(int u, int f) {
  int cnt = 0;
  for (auto v : e[u]) {
    if (v != f) dfs(v, u);
    ++cnt;
  }
  for (int i = 0; i <= n; i++) {
    int now = 0;
    for (auto v : e[u]) {
      if (v != f) now += max(1, query(v, i) - i);
    }
    dp[u].push_back(now);
    if (now == cnt) break;
  }
}
signed main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << query(x, y) << "\n";
  }
  return 0;
}
