#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17;
const long long mod = 998244353;
const long long N = 1010;
const long double pi = 3.14159265358979323846;
const long double eps = 1e-7;
long long di[] = {-1, 0, 1, 0, -1, -1, 1, 1};
long long dj[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};
long long bPow(long long a, long long b) {
  if (b < 0) {
    return 0;
  }
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
  long long n, k;
  cin >> n >> k;
  long long cur = 1, ans = 0;
  while (cur < k) {
    cur *= 2, ans++;
    if (cur >= n) {
      cout << ans << "\n";
      return;
    }
  }
  ans += (n - cur + k - 1) / k;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long tc = 1, test = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
