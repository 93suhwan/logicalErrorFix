#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
const long long M = 998244353;
int n, m;
long long dp[maxn][maxn], c[maxn][maxn];
void init() {
  c[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
  }
}
long long ksm(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % M;
    x = x * x % M;
    y >>= 1;
  }
  return ans;
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) dp[1][i] = i;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= m; j++) {
      for (int k = 0; k < i; k++) {
        dp[i][j] = (dp[i][j] +
                    dp[i - k][j - i + 1] * ksm(i - 1, k) % M * c[i][k] % M) %
                   M;
      }
    }
  }
  long long ans = (ksm(m, n) - dp[n][m] + M) % M;
  printf("%lld\n", ans);
  return 0;
}
