#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const int mod = 998244353;
int n, m, i, j, k, l[2005], r[2005], dp[2][2005][2005], sum[2][2005][2005],
    fac[2005], inv[2005], first[2005], ans;
int main() {
  fac[0] = fac[1] = inv[1] = first[0] = first[1] = 1;
  for ((i) = (2); (i) <= (2002); (i)++) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    first[i] = 1ll * first[i - 1] * inv[i] % mod;
  }
  read(n);
  read(m);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    int x;
    read(x);
    l[i] = max(0, x - m);
    r[i] = min(i, x + m);
  }
  dp[0][0][0] = 1;
  sum[0][0][0] = 1;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    for (j = 0; j <= i; j++) {
      for ((k) = (l[i]); (k) <= (r[i]); (k)++) {
        if (k > j) break;
        dp[i & 1][j][k] =
            (dp[i & 1][j][k] + 1ll * dp[(i - 1) & 1][j][k] * j) % mod;
        if (j)
          dp[i & 1][j][k] += dp[(i - 1) & 1][j - 1][k],
              dp[i & 1][j][k] = dp[i & 1][j][k] >= mod ? dp[i & 1][j][k] - mod
                                                       : dp[i & 1][j][k];
        if (j && k)
          dp[i & 1][j][k] =
              (dp[i & 1][j][k] +
               1ll * sum[(i - 1) & 1][j - 1][min(k - 1, r[i - 1])] *
                   first[j - k]) %
              mod;
        sum[i & 1][j][k] = 1ll * dp[i & 1][j][k] * fac[j - k] % mod;
        if (k)
          sum[i & 1][j][k] += sum[i & 1][j][k - 1],
              sum[i & 1][j][k] = sum[i & 1][j][k] >= mod
                                     ? sum[i & 1][j][k] - mod
                                     : sum[i & 1][j][k];
      }
    }
    for (((j)) = (0); ((j)) <= (((int)(i)) - 1); ((j))++) {
      for ((k) = (l[i - 1]); (k) <= (r[i - 1]); (k)++) {
        if (k > j) break;
        dp[(i - 1) & 1][j][k] = sum[(i - 1) & 1][j][k] = 0;
      }
    }
  }
  int ans = 0;
  for (i = 0; i <= n; i++) {
    for ((j) = (l[n]); (j) <= (r[n]); (j)++) {
      if (j > i) break;
      ans =
          (ans + 1ll * dp[n & 1][i][j] * fac[n - j] % mod * first[n - i]) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
