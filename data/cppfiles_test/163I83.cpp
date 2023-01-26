#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvpii = vector<vector<pair<int, int>>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;
template <int mod>
struct Mod {
  long long x;
  Mod() : x(0) {}
  Mod(long long xx) : x(xx) {
    if (abs(x) >= mod) x %= mod;
    if (x < 0) x += mod;
  }
  operator int() const { return x; }
  operator long long() const { return x; }
  Mod operator+(const Mod &a) const {
    Mod n;
    n.x = x + a.x;
    if (n.x >= mod) n.x -= mod;
    return n;
  }
  Mod operator-(const Mod &a) const {
    Mod n;
    n.x = x - a.x;
    if (n.x < 0) n.x += mod;
    return n;
  }
  Mod operator*(const Mod &a) const { return x * a.x; }
  Mod operator+=(const Mod &a) {
    x += a.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  Mod operator-=(const Mod &a) {
    x -= a.x;
    if (x < 0) x += mod;
    return *this;
  }
  Mod operator++() {
    *this += 1;
    return *this;
  }
  Mod operator++(int) {
    Mod temp = *this;
    *this += 1;
    return temp;
  }
  Mod operator--() {
    *this -= 1;
    return *this;
  }
  Mod operator--(int) {
    Mod temp = *this;
    *this -= 1;
    return temp;
  }
  Mod operator*=(const Mod &a) {
    x = (x * a.x) % mod;
    return *this;
  }
  Mod pow(long long b) const {
    Mod ans = 1;
    Mod a = *this;
    while (b > 0) {
      if (b & 1) ans *= a;
      a *= a;
      b /= 2;
    }
    return ans;
  }
  Mod inv() const { return pow(mod - 2); }
  Mod operator/(const Mod &a) const { return (*this) * a.inv(); }
  Mod operator/=(const Mod &a) { return (*this) *= a.inv(); }
  bool operator==(const Mod &o) const { return x == o.x; }
  bool operator!=(const Mod &o) const { return x != o.x; }
  long long operator()() const { return x; }
  template <int _mod>
  friend ostream &operator<<(ostream &os, const Mod<_mod> &num) {
    os << num.x;
    return os;
  }
  template <int _mod>
  friend istream &operator>>(istream &is, Mod<_mod> &num) {
    is >> num.x;
    if (abs(num.x) >= mod) num.x %= mod;
    if (num.x < 0) num.x += mod;
    return is;
  }
};
using base = Mod<1000000007>;
using vbase = vector<base>;
using vvbase = vector<vector<base>>;
base two = 2;
inline void __run_test() {
  int n, m, rb, cb, rd, cd, p;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  rb--;
  cb--;
  rd--;
  cd--;
  int dr = 1;
  int dc = 1;
  bool grid[n][m][2][2];
  memset(grid, 0, sizeof grid);
  int time = 0;
  int washable = 0;
  base res = 0;
  base noclean = base(1) - base(p) / base(100);
  base clean = base(p) / base(100);
  base extra = 1;
  if (rb == rd || cb == cd) extra = 0;
  while (true) {
    int rr = rb + dr;
    int cc = cb + dc;
    if (rr < 0 || rr >= n) dr = -dr;
    if (cc < 0 || cc >= m) dc = -dc;
    rb = rb + dr;
    cb = cb + dc;
    if (grid[rb][cb][(dr + 1) / 2][(dc + 1) / 2]) break;
    grid[rb][cb][(dr + 1) / 2][(dc + 1) / 2] = 1;
    if (rb == rd || cb == cd) {
      res += noclean.pow(washable) * clean * base(time);
      washable++;
    }
    time++;
  }
  base d = res + noclean.pow(washable) * base(time);
  base temp = base(1) - noclean.pow(washable);
  d = d / temp;
  cout << d + extra << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int __tests;
  cin >> __tests;
  while (__tests--) __run_test();
}
