#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int cnt[110];
vector<int> v[110];
int dp[110][110];
ll add(ll x, ll y) { return (x + y) % MOD; }
ll mul(ll x, ll y) { return x * y % MOD; }
ll get_ans(int n, int k) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) dp[i][j] = 0;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= k; j++) {
      dp[i][j] = add(dp[i - 1][j], dp[i][j]);
      dp[i][j] = add(dp[i][j], mul(dp[i - 1][j - 1], cnt[i]));
    }
  }
  return dp[n][k];
}
void dfs(int u, int fa = -1) {
  cout << u << endl;
  for (auto t : v[u]) {
    if (t == fa) continue;
    dfs(t, u);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) v[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    if (k == 2) {
      printf("%lld\n", 1ll * n * (n - 1) / 2 % MOD);
      continue;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      vector<int> used(n + 1, 0);
      used[i] = true;
      int m = v[i].size();
      vector<pair<int, int>> layer;
      for (int j = 0; j < m; j++) {
        int y = v[i][j];
        layer.push_back({y, j + 1});
        used[y] = true;
        cnt[j + 1] = 1;
      }
      while (!layer.empty()) {
        ans = add(ans, get_ans(m, k));
        vector<pair<int, int>> newlayer;
        for (auto now : layer) {
          cnt[now.second]--;
          for (auto next : v[now.first]) {
            if (used[next]) continue;
            newlayer.push_back({next, now.second});
            used[next] = true;
            cnt[now.second]++;
          }
        }
        layer = newlayer;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
