#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int N = 101;
constexpr int M = 1e9 + 7;
ll ans;
int n, k;
vector<int> edges[N];
int depth[N][N];
int arr[N];
int dp[N][N];
void dfs(int cur, int par) {
  memset(depth[cur], 0, sizeof(int) * n);
  depth[cur][0] = 1;
  for (int i = (0); i < (edges[cur].size()); ++i) {
    int nxt = edges[cur][i];
    if (nxt == par) continue;
    dfs(nxt, cur);
    for (int j = (1); j < (n); ++j) {
      depth[cur][j] += depth[nxt][j - 1];
    }
  }
}
void solve(int root) {
  if (edges[root].size() < k) return;
  dfs(root, -1);
  for (int dist = (0); dist < (n); ++dist) {
    for (int i = (0); i < (edges[root].size()); ++i) {
      int child = edges[root][i];
      int x = depth[child][dist];
      arr[i] = x;
    }
    memset(dp, 0, sizeof(int) * N * N);
    for (int i = (0); i < (edges[root].size()); ++i) {
      dp[i][0] = 1;
    }
    for (int i = (1); i <= (edges[root].size()); ++i) {
      for (int j = (1); j <= (min(i, k)); ++j) {
        dp[i][j] = (dp[i - 1][j] + (ll)arr[i - 1] * dp[i - 1][j - 1]) % M;
      }
    }
    ans += dp[edges[root].size()][k];
    ans %= M;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    memset(edges, 0, sizeof(vector<int>) * N);
    ans = 0;
    for (int i = (0); i < (n - 1); ++i) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    if (k == 2) {
      ans = n * (n - 1) / 2;
      ans %= M;
    } else {
      for (int i = (0); i < (n); ++i) {
        solve(i);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
