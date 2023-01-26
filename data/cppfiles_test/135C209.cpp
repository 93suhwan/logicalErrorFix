#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17;
const long long mod = 1e15 + 9;
const long long N = 510;
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
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a.front() << "\n";
    return;
  }
  sort(a.rbegin(), a.rend());
  long long ans = 0;
  for (long long i = 0; i < k; ++i) {
    long long prev = inf, id = -1;
    for (long long j = k; j < n; ++j) {
      if (a[j] == 0) {
        continue;
      }
      long long cur = a[j] / a[i] - a[i] - a[j];
      if (cur < prev) {
        prev = cur, id = j;
      }
    }
    ans += prev + a[i] + a[id], a[i] = 0, a[id] = 0;
  }
  for (long long x : a) {
    ans += x;
  }
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
