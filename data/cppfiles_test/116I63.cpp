#include <bits/stdc++.h>
using namespace std;
long double pi = 3.141592653589793238462643383279;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 3e5 + 9, mod = 998244353;
struct base {
  long double x, y;
  base() { x = y = 0; }
  base(long double x, long double y) : x(x), y(y) {}
};
inline base operator+(base a, base b) { return base(a.x + b.x, a.y + b.y); }
inline base operator-(base a, base b) { return base(a.x - b.x, a.y - b.y); }
inline base operator*(base a, base b) {
  return base(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
inline base conj(base a) { return base(a.x, -a.y); }
int lim = 1;
vector<base> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};
const long double PI = acosl(-1.0);
void ensure_base(int p) {
  if (p <= lim) return;
  rev.resize(1 << p);
  for (int i = 0; i < (1 << p); i++)
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (p - 1));
  roots.resize(1 << p);
  while (lim < p) {
    long double angle = 2 * PI / (1 << (lim + 1));
    for (int i = 1 << (lim - 1); i < (1 << lim); i++) {
      roots[i << 1] = roots[i];
      long double angle_i = angle * (2 * i + 1 - (1 << lim));
      roots[(i << 1) + 1] = base(cos(angle_i), sin(angle_i));
    }
    lim++;
  }
}
void fft(vector<base> &a, int n = -1) {
  if (n == -1) n = a.size();
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = lim - zeros;
  for (int i = 0; i < n; i++)
    if (i < (rev[i] >> shift)) swap(a[i], a[rev[i] >> shift]);
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        base z = a[i + j + k] * roots[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}
vector<int> multiply(vector<int> &a, vector<int> &b, int eq = 0) {
  int need = a.size() + b.size() - 1;
  int p = 0;
  while ((1 << p) < need) p++;
  ensure_base(p);
  int sz = 1 << p;
  vector<base> A, B;
  if (sz > (int)A.size()) A.resize(sz);
  for (int i = 0; i < (int)a.size(); i++) {
    int x = (a[i] % mod + mod) % mod;
    A[i] = base(x & ((1 << 15) - 1), x >> 15);
  }
  fill(A.begin() + a.size(), A.begin() + sz, base{0, 0});
  fft(A, sz);
  if (sz > (int)B.size()) B.resize(sz);
  if (eq)
    copy(A.begin(), A.begin() + sz, B.begin());
  else {
    for (int i = 0; i < (int)b.size(); i++) {
      int x = (b[i] % mod + mod) % mod;
      B[i] = base(x & ((1 << 15) - 1), x >> 15);
    }
    fill(B.begin() + b.size(), B.begin() + sz, base{0, 0});
    fft(B, sz);
  }
  long double ratio = 0.25 / sz;
  base r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    base a1 = (A[i] + conj(A[j])), a2 = (A[i] - conj(A[j])) * r2;
    base b1 = (B[i] + conj(B[j])) * r3, b2 = (B[i] - conj(B[j])) * r4;
    if (i != j) {
      base c1 = (A[j] + conj(A[i])), c2 = (A[j] - conj(A[i])) * r2;
      base d1 = (B[j] + conj(B[i])) * r3, d2 = (B[j] - conj(B[i])) * r4;
      A[i] = c1 * d1 + c2 * d2 * r5;
      B[i] = c1 * d2 + c2 * d1;
    }
    A[j] = a1 * b1 + a2 * b2 * r5;
    B[j] = a1 * b2 + a2 * b1;
  }
  fft(A, sz);
  fft(B, sz);
  vector<int> res(need);
  for (int i = 0; i < need; i++) {
    long long aa = A[i].x + 0.5;
    long long bb = B[i].x + 0.5;
    long long cc = A[i].y + 0.5;
    res[i] = (aa + ((bb % mod) << 15) + ((cc % mod) << 30)) % mod;
  }
  return res;
}
template <int32_t MOD>
struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  inline modint<MOD> operator+(modint<MOD> other) const {
    int32_t c = this->value + other.value;
    return modint<MOD>(c >= MOD ? c - MOD : c);
  }
  inline modint<MOD> operator-(modint<MOD> other) const {
    int32_t c = this->value - other.value;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> operator*(modint<MOD> other) const {
    int32_t c = (int64_t)this->value * other.value % MOD;
    return modint<MOD>(c < 0 ? c + MOD : c);
  }
  inline modint<MOD> &operator+=(modint<MOD> other) {
    this->value += other.value;
    if (this->value >= MOD) this->value -= MOD;
    return *this;
  }
  inline modint<MOD> &operator-=(modint<MOD> other) {
    this->value -= other.value;
    if (this->value < 0) this->value += MOD;
    return *this;
  }
  inline modint<MOD> &operator*=(modint<MOD> other) {
    this->value = (int64_t)this->value * other.value % MOD;
    if (this->value < 0) this->value += MOD;
    return *this;
  }
  inline modint<MOD> operator-() const {
    return modint<MOD>(this->value ? MOD - this->value : 0);
  }
  modint<MOD> pow(uint64_t k) const {
    modint<MOD> x = *this, y = 1;
    for (; k; k >>= 1) {
      if (k & 1) y *= x;
      x *= x;
    }
    return y;
  }
  modint sqrt() const {
    if (value == 0) return 0;
    if (MOD == 2) return 1;
    if (pow((MOD - 1) >> 1) == MOD - 1) return 0;
    unsigned int Q = MOD - 1, M = 0, i;
    modint zQ;
    while (!(Q & 1)) Q >>= 1, M++;
    for (int z = 1;; z++) {
      if (modint(z).pow((MOD - 1) >> 1) == MOD - 1) {
        zQ = modint(z).pow(Q);
        break;
      }
    }
    modint t = pow(Q), R = pow((Q + 1) >> 1), r;
    while (true) {
      if (t == 1) {
        r = R;
        break;
      }
      for (i = 1; modint(t).pow(1 << i) != 1; i++)
        ;
      modint b = modint(zQ).pow(1 << (M - 1 - i));
      M = i, zQ = b * b, t = t * zQ, R = R * b;
    }
    return min(r, -r + MOD);
  }
  modint<MOD> inv() const { return pow(MOD - 2); }
  inline modint<MOD> operator/(modint<MOD> other) const {
    return *this * other.inv();
  }
  inline modint<MOD> operator/=(modint<MOD> other) {
    return *this *= other.inv();
  }
  inline bool operator==(modint<MOD> other) const {
    return value == other.value;
  }
  inline bool operator!=(modint<MOD> other) const {
    return value != other.value;
  }
  inline bool operator<(modint<MOD> other) const { return value < other.value; }
  inline bool operator>(modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n) {
  return modint<MOD>(value) * n;
}
template <int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n) {
  return modint<MOD>(value % MOD) * n;
}
template <int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n) {
  return out << n.value;
}
using mint = modint<mod>;
struct poly {
  vector<mint> a;
  inline void normalize() {
    while ((int)a.size() && a.back() == 0) a.pop_back();
  }
  template <class... Args>
  poly(Args... args) : a(args...) {}
  poly(const initializer_list<mint> &x) : a(x.begin(), x.end()) {}
  int size() const { return (int)a.size(); }
  inline mint coef(const int i) const {
    return (i < a.size() && i >= 0) ? a[i] : mint(0);
  }
  mint operator[](const int i) const {
    return (i < a.size() && i >= 0) ? a[i] : mint(0);
  }
  bool is_zero() const {
    for (int i = 0; i < size(); i++)
      if (a[i] != 0) return 0;
    return 1;
  }
  poly operator+(const poly &x) const {
    int n = max(size(), x.size());
    vector<mint> ans(n);
    for (int i = 0; i < n; i++) ans[i] = coef(i) + x.coef(i);
    while ((int)ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
  poly operator-(const poly &x) const {
    int n = max(size(), x.size());
    vector<mint> ans(n);
    for (int i = 0; i < n; i++) ans[i] = coef(i) - x.coef(i);
    while ((int)ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
  poly operator*(const poly &b) const {
    if (is_zero() || b.is_zero()) return {};
    vector<int> A, B;
    for (auto x : a) A.push_back(x.value);
    for (auto x : b.a) B.push_back(x.value);
    auto res = multiply(A, B, (A == B));
    vector<mint> ans;
    for (auto x : res) ans.push_back(mint(x));
    while ((int)ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
  poly operator*(const mint &x) const {
    int n = size();
    vector<mint> ans(n);
    for (int i = 0; i < n; i++) ans[i] = a[i] * x;
    return ans;
  }
  poly operator/(const mint &x) const { return (*this) * x.inv(); }
  poly &operator+=(const poly &x) { return *this = (*this) + x; }
  poly &operator-=(const poly &x) { return *this = (*this) - x; }
  poly &operator*=(const poly &x) { return *this = (*this) * x; }
  poly &operator*=(const mint &x) { return *this = (*this) * x; }
  poly &operator/=(const mint &x) { return *this = (*this) / x; }
  poly mod_xk(int k) const { return {a.begin(), a.begin() + min(k, size())}; }
  poly mul_xk(int k) const {
    poly ans(*this);
    ans.a.insert(ans.a.begin(), k, 0);
    return ans;
  }
  poly div_xk(int k) const {
    return vector<mint>(a.begin() + min(k, (int)a.size()), a.end());
  }
  poly substr(int l, int r) const {
    l = min(l, size());
    r = min(r, size());
    return vector<mint>(a.begin() + l, a.begin() + r);
  }
  poly reverse_it(int n, bool rev = 0) const {
    poly ans(*this);
    if (rev) {
      ans.a.resize(max(n, (int)ans.a.size()));
    }
    reverse(ans.a.begin(), ans.a.end());
    return ans.mod_xk(n);
  }
  poly differentiate() const {
    int n = size();
    vector<mint> ans(n);
    for (int i = 1; i < size(); i++) ans[i - 1] = coef(i) * i;
    return ans;
  }
  poly integrate() const {
    int n = size();
    vector<mint> ans(n + 1);
    for (int i = 0; i < size(); i++) ans[i + 1] = coef(i) / (i + 1);
    return ans;
  }
  poly inverse(int n) const {
    assert(!is_zero());
    assert(a[0] != 0);
    poly ans{mint(1) / a[0]};
    for (int i = 1; i < n; i *= 2) {
      ans = (ans * mint(2) - ans * ans * mod_xk(2 * i)).mod_xk(2 * i);
    }
    return ans.mod_xk(n);
  }
  pair<poly, poly> divmod_slow(const poly &b) const {
    vector<mint> A(a);
    vector<mint> ans;
    while (A.size() >= b.a.size()) {
      ans.push_back(A.back() / b.a.back());
      if (ans.back() != mint(0)) {
        for (size_t i = 0; i < b.a.size(); i++) {
          A[A.size() - i - 1] -= ans.back() * b.a[b.a.size() - i - 1];
        }
      }
      A.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return {ans, A};
  }
  pair<poly, poly> divmod(const poly &b) const {
    if (size() < b.size()) return {poly{0}, *this};
    int d = size() - b.size();
    if (min(d, b.size()) < 250) return divmod_slow(b);
    poly D = (reverse_it(d + 1) * b.reverse_it(d + 1).inverse(d + 1))
                 .mod_xk(d + 1)
                 .reverse_it(d + 1, 1);
    return {D, *this - (D * b)};
  }
  poly operator/(const poly &t) const { return divmod(t).first; }
  poly operator%(const poly &t) const { return divmod(t).second; }
  poly &operator/=(const poly &t) { return *this = divmod(t).first; }
  poly &operator%=(const poly &t) { return *this = divmod(t).second; }
  poly log(int n) const {
    assert(a[0] == 1);
    return (differentiate().mod_xk(n) * inverse(n)).integrate().mod_xk(n);
  }
  poly exp(int n) const {
    if (is_zero()) return {1};
    assert(a[0] == 0);
    poly ans({1});
    int i = 1;
    while (i < n) {
      poly C = ans.log(2 * i).div_xk(i) - substr(i, 2 * i);
      ans -= (ans * C).mod_xk(i).mul_xk(i);
      i *= 2;
    }
    return ans.mod_xk(n);
  }
  poly pow(int k, int n) const {
    if (is_zero()) return *this;
    poly ans({1}), b = mod_xk(n);
    while (k) {
      if (k & 1) ans = (ans * b).mod_xk(n);
      b = (b * b).mod_xk(n);
      k >>= 1;
    }
    return ans;
  }
  int leading_xk() const {
    if (is_zero()) return 1000000000;
    int res = 0;
    while (a[res] == 0) res++;
    return res;
  }
  poly pow2(int k, int n) const {
    if (is_zero()) return *this;
    int i = leading_xk();
    mint j = a[i];
    poly t = div_xk(i) / j;
    poly ans = (t.log(n) * mint(k)).exp(n);
    if (1LL * i * k > n)
      ans = {0};
    else
      ans = ans.mul_xk(i * k).mod_xk(n);
    ans *= (j.pow(k));
    return ans;
  }
  poly sqrt(int n) const {
    if ((*this)[0] == mint(0)) {
      for (int i = 1; i < size(); i++) {
        if ((*this)[i] != mint(0)) {
          if (i & 1) return {};
          if (n - i / 2 <= 0) break;
          return div_xk(i).sqrt(n - i / 2).mul_xk(i / 2);
        }
      }
      return {};
    }
    mint s = (*this)[0].sqrt();
    if (s == 0) return {};
    poly y = *this / (*this)[0];
    poly ret({1});
    mint inv2 = mint(1) / 2;
    for (int i = 1; i < n; i <<= 1) {
      ret = (ret + y.mod_xk(i << 1) * ret.inverse(i << 1)) * inv2;
    }
    return ret.mod_xk(n) * s;
  }
  poly root(int n, int k = 2) const {
    if (is_zero()) return *this;
    if (k == 1) return mod_xk(n);
    assert(a[0] == 1);
    poly q({1});
    for (int i = 1; i < n; i <<= 1) {
      if (k == 2)
        q += mod_xk(2 * i) * q.inverse(2 * i);
      else
        q = q * mint(k - 1) +
            mod_xk(2 * i) * q.inverse(2 * i).pow(k - 1, 2 * i);
      q = q.mod_xk(2 * i) / mint(k);
    }
    return q.mod_xk(n);
  }
  poly mulx(mint x) {
    mint cur = 1;
    poly ans(*this);
    for (int i = 0; i < size(); i++) ans.a[i] *= cur, cur *= x;
    return ans;
  }
  poly mulx_sq(mint x) {
    mint cur = x, total = 1, xx = x * x;
    poly ans(*this);
    for (int i = 0; i < size(); i++) ans.a[i] *= total, total *= cur, cur *= xx;
    return ans;
  }
  vector<mint> chirpz_even(mint z, int n) {
    int m = size() - 1;
    if (is_zero()) return vector<mint>(n, 0);
    vector<mint> vv(m + n);
    mint iz = z.inv(), zz = iz * iz, cur = iz, total = 1;
    for (int i = 0; i <= max(n - 1, m); i++) {
      if (i <= m) vv[m - i] = total;
      if (i < n) vv[m + i] = total;
      total *= cur;
      cur *= zz;
    }
    poly w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
    vector<mint> ans(n);
    for (int i = 0; i < n; i++) ans[i] = w[i];
    return ans;
  }
  vector<mint> chirpz(mint z, int n) {
    auto even = chirpz_even(z, (n + 1) / 2);
    auto odd = mulx(z).chirpz_even(z, n / 2);
    vector<mint> ans(n);
    for (int i = 0; i < n / 2; i++) {
      ans[2 * i] = even[i];
      ans[2 * i + 1] = odd[i];
    }
    if (n % 2 == 1) ans[n - 1] = even.back();
    return ans;
  }
  poly shift_it(int m, vector<poly> &pw) {
    if (size() <= 1) return *this;
    while (m >= size()) m /= 2;
    poly q(a.begin() + m, a.end());
    return q.shift_it(m, pw) * pw[m] + mod_xk(m).shift_it(m, pw);
  };
  poly shift(mint a) {
    int n = size();
    if (n == 1) return *this;
    vector<poly> pw(n);
    pw[0] = poly({1});
    pw[1] = poly({a, 1});
    int i = 2;
    for (; i < n; i *= 2) pw[i] = pw[i / 2] * pw[i / 2];
    return shift_it(i, pw);
  }
  mint eval(mint x) {
    mint ans(0);
    for (int i = size() - 1; i >= 0; i--) {
      ans *= x;
      ans += a[i];
    }
    return ans;
  }
  poly composition_brute(poly g, int deg) {
    int n = size();
    poly c(deg, 0), pw({1});
    for (int i = 0; i < min(deg, n); i++) {
      int d = min(deg, (int)pw.size());
      for (int j = 0; j < d; j++) {
        c.a[j] += coef(i) * pw[j];
      }
      pw *= g;
      if (pw.size() > deg) pw.a.resize(deg);
    }
    return c;
  }
  poly composition(poly g, int deg) {
    int n = size();
    int k = 1;
    while (k * k <= n) k++;
    k--;
    int d = n / k;
    if (k * d < n) d++;
    vector<poly> pw(k + 3, poly({1}));
    for (int i = 1; i <= k + 2; i++) {
      pw[i] = pw[i - 1] * g;
      if (pw[i].size() > deg) pw[i].a.resize(deg);
    }
    vector<poly> fi(k, poly(deg, 0));
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < d; j++) {
        int idx = i * d + j;
        if (idx >= n) break;
        int sz = min(fi[i].size(), pw[j].size());
        for (int t = 0; t < sz; t++) {
          fi[i].a[t] += pw[j][t] * coef(idx);
        }
      }
    }
    poly ret(deg, 0), gd({1});
    for (int i = 0; i < k; i++) {
      fi[i] = fi[i] * gd;
      int sz = min((int)ret.size(), (int)fi[i].size());
      for (int j = 0; j < sz; j++) ret.a[j] += fi[i][j];
      gd = gd * pw[d];
      if (gd.size() > deg) gd.a.resize(deg);
    }
    return ret;
  }
  poly build(vector<poly> &ans, int v, int l, int r, vector<mint> &vec) {
    if (l == r) return ans[v] = poly({-vec[l], 1});
    int mid = l + r >> 1;
    return ans[v] = build(ans, 2 * v, l, mid, vec) *
                    build(ans, 2 * v + 1, mid + 1, r, vec);
  }
  vector<mint> eval(vector<poly> &tree, int v, int l, int r,
                    vector<mint> &vec) {
    if (l == r) return {eval(vec[l])};
    if (size() < 400) {
      vector<mint> ans(r - l + 1, 0);
      for (int i = l; i <= r; i++) ans[i - l] = eval(vec[i]);
      return ans;
    }
    int mid = l + r >> 1;
    auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, mid, vec);
    auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, mid + 1, r, vec);
    A.insert(A.end(), B.begin(), B.end());
    return A;
  }
  vector<mint> eval(vector<mint> x) {
    int n = x.size();
    if (is_zero()) return vector<mint>(n, mint(0));
    vector<poly> tree(4 * n);
    build(tree, 1, 0, n - 1, x);
    return eval(tree, 1, 0, n - 1, x);
  }
  poly interpolate(vector<poly> &tree, int v, int l, int r, int ly, int ry,
                   vector<mint> &y) {
    if (l == r) return {y[ly] / a[0]};
    int mid = l + r >> 1;
    int midy = ly + ry >> 1;
    auto A =
        (*this % tree[2 * v]).interpolate(tree, 2 * v, l, mid, ly, midy, y);
    auto B = (*this % tree[2 * v + 1])
                 .interpolate(tree, 2 * v + 1, mid + 1, r, midy + 1, ry, y);
    return A * tree[2 * v + 1] + B * tree[2 * v];
  }
};
poly interpolate(vector<mint> x, vector<mint> y) {
  int n = x.size();
  assert(n == (int)y.size());
  vector<poly> tree(4 * n);
  poly tmp({1});
  return tmp.build(tree, 1, 0, n - 1, x)
      .differentiate()
      .interpolate(tree, 1, 0, n - 1, 0, n - 1, y);
}
poly gcd(poly a, poly b) { return b.is_zero() ? a : gcd(b, a % b); }
mint resultant(poly a, poly b) {
  if (b.is_zero() || a.is_zero())
    return 0;
  else if (b.size() == 1)
    return b.a.back().pow((int)a.size() - 1);
  else {
    int pw = (int)a.size() - 1;
    a %= b;
    pw -= (int)a.size() - 1;
    mint mul = b.a.back().pow(pw) *
               mint(((b.size() - 1) & (a.size() - 1) & 1) ? -1 : 1);
    mint ans = resultant(b, a);
    return ans * mul;
  }
}
vector<int> adj[N];
vector<int> act_adj[N];
bool vis[N];
int mark[N];
int dfs(int v) {
  int ans = 1;
  vis[v] = 1;
  int flag = 0;
  if (mark[v] == 2) {
    flag = 1;
  }
  int pika = 0;
  for (int x : adj[v]) {
    if (vis[x]) {
      continue;
    }
    pika = 1;
    int cnt = dfs(x);
    if (cnt == 0) flag = 1;
    ans += cnt;
  }
  if (flag)
    return 0;
  else
    return ans;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int rem[k];
  memset(rem, -1, sizeof(rem));
  vector<int> v[n];
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    vector<int> tmp;
    for (int j = 0; j < c; j++) {
      int x;
      cin >> x;
      tmp.push_back(x);
      rem[x - 1] = 0;
    }
    v[i] = tmp;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < v[i].size(); j++) {
      int x = v[i][j - 1];
      int y = v[i][j];
      if (mark[y] == 1 && !(adj[x].size() == 1 && adj[x][0] == y)) {
        mark[y] = 2;
      }
      if (x == y) {
        mark[x] = 2;
      }
      if (act_adj[x].size() == 1) {
        if (act_adj[x][0] != y) {
          mark[x] = 2;
        }
      } else {
        act_adj[x].push_back(y);
      }
      adj[x].push_back(y);
      adj[y].push_back(x);
      if (mark[x] == 0) mark[x] = 1;
      if (mark[y] == 0) mark[y] = 1;
    }
  }
  vector<int> p(m + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (!vis[v[i][j]]) {
        int cnt = dfs(v[i][j]);
        if (cnt <= m) {
          p[cnt]++;
        }
      }
    }
  }
  p[0] = 0;
  p[1] += (abs(accumulate(rem, rem + k, 0)));
  int idx = -1;
  for (int i = m; i >= 0; i--) {
    if (p[i] >= 1) {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    cout << "0\n";
    return;
  }
  poly a;
  for (int i = 0; i <= idx; i++) {
    int x = p[i];
    a.a.push_back(x);
  }
  poly b = a.pow2(m + 1, m + 1) - a;
  poly c;
  c.a.push_back(1);
  poly d = a - c;
  d = d.inverse(m + 1);
  d = d * b;
  cout << d.a[m];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
}
