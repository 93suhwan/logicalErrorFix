#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int maxn = 1e7 + 2;
vector<long long> a(maxn);
vector<long long> ainv(maxn);
vector<long long> pow2(maxn, 1);
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
    return expmod(2, (n * (n - 1)) / 2, MOD) * (a[k] * ainv[k - n] % MOD) % MOD;
  } else {
    long long ans = 0;
    long long u = expmod(2, n, MOD);
    long long v = 1;
    long long q = expmod(pow2[k] - 1, MOD - 2, MOD);
    for (long long i = 0; i < k; i++) {
      long long z = g(i, k) * (MOD + 1 - (pow2[i] - 1) * q % MOD) % MOD;
      long long sgn = ((k ^ i) & 1 ? 1 : -1);
      ans = (ans + sgn * v * (z * a[k - i - 1] % MOD)) % MOD;
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
  for (int i = 0; i < maxn; i++) {
    if (i > 0) pow2[i] = 2 * pow2[i - 1] % MOD;
    a[i] = s;
    s = s * (b - 1) % MOD;
    b = 2 * b % MOD;
  }
  s = expmod(s, MOD - 2, MOD);
  const int half = expmod(2, MOD - 2, MOD);
  for (int i = maxn - 1; i >= 0; i--) {
    b = half * b % MOD;
    s = s * (b - 1) % MOD;
    ainv[i] = s;
  }
  int T;
  cin >> T;
  while (T--) {
    long long n, k, x;
    cin >> n >> k >> x;
    cout << p(n, k, x) << endl;
  }
}
