#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const int mod = 998244353;
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]++;
  }
  vector<vector<long long> > dp(2, vector<long long>(n + 5));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    dp[0][v[i]] = dp[0][v[i]] * 2 % mod;
    dp[0][v[i]] = (dp[0][v[i]] + dp[0][v[i] - 1]) % mod;
    if (v[i] > 1) {
      dp[1][v[i]] = dp[1][v[i]] * 2 % mod;
      dp[1][v[i]] = (dp[1][v[i]] + dp[0][v[i] - 2]) % mod;
    }
    if (v[i] + 2 <= n + 1) {
      dp[1][v[i] + 2] = dp[1][v[i] + 2] * 2 % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n + 1; i++) {
    ans = (ans + dp[0][i] + dp[1][i]) % mod;
  }
  cout << ans << '\n';
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
