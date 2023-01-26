#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> edges[N * 30];
array<int, 2> dp[N * 30][2];
int in[N * 30], used[N * 30];
array<int, 3> dfs(int u) {
  array<int, 3> res{};
  dp[u][0][1] = in[u];
  for (auto x : edges[u]) {
    if (used[x]) continue;
    used[x] = 1;
    res = max(res, dfs(x));
    dp[u][1] = max(dp[u][1], {dp[x][0][0] + 1, dp[x][0][1]});
    if (dp[u][0] < dp[u][1]) swap(dp[u][0], dp[u][1]);
  }
  res = max(res, {dp[u][0][0] + dp[u][1][0], dp[u][0][1], dp[u][1][1]});
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> p(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int, int> mm;
  int last = 0;
  for (int i = 0; i < n; i++) {
    int v = a[i];
    in[(mm.count(v) ? mm[v] : mm[v] = last++)] = i + 1;
    for (int j = 30; ~j; j--) {
      if (!(v >> j & 1)) continue;
      int a = mm[v];
      if (v > (1 << j))
        v = (1 << (j + 1)) - v;
      else
        v = 0;
      int b = (mm.count(v) ? mm[v] : mm[v] = last++);
      edges[b].push_back(a);
    }
  }
  auto res = dfs(mm[0]);
  cout << res[1] << " " << res[2] << " " << res[0] << "\n";
}
