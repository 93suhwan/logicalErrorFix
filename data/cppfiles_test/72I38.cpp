#include <bits/stdc++.h>
using namespace std;
template <int MOD>
class ModInt {
 public:
  int v;
  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD;
  }
  friend bool operator==(const ModInt &a, const ModInt &b) {
    return a.v == b.v;
  }
  friend bool operator!=(const ModInt &a, const ModInt &b) {
    return a.v != b.v;
  }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) {
    return a.v <= b.v;
  }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) {
    return a.v >= b.v;
  }
  ModInt &operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &a) { return (*this) *= inverse(a); }
  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1;
    assert(x >= 0);
    for (; x; x /= 2, a *= a)
      if (x & 1) res *= a;
    return res;
  }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }
  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }
  friend istream &operator>>(istream &is, ModInt &v) {
    is >> v.v;
    return is;
  }
  friend ostream &operator<<(ostream &os, const ModInt &v) {
    os << v.v;
    return os;
  }
};
const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;
using lint = long long;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  lint DEBUG = 0;
  lint anslox = 20, ansloy = 30, anshix = 74, anshiy = 84;
  const lint MAX = 1e9;
  const auto Query = [&](lint x, lint y) {
    y = max(y, 1ll);
    y = min(y, MAX);
    x = max(x, 1ll);
    x = min(x, MAX);
    cout << "? " << x << ' ' << y << endl;
    lint res;
    if (!DEBUG) {
      cin >> res;
    } else {
      res = 1e18;
      for (lint i = anslox; i <= anshix; i++) {
        for (lint j = ansloy; j <= anshiy; j++) {
          res = min(res, abs(x - i) + abs(y - j));
        }
      }
    }
    return res;
  };
  vector<lint> corner;
  corner.emplace_back(Query(1, 1));
  corner.emplace_back(Query(MAX, 1));
  corner.emplace_back(Query(MAX, MAX));
  corner.emplace_back(Query(1, MAX));
  lint loy = Query((MAX - 1 - corner[1] + corner[0]) / 2, 1) + 1;
  lint hix =
      MAX - Query(MAX, (MAX + MAX - corner[2] - MAX + 1 + corner[1]) / 2);
  lint hiy =
      MAX - Query((MAX + MAX - corner[2] - MAX + 1 + corner[3]) / 2, MAX);
  lint lox = Query(1, (corner[0] + MAX - 1 - corner[3]) / 2) + 1;
  cout << "! " << lox << ' ' << loy << ' ' << hix << ' ' << hiy << endl;
  return 0;
}
