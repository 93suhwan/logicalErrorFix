#include <bits/stdc++.h>
using namespace std;
const long long linf = 4000000000000000000LL;
const long long inf = 1000000007;
void pv(vector<int> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<long long> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<vector<int> > a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
    cout << '\n';
  }
}
void pv(vector<vector<long long> > a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
  }
  cout << '\n';
}
void pv(vector<string> a) {
  for (auto& x : a) cout << x << '\n';
  cout << '\n';
}
void setIO(string second) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
template <int MOD, int RT>
struct mint {
  static const int mod = MOD;
  static constexpr mint rt() { return RT; }
  int v;
  explicit operator int() const { return v; }
  mint() { v = 0; }
  mint(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  mint& operator+=(const mint& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(const mint& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(const mint& m) {
    v = int((long long)v * m.v % MOD);
    return *this;
  }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint power(mint a, long long p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mint inv(const mint& a) {
    assert(a.v != 0);
    return power(a, MOD - 2);
  }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
};
int main() {
  setIO("test1");
  int n, m, k, r, c, ax, ay, bx, by;
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  cout << (int)power((mint<inf, 5>)k, (long long)n * m - (long long)r * c);
}
