#include <bits/stdc++.h>
using namespace std;
const int N = 105, INF = 1 << 30, MOD = 1e9 + 7;
int n, k;
vector<int> adj[N];
long long cnt[N][N];
long long ans = 0, F[N];
long long sumOfProducts(vector<int>& arr, int n, int k) {
  long long dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  long long cur_sum = 0;
  for (int i = 1; i <= n; i++) {
    dp[1][i] = arr[i - 1];
    (cur_sum += arr[i - 1]) %= MOD;
  }
  for (int i = 2; i <= k; ++i) {
    long long temp_sum = 0;
    for (int j = 1; j <= n; j++) {
      (cur_sum -= dp[i - 1][j]) %= MOD;
      dp[i][j] = (arr[j - 1] * cur_sum) % MOD;
      (temp_sum += dp[i][j]) %= MOD;
    }
    cur_sum = temp_sum;
  }
  return (cur_sum + MOD) % MOD;
}
void dfs(int u, int root, int p, int d) {
  ++cnt[root][d];
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, root, u, d + 1);
  }
}
void solve(int u) {
  memset(cnt, 0, sizeof(cnt));
  if (adj[u].size() < k) return;
  for (int v : adj[u]) {
    dfs(v, v, u, 0);
  }
  for (int i = 0; i < n; ++i) {
    int CNT = 0;
    for (int v : adj[u])
      if (cnt[v][i]) ++CNT;
    if (CNT < k) break;
    vector<int> C;
    for (int v : adj[u])
      if (cnt[v][i]) C.push_back(cnt[v][i]);
    ans += sumOfProducts(C, CNT, k);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  F[0] = 1;
  for (int i = 1; i < N; ++i) F[i] = (F[i - 1] * i) % MOD;
  int t;
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[--u].push_back(--v);
      adj[v].push_back(u);
    }
    if (k == 2)
      cout << n * (n - 1) / 2 << '\n';
    else {
      for (int i = 0; i < n; ++i) solve(i);
      cout << ans << '\n';
    }
  }
}
