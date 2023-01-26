#include <bits/stdc++.h>
using namespace std;
long long dp[200010];
long long h[200010];
int main() {
  dp[0] = 0;
  h[1] = 0;
  long long n, m;
  long long sum = 0;
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    h[i] = 0;
  }
  dp[1] = 1;
  sum += dp[1];
  for (int i = 2; i <= n; i++) {
    dp[i] += sum;
    dp[i] %= m;
    h[i] += h[i - 1] + 1;
    h[i] %= m;
    dp[i] += h[i];
    dp[i] %= m;
    sum += dp[i];
    sum %= m;
    int j = 2;
    while (j * i <= n) {
      h[j * i] += dp[i] - dp[i - 1];
      h[j * i] %= m;
      j++;
    }
  }
  printf("%lld", dp[n]);
  return 0;
}
