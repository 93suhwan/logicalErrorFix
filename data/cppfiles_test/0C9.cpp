#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  for (int i = 0; i < (int)v.size(); i++) {
    if (i) {
      os << ',';
    }
    os << v[i];
  }
  os << '}';
  return os;
}
ostream &operator<<(ostream &os, const set<int> &se) {
  os << '{';
  int now = 0;
  for (auto x : se) {
    if (now) {
      os << ',';
    }
    os << x;
    now++;
  }
  os << '}';
  return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &...args) {
  cerr << " " << x;
  debugg(args...);
}
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = 1LL << 61;
const int MAX = 3010000;
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
const double pi = acos(-1);
const double eps = 1e-8;
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T>
inline void print(T &a) {
  int sz = a.size();
  for (auto itr = a.begin(); itr != a.end(); itr++) {
    cout << *itr;
    sz--;
    if (sz) cout << " ";
  }
  cout << "\n";
}
template <typename T1, typename T2>
inline void print2(T1 a, T2 b) {
  cout << a << " " << b << "\n";
}
template <typename T1, typename T2, typename T3>
inline void print3(T1 a, T2 b, T3 c) {
  cout << a << " " << b << " " << c << "\n";
}
void mark() {
  cout << "#"
       << "\n";
}
long long pcount(long long x) { return __builtin_popcountll(x); }
const int mod = 1e9 + 7;
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int get_mod() { return mod; }
};
using mint = ModInt<mod>;
vector<mint> fac(MAX), finv(MAX), inv(MAX);
void comInit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (long long i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i;
    inv[i] = (mint)mod - inv[mod % i] * (mod / i);
    finv[i] = finv[i - 1] * inv[i];
  }
}
mint com(long long n, long long k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * finv[k] * finv[n - k];
}
mint f[3030303];
mint g[3] = {3, 3, 1};
mint h[3030303];
void solve() {
  int n, q;
  cin >> n >> q;
  comInit();
  for (int i = 1; i <= n * 3 + 3; i++) f[i] = com(n * 3 + 3, i);
  mint inv = mint(3).inverse();
  for (int i = 0; i <= n * 3; i++) {
    h[i] = f[i + 1] * inv;
    f[i + 2] -= g[1] * h[i];
    f[i + 3] -= h[i];
  }
  while (q--) {
    int x;
    cin >> x;
    cout << h[x] << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
}
