#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int mod = 998244353;
int n, a[N], cnt;
long long dp[N][4];
long long ksm(long long base, long long n) {
  long long ans = 1ll;
  while (n) {
    if (n & 1ll) ans = ans * base % mod;
    base = base * base % mod;
    n >>= 1ll;
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n + 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        dp[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == 1) cnt++;
    }
    for (int i = 1; i <= n; ++i) {
      dp[a[i]][0] = 2 * dp[a[i]][0] % mod;
      if (a[i] >= 1) {
        dp[a[i]][0] = (dp[a[i]][0] + dp[a[i] - 1][0]) % mod;
      }
      dp[a[i]][1] = 2 * dp[a[i]][1] % mod;
      if (a[i] >= 2) {
        dp[a[i]][1] = (dp[a[i]][1] + dp[a[i] - 2][0]) % mod;
        dp[a[i]][1] = (dp[a[i]][1] + dp[a[i] - 2][2]) % mod;
      }
      dp[a[i]][2] = (dp[a[i]][2] + dp[a[i] + 2][1]) % mod;
      if (a[i] == 0) {
        dp[0][0]++;
      }
    }
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 3; ++j) {
        ans = (ans + dp[i][j]) % mod;
      }
    }
    ans = (ans + ksm(2, cnt)) % mod;
    ans = (ans - 1 + mod) % mod;
    printf("%lld\n", ans);
  }
}
