#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long MOD = 998244353;
vector<long long> a(1e7 + 20, 0);
vector<long long> ainv(1e7 + 20, 0);
vector<long long> pow2(1e7 + 20, 1);
long long expmod(long long a, long long b, int m) {
  int res = 1;
  a = a % m;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return res;
}
long long g(int n, int k) {
  if (n > k) return 0;
  return a[k] * (ainv[k - n] * ainv[n] % MOD) % MOD;
}
int p(long long n, long long k, long long x) {
  if (x == 0) {
    if (n > k) return 0;
    long long ans = a[k] * expmod(a[k - n], MOD - 2, MOD) % MOD;
    ans *= expmod(2, (n * (n - 1)) / 2, MOD);
    return ans % MOD;
  } else {
    long long ans = 0;
    long long u = expmod(2, n, MOD);
    long long v = 1;
    long long nonzero = pow2[k] - 1;
    long long nzi = expmod(nonzero, MOD - 2, MOD);
    for (long long i = 0; i < k; i++) {
      long long x = g(i, k);
      long long y = a[k - i - 1];
      long long z = x * (MOD + 1 - (pow2[i] - 1) * nzi % MOD) % MOD;
      long long sgn = ((k ^ i) & 1 ? 1 : -1);
      ans += sgn * v * (z * y % MOD) % MOD;
      ans %= MOD;
      v = v * u % MOD;
    }
    return (ans + MOD) % MOD;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long s = 1;
  long long b = 2;
  for (int i = 0; i <= 1e7; i++) {
    a[i] = s;
    s = s * (b - 1) % MOD;
    b = 2 * b % MOD;
  }
  s = expmod(s, MOD - 2, MOD);
  int half = expmod(2, MOD - 2, MOD);
  for (int i = 1e7; i >= 0; i--) {
    b = half * b % MOD;
    s = s * (b - 1) % MOD;
    ainv[i] = s;
  }
  for (int i = 1; i <= 1e7 + 5; i++) {
    pow2[i] = 2 * pow2[i - 1] % MOD;
  }
  int T;
  cin >> T;
  while (T--) {
    long long n, k, x;
    cin >> n >> k >> x;
    cout << p(n, k, x) << endl;
  }
}
