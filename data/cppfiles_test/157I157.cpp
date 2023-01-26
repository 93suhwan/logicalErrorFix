#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline namespace {
template <typename B, typename E>
inline B bin_pow(const B &b, const E &e) {
  assert(e >= 0);
  B res = 1;
  B a = b;
  for (E q = e; q; q >>= 1) {
    if (q & 1) res *= a;
    a *= a;
  }
  return res;
}
template <typename T>
inline T modulo(const T &val, const T &mod) {
  T res = -mod <= val && val < mod ? val : val % mod;
  if (res < 0) res += mod;
  return res;
}
template <typename T = int, T MOD = (T)1000000007>
class mod_int {
  T v;

 public:
  inline static const T mod = MOD;
  mod_int(const T &_v = 0) : v(modulo(_v, mod)) {}
  template <typename U>
  explicit operator U() const {
    return (U)get();
  }
  bool operator==(const mod_int &mi) const { return v == mi.v; }
  bool operator!=(const mod_int &mi) const { return v != mi.v; }
  bool operator<(const mod_int &mi) const { return v < mi.v; }
  bool operator>(const mod_int &mi) const { return v > mi.v; }
  mod_int operator+() const { return *this; }
  mod_int operator-() const { return mod_int(-v); }
  mod_int &operator++() {
    if ((v += 1) == mod) v = 0;
    return *this;
  }
  mod_int &operator--() {
    if ((v -= 1) == -1) v = mod - 1;
    return *this;
  }
  mod_int operator++(int) {
    mod_int _old = *this;
    if ((v += 1) == mod) v = 0;
    return _old;
  }
  mod_int operator--(int) {
    mod_int _old = *this;
    if ((v -= 1) == -1) v = mod - 1;
    return _old;
  }
  mod_int &operator+=(const mod_int &mi) {
    if ((v += mi.v) >= mod) v -= mod;
    return *this;
  }
  mod_int &operator-=(const mod_int &mi) {
    if ((v -= mi.v) < 0) v += mod;
    return *this;
  }
  mod_int &operator*=(const mod_int &mi) {
    v = (v * mi.v) % mod;
    return *this;
  }
  mod_int &operator/=(const mod_int &mi) { return *this *= mi.inv(); }
  mod_int &operator+=(const T &_v) {
    v = modulo(v += _v, mod);
    return *this;
  }
  mod_int &operator-=(const T &_v) {
    v = modulo(v -= _v, mod);
    return *this;
  }
  mod_int &operator*=(const T &_v) {
    v = modulo(v *= _v, mod);
    return *this;
  }
  mod_int operator+(const mod_int &mi) const { return mod_int(*this) += mi; }
  mod_int operator-(const mod_int &mi) const { return mod_int(*this) -= mi; }
  mod_int operator*(const mod_int &mi) const { return mod_int(*this) *= mi; }
  mod_int operator/(const mod_int &mi) const { return mod_int(*this) /= mi; }
  mod_int operator+(const T &_v) const { return mod_int(*this) += _v; }
  mod_int operator-(const T &_v) const { return mod_int(*this) -= _v; }
  mod_int operator*(const T &_v) const { return mod_int(*this) *= _v; }
  mod_int inv() const {
    assert(v != 0);
    return bin_pow(*this, mod - 2);
  }
  T get() const { return v; };
};
template <typename T, int X>
struct factorial {
  explicit factorial() {
    fact[0] = (T)1;
    for (int t = 1; t <= X; t++) fact[t] = fact[t - 1] * t;
  }
  T operator()(const int &k) const { return fact[k]; }

 private:
  array<T, X + 1> fact;
};
}  // namespace
const ll mod = 998244353;
using mint = mod_int<ll, mod>;
factorial<mint, 5000> fac;
mint choose(int n, int k) { return fac(n) / (fac(k) * (fac(n - k))); }
void solve(const int __test__ = -1) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 0) {
    cout << 1 << '\n';
    return;
  }
  mint cnt = 0;
  int l = 0, r = 0;
  int sum = 0;
  while (1) {
    if ((r == n && sum == k) || sum + s[r] - '0' > k) {
      cnt += choose(r - l, k);
      break;
    } else if (r == n)
      break;
    sum += s[r] - '0';
    r++;
  }
  cerr << l << ' ' << r << '\n';
  while (r < n) {
    while (sum == k) {
      sum -= s[l] - '0';
      l++;
    }
    cerr << l << '\n';
    while (1) {
      if ((r == n && sum == k) || sum + s[r] - '0' > k) {
        cerr << l << ' ' << r << '\n';
        cnt += choose(r - l, k) - choose(r - l - 1, k - 1);
        break;
      } else if (r == n)
        break;
      sum += s[r] - '0';
      r++;
    }
  }
  cnt = max(cnt, (mint)1);
  cout << (ll)cnt << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int __T = 1;
  for (int __t = 0; __t < __T; __t++) solve(__t);
  return 0;
}
