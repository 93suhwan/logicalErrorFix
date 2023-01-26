#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
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
const long long MOD = Mod2;
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
const long long maxn = 100005;
long long n, a[maxn], res;
void orzck() {
  cin >> n;
  for (long long i = (0); i < ((long long)(n)); i++) cin >> a[i];
  res = -4000000000000000000;
  for (long long i = (0); i < ((long long)(n - 1)); i++)
    (res = max(res, a[i] * a[i + 1]));
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
