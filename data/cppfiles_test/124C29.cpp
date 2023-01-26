#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
const long long Mod = 1000000007, Mod2 = 998244353;
const long long MOD = Mod;
template <long long mod>
struct Modint {
  long long val;
  Modint(long long _val = 0) {
    val = _val % mod;
    if (val < 0) val += mod;
  }
  Modint operator+(const Modint& o) const {
    Modint res;
    res.val = val + o.val;
    if (res.val >= mod) res.val -= mod;
    return res;
  }
  Modint operator+(const long long& o) const { return Modint(val + o); }
  Modint operator-() const {
    Modint res;
    res.val = -val;
    if (res.val < 0) res.val += mod;
    return res;
  }
  Modint operator-(const Modint& o) const {
    Modint res;
    res.val = val - o.val;
    if (res.val < 0) res.val += mod;
    return res;
  }
  Modint operator-(const long long& o) const { return Modint(val - o); }
  Modint operator*(const Modint& o) const { return Modint(val * o.val); }
  Modint operator*(const long long& o) const { return Modint(val * (o % mod)); }
  Modint operator+=(const Modint& o) {
    *this = (*this) + o;
    return *this;
  }
  Modint operator-=(const Modint& o) {
    *this = (*this) - o;
    return *this;
  }
  Modint operator*=(const Modint& o) {
    *this = (*this) * o;
    return *this;
  }
  Modint Pow(long long b) const {
    Modint tmp(val), ret(1);
    while (b) {
      if (b & 1) ret *= tmp;
      b >>= 1;
      tmp *= tmp;
    }
    return ret;
  }
  Modint Pow(const Modint& a, long long b) const { return a.Pow(b); }
  inline Modint inv() const { return (*this).Pow(mod - 2); }
  Modint operator/(const Modint& o) const { return *this * o.inv(); }
  Modint operator/(const long long& o) const { return *this * Modint(o).inv(); }
  bool operator==(const Modint& o) const { return val == o.val; }
};
template <long long mod>
ostream& operator<<(ostream& o, Modint<mod> x) {
  return o << x.val;
}
template <long long mod>
Modint<mod> operator+(const long long& x, const Modint<mod>& y) {
  return Modint<mod>(x + y.val);
}
template <long long mod>
Modint<mod> operator-(const long long& x, const Modint<mod>& y) {
  return Modint<mod>(x - y.val);
}
template <long long mod>
Modint<mod> operator*(const long long& x, const Modint<mod>& y) {
  return Modint<mod>(x % mod * y.val);
}
vector<Modint<MOD> > inv, fac, invfac;
void init_comb(long long N) {
  inv.resize(N), fac.resize(N), invfac.resize(N);
  inv[1] = 1, fac[0] = 1, invfac[0] = 1;
  for (long long i = (2); i < ((long long)(N)); i++)
    inv[i] = inv[MOD % i] * (MOD - MOD / i);
  for (long long i = (1); i < ((long long)(N)); i++) fac[i] = fac[i - 1] * i;
  for (long long i = (1); i < ((long long)(N)); i++)
    invfac[i] = invfac[i - 1] * inv[i];
}
inline Modint<MOD> C(long long n, long long m) {
  return m > n || m < 0 ? Modint<MOD>(0) : fac[n] * invfac[m] * invfac[n - m];
}
const long long maxn = 2005, maxm = 10000005, maxk = 7777714;
long long n, pre[2][3][maxn], suf[2][3][maxn];
string str[2];
Modint<MOD> res;
void orzck() {
  init_comb(2 * maxn);
  cin >> n >> str[0] >> str[1];
  for (long long _ = (0); _ < ((long long)(2)); _++)
    for (long long i = (0); i < ((long long)(n)); i++)
      if ((i & 1) && str[_][i] != '?') str[_][i] ^= 1;
  for (long long _ = (0); _ < ((long long)(2)); _++)
    for (long long i = (0); i < ((long long)(3)); i++)
      pre[_][i][0] = suf[_][i][n] = 0;
  for (long long _ = (0); _ < ((long long)(2)); _++)
    for (long long i = (0); i < ((long long)(n)); i++) {
      pre[_][0][i + 1] = pre[_][0][i] + (str[_][i] == '0');
      pre[_][1][i + 1] = pre[_][1][i] + (str[_][i] == '1');
      pre[_][2][i + 1] = pre[_][2][i] + (str[_][i] == '?');
      suf[_][0][n - 1 - i] = suf[_][0][n - i] + (str[_][n - 1 - i] == '0');
      suf[_][1][n - 1 - i] = suf[_][1][n - i] + (str[_][n - 1 - i] == '1');
      suf[_][2][n - 1 - i] = suf[_][2][n - i] + (str[_][n - 1 - i] == '?');
    }
  res = 0;
  for (long long i = (0); i < ((long long)(n)); i++)
    for (long long j = (0); j < ((long long)(n)); j++)
      if (str[0][i] != '0' && str[1][j] != '0') {
        res += abs(i - j) *
               C(pre[0][2][i] + pre[1][2][j], j - pre[0][1][i] - pre[1][0][j]) *
               C(suf[0][2][i + 1] + suf[1][2][j + 1],
                 n - 1 - j - suf[0][1][i + 1] - suf[1][0][j + 1]);
      }
  print(res);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(15);
  long long t;
  cin >> t;
  while (t--) orzck();
  return 0;
}
