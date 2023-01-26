#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, k, nr[105][105], dp[105][105], t;
vector<int> muchii[200005];
bool use[200005];
void dfs(int nod) {
  use[nod] = 1;
  nr[nod][0] = 1;
  for (auto i : muchii[nod])
    if (!use[i]) {
      dfs(i);
      for (int dist = 1; dist <= n; dist++)
        nr[nod][dist] = (nr[nod][dist] + nr[i][dist - 1]) % mod;
    }
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) muchii[i].clear();
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    muchii[a].push_back(b);
    muchii[b].push_back(a);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << '\n';
    return;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      use[j] = 0;
      for (int dist = 0; dist <= n; dist++) nr[j][dist] = 0;
    }
    dfs(i);
    for (int dist = 0; dist <= n; dist++) {
      dp[0][0] = 1;
      for (int j = 0; j < muchii[i].size(); j++) {
        dp[j + 1][0] = 1;
        for (int x = 1; x <= k; x++)
          dp[j + 1][x] =
              (dp[j][x] + dp[j][x - 1] * nr[muchii[i][j]][dist]) % mod;
      }
      ans = (ans + dp[muchii[i].size()][k]) % mod;
    }
  }
  cout << ans << '\n';
}
int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}
