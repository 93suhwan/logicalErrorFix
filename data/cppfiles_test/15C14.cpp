#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long sumproduct(vector<vector<int> > &cd, int k) {
  long long res = 0;
  for (auto a : cd) {
    int m = a.size();
    if (m < k) continue;
    vector<vector<long long> > dp(m, vector<long long>(k + 1));
    dp[0][1] = a[0];
    for (int i = 0; i < m; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j <= k; ++j) {
        dp[i][j] = dp[i - 1][j] + 1LL * a[i] * dp[i - 1][j - 1];
        dp[i][j] %= M;
      }
    }
    res += dp[m - 1][k];
    res %= M;
  }
  return res;
}
void bfs(vector<vector<int> > &e, vector<int> &d, int u) {
  queue<int> q;
  q.push(u);
  d[u] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : e[u]) {
      if (d[v] > 0) continue;
      d[v] = d[u] + 1;
      q.push(v);
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > e(n + 1);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << endl;
      continue;
    }
    long long res = 0;
    for (int u = 1; u <= n; ++u) {
      vector<vector<int> > cd(n + 1);
      for (int v : e[u]) {
        vector<int> d(n + 1);
        d[u] = n + 1;
        bfs(e, d, v);
        d[u] = 0;
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; ++i) {
          ++cnt[d[i]];
        }
        for (int i = 1; i <= n; ++i) {
          if (cnt[i] > 0) cd[i].push_back(cnt[i]);
        }
      }
      res += sumproduct(cd, k);
      res %= M;
    }
    cout << res << endl;
  }
  return 0;
}
