#include <bits/stdc++.h>
using namespace std;
inline int inc(int& a, int b) {
  a = (a + b < 998244353) ? a + b : a + b - 998244353;
  return a;
}
inline int mul(int a, int b) { return (int)((long long int)a * b % 998244353); }
inline int pow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int n, k, ans = 0;
int dp[2][101][2002];
int sum[2][101][2002];
int cen[2002];
int fac[2002];
int C(int a, int b) {
  return mul(fac[a], pow(mul(fac[b], fac[a - b]), 998244353 - 2));
}
int main(void) {
  scanf("%d%d", &n, &k);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &cen[i]);
    cen[i] -= k;
    fac[i] = mul(fac[i - 1], i);
  }
  for (int i = 0; i <= k + k; i++) sum[0][i][0] = 1;
  dp[0][0][0] = 1;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    int lst = now;
    now ^= 1;
    for (int j = 0; j <= k + k; j++)
      for (int p = 0; p <= n; p++) dp[now][j][p] = sum[now][j][p] = 0;
    for (int j = 0; j <= k + k; j++)
      for (int p = max(j + cen[i], 0); p <= i; p++) {
        int lstj = j + cen[i] - cen[i - 1];
        if (p > 0) inc(dp[now][j][p], sum[lst][min(lstj - 1, k + k)][p - 1]);
        if (lstj >= 0) {
          inc(dp[now][j][p], mul(dp[lst][lstj][p], p));
          inc(dp[now][j][p], mul(dp[lst][lstj][p - 1], p - (j + cen[i])));
        }
        sum[now][j][p] = dp[now][j][p];
        if (j > 0) inc(sum[now][j][p], sum[now][j - 1][p]);
      }
  }
  int ans = 0;
  for (int j = 0; j <= (k + k); j++) {
    int realj = j + cen[n];
    if (realj > n) break;
    for (int p = max(realj, 0); p <= n; p++) {
      int w = dp[now][j][p];
      inc(ans, mul(w, C(n - realj, p - realj)));
    }
  }
  printf("%d\n", ans);
  return 0;
}
