#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long binpow(long long base, long long exp) {
  long long mod = 1000000007LL;
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return res;
}
long long mod(long long x) {
  return ((x % 1000000007LL + 1000000007LL) % 1000000007LL);
}
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
const long long N = (long long)1e6;
void sieve(long long N) {
  bool prime[N + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= N; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= N; i += p) prime[i] = false;
    }
  }
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007LL;
  }
  return res;
}
long long C(long long n, long long k) {
  return fact(n) * 1ll * binpow(fact(k), 1000000007LL - 2) % 1000000007LL *
         1ll * binpow(fact(n - k), 1000000007LL - 2) % 1000000007LL;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long sum, n;
    cin >> sum >> n;
    vector<long long> ans(n, 0);
    long long maxe = (long long)1e9;
    long long i = 0;
    for (long long j = maxe; j >= 1; j = j / 10) {
      while (sum >= j && (sum - j) >= (n - i - 1)) {
        ans[i] += j;
        sum -= j;
        i++;
        if (i == n) {
          i = n - 1;
        }
      }
      if (sum <= 0) {
        break;
      }
    }
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
