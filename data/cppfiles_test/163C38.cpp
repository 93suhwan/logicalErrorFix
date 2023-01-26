#include <bits/stdc++.h>
using namespace std;
template <const int mod, const int modPhi>
struct Mint {
  int v;
  Mint() { v = 0; }
  Mint(int x) {
    v = x % mod;
    if (v < 0) v += mod;
  }
  Mint(long long x) {
    v = x % mod;
    if (v < 0) v += mod;
  }
  friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }
  friend bool operator!=(const Mint &a, const Mint &b) { return a.v != b.v; }
  friend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }
  friend bool operator<=(const Mint &a, const Mint &b) { return a.v <= b.v; }
  friend bool operator>(const Mint &a, const Mint &b) { return a.v > b.v; }
  friend bool operator>=(const Mint &a, const Mint &b) { return a.v >= b.v; }
  Mint &operator+=(const Mint &a) {
    v += a.v;
    if (v >= mod) v -= mod;
    return *this;
  }
  Mint &operator-=(const Mint &a) {
    v -= a.v;
    if (v < 0) v += mod;
    return *this;
  }
  Mint &operator*=(const Mint &a) {
    v = (1LL * v * a.v) % mod;
    return *this;
  }
  Mint operator-() { return Mint(-v); }
  Mint &operator++() { return *this += 1; }
  Mint &operator--() { return *this -= 1; }
  friend Mint operator+(Mint a, const Mint b) { return a += b; }
  friend Mint operator-(Mint a, const Mint b) { return a -= b; }
  friend Mint operator*(Mint a, const Mint b) { return a *= b; }
  friend Mint min(Mint a, Mint b) { return (a < b ? b : a); }
  friend Mint max(Mint a, Mint b) { return (a > b ? a : b); }
  friend Mint pow(Mint a, long long b) {
    Mint res = 1;
    while (b > 0) {
      if (b & 1) {
        res *= a;
      }
      a *= a, b >>= 1;
    }
    return res;
  }
  friend Mint inv(const Mint &a) { return pow(a, modPhi - 1); }
  Mint operator/=(const Mint &a) {
    *this *= inv(a);
    return *this;
  }
  friend Mint operator/(Mint a, const Mint b) { return a /= b; }
  friend istream &operator>>(istream &in, Mint &a) { return in >> a.v; }
  friend ostream &operator<<(ostream &out, Mint a) { return out << a.v; }
};
const int mod = 1e9 + 7;
using mint = Mint<mod, mod - 1>;
mint k;
mint pp = 1;
int moves = 0;
void move(int &x, int &del, int b) {
  if (x == b) del = -1;
  if (x == 1) del = 1;
  x += del;
}
int move1(int x, int del, int b) {
  if (x == b) del = -1;
  if (x == 1) del = 1;
  x += del;
  return x;
}
void testCase() {
  int n, m, rb, cb, rd, cd;
  mint p;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  cin >> p;
  p /= mint(100);
  int delr = 1, delc = 1;
  if (rb == rd || cb == cd)
    k += mint(pp) * mint(p) * mint(moves), pp *= (1 - p);
  moves++;
  int initr = rb;
  int initc = cb;
  move(rb, delr, n);
  move(cb, delc, m);
  int initr1 = rb;
  int initc1 = cb;
  while (true) {
    if (rb == rd || cb == cd)
      k += mint(pp) * mint(p) * mint(moves), pp *= (1 - p);
    moves++;
    move(rb, delr, n);
    move(cb, delc, m);
    if (rb == initr && cb == initc && move1(rb, delr, n) == initr1 &&
        move1(cb, delc, m) == initc1)
      break;
  }
  mint ans = mint(k + moves * pp) / mint(1 - pp);
  cout << ans << "\n";
  moves = 0;
  pp = 1;
  k = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
  return 0;
}
