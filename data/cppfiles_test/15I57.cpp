#include <bits/stdc++.h>
using namespace std;
int d[1000005];
int c[105][105];
vector<int> g[1000005];
void dfs(int u, int r = 0, int dis = 0) {
  d[dis]++;
  for (auto &v : g[u])
    if (v != r) dfs(v, u, dis + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i <= 100; ++i)
    for (int j = i; j <= 100; ++j)
      if (i == 0 || i == j)
        c[i][j] = 1;
      else
        c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % 1000000007;
  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) d[j] = 0;
      dfs(i);
      for (int j = 1; j < n; ++j) {
        if (d[j] >= k) res = (res + c[k][d[j]]) % 1000000007;
      }
    }
    cout << res << endl;
  }
}
