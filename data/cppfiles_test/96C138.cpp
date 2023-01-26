#include <bits/stdc++.h>
using namespace std;
long long i, j, p, q, n, m, k, x, ans, dp[506][506], comb[506][506];
long long st(long long a, long long b) {
  long long f = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      f = f * a;
      f %= 998244353;
    }
    a = a * a;
    a %= 998244353;
    b /= 2;
  }
  return f;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> x;
  comb[0][1] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i + 1; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      comb[i][j] %= 998244353;
    }
  }
  dp[n][0] = 1;
  for (i = n; i >= 2; i--) {
    for (j = 0; j <= x; j++) {
      q = min(x, j + i - 1);
      if (dp[i][j] == 0) continue;
      for (k = i; k >= 0; k--) {
        dp[k][q] +=
            (dp[i][j] * ((comb[i][i - k + 1] * st(q - j, i - k)) % 998244353)) %
            998244353;
        dp[k][q] %= 998244353;
      }
    }
  }
  for (i = 1; i <= x; i++) ans += dp[0][i], ans %= 998244353;
  cout << ans << endl;
  return 0;
}
