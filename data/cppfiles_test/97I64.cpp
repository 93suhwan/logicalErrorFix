#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
using namespace std;
const int MAX = 2e5 + 2;
const int SQRT = 448;
int n;
vector<vector<int> > adj(MAX);
int dp[MAX][SQRT + 2];
int tmpdp[SQRT + 2];
void dfs(int node, int par) {
  for (auto &child : adj[node]) {
    if (child == par) continue;
    dfs(child, node);
    for (int j = 0; j <= SQRT; ++j) dp[node][j] += max(1, dp[child][j] - j);
  }
}
void dfs2(int node, int par) {
  for (auto &child : adj[node]) {
    if (child == par) continue;
    dfs2(child, node);
  }
  memset(tmpdp, 0, sizeof(tmpdp));
  tmpdp[0] = 1;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    int Max = 0;
    for (int j = 0; j <= SQRT; ++j) {
      if (!dp[node][j] && j) break;
      for (int j2 = 0; j + j2 + 1 <= SQRT; ++j2) {
        if (!dp[child][j2]) break;
        Max = max(Max, j + j2 + 1);
        tmpdp[j + j2 + 1] =
            max(tmpdp[j + j2 + 1],
                max(dp[node][j + j2 + 1] + 1, dp[node][j] + dp[child][j2]));
      }
    }
    for (int i = 0; i <= Max; ++i) {
      dp[node][i] = tmpdp[i];
      tmpdp[i]++;
    }
  }
}
int qu[MAX], qk[MAX], ans[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int node, k;
    cin >> node >> k;
    qu[i] = node, qk[i] = k;
    if (k <= SQRT) ans[i] = dp[node][k];
  }
  memset(dp, 0, sizeof(dp));
  dfs2(1, -1);
  for (int i = 1; i <= q; ++i) {
    int node = qu[i], k = qk[i];
    if (k > SQRT) {
      for (int j = 0; j <= SQRT; ++j) ans[i] = max(ans[i], dp[node][j] - k * j);
    }
    cout << ans[i] << "\n";
  }
  return 0;
}
