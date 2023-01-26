#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void mine(T1 &x, const T2 &y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void maxe(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &b) {
  for (const auto &k : b) os << k << ' ';
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &b) {
  for (auto &k : b) is >> k;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &b) {
  for (const auto &k : b) os << k << ' ';
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &b) {
  os << b.first << ' ' << b.second;
  return os;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9 + 7;
namespace md {
long long mod(long long n) {
  if (n <= -MOD || n >= MOD) n %= MOD;
  if (n < 0)
    return n + MOD;
  else
    return n;
}
long long add(long long a, long long b) {
  a += b;
  if (a >= MOD) return a - MOD;
  return a;
}
long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) return a + MOD;
  return a;
}
long long mult(long long a, long long b) { return a * b % MOD; }
long long powmod(long long a, long long p) {
  if (p == 0) return 1;
  if (p & 1) return mult(a, powmod(a, p - 1));
  return powmod(mult(a, a), p / 2);
}
long long rev(long long a) { return powmod(a, MOD - 2); }
}  // namespace md
struct M {
  long long x;
  M(long long _x) { x = md::mod(_x); }
  M() { x = 0; }
  M operator+(M y) const { return M(md::add(x, y.x)); }
  M operator-(M y) const { return M(md::sub(x, y.x)); }
  M operator*(M y) const { return md::mult(x, y.x); }
  M operator/(M y) const { return md::mult(x, md::rev(y.x)); }
  M operator+(long long y) { return (*this) + M(y); }
  M operator-(long long y) { return (*this) - M(y); }
  M operator*(long long y) { return (*this) * M(y); }
  M operator/(long long y) { return (*this) / M(y); }
  M operator^(long long y) const { return M(x ^ y); }
  void operator+=(M y) { *this = *this + y; }
  void operator-=(M y) { *this = *this - y; }
  void operator*=(M y) { *this = *this * y; }
  void operator/=(M y) { *this = *this / y; }
  void operator+=(long long y) { *this = *this + y; }
  void operator-=(long long y) { *this = *this - y; }
  void operator*=(long long y) { *this = *this * y; }
  void operator/=(long long y) { *this = *this / y; }
  void operator^=(long long y) { *this = *this ^ y; }
  bool operator==(M y) const { return x == y.x; }
  bool operator<(M y) const { return x < y.x; }
};
M operator*(long long x, const M &y) { return y * x; }
M operator+(long long x, const M &y) { return y + x; }
M operator-(long long x, const M &y) { return M(x) - y; }
M operator/(long long x, const M &y) { return M(x) / y; }
ostream &operator<<(ostream &os, const M &a) {
  os << a.x;
  return os;
}
istream &operator>>(istream &is, M &a) {
  long long x;
  is >> x;
  a = M(x);
  return is;
}
void solve() {
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long lx1, ly1;
  long long lx2, ly2;
  cin >> lx1 >> ly1;
  cin >> lx2 >> ly2;
  long long rx1 = lx1 + r - 1;
  long long ry1 = ly1 + c - 1;
  long long rx2 = lx2 + r - 1;
  long long ry2 = ly2 + c - 1;
  long long lxs = max(lx1, lx2);
  long long rxs = min(rx1, rx2);
  long long lys = max(ly1, ly2);
  long long rys = min(ry1, ry2);
  long long cnt = 0;
  if (rys < lys || rxs < lxs) {
    cnt = n * m - r * c;
  } else {
    long long inter = (rys - lys + 1) * (rxs - lxs + 1);
    if (inter == r * c) {
      cnt = n * m;
    } else {
      cnt = n * m - r * c - r * c + inter;
      cnt += r * c - inter;
    }
  }
  cout << md::powmod(k, cnt) << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
