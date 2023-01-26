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
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
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
long long ncr(long long n, long long k) {
  long long ans = 1;
  if (k > n - k) {
    k = n - k;
  }
  for (long long i = 1; i <= k; i++) {
    ans *= (n - i + 1), ans /= i;
  }
  return ans;
}
long long power(long long r, long long y, long long p) {
  long long res = 1;
  r = r % p;
  while (y > 0) {
    if (y & 1) res = (res * r) % p;
    y = y >> 1;
    r = (r * r) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long ncrModPFermat(long long n, long long r, long long p) {
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
}  // namespace number_theory
using namespace number_theory;
struct custom_hash {
  static uint64_t splitmix64(uint64_t r) {
    r += 0x9e3779b97f4a7c15;
    r = (r ^ (r >> 30)) * 0xbf58476d1ce4e5b9;
    r = (r ^ (r >> 27)) * 0x94d049bb133111eb;
    return r ^ (r >> 31);
  }
  size_t operator()(uint64_t r) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(r + FIXED_RANDOM);
  }
};
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  bool pos = true;
  if (n == 1) {
    if (k != m / 2) {
      cout << "no\n";
      return;
    }
  }
  if (m == 1 and k != 0) {
    cout << "no\n";
    return;
  }
  vector<long long> grid(m, n);
  long long cur = k;
  long long i = 0;
  while (cur > 0 and pos) {
    if (i >= n - 1) {
      i = 0;
      continue;
    }
    if (grid[i] & 1) {
      cur--;
      grid[i]--;
      grid[i + 1]--;
    } else {
      if (cur < 2) {
        pos = false;
        break;
      }
      cur -= 2;
      grid[i] -= 2;
      grid[i + 1] -= 2;
    }
    i++;
    if (i >= m) {
      i = 0;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (grid[i] & 1) {
      pos = false;
      break;
    }
  }
  if (pos)
    cout << "yes\n";
  else
    cout << "no\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
