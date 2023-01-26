#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long mx = 100000;
vector<long long> mobius(1 + mx, 0);
vector<bool> isprime(1 + mx, true);
long long n, m;
vector<long long> l, r;
void sieve() {
  isprime[1] = false;
  mobius[1] = 1;
  vector<long long> primes;
  long long i, j;
  for (i = 2; i <= mx; i++) {
    if (isprime[i]) {
      primes.push_back(i);
      mobius[i] = -1;
    }
    for (j = 0; j < primes.size() and i * primes[j] <= mx; j++) {
      isprime[i * primes[j]] = false;
      if (i % primes[j] == 0) {
        mobius[i * primes[j]] = 0;
        break;
      } else {
        mobius[i * primes[j]] = mobius[i] * mobius[primes[j]];
      }
    }
  }
}
long long solve(long long d) {
  long long M;
  M = m / d;
  vector<long long> dp(M + 1, 0);
  long long i, j;
  vector<long long> psum(M + 1, 0);
  dp[0] = 1;
  for (i = 0; i <= M; i++) psum[i] = 1;
  for (i = 1; i <= n; i++) {
    long long left, right;
    left = ceil_div(l[i], d);
    right = r[i] / d;
    if (left > right) return 0LL;
    for (j = 0; j <= M; j++) {
      dp[j] = ((j - left >= 0 ? psum[j - left] : 0LL) + mod -
               (j - right > 0 ? psum[j - right - 1] : 0LL)) %
              mod;
    }
    for (j = 0; j <= M; j++) {
      psum[j] = (j == 0 ? dp[0] : mod_add(dp[j], psum[j - 1]));
    }
  }
  long long ans = 0;
  for (i = 1; i <= M; i++) {
    ans = mod_add(ans, dp[i]);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, i, j, ans, temp, sum;
  string sans;
  t = 1;
  while (t--) {
    sans = "NO";
    ans = temp = sum = 0;
    cin >> n >> m;
    l.resize(n + 1);
    r.resize(n + 1);
    for (i = 1; i <= n; i++) {
      cin >> l[i] >> r[i];
    }
    vector<long long> f(m + 1), g(m + 1);
    for (i = 1; i <= m; i++) {
      g[i] = solve(i);
    }
    for (i = m; i >= 1; i--) {
      f[i] = g[i] % mod;
      for (j = 2 * i; j <= m; j += i) {
        f[i] = (f[i] - f[j] + mod) % mod;
      }
    }
    ans = f[1];
    cout << ans << "\n";
  }
  return 0;
}
