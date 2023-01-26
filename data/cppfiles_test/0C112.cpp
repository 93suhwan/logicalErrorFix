#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
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
  static const int SAVE_INV = int(1e6) + 5;
  static _m_int save_inv[SAVE_INV];
  static void prepare_inv() {
    for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1) assert(MOD % p != 0);
    save_inv[0] = 0;
    save_inv[1] = 1;
    for (int i = 2; i < SAVE_INV; i++)
      save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
  }
  _m_int inv() const {
    if (save_inv[1] == 0) prepare_inv();
    if (val < SAVE_INV) return save_inv[val];
    _m_int product = 1;
    int v = val;
    while (v >= SAVE_INV) {
      product *= MOD - MOD / v;
      v = MOD % v;
    }
    return product * save_inv[v];
  }
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
template <const int &MOD>
_m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
extern const int MOD = int(1e9) + 7;
using mod_int = _m_int<MOD>;
vector<mod_int> fact(1, 1);
vector<mod_int> inv_fact(1, 1);
mod_int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int)fact.size() < n + 1) {
    fact.push_back(fact.back() * (int)fact.size());
    inv_fact.push_back(fact.back().inv());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
void solve() {
  int N, q;
  cin >> N >> q;
  vector<vector<mod_int>> dp(3 * N + 1, vector<mod_int>(3, 0));
  dp[0][0] = dp[0][1] = dp[0][2] = N;
  for (int i = 1; i < (3 * N + 1); ++i) {
    dp[i][0] = (C(3 * N, i + 1) - 2 * (dp[i - 1][0]) - dp[i - 1][1]) / 3;
    dp[i][1] = dp[i][0] + dp[i - 1][0];
    dp[i][2] = dp[i][1] + dp[i - 1][1];
  }
  for (int i = 0; i < (q); ++i) {
    int x;
    cin >> x;
    printf("%d\n", dp[x][0] + C(3 * N, x));
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  for (int i = 0; i < (t); ++i) solve();
}
