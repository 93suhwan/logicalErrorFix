#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<vector<long long> > dp(N + 5, vector<long long>(2, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
      int x;
      cin >> x;
      if (x >= 1)
        dp[x - 1][1] = (dp[x - 1][1] + dp[x - 1][1] + dp[x - 1][0]) % MOD;
      dp[x + 1][0] = (dp[x + 1][0] + dp[x + 1][0] + dp[x][0]) % MOD;
      dp[x + 1][1] = (dp[x + 1][1] + dp[x + 1][1]) % MOD;
    }
    long long ans = 0;
    for (int i = 0; i <= N; i++) {
      ans = (ans + dp[i][0] + dp[i][1]) % MOD;
    }
    cout << (ans - 1 + MOD) % MOD << '\n';
  }
}
