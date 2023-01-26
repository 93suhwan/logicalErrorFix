#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 5;
const int MOD = 998244353;
vector<int> bio(MAX);
vector<int> degree(MAX);
vector<int> edges[MAX];
int add(int x, int y) {
  x += y;
  while (x >= MOD) {
    x -= MOD;
  }
  while (x < 0) {
    x += MOD;
  }
  return x;
}
int mul(int x, int y) { return (x * 1ll * y) % MOD; }
int dfs(int a) {
  if (degree[a] > 1 || edges[a].size() > 1) return 0;
  if (edges[a].size() == 0) return 1;
  int z = dfs(edges[a][0]);
  if (z == 0)
    return 0;
  else
    return z + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int c, a, b;
    cin >> c >> a;
    c--;
    while (c--) {
      cin >> b;
      if (edges[a].size() == 0 || edges[a][0] != b) {
        edges[a].push_back(b);
        degree[b]++;
      }
      a = b;
    }
  }
  map<int, int> mp;
  for (int i = 1; i <= k; i++) {
    if (degree[i] == 0) {
      int z = dfs(i);
      if (z) mp[z]++;
    }
  }
  vector<int> dp(m + 1);
  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (auto e : mp) {
      if (i < e.first) continue;
      dp[i] = add(dp[i], mul(dp[i - e.first], e.second));
    }
  }
  cout << dp[m] << "\n";
  return 0;
}
