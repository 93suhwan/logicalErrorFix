#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]\n"; }
template <typename T, typename... Args>
void DBG(T first, Args... args) {
  cerr << first;
  if (sizeof...(args)) cerr << ", ";
  DBG(args...);
}
long long inv(long long a, long long m) {
  a %= m;
  assert(a);
  return a == 1 ? 1 : (int64_t)(m - (int64_t)(inv(m, a)) * (int64_t)(m) / a);
}
template <long long MOD_>
struct Mint {
  static constexpr long long Mod = MOD_;
  long long value;
  Mint() : value(0) {}
  Mint(int64_t v_) : value((int64_t)(v_ % Mod)) {
    if (value < 0) value += Mod;
  }
  const Mint &operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  Mint inverse() const {
    Mint res;
    res.value = inv(value, Mod);
    return res;
  }
  friend std::istream &operator>>(std::istream &input, Mint &other) {
    input >> other.value;
    return input;
  }
  friend std::ostream &operator<<(std::ostream &out, const Mint &other) {
    out << other.value;
    return out;
  }
  Mint operator-() const { return Mint(-value); }
  Mint operator+() const { return Mint(*this); }
  Mint &operator++() {
    value++;
    if (value == Mod) value = 0;
    return *this;
  }
  Mint &operator--() {
    if (value == 0) value = Mod;
    value--;
    return *this;
  }
  Mint &operator+=(const Mint &o) {
    value = value + o.value;
    if (value >= Mod) value -= Mod;
    return *this;
  }
  Mint &operator-=(const Mint &o) {
    value = value - o.value;
    if (value < 0) value += Mod;
    return *this;
  }
  Mint &operator*=(const Mint &o) {
    value = (int64_t)((int64_t)(value) * (int64_t)(o.value) % Mod);
    return *this;
  }
  Mint &operator/=(const Mint &o) { return *this *= o.inverse(); }
  friend Mint operator++(Mint &a, int32_t) {
    Mint r = a;
    ++a;
    return r;
  }
  friend Mint operator--(Mint &a, int32_t) {
    Mint r = a;
    --a;
    return r;
  }
  friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
  friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
  friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
  friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
  friend bool operator==(const Mint &a, const Mint &b) {
    return a.value == b.value;
  }
  friend bool operator!=(const Mint &a, const Mint &b) {
    return a.value != b.value;
  }
  friend bool operator<(const Mint &a, const Mint &b) {
    return a.value < b.value;
  }
  friend bool operator>(const Mint &a, const Mint &b) {
    return a.value > b.value;
  }
  friend bool operator<=(const Mint &a, const Mint &b) {
    return a.value <= b.value;
  }
  friend bool operator>=(const Mint &a, const Mint &b) {
    return a.value >= b.value;
  }
};
using mint = Mint<998244353>;
template <typename T, typename U>
mint power(T a, U b) {
  mint res = 1, x = a;
  while (b > 0) {
    if (b & 1) res *= x;
    x = (x * x);
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n, x;
  cin >> n >> x;
  vector<vector<mint>> dp(n + 1, vector<mint>(x + 1));
  mint C[n + 1][n + 1];
  mint P[x + 1][n + 1];
  for (long long i = 0; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    for (long long j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  for (long long i = 0; i <= x; i++) {
    P[i][0] = 1;
    for (long long j = 1; j <= n; j++) {
      P[i][j] = P[i][j - 1] * i;
    }
  }
  dp[n][0] = 1;
  for (long long i = n; i >= 1; i--) {
    for (long long j = 0; j <= x; j++) {
      long long newDamage = min(x, i - 1 + j);
      for (long long k = i; k >= 0; k--) {
        dp[k][newDamage] += dp[i][j] * C[i][k] * P[newDamage - j][i - k];
      }
    }
  }
  mint ans = 0;
  for (long long i = 0; i <= x; i++) {
    ans += dp[0][i];
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  for (long long tt = 1; tt <= t; tt++) {
    solve();
  }
}
