#include <bits/stdc++.h>
using namespace std;
template <const int &MOD>
struct _m_int {
  int val;
  _m_int(int64_t v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = int(v);
  }
  _m_int(uint64_t v) {
    if (v >= MOD) v %= MOD;
    val = int(v);
  }
  _m_int(int v) : _m_int(int64_t(v)) {}
  _m_int(unsigned v) : _m_int(uint64_t(v)) {}
  static int inv_mod(int a, int m = MOD) {
    int g = m, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + m : x;
  }
  explicit operator int() const { return val; }
  explicit operator unsigned() const { return val; }
  explicit operator int64_t() const { return val; }
  explicit operator uint64_t() const { return val; }
  explicit operator double() const { return val; }
  explicit operator long double() const { return val; }
  _m_int &operator+=(const _m_int &other) {
    val -= MOD - other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  _m_int &operator-=(const _m_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
    return unsigned(x % m);
    unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  _m_int &operator*=(const _m_int &other) {
    val = fast_mod(uint64_t(val) * other.val);
    return *this;
  }
  _m_int &operator/=(const _m_int &other) { return *this *= other.inv(); }
  friend _m_int operator+(const _m_int &a, const _m_int &b) {
    return _m_int(a) += b;
  }
  friend _m_int operator-(const _m_int &a, const _m_int &b) {
    return _m_int(a) -= b;
  }
  friend _m_int operator*(const _m_int &a, const _m_int &b) {
    return _m_int(a) *= b;
  }
  friend _m_int operator/(const _m_int &a, const _m_int &b) {
    return _m_int(a) /= b;
  }
  _m_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  _m_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  _m_int operator++(int) {
    _m_int before = *this;
    ++*this;
    return before;
  }
  _m_int operator--(int) {
    _m_int before = *this;
    --*this;
    return before;
  }
  _m_int operator-() const { return val == 0 ? 0 : MOD - val; }
  friend bool operator==(const _m_int &a, const _m_int &b) {
    return a.val == b.val;
  }
  friend bool operator!=(const _m_int &a, const _m_int &b) {
    return a.val != b.val;
  }
  friend bool operator<(const _m_int &a, const _m_int &b) {
    return a.val < b.val;
  }
  friend bool operator>(const _m_int &a, const _m_int &b) {
    return a.val > b.val;
  }
  friend bool operator<=(const _m_int &a, const _m_int &b) {
    return a.val <= b.val;
  }
  friend bool operator>=(const _m_int &a, const _m_int &b) {
    return a.val >= b.val;
  }
  _m_int inv() const { return inv_mod(val); }
  _m_int pow(int64_t p) const {
    if (p < 0) return inv().pow(-p);
    _m_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      p >>= 1;
      if (p > 0) a *= a;
    }
    return result;
  }
  friend ostream &operator<<(ostream &os, const _m_int &m) {
    return os << m.val;
  }
};
const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  const int MX = 1e5 + 7;
  vector<int> phi(MX);
  vector<vector<int>> div(MX);
  for (int i = 0; i < MX; i++) phi[i] = i;
  for (int i = 2; i < MX; i++) {
    if (phi[i] == i) {
      for (int j = i; j < MX; j += i) phi[j] = (phi[j] / i) * (i - 1);
    }
  }
  for (int i = 1; i < MX; i++)
    for (int j = i; j < MX; j += i) div[j].push_back(i);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> cnt(MX);
  auto f = [&](vector<int> &v) -> mod_int {
    vector<int> used;
    for (auto x : v) {
      for (auto d : div[x]) {
        cnt[d]++;
        used.push_back(d);
      }
    }
    mod_int res = 0;
    for (auto d : used) {
      if (cnt[d] == 0) continue;
      res += mod_int(phi[d]) * cnt[d] * cnt[d];
      cnt[d] = 0;
    }
    return res;
  };
  mod_int ans = 0;
  for (int d = 1; d < MX; d++) {
    vector<int> v;
    for (int i = d; i <= n; i += d) v.push_back(a[i]);
    ans += phi[d] * f(v);
  }
  cout << ans << '\n';
}
