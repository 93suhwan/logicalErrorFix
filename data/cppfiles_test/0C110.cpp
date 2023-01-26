#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 1050000;
const int mod = (int)1e9 + 7;
long long binpow(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res = (res * x) % mod;
      p--;
    } else {
      x = (x * x) % mod;
      p /= 2;
    }
  }
  return res % mod;
}
long long inv(long long x) { return binpow(x, mod - 2) % mod; }
long long f[MAXN];
long long invF[MAXN];
long long getCnk(long long n, long long k) {
  if (n < k) return 0;
  long long res = f[n];
  res = res * invF[n - k] % mod;
  res = res * invF[k] % mod;
  return res;
}
long long subMod(long long a, long long b) {
  long long res = a - b;
  return res < 0 ? res + mod : res;
}
int n, qn;
long long dp[MAXN][3];
int main() {
  scanf("%d %d", &n, &qn);
  f[0] = 1;
  for (int i = 1; i <= 3 * n; i++) f[i] = 1ll * f[i - 1] * i % mod;
  invF[3 * n] = inv(f[3 * n]);
  for (int i = 3 * n - 1; i >= 0; i--)
    invF[i] = 1ll * invF[i + 1] * (i + 1) % mod;
  dp[0][0] = dp[0][1] = dp[0][2] = n;
  long long inv3 = inv(3);
  for (int i = 1; i <= 3 * n; i++) {
    long long sum = getCnk(3 * n, i + 1);
    dp[i][0] = subMod(sum, 2 * dp[i - 1][0] % mod);
    dp[i][0] = subMod(dp[i][0], dp[i - 1][1]);
    dp[i][0] = dp[i][0] * inv3 % mod;
    dp[i][1] = (dp[i][0] + dp[i - 1][0]) % mod;
    dp[i][2] = (dp[i][1] + dp[i - 1][1]) % mod;
  }
  for (int i = 0; i < qn; i++) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", (dp[x][0] + getCnk(3 * n, x)) % mod);
  }
  return 0;
}
