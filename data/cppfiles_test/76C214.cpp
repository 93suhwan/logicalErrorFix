#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  long long m;
  cin >> n >> m;
  long long sm = 1;
  long long dp[n + 1];
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
  }
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    int mx = (int)sqrt(i);
    int j = 2;
    dp[i] += sm;
    dp[i] %= m;
    while (true) {
      if (i / j <= mx) {
        break;
      } else {
        dp[i] += dp[i / j];
        dp[i] %= m;
      }
      j++;
    }
    int prev = i + 1;
    for (int j = 1; j <= mx; j++) {
      int r = prev - 1;
      int l = j;
      while (l < r) {
        int mid = (l + r) / 2;
        if (i / mid != j) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      dp[i] += (dp[j] * (prev - r)) % m;
      dp[i] %= m;
      prev = r;
    }
    sm += dp[i];
  }
  cout << dp[n] << "\n";
  return 0;
}
