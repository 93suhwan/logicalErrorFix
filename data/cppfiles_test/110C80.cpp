#include <bits/stdc++.h>
using namespace std;
const int Inf = 1e9 + 7;
const int N = 200004;
vector<int> g[N];
int vis[N], dp[N];
int flag;
void dfs(int u) {
  vis[u] = 2;
  dp[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (vis[v] == 0) {
      dfs(v);
      if (v > u) {
        dp[u] = max(dp[u], dp[v] + 1);
      } else {
        dp[u] = max(dp[u], dp[v]);
      }
    }
    if (vis[v] == 1) {
      if (v > u) {
        dp[u] = max(dp[u], dp[v] + 1);
      } else {
        dp[u] = max(dp[u], dp[v]);
      }
    } else {
      flag = 0;
      break;
    }
  }
  vis[u] = 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int i, j;
    flag = 1;
    for (i = 1; i <= n; i++) {
      g[i].clear();
      vis[i] = 0;
      dp[i] = 0;
    }
    for (i = 1; i <= n; i++) {
      int k;
      scanf("%d", &k);
      for (j = 1; j <= k; j++) {
        int x;
        scanf("%d", &x);
        g[i].push_back(x);
      }
    }
    for (i = 1; i <= n; i++) {
      if (!vis[i]) {
        dfs(i);
        if (flag == 0) break;
      }
    }
    if (!flag)
      printf("-1\n");
    else {
      int ans = 0;
      for (i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
