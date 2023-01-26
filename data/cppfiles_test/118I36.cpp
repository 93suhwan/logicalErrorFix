#include <bits/stdc++.h>
using namespace std;
const int N = 2500;
const int mod = 998244353;
vector<vector<int>> e;
int dp[N][N];
int fac[N];
int d[N];
void dfs(int x, int fa) {
  for (auto y : e[x]) {
    if (y != fa) {
      d[x]++;
      dfs(y, x);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  e.resize(n + 1);
  for (int i = 0; i < int(n - 1); i++) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1, 1);
  for (int i = 0; i < int(n); i++) dp[0][i] = 0;
  for (int i = 0; i < int(n + 1); i++) dp[i][0] = 1;
  for (int i = int(1); i <= int(n); ++i) {
    for (int j = int(1); j <= int(n - 1); ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * d[i];
      dp[i][j] %= mod;
    }
  }
  fac[0] = 1;
  for (int i = int(1); i <= int(n); ++i) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  int ans = 0;
  for (int k = 0; k < int(n); k++) {
    if (k % 2)
      ans = (ans - dp[n][k] * fac[n - k] + mod) % mod;
    else
      ans = (ans + dp[n][k] * fac[n - k]) % mod;
  }
  cout << ans << "\n";
  return 0;
}
