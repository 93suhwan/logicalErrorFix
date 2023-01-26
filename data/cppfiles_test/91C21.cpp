#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long mod = 998244353;
int n;
long long dp[2][N], a[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    long long ans = 0;
    int idx = 0;
    dp[1][a[n]] = 1;
    for (int i = n - 1; i >= 1; --i) {
      for (int j = 1; j <= a[i + 1];) {
        int v = a[i + 1] / j;
        int k = (a[i] + v - 1) / v;
        ans = (ans + i * dp[idx ^ 1][v] % mod * (k - 1) % mod) % mod;
        if (i != 1)
          dp[idx][a[i] / k] = (dp[idx][a[i] / k] + dp[idx ^ 1][v]) % mod;
        dp[idx ^ 1][v] = 0;
        j = a[i + 1] / v + 1;
      }
      if (i != 1) dp[idx][a[i]]++;
      idx ^= 1;
    }
    dp[1][a[n]] = 0;
    printf("%lld\n", ans);
  }
}
