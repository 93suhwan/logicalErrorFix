#include <bits/stdc++.h>
using namespace std;
long long fac[505] = {};
long long dp[505][505] = {};
long long x;
long long modpow(long long a, long long b) {
  long long x = 1;
  while (b) {
    if (b % 2 == 1) {
      x = (x * a) % 998244353;
    }
    b /= 2;
    a = (a * a) % 998244353;
  }
  return x;
}
long long ncr(long long n, long long r) {
  long long x = fac[n];
  long long y = (fac[r] * fac[n - r]) % 998244353;
  x = (x * modpow(y, 998244353 - 2)) % 998244353;
  return x;
}
long long fn(long long n, long long th) {
  if (th >= x)
    return 0;
  else if (n == 0) {
    return x - th;
  }
  if (dp[n][th] != 0) {
    return dp[n][th];
  }
  for (long long i = n - 1; i >= 0; i--) {
    dp[n][th] = (dp[n][th] +
                 ((modpow(n, n - i) * ncr(n, i)) % 998244353 * fn(i, th + n)) %
                     998244353) %
                998244353;
  }
  return dp[n][th];
}
void precompute(long long n) {
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % 998244353;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n >> x;
  precompute(n);
  cout << (modpow(x, n) - (n * fn(n - 1, 0)) % 998244353 + 998244353) %
              998244353;
  return 0;
}
