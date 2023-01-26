#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  for (int j = 4; j <= n; j += 2) dp[j] = (dp[j] + 1) % m;
  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i] + 2 * dp[i - 1] + 1) % m;
    for (int j = 2 * i; j <= n; j += i) {
      long long inc = dp[i] - dp[i - 1];
      while (inc < 0) inc += m;
      dp[j] = (dp[j] + inc) % m;
    }
  }
  cout << dp[n] << endl;
}
