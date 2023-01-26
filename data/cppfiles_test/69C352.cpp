#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 5;
const double pi = acos(-1.0);
long long addM(long long a, long long b) { return (a + b) % MOD; }
long long multM(long long a, long long b) { return (a * b) % MOD; }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
long long ModInverse(long long n) { return binpow(n, MOD - 2); }
vector<long long> findFact() {
  vector<long long> fact(N);
  fact[0] = 1;
  for (long long i = 1; i <= N; i++) {
    fact[i] = multM(i, fact[i - 1]);
  }
  return fact;
}
long long ncr(long long n, long long r) {
  vector<long long> fact = findFact();
  return ((fact[n] * ModInverse(fact[n - r])) % MOD * ModInverse(fact[r])) %
         MOD;
}
vector<bool> findPrime() {
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (long long i = 2; i <= N; i++) {
    if (is_prime[i] && i * i <= N) {
      for (long long j = i * i; j <= N; j += i) is_prime[j] = false;
    }
  }
  return is_prime;
}
vector<bool> segmentedSieveNoPreGen(long long L, long long R) {
  vector<bool> isPrime(R - L + 1, true);
  long long lim = sqrt(R);
  for (long long i = 2; i <= lim; ++i)
    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
      isPrime[j - L] = false;
  if (L == 1) isPrime[0] = false;
  return isPrime;
}
long long n, m;
long long dp[20][20];
string x, y;
long long solve(long long i, long long j) {
  if (i >= n) {
    return m - j;
  }
  if (j >= m) {
    return n - i;
  }
  if (dp[i][j] != -1) return dp[i][j];
  if (x[i] == y[j]) {
    long long ans = solve(i + 1, j + 1);
    ans = min(ans, 1 + solve(i + 1, j));
    return dp[i][j] = ans;
  } else {
    return dp[i][j] = 1 + solve(i + 1, j);
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  vector<string> v;
  for (long long i = 0; i < 60; i++) {
    long long num = binpow(2, i);
    v.push_back(to_string(num));
  }
  while (tt--) {
    string k;
    cin >> k;
    long long ans = 1e18;
    n = k.length();
    x = k;
    for (auto& xx : v) {
      m = xx.length();
      y = xx;
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
          dp[i][j] = -1;
        }
      }
      long long val = solve(0, 0);
      ans = min(ans, val);
    }
    cout << ans << "\n";
  }
  return 0;
}
