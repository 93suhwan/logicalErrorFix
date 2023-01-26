#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using ll = long long;
using ull = unsigned long long;
using ld = long double;
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr int MOD = 998244353;
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
template <typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) cin >> it;
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) cout << it << " ";
  return ostream;
}
template <typename T>
void print(T &&t) {
  cout << t << "\n";
}
template <typename T, typename... Args>
void print(T &&t, Args &&...args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
template <typename T>
int32_t size_i(T &container) {
  return static_cast<int32_t>(container.size());
}
long long GCD(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long GCD_extended(long long a, long long b, long long &x, long long &y) {
  x = 1, y = 0;
  long long x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    long long q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
long long LCM(long long a, long long b) { return (a * b) / GCD(a, b); }
long long modpow(ll x, long long n, long long m = MOD) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
    n >>= 1;
  }
  return res;
}
long long modinv(long long x, long long m = MOD) { return modpow(x, m - 2, m); }
mt19937 rng;
long long getRandomNumber(long long l, long long r) {
  uniform_int_distribution<long long> dist(l, r);
  return dist(rng);
}
void preSolve() {
  rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
}
void solve(long long tc) {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0 && m % 2 == 0 && k % 2 == 0) return void(print("YES"));
  if (n % 2 == 1) {
    if (k % 2 == 1 && k >= m / 2)
      print("YES");
    else
      print("NO");
    return;
  }
  if (n % 2 == 0 && m % 2) {
    if (k % 2 == 0 && k * 2 <= n * (m - 1))
      print("YES");
    else
      print("NO");
    return;
  }
  print("NO");
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  preSolve();
  long long tests = 1;
  cin >> tests;
  for (long long t = 1; t <= tests; t++) solve(t);
  return 0;
}
