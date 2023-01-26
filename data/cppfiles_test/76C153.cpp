#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
long long dp[N], sum[N];
int main() {
  int n, mod;
  scanf("%d %d", &n, &mod);
  dp[n] = sum[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    dp[i] = sum[i + 1];
    for (int j = 2; j * i <= n; j++) {
      int r = min((long long)n, (long long)i * j + j - 1);
      dp[i] = (dp[i] + sum[i * j] - sum[r + 1]) % mod;
    }
    sum[i] = (sum[i + 1] + dp[i]) % mod;
  }
  printf("%lld\n", dp[1]);
  return 0;
}
