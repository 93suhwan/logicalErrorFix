#include <bits/stdc++.h>
const long long P = 998244353;
using namespace std;
long long up(long long x, long long n) {
  if (x % n == 0)
    return x / n;
  else
    return x / n + 1;
}
long long gcd(long long a, long long b) {
  if (b != 0)
    return gcd(b, a % b);
  else
    return a;
}
const long long N = 507;
long long fact[N];
void factorial() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    long long x = fact[i - 1] * i;
    fact[i] = x % P;
  }
}
long long fastexp(long long bs, long long ex) {
  if (!ex) return 1;
  long long p = fastexp((bs * bs) % P, ex >> 1);
  return (ex & 1) ? (p * bs) % P : p;
}
long long ncr(long long n, long long i) {
  if (i > n) return 0;
  long long x = fact[n];
  long long y = (fact[i] * fact[n - i]) % P;
  long long q = fastexp(y, P - 2);
  x *= q;
  x %= P;
  return x;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  factorial();
  long long n, m;
  cin >> n >> m;
  long long dp[n + 1][m + 1];
  memset(dp, 0, sizeof(dp));
  dp[n][0] = 1;
  for (long long i = n; i >= 2; i--) {
    for (long long j = 0; j < m + 1; j++) {
      if (dp[i][j] != 0) {
        long long jj = min(m, j + i - 1);
        for (long long k = i; k >= 0; k--) {
          dp[k][jj] += (dp[i][j] % P * ncr(i, k) * fastexp(jj - j, i - k)) % P;
          dp[k][jj] %= P;
        }
      }
    }
  }
  long long sum = 0;
  for (long long i = 0; i < m + 1; i++) {
    sum += dp[0][i];
    sum %= P;
  }
  cout << sum;
  return 0;
}
