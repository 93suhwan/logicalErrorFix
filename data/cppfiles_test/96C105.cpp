#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<long double>;
using vvd = vector<vd>;
using vs = vector<string>;
using pii = pair<long long, long long>;
using pdd = pair<long double, long double>;
using vpii = vector<pii>;
using vpdd = vector<pdd>;
template <long long MOD>
class Modular {
 public:
  Modular(long long v = 0) {
    value = v % MOD;
    if (value < 0) value += MOD;
  }
  Modular(long long a, long long b) : value(0) {
    *this += a;
    *this /= b;
  }
  Modular& operator+=(Modular const& b) {
    value += b.value;
    if (value >= MOD) value -= MOD;
    return *this;
  }
  Modular& operator-=(Modular const& b) {
    value -= b.value;
    if (value < 0) value += MOD;
    return *this;
  }
  Modular& operator*=(Modular const& b) {
    value = (long long)value * b.value % MOD;
    return *this;
  }
  friend Modular power(Modular a, long long e) {
    Modular res = 1;
    while (e) {
      if (e & 1) res *= a;
      a *= a;
      e >>= 1;
    }
    return res;
  }
  friend Modular inverse(Modular a) { return power(a, MOD - 2); }
  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {
    return os << a.value;
  }
  friend istream& operator>>(istream& in, Modular& c) {
    in >> c.value;
    return in;
  }
  friend bool operator==(Modular const& a, Modular const& b) {
    return a.value == b.value;
  }
  friend bool operator!=(Modular const& a, Modular const& b) {
    return a.value != b.value;
  }
  long long value;
  static const long long MOD_value = MOD;
};
using mdint = Modular<(long long)998244353>;
const long long maxn = 505;
mdint C[maxn + 1][maxn + 1];
mdint pw(mdint a, long long b) {
  mdint ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a, b /= 2;
  }
  return ans;
}
long long memo[505][505];
mdint dp(long long n, long long x) {
  if (x <= 0) return 0;
  if (n == 1) return 0;
  if (x < n) return pw(x, n);
  if (n == 0) return 1;
  if (memo[n][x] != -1) return memo[n][x];
  mdint ans = 0;
  for (long long i = 0; i <= n; i++) {
    ans += pw(n - 1, i) * C[n][i] * dp(n - i, x - n + 1);
  }
  return memo[n][x] = ans.value;
}
void solve() {
  long long n, x;
  cin >> n >> x;
  memset(memo, -1, sizeof memo);
  cout << dp(n, x) << '\n';
}
void preprocessing() {
  C[0][0] = 1;
  for (long long n = 1; n <= maxn; ++n) {
    C[n][0] = C[n][n] = 1;
    for (long long k = 1; k < n; ++k) C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
  }
}
bool MULTI_TEST_CASES = 0;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20);
  cout << fixed;
  preprocessing();
  long long t = 1;
  if (MULTI_TEST_CASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
