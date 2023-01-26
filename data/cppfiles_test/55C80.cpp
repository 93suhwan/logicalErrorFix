#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
struct mhash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  uint64_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
struct phash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  template <class T1, class T2>
  uint64_t operator()(const std::pair<T1, T2>& p) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    static const uint64_t FIXED_RANDOM1 =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(p.first + FIXED_RANDOM) ^
           splitmix64(p.second + FIXED_RANDOM);
  }
};
using ll = long long;
using ul = unsigned long long;
using ld = long double;
const ld PI = 3.141592653589793;
const ld eps = 1e-8;
const int md = 1e9 + 7;
const int inf = (1 << 30);
const ll linf = (1ll << 60);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << p.first << ' ' << p.second;
  return os;
}
inline int add(const int& a, const int& b) {
  return a + b >= md ? a + b - md : a + b;
}
inline int sub(const int& a, const int& b) {
  return a - b < 0 ? a - b + md : a - b;
}
inline int mul(const int& a, const int& b) { return (1ll * a * b) % md; }
void init() {}
ll bp(ll a, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = mul(a, res);
    n >>= 1;
    a = mul(a, a);
  }
  return res;
}
void solve_one() {
  ll n;
  cin >> n;
  ll res = 6;
  ll cur = 2;
  for (int i = (0); i < (n - 1); ++i) {
    res = mul(res, bp(4, cur));
    cur <<= 1;
  }
  cout << res << "\n";
}
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  auto t = 1;
  cout << setprecision(15);
  init();
  for (int C = (1); C < (t + 1); ++C) {
    solve_one();
  }
}
