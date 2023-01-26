#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  vector<long long int> dp(n + 1, 0);
  long long int sum = 1;
  dp[1] = 1;
  for (long long int i = 2; i <= n; i++) {
    dp[i] = sum;
    dp[i] %= m;
    for (long long int j = 1; j * j <= i; j++) {
      dp[i] = (dp[i] + (dp[j] * (i / j - i / (j + 1))) % m) % m;
      if (j > 1 && j != i / j) {
        dp[i] = (dp[i] + dp[i / j]) % m;
      }
    }
    sum += dp[i];
    sum %= m;
  }
  cout << dp[n] % m << "\n";
}
