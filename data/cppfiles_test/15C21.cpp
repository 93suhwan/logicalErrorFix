#include <bits/stdc++.h>
using namespace std;
long long nCrModp(int n, int r, int p) {
  if (r > n - r) r = n - r;
  long long C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
int n, k;
vector<vector<int> > graph(105);
vector<bool> visited(105);
long long NCR[105][105];
int dfs(int curr, int dist) {
  visited[curr] = true;
  if (dist == 0) return 1;
  int ans = 0;
  for (int a = 0; a < graph[curr].size(); a++) {
    int x = graph[curr][a];
    if (visited[x]) continue;
    ans += dfs(x, dist - 1);
  }
  return ans;
}
void solve() {
  cin >> n >> k;
  for (int a = 0; a <= n; a++) {
    graph[a].clear();
  }
  int x, y;
  for (int a = 1; a < n; a++) {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  if (k == 2) {
    cout << NCR[n][2] << '\n';
    return;
  }
  long long ans = 0;
  long long pairs = 0;
  long long dp[k + 1][2];
  for (int a = 2; a < n; a += 2) {
    for (int b = 1; b <= n; b++) {
      if (graph[b].size() < k) {
        continue;
      }
      for (int c = 1; c <= n; c++) {
        visited[c] = false;
      }
      for (int c = 0; c <= k; c++) {
        dp[c][0] = 0;
        dp[c][1] = 0;
      }
      dp[0][1] = 1;
      dp[0][0] = 1;
      visited[b] = true;
      int cnt = 0, last, now;
      for (int c = 0; c < graph[b].size(); c++) {
        now = c % 2;
        last = (c + 1) % 2;
        for (int d = 0; d <= min(c + 1, k); d++) {
          dp[d][now] = dp[d][last];
        }
        cnt = dfs(graph[b][c], a / 2 - 1);
        if (cnt == 0) {
          continue;
        }
        for (int d = 1; d <= min(c + 1, k); d++) {
          dp[d][now] += (cnt * dp[d - 1][last]) % 1000000007;
          dp[d][now] %= 1000000007;
        }
      }
      ans += dp[k][now];
      ans %= 1000000007;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int a = 0; a < 105; a++) {
    for (int b = 0; b <= a; b++) {
      NCR[a][b] = nCrModp(a, b, 1000000007);
    }
  }
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
