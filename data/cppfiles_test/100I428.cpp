#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0ll) {
    if (b % 2ll == 1ll) {
      result *= a;
    }
    a *= a;
    b /= 2ll;
  }
  return result;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
bool isPerfectSquare(long long n) {
  long long sr = sqrt(n);
  if (sr * sr == n)
    return true;
  else
    return false;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
int log22(long long x) { return 64 - __builtin_clzll(x) - 1; }
vector<int> SieveOfEratosthenes(int n) {
  vector<int> mem;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long i = 2; i < n; i++)
    if (prime[i]) mem.push_back(i);
  return mem;
}
long long modInverse(long long n, long long p) { return powerM(n, p - 2, p); }
long long nCrMod(long long n, int r, long long p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long phac(long long n) {
  long long res = 1;
  for (long long i = 1; i < n + 1; i++) (res *= i) %= MOD;
  return res;
}
void solve() {
  long long n;
  cin >> n;
  vector<int> v(n + 1);
  int maxm = 0;
  int maxc = 0;
  for (long long i = 1; i < n + 1; i++) {
    cin >> v[i];
    maxm = max(maxm, v[i]);
  }
  for (long long i = 1; i < n + 1; i++) {
    if (v[i] == maxm) maxc++;
  }
  int secmax = 0;
  int secmaxc = 0;
  for (long long i = 1; i < n + 1; i++) {
    if (v[i] == maxm) continue;
    secmax = max(secmax, v[i]);
  }
  for (long long i = 1; i < n + 1; i++) {
    if (secmax == v[i]) secmaxc++;
  }
  if (maxm > secmax + 1 && secmax != 0) {
    cout << 0 << '\n';
    return;
  }
  int ans = phac(n);
  if (maxc > 1) {
    cout << ans << '\n';
    return;
  }
  int res = nCrMod(n, secmaxc + 1, MOD);
  (res *= phac(secmaxc)) %= MOD;
  (res *= phac(n - secmaxc - 1)) %= MOD;
  (ans -= res) %= MOD;
  if (ans <= 0) ans += MOD;
  cout << ans % MOD << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
