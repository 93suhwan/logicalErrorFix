#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;
#define fst first
#define snd second

void prec() {}

using UINT = unsigned long long;
using ull = unsigned long long;
template <UINT MD>
struct ModInt {
  using M = ModInt;
  static constexpr UINT get_mod() { return MD; }
  const static M G;
  UINT v;
  ModInt(ll _v = 0) { set_v(UINT(_v % MD + MD)); }
  M &set_v(UINT _v) {
    v = (_v < MD) ? _v : _v - MD;
    return *this;
  }
  explicit operator bool() const { return v != 0; }
  M operator-() const { return M() - *this; }
  M operator+(const M &r) const { return M().set_v(v + r.v); }
  M operator-(const M &r) const { return M().set_v(v + MD - r.v); }
  M operator*(const M &r) const { return M().set_v(UINT(ull(v) * r.v % MD)); }
  M operator/(const M &r) const { return *this * r.inv(); }
  M &operator+=(const M &r) { return *this = *this + r; }
  M &operator-=(const M &r) { return *this = *this - r; }
  M &operator*=(const M &r) { return *this = *this * r; }
  M &operator/=(const M &r) { return *this = *this / r; }
  bool operator==(const M &r) const { return v == r.v; }
  M pow(ll n) const {
    M x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  M inv() const { return pow(MD - 2); }
  friend ostream &operator<<(ostream &os, const M &r) { return os << r.v; }
};
using Mint = ModInt<1000'000'007>;

using PLL = pair<ll, ll>;
PLL combine(PLL a, PLL b) { return {max(a.fst, b.fst), min(a.snd, b.snd)}; }

ll len(PLL a) { return max(0ll, a.snd - a.fst + 1); }

void solve() {
  ll n, m, k, r, c, ax, ay, bx, by;
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;

  PLL xs = combine({ax, ax + r - 1}, {bx, bx + r - 1});
  PLL ys = combine({ay, ay + c - 1}, {by, by + c - 1});
  ll common = len(xs) * len(ys);
  ll extra = r * c - common;
  ll rest = n * m - 2 * extra - common;

  Mint ans = Mint(k).pow(rest + extra);
  cout << ans << '\n';
}

#ifdef LOCAL_EXEC
#define TEST_CASES
#endif
// #define PRINT_CASE_NUMBERS

/*----- TEMPLATE ----------------------------------------------------------*/
int main(int argc, char *argv[]) {
#ifdef LOCAL_EXEC
  if (!(argc == 2 && string(argv[1]) == "-c")) {
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);
  }
#else
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#endif

  prec();

  int t = 1;
#ifdef TEST_CASES
  cin >> t;
#endif
  for (int it = 1; it <= t; it++) {
#ifdef PRINT_CASE_NUMBERS
    cout << "Case #" << it << ": ";
#endif
    solve();
  }

  return 0;
}
