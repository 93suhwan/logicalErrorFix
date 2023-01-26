#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")
const long long MOD = 1e9 + 7;
long long md = MOD;
long long Power(long long n, long long x) {
  long long ans = 1;
  while (x > 0) {
    if (x & 1) ans = (ans * n) % md;
    n = (n * n) % md;
    x = x >> 1;
  }
  return ans;
}
vector<long long> fact, inv;
void inverse(long long n) {
  if (n >= inv.size()) {
    long long size = inv.size();
    size = size == 0 ? 1 : size;
    inv.resize(n + 1);
    inv[0] = 1;
    for (long long i = size; i <= n; i++) inv[i] = Power(fact[i], md - 2);
  }
}
void factorial(long long n) {
  if (n >= fact.size()) {
    long long size = fact.size();
    size = size == 0 ? 1 : size;
    fact.resize(n + 1);
    fact[0] = 1;
    for (long long i = size; i <= n; i++) fact[i] = (fact[i - 1] * i) % md;
  }
}
long long ncr(long long n, long long r) {
  return (((fact[n] * inv[r]) % md) * inv[n - r]) % md;
}
vector<long long> SieveOfEratosthenes(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<long long> ans;
  for (long long p = 2; p <= n; p++)
    if (prime[p]) ans.push_back(p);
  return ans;
}
vector<long long> primeFactors(long long n) {
  vector<long long> ans;
  while (n % 2 == 0) {
    ans.push_back(2);
    n /= 2;
  }
  for (long long i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      ans.push_back(i);
      n /= i;
    }
  }
  if (n > 2) ans.push_back(n);
  return ans;
}
long long isPerfectSquare(long long x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  double ans = sqrt(n);
  if (n < 10)
    cout << n - 1;
  else if (isPerfectSquare(n)) {
    cout << ans - 1;
  } else if (n % 2 == 0) {
    cout << (long long)ceil(ans);
  } else {
    cout << (long long)floor(ans);
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
