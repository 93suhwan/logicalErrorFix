#include <bits/stdc++.h>
using namespace std;
const long long INF = 998244353;
long long modpow(long long b, long long e) {
  long long ans = 1;
  for (; e; b = b * b % INF, e /= 2)
    if (e & 1) ans = ans * b % INF;
  return ans;
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long memo[501][501];
long long dp(int hero, int mx) {
  if (hero == 1) return 0;
  if (memo[hero][mx] != -1) return memo[hero][mx];
  long long &ans = memo[hero][mx];
  ans = modpow(min(hero - 1, mx), hero);
  if (mx > hero - 1) {
    for (int i = (2); i < (hero + 1); ++i) {
      ans += dp(i, mx - hero + 1) * modpow(min(hero - 1, mx), hero - i) % INF *
             nCrModPFermat(hero, i, INF) % INF;
      ans %= INF;
    }
  }
  return ans;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  memset(memo, -1, sizeof(memo));
  int n, x;
  cin >> n >> x;
  cout << dp(n, x) << endl;
  return 0;
}
