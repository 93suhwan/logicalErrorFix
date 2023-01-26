#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
long long int dp[501][501], pw[501][501], C[501][501];
int main() {
  int n, x;
  cin >> n >> x;
  C[0][0] = 1;
  for (int i = 1; i <= 500; i++) {
    pw[i][0] = 1;
    C[i][0] = 1;
    for (int j = 1; j <= 500; j++) {
      pw[i][j] = pw[i][j - 1] * i % (long long int)(998244353);
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (j < i) {
        dp[i][j] = (pw[j][i] - pw[j - 1][i] + (long long int)(998244353)) %
                   (long long int)(998244353);
        continue;
      }
      for (int k = 2; k <= i; k++) {
        dp[i][j] += (dp[k][j - i + 1] * C[i][k] % (long long int)(998244353)) *
                    pw[i - 1][i - k] % (long long int)(998244353);
        dp[i][j] %= (long long int)(998244353);
      }
    }
  }
  long long int ans = 0;
  for (int i = 1; i <= x; i++) {
    ans += dp[n][i];
    ans %= (long long int)(998244353);
  }
  cout << ans;
}
