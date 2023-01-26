#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int t, n;
vector<int> edges[200005];
int deg[200005];
int dp[200005];
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      deg[i] = 0;
      edges[i].clear();
      dp[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      int k;
      scanf("%d", &k);
      for (int j = 1; j <= k; ++j) {
        int u;
        scanf("%d", &u);
        edges[u].push_back(i);
        deg[i]++;
      }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (deg[i] == 0) {
        q.push(i);
        dp[i] = 1;
      }
    }
    int cnt = 0;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      cnt++;
      for (int i = 0; i < edges[cur].size(); ++i) {
        int v = edges[cur][i];
        if (cur > v) {
          dp[v] = max(dp[v], dp[cur] + 1);
        } else {
          dp[v] = max(dp[v], dp[cur]);
        }
        deg[v]--;
        if (deg[v] == 0) {
          q.push(v);
        }
      }
    }
    if (cnt < n) {
      puts("-1");
    } else {
      int ans = 1;
      for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
