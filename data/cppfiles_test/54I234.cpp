#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MONKE = 0;
ll inv_mod(ll a, ll m) {
  ll _m = m, q, t, x, y;
  if (m == 1) return 0;
  for (y = 0, x = 1; a > 1; t = y, y = x - q * y, x = t) {
    q = a / m, t = m;
    m = a % m, a = t;
  }
  return x < 0 ? x + _m : x;
}
class modulo_int {
 public:
  ll val;
  static const ll mod = 1e9 + 7;
  modulo_int(ll _val = 0) { val = _val > 0 ? _val % mod : _val % mod + mod; }
  modulo_int operator+(modulo_int rhs) { return modulo_int((val + rhs.val)); }
  modulo_int operator-(modulo_int rhs) { return modulo_int((val - rhs.val)); }
  modulo_int operator*(modulo_int rhs) { return modulo_int((val * rhs.val)); }
  modulo_int operator/(modulo_int rhs) {
    return modulo_int(binpow(rhs, mod - 2) * val);
  }
  void operator+=(modulo_int rhs) { *this = *this + rhs; }
  void operator-=(modulo_int rhs) { *this = *this - rhs; }
  void operator*=(modulo_int rhs) { *this = *this * rhs; }
  void operator/=(modulo_int rhs) { *this = *this / rhs; }
  friend modulo_int binpow(modulo_int val, ll p) {
    modulo_int ans = 1;
    for (; p > 0; p >>= 1) {
      if (p & 1) ans = ans * val;
      val *= val;
    }
    return ans;
  }
  friend ostream& operator<<(ostream& o, modulo_int& a) {
    o << a.val;
    return o;
  }
  friend istream& operator>>(istream& o, modulo_int& a) {
    o >> a.val;
    return o;
  }
};
void solve() {
  int n, k;
  cin >> n >> k;
  vector<modulo_int> DP(k + 1);
  DP[0] = 1;
  modulo_int two = 2;
  modulo_int ways = binpow(two, n - 1);
  for (int i = 1; i <= k; i++) {
    if (n & 1)
      DP[i] = DP[i - 1] * (ways + 1);
    else
      DP[i] = DP[i - 1] * (ways - 1) + binpow(two, i - 1);
  }
  cout << DP[k] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
  return MONKE;
}
