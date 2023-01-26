#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  int prefSum = dp[1];
  for (int(i) = (2); (i) < (n + 1); ++(i)) {
    dp[i] = prefSum;
    for (int j = 1; j * j <= i; ++j) {
      dp[i] = (dp[i] + (dp[j] * ((i / j) - (i / (j + 1)))) % m) % m;
      if (j != i / j && j > 1) {
        dp[i] = (dp[i] + dp[i / j]) % m;
      }
    }
    prefSum = (prefSum + dp[i]) % m;
  }
  cout << dp[n];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc = 1;
  while (tc--) {
    solve();
    cout << '\n';
  }
  return 0;
}
