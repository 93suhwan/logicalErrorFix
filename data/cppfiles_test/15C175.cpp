#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 128;
const long long mod = 1000 * 1000 * 1000 + 7;
long long add(long long x, long long y) { return (x + y) % mod; }
long long mul(long long x, long long y) { return x * y % mod; }
vector<int> g[MAX_N];
bool used[MAX_N];
int cnt[MAX_N];
long long dp[MAX_N][MAX_N];
long long rundp(int m, int k) {
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= k; j++) dp[i][j] = 0;
  dp[0][0] = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j <= k; j++) {
      dp[i + 1][j] = add(dp[i + 1][j], dp[i][j]);
      dp[i + 1][j + 1] = add(dp[i + 1][j + 1], mul(dp[i][j], cnt[i]));
    }
  return dp[m][k];
}
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) g[i].clear();
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  if (k == 2) {
    cout << n * (n - 1LL) / 2 % mod << '\n';
    return;
  }
  long long ans = 0;
  for (int center = 0; center < n; center++) {
    memset(used, 0, n);
    used[center] = true;
    vector<pair<int, int>> layer;
    int m = g[center].size();
    for (int i = 0; i < m; i++) {
      int y = g[center][i];
      layer.emplace_back(y, i);
      cnt[i] = 1;
      used[y] = true;
    }
    while (!layer.empty()) {
      ans = add(ans, rundp(m, k));
      vector<pair<int, int>> newlayer;
      for (auto p : layer) {
        cnt[p.second]--;
        for (auto y : g[p.first])
          if (!used[y]) {
            newlayer.emplace_back(y, p.second);
            used[y] = true;
            cnt[p.second]++;
          }
      }
      layer = newlayer;
    }
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
