#include <bits/stdc++.h>
const long long N = 1e5 + 10;
const long long mod2 = 998244353;
long long n, m, sum[N], ans, cnt;
long long l[N], r[N], dp[55][N];
long long mu[N], prime[N], prime_tot;
bool prime_tag[N];
void init(long long lim) {
  prime_tot = 0;
  mu[1] = 1;
  for (long long i = (2); i <= (lim); i++) {
    if (!prime_tag[i]) {
      prime[++prime_tot] = i;
      mu[i] = -1;
    }
    for (long long j = (1); j <= (prime_tot); j++) {
      if (i * prime[j] > lim) break;
      prime_tag[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      } else
        mu[i * prime[j]] = -mu[i];
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  init(m);
  for (long long i = (1); i <= (n); i++) std::cin >> l[i] >> r[i];
  for (long long d = (1); d <= (m); d++) {
    dp[0][0] = 1;
    cnt = 0;
    for (long long i = (1); i <= (n); i++) {
      sum[0] = dp[i - 1][0];
      for (long long j = (1); j <= (m / d); j++)
        sum[j] = sum[j - 1] + dp[i - 1][j];
      for (long long j = ((l[i] + d - 1) / d); j <= (m / d); j++) {
        if (j - r[i] / d - 1 < 0)
          dp[i][j] = sum[j - ((l[i] + d - 1) / d)];
        else
          dp[i][j] = sum[j - ((l[i] + d - 1) / d)] - sum[j - r[i] / d - 1];
        dp[i][j] %= mod2;
      }
    }
    for (long long i = (1); i <= (m / d); i++) cnt += dp[n][i];
    ans = ((ans + mu[d] * cnt) % mod2 + mod2) % mod2;
  }
  std::cout << ans << '\n';
  return 0;
}
