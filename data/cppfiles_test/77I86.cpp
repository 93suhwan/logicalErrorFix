#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long dp[4000400];
long long sum[4000400];
long long f(long long l, long long r) {
  int x = sum[l] - sum[r + 1];
  if (x < 0) {
    x += m;
  }
  return x;
}
int main() {
  cin >> n >> m;
  dp[n] = 1;
  sum[n] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    for (long long z = 2; i * z <= n; z++) {
      dp[i] += f(i * z, (i + 1) * z - 1);
      if (dp[i] >= m) {
        dp[i] -= m;
      }
    }
    dp[i] += sum[i + 1];
    if (dp[i] >= m) {
      dp[i] -= m;
    }
    sum[i] = sum[i + 1] + dp[i];
    if (sum[i] >= m) {
      sum[i] -= m;
    }
  }
  cout << dp[1];
  return 0;
}
