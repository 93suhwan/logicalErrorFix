#include <bits/stdc++.h>
using namespace std;
long long T, n, dp[50], a[50];
signed main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld", &n);
    long long k = 0;
    memset(dp, 0, sizeof dp);
    while (n) {
      a[++k] = n % 10;
      n /= 10;
    }
    long long temp1 = 0, temp2 = 0;
    for (long long i = k; i; i--) {
      if (i % 2)
        temp1 = temp1 * 10 + a[i];
      else
        temp2 = temp2 * 10 + a[i];
    }
    if (temp1 == 0 || temp2 == 0)
      printf("%lld\n", temp1 + temp2 - 1);
    else {
      printf("%lld\n", (temp2 + 1) * (temp1 + 1) - 2);
    }
  }
  return 0;
}
