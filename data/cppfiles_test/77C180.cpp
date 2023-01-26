#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("O2")
long long MOD = 1e9 + 7;
long long power(long long a, long long b, long long m = MOD) {
  long long ans = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) ans = (1ll * a * ans) % m;
    b >>= 1;
    a = (1ll * a * a) % m;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long x, long long y) { return (x * y) / gcd(x, y); }
bool isprime(long long n) {
  if (n < 2) return 0;
  long long i = 2;
  while (i * i <= n) {
    if (n % i == 0) return 0;
    i++;
  }
  return 1;
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
double distform(long long x, long long y, long long z, long long w) {
  return sqrt(1. * pow(x - z, 2) + 1. * pow(y - w, 2));
}
long long dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
long long dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
const long long MAXN = 4e6 + 10;
const long long inf = 1e18;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
long long intlog(double base, double x) {
  return (long long)(log(x) / log(base));
}
bool isvalid(long long x, long long y, long long n, long long m) {
  return x >= 0 and x < n and y >= 0 and y < m;
}
template <typename T>
void read(T &x) {
  for (long long i = 0; i < ((long long)(x).size()); ++i) cin >> x[i];
}
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
long long query(long long start, long long end) {
  cout << "? " << start << " " << end << '\n';
  long long q;
  cin >> q;
  return q;
}
void print(long long n) { cout << "! " << n << '\n'; }
struct Local {
  char paramA;
  Local(char paramA) { this->paramA = paramA; }
  bool operator()(long long i, long long j, ...) { return false; }
};
long long diff_array[MAXN];
void solve() {
  long long n, m;
  cin >> n >> m;
  MOD = m;
  vector<long long> dp(n + 1);
  dp[1] = 1;
  long long sum = 0;
  long long diff_sum = 0;
  for (long long i = 1; i <= n; ++i) {
    diff_sum += diff_array[i];
    if (i != 1) dp[i] = diff_sum;
    dp[i] = (dp[i] + sum) % MOD;
    sum = (sum + dp[i]) % MOD;
    for (long long j = 2; i * j <= n; ++j) {
      diff_array[j * i] += dp[i];
      diff_array[j * i] %= MOD;
      diff_array[min(n, (j * (i + 1)) - 1) + 1] -= dp[i];
      diff_array[min(n, (j * (i + 1)) - 1) + 1] %= MOD;
    }
    diff_sum %= MOD;
  }
  cout << (dp[n] + MOD) % MOD << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
}
