#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = (int)(1e6 + 5);
int dfs(int v, bitset<MAXN> &used, vector<vector<int> > &g, vector<int> &dp) {
  if (used[v]) return dp[v];
  used[v] = true;
  for (auto to : g[v]) {
    dfs(to, used, g, dp);
    if (dp[to] != INT_MAX) dp[v] = min(dp[v], dp[to] + 1);
  }
  return dp[v];
}
int main(int argc, const char *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, d, a;
    vector<int> v;
    scanf("%d", &n);
    scanf("%d", &d);
    for (int i = 0; i < (n); i++) {
      scanf("%d", &a);
      v.push_back(a);
    }
    vector<vector<int> > g(n);
    vector<int> dp(n, INT_MAX);
    bitset<MAXN> used;
    for (int i = 0; i < (n); i++) {
      g[i].push_back((i + d) % n);
      if (!v[i]) {
        used[i] = true;
        dp[i] = 0;
      }
    }
    for (int i = 0; i < (n); i++)
      if (v[i] == 1) dfs(i, used, g, dp);
    int ans = INT_MIN;
    for (int i = 0; i < (n); i++) {
      if (dp[i] == INT_MAX) {
        ans = -1;
        break;
      }
      ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
