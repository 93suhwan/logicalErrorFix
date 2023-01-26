#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
const long long MAXN = 1e7;
bool prime[MAXN + 5];
long long tot_primes_till[MAXN + 5];
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
void sieve() {
  int n = MAXN;
  fill(begin(prime), end(prime), true);
  prime[0] = prime[1] = false;
  for (long long i = 2; i <= n; i++) {
    tot_primes_till[i] = tot_primes_till[i - 1];
    if (!prime[i]) continue;
    tot_primes_till[i]++;
    for (long long j = 2 * i; j <= n; j += i) {
      prime[j] = false;
    }
  }
}
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long answer = power(a, b / 2, mod);
  answer *= answer;
  answer %= mod;
  if (b % 2) {
    answer *= a;
  }
  return answer % mod;
}
long long modmul(long long a, long long b, long long mod) {
  long long res = 0;
  a %= mod;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
void solve() {
  long long q;
  cin >> q;
  map<long long, long long> m;
  vector<long long> v;
  while (q--) {
    long long f;
    cin >> f;
    if (f == 1) {
      long long x;
      cin >> x;
      v.push_back(x);
    } else {
      long long x, y;
      cin >> x >> y;
      m[x] = y;
    }
  }
  for (long long i = 0; i < v.size(); i++) {
    if (m[v[i]] != 0) {
      v[i] = m[v[i]];
    }
  }
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
