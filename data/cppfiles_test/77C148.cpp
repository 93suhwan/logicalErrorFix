#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long dp[4000050];
long long sum[4000050];
int main() {
  scanf("%lld%lld", &n, &m);
  dp[n] = 1;
  sum[n + 1] = 0;
  for (long long i = n; i >= 1; --i) {
    dp[i] += sum[i + 1];
    dp[i] %= m;
    for (long long j = 2; j * i <= n; ++j) {
      long long l = j * i;
      long long r = min(j * i + j, n + 1);
      dp[i] += (sum[l] - sum[r]);
      dp[i] %= m;
    }
    sum[i] = sum[i + 1] + dp[i];
    sum[i] %= m;
  }
  printf("%lld\n", dp[1]);
  return 0;
}
