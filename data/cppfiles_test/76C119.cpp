#include <bits/stdc++.h>
using namespace std;
long long dp[200005];
void solve(long long tc) {
  long long n, m;
  cin >> n >> m;
  dp[1] = 1;
  long long sum = 1;
  for (long long i = 2; i <= n; i++) {
    dp[i] = sum;
    for (long long j = 1; j * j <= i; j++) {
      long long lo = i / (j + 1);
      long long hi = i / j;
      long long cnt = hi - lo;
      dp[i] = dp[i] + cnt * dp[j];
      dp[i] %= m;
      if (j != i / j and j > 1) {
        dp[i] = dp[i] + dp[i / j];
        dp[i] %= m;
      }
    }
    sum = sum + dp[i];
    sum %= m;
  }
  cout << dp[n];
}
int main() {
  ios_base::sync_with_stdio(0);
  long long t = 1;
  long long tc = 1;
  while (t--) {
    solve(tc);
    tc++;
  }
  return 0;
}
