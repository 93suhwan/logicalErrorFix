#include <bits/stdc++.h>
using namespace std;
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
void __print(long long x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\m"; }
template <typename T, typename... V>
void _print(T n, V... v) {
  __print(n);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
namespace number_theory {
long long powersimple(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
      b--;
    }
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long ncr(long long m, long long k) {
  long long ans = 1;
  if (k > m - k) {
    k = m - k;
  }
  for (long long i = 1; i <= k; i++) {
    ans *= (m - i + 1), ans /= i;
  }
  return ans;
}
long long power(long long m, long long y, long long p) {
  long long res = 1;
  m = m % p;
  while (y > 0) {
    if (y & 1) res = (res * m) % p;
    y = y >> 1;
    m = (m * m) % p;
  }
  return res;
}
long long modInverse(long long m, long long p) { return power(m, p - 2, p); }
long long ncrModPFermat(long long m, long long r, long long p) {
  if (m == 0) return 1;
  long long fac[m + 1];
  fac[0] = 1;
  for (long long i = 1; i <= m; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[m] * modInverse(fac[m], p) % p * modInverse(fac[m - m], p) % p) %
         p;
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
}  // namespace number_theory
using namespace number_theory;
struct custom_hash {
  static uint64_t splitmix64(uint64_t m) {
    m += 0x9e3779b97f4a7c15;
    m = (m ^ (m >> 30)) * 0xbf58476d1ce4e5b9;
    m = (m ^ (m >> 27)) * 0x94d049bb133111eb;
    return m ^ (m >> 31);
  }
  size_t operator()(uint64_t m) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(m + FIXED_RANDOM);
  }
};
void solve() {
  long long m, n, k;
  cin >> m >> n >> k;
  bool pos = true;
  cin >> n >> m >> k;
  if (n % 2 == 0 and m % 2 == 0) {
    if (k % 2 == 0)
      cout << "yes\n";
    else
      cout << "no\n";
  } else if (n & 1 and m % 2 == 0) {
    if ((k - m / 2) % 2 == 0)
      cout << "yes\n";
    else
      cout << "no\n";
  } else if (n % 2 == 0 and m % 2 == 1) {
    if (((m - 1) * n / 2 - k) % 2 == 0)
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n = 1;
  cin >> n;
  while (n-- > 0) {
    solve();
  }
  return 0;
}
