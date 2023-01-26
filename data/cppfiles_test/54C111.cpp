#include <bits/stdc++.h>
using namespace std;
long long extEuclid(long long a, long long b, long long &x, long long &y) {
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {
    long long q = a / b;
    tie(a, b) = make_tuple(b, a % b);
    tie(x, xx) = make_tuple(xx, x - q * xx);
    tie(y, yy) = make_tuple(yy, y - q * yy);
  }
  return a;
}
long long modInverse(long long b, long long m) {
  long long x, y;
  long long d = extEuclid(b, m, x, y);
  if (d != 1) return -1;
  return (x + m) % m;
}
const int maxN = 200010;
long long MOD = 1e9 + 7, fact[maxN], invFact[maxN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i < maxN; i++) {
    fact[i] = (i * fact[i - 1]) % MOD;
    invFact[i] = modInverse(fact[i], MOD);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    long long combis = 0;
    for (int i = 0; i < n; i += 2) {
      long long ncr = (fact[n] * invFact[i]) % MOD;
      ncr = (ncr * invFact[n - i]) % MOD;
      combis = (combis + ncr) % MOD;
    }
    long long _2pwn = 1;
    for (int i = 0; i < n; i++) _2pwn = (_2pwn * 2) % MOD;
    long long ans = 1;
    if (n & 1) {
      combis++;
      for (int i = 0; i < k; i++) ans = (ans * combis) % MOD;
    } else {
      for (int i = 0; i < k; i++) ans = (ans * combis) % MOD;
      long long pow2pwn[k];
      pow2pwn[0] = 1;
      for (int i = 1; i < k; i++) pow2pwn[i] = (pow2pwn[i - 1] * _2pwn) % MOD;
      long long front = 1;
      for (int i = 0; i < k; i++) {
        ans += (front * pow2pwn[k - i - 1]) % MOD;
        ans %= MOD;
        front = (front * combis) % MOD;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
