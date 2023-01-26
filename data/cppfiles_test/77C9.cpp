#include <bits/stdc++.h>
using namespace std;
const long long inf = (1ll << 62) - 1;
long long mod = 1e9 + 7;
const long long N = 1e5 + 100;
const long double pi = 3.14159265358979323846;
const long double eps = 1e-7;
long long dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
long long dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
long long bPow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    b >>= 1;
    a = (a * a) % mod;
  }
  return res % mod;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<long long> fact(N, 0ll);
void factorial() {
  fact[0] = 1, fact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}
long long ncr(long long n, long long r) {
  if (r > n) return 0;
  long long ans = fact[n] % mod;
  ans *= bPow(fact[r], mod - 2) % mod;
  ans %= mod;
  ans *= bPow(fact[n - r], mod - 2) % mod;
  ans %= mod;
  return ans;
}
vector<long long> primes(N, -1);
void sieve() {
  iota(primes.begin(), primes.end(), 0);
  for (long long i = 2; i < N; ++i) {
    if (primes[i] == i) {
      for (long long j = i * 2; j < N; j += i) {
        primes[j] = i;
      }
    }
  }
}
long long add(long long a, long long b) {
  a %= mod, b %= mod;
  return ((a + b) % mod + mod) % mod;
}
long long mul(long long a, long long b) {
  a %= mod, b %= mod;
  return ((a * b) % mod + mod) % mod;
}
long long sub(long long a, long long b) {
  a %= mod, b %= mod;
  return ((a - b + 2 * mod) % mod + mod) % mod;
}
void solve() {
  long long n;
  cin >> n >> mod;
  vector<long long> dp(n + 1, 0), pref(n + 2, 0);
  long long prev = 0;
  for (long long i = 1; i <= n; ++i) {
    pref[i] = add(pref[i], pref[i - 1]);
    dp[i] = add(dp[i], pref[i] + prev);
    if (i == 1) {
      dp[i] = add(dp[i], 1);
    }
    long long j = 2;
    while (i * j <= n) {
      long long x = i * j, y = min(n + 1, (i + 1) * j);
      pref[x] = add(pref[x], dp[i]);
      pref[y] = sub(pref[y], dp[i]);
      j++;
    }
    prev = add(prev, dp[i]);
  }
  cout << dp[n] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long tc = 1, test = 1;
  while (tc--) {
    solve();
  }
}
