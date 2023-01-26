#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using P = pair<ll, ll>;
using vvc = vector<vc>;
using vd = vector<double>;
using vp = vector<P>;
using vb = vector<bool>;
const ll inf = 2e18;
const ll MOD = 1000000007;
const ll mod = 998244353;
const double pi = acos(-1);
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in : v) {
    is >> in;
  }
  return is;
}
void scan() {}
template <class Head, class... Tail>
void scan(Head &head, Tail &...tail) {
  cin >> head;
  scan(tail...);
}
template <class T>
void print(const T &t) {
  cout << t << '\n';
}
template <class Head, class... Tail>
void print(const Head &head, const Tail &...tail) {
  cout << head << ' ';
  print(tail...);
}
template <class... T>
void fin(const T &...a) {
  print(a...);
  exit(0);
}
template <typename T>
T sum_(vector<T> a) {
  return accumulate(begin(a), end(a), T(0));
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}
template <long long m>
struct modint {
  long long x;
  modint() : x(0) {}
  modint(long long y) : x(y >= 0 ? y % m : (m - (-y) % m) % m) {}
  modint inv() const {
    long long a = x, b = m, u = 1, v = 0, t;
    while (b) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return modint(u);
  }
  modint &operator+=(const modint &p) {
    if ((x += p.x) >= m) x -= m;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((x += m - p.x) >= m) x -= m;
    return *this;
  }
  modint &operator*=(const modint &p) {
    x = x * p.x % m;
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inv();
    return *this;
  }
  modint operator-() const { return modint(-x); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return x == p.x; }
  bool operator!=(const modint &p) const { return x != p.x; }
  modint pow(long long n) const {
    modint ret(1), mul(x);
    while (n) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const modint &p) { return os << p.x; }
  friend istream &operator>>(istream &is, modint &a) {
    long long t;
    is >> t;
    a = modint<m>(t);
    return (is);
  }
  static long long get_mod() { return m; }
};
using mint = modint<MOD>;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  ll times = 1;
  cin >> times;
  while (times--) {
    solve();
  }
}
void solve() {
  int n, m, sx, sy, gx, gy;
  cin >> n >> m >> sx >> sy >> gx >> gy;
  sx--, sy--, gx--, gy--;
  mint p;
  cin >> p;
  p /= 100;
  vector<bool> v(4 * (n - 1) * (m - 1));
  ll cx = sx, cy = sy, dx = 1, dy = 1;
  for (__typeof(v.size()) i = 0; i < v.size(); i++) {
    if (cx == gx || cy == gy) v[i] = true;
    cx += dx;
    if (cx >= n || cx < 0) dx *= -1, cx += 2 * dx;
    cy += dy;
    if (cy >= m || cy < 0) dy *= -1, cy += 2 * dy;
  }
  vector<pair<mint, mint>> dp(v.size() + 1);
  dp.back() = {1, 0};
  for (__typeof((int)v.size()) i = ((int)v.size()) - 1; i >= 0; i--) {
    if (v[i]) {
      dp[i] = dp[i + 1];
      dp[i].second += 1;
      dp[i].first *= mint(1) - p;
      dp[i].second *= mint(1) - p;
    } else {
      dp[i] = dp[i + 1];
      dp[i].second += 1;
    }
  }
  print(dp[0].second / (mint(1) - dp[0].first));
}
