#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long sz = 2e6 + 5;
vector<long long> fac, ifac;
vector<int> prime;
long long mpow(long long a, long long b = mod - 2, long long m = mod) {
  long long res = 1;
  a %= m;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
  }
  return res;
}
void init() {
  fac.resize(sz, 1);
  ifac.resize(sz);
  for (long long i = 2; i < sz; i++) fac[i] = (fac[i - 1] * i) % mod;
  ifac[sz - 1] = mpow(fac[sz - 1]);
  for (long long i = sz - 2; i >= 0; i--)
    ifac[i] = (ifac[i + 1] * (i + 1)) % mod;
  prime.resize(sz);
  for (int i = 2; i < sz; i++) prime[i] = i;
  for (long long i = 2; i * i < sz; i++) {
    if (prime[i] != i) continue;
    for (long long j = i * i; j < sz; j += i)
      if (prime[j] == j) prime[j] = i;
  }
}
long long nCr(long long n, long long r) {
  if (n <= 0 || r < 0) return 0;
  if (n < r) return 0;
  return (fac[n] * (ifac[r] * ifac[n - r] % mod)) % mod;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void solve() {
  long long n;
  cin >> n;
  long long sm = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    sm += x;
  }
  if (sm % n == 0)
    cout << 0 << "\n";
  else
    cout << 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
