#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T maxs(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T mins(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long MOD = 998244353;
struct mod_int {
  long long val;
  mod_int(long long v = 0) {
    if (v < 0) v = v % MOD + MOD;
    if (v >= MOD) v %= MOD;
    val = v;
  }
  static long long mod_inv(long long a, long long m = MOD) {
    long long g = m, r = a, first = 0, second = 1;
    while (r != 0) {
      long long q = g / r;
      g %= r;
      swap(g, r);
      first -= q * second;
      swap(first, second);
    }
    return first < 0 ? first + m : first;
  }
  explicit operator long long() const { return val; }
  mod_int &operator+=(const mod_int &other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  mod_int &operator-=(const mod_int &other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  static unsigned fast_mod(uint64_t first, unsigned m = MOD) {
    return first % m;
    unsigned x_high = first >> 32, x_low = (unsigned)first;
    unsigned quot, rem;
    asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
    return rem;
  }
  mod_int &operator*=(const mod_int &other) {
    val = fast_mod((uint64_t)val * other.val);
    return *this;
  }
  mod_int &operator/=(const mod_int &other) { return *this *= other.inv(); }
  friend mod_int operator+(const mod_int &a, const mod_int &b) {
    return mod_int(a) += b;
  }
  friend mod_int operator-(const mod_int &a, const mod_int &b) {
    return mod_int(a) -= b;
  }
  friend mod_int operator*(const mod_int &a, const mod_int &b) {
    return mod_int(a) *= b;
  }
  friend mod_int operator/(const mod_int &a, const mod_int &b) {
    return mod_int(a) /= b;
  }
  mod_int &operator++() {
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
  mod_int &operator--() {
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
  mod_int operator++(int32_t) {
    mod_int before = *this;
    ++*this;
    return before;
  }
  mod_int operator--(int32_t) {
    mod_int before = *this;
    --*this;
    return before;
  }
  mod_int operator-() const { return val == 0 ? 0 : MOD - val; }
  bool operator==(const mod_int &other) const { return val == other.val; }
  bool operator!=(const mod_int &other) const { return val != other.val; }
  mod_int inv() const { return mod_inv(val); }
  mod_int pow(long long p) const {
    assert(p >= 0);
    mod_int a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &stream, const mod_int &m) {
    return stream << m.val;
  }
  friend istream &operator>>(istream &stream, mod_int &m) {
    return stream >> m.val;
  }
};
namespace algebra {
const long long inf = 1e9;
const long long magic = 200;
namespace NTT {
vector<mod_int> roots = {0, 1};
vector<long long> bit_reverse;
long long max_size = -1;
mod_int root;
bool is_power_of_two(long long n) { return (n & (n - 1)) == 0; }
long long round_up_power_two(long long n) {
  while (n & (n - 1)) n = (n | (n - 1)) + 1;
  return max(n, 1LL);
}
long long get_length(long long n) {
  assert(is_power_of_two(n));
  return __builtin_ctz(n);
}
void bit_reorder(long long n, vector<mod_int> &values) {
  if ((long long)bit_reverse.size() != n) {
    bit_reverse.assign(n, 0);
    long long length = get_length(n);
    for (long long i = 0; i < n; i++)
      bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
  }
  for (long long i = 0; i < n; i++)
    if (i < bit_reverse[i]) swap(values[i], values[bit_reverse[i]]);
}
void find_root() {
  max_size = 1 << __builtin_ctz(MOD - 1);
  root = 2;
  while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1)) root++;
}
void prepare_roots(long long n) {
  if (max_size < 0) find_root();
  assert(n <= max_size);
  if ((long long)roots.size() >= n) return;
  long long length = get_length(roots.size());
  roots.resize(n);
  while (1 << length < n) {
    mod_int z = root.pow(max_size >> (length + 1));
    for (long long i = 1 << (length - 1); i < 1 << length; i++) {
      roots[2 * i] = roots[i];
      roots[2 * i + 1] = roots[i] * z;
    }
    length++;
  }
}
void fft_iterative(long long N, vector<mod_int> &values) {
  assert(is_power_of_two(N));
  prepare_roots(N);
  bit_reorder(N, values);
  for (long long n = 1; n < N; n *= 2)
    for (long long start = 0; start < N; start += 2 * n)
      for (long long i = 0; i < n; i++) {
        mod_int even = values[start + i];
        mod_int odd = values[start + n + i] * roots[n + i];
        values[start + n + i] = even - odd;
        values[start + i] = even + odd;
      }
}
const long long FFT_CUTOFF = magic;
vector<mod_int> mod_multiply(vector<mod_int> left, vector<mod_int> right) {
  long long n = left.size();
  long long m = right.size();
  if (min(n, m) < FFT_CUTOFF) {
    const uint64_t ULL_BOUND =
        numeric_limits<uint64_t>::max() - (uint64_t)MOD * MOD;
    vector<uint64_t> result(n + m - 1, 0);
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) {
        result[i + j] += (uint64_t)((long long)left[i]) * ((long long)right[j]);
        if (result[i + j] > ULL_BOUND) result[i + j] %= MOD;
      }
    for (uint64_t &first : result)
      if (first >= MOD) first %= MOD;
    return vector<mod_int>(result.begin(), result.end());
  }
  long long N = round_up_power_two(n + m - 1);
  left.resize(N);
  right.resize(N);
  bool equal = left == right;
  fft_iterative(N, left);
  if (equal)
    right = left;
  else
    fft_iterative(N, right);
  mod_int inv_N = mod_int(N).inv();
  for (long long i = 0; i < N; i++) left[i] *= right[i] * inv_N;
  reverse(left.begin() + 1, left.end());
  fft_iterative(N, left);
  left.resize(n + m - 1);
  return left;
}
template <typename T>
void mul(vector<T> &a, const vector<T> &b) {
  a = mod_multiply(a, b);
}
}  // namespace NTT
template <typename T>
struct poly {
  vector<T> a;
  void normalize() {
    while (!a.empty() && a.back() == T(0)) {
      a.pop_back();
    }
  }
  poly() {}
  poly(T a0) : a{a0} { normalize(); }
  poly(vector<T> t) : a(t) { normalize(); }
  poly operator+=(const poly &t) {
    a.resize(max(a.size(), t.a.size()));
    for (size_t i = 0; i < t.a.size(); i++) {
      a[i] += t.a[i];
    }
    normalize();
    return *this;
  }
  poly operator-=(const poly &t) {
    a.resize(max(a.size(), t.a.size()));
    for (size_t i = 0; i < t.a.size(); i++) {
      a[i] -= t.a[i];
    }
    normalize();
    return *this;
  }
  poly operator+(const poly &t) const { return poly(*this) += t; }
  poly operator-(const poly &t) const { return poly(*this) -= t; }
  poly mod_xk(size_t k) const {
    k = min(k, a.size());
    return vector<T>(begin(a), begin(a) + k);
  }
  poly mul_xk(size_t k) const {
    poly res(*this);
    res.a.insert(begin(res.a), k, 0);
    return res;
  }
  poly div_xk(size_t k) const {
    k = min(k, a.size());
    return vector<T>(begin(a) + k, end(a));
  }
  poly substr(size_t l, size_t r) const {
    l = min(l, a.size());
    r = min(r, a.size());
    return vector<T>(begin(a) + l, begin(a) + r);
  }
  poly inv(size_t n) const {
    assert(!is_zero());
    poly ans = a[0].inv();
    size_t a = 1;
    while (a < n) {
      poly C = (ans * mod_xk(2 * a)).substr(a, 2 * a);
      ans -= (ans * C).mod_xk(a).mul_xk(a);
      a *= 2;
    }
    ans.a.resize(n);
    return ans;
  }
  poly sqrt(size_t n) const {
    long long m = a.size();
    poly b = {1};
    size_t s = 1;
    while (s < n) {
      vector<T> first(a.begin(), a.begin() + min(a.size(), b.a.size() << 1));
      b.a.resize(b.a.size() << 1);
      poly c(first);
      c *= b.inv(b.a.size());
      T inv2 = static_cast<T>(1) / static_cast<T>(2);
      for (long long i = b.a.size() >> 1; i < min(c.a.size(), b.a.size());
           i++) {
        b.a[i] = c.a[i] * inv2;
      }
      s *= 2;
    }
    b.a.resize(n);
    return b;
  }
  poly operator*=(const poly &t) {
    NTT::mul(a, t.a);
    normalize();
    return *this;
  }
  poly operator*(const poly &t) const { return poly(*this) *= t; }
  poly reverse(size_t n, bool rev = 0) const {
    poly res(*this);
    if (rev) {
      res.a.resize(max(n, res.a.size()));
    }
    std::reverse(res.a.begin(), res.a.end());
    return res.mod_xk(n);
  }
  pair<poly, poly> divmod_slow(const poly &b) const {
    vector<T> A(a);
    vector<T> res;
    while (A.size() >= b.a.size()) {
      res.push_back(A.back() / b.a.back());
      if (res.back() != T(0)) {
        for (size_t i = 0; i < b.a.size(); i++) {
          A[A.size() - i - 1] -= res.back() * b.a[b.a.size() - i - 1];
        }
      }
      A.pop_back();
    }
    std::reverse(begin(res), end(res));
    return {res, A};
  }
  pair<poly, poly> divmod(const poly &b) const {
    if (deg() < b.deg()) {
      return {poly{0}, *this};
    }
    long long d = deg() - b.deg();
    if (min(d, b.deg()) < magic) {
      return divmod_slow(b);
    }
    poly D = (reverse(d + 1) * b.reverse(d + 1).inv(d + 1))
                 .mod_xk(d + 1)
                 .reverse(d + 1, 1);
    return {D, *this - D * b};
  }
  poly operator/(const poly &t) const { return divmod(t).first; }
  poly operator%(const poly &t) const { return divmod(t).second; }
  poly operator/=(const poly &t) { return *this = divmod(t).first; }
  poly operator%=(const poly &t) { return *this = divmod(t).second; }
  poly operator*=(const T &first) {
    for (auto &it : a) {
      it *= first;
    }
    normalize();
    return *this;
  }
  poly operator/=(const T &first) {
    for (auto &it : a) {
      it /= first;
    }
    normalize();
    return *this;
  }
  poly operator*(const T &first) const { return poly(*this) *= first; }
  poly operator/(const T &first) const { return poly(*this) /= first; }
  void print() const {
    for (auto it : a) {
      cout << it << ' ';
    }
    cout << "\n";
  }
  T eval(T first) const {
    T res(0);
    for (long long i = (long long)a.size() - 1; i >= 0; i--) {
      res *= first;
      res += a[i];
    }
    return res;
  }
  T &lead() { return a.back(); }
  long long deg() const { return a.empty() ? -inf : a.size() - 1; }
  bool is_zero() const { return a.empty(); }
  T operator[](long long idx) const {
    return idx >= (long long)a.size() || idx < 0 ? T(0) : a[idx];
  }
  T &coef(size_t idx) { return a[idx]; }
  bool operator==(const poly &t) const { return a == t.a; }
  bool operator!=(const poly &t) const { return a != t.a; }
  poly deriv() {
    vector<T> res;
    for (long long i = 1; i <= deg(); i++) {
      res.push_back(T(i) * a[i]);
    }
    return res;
  }
  poly integr() {
    vector<T> res = {0};
    for (long long i = 0; i <= deg(); i++) {
      res.push_back(a[i] / T(i + 1));
    }
    return res;
  }
  size_t leading_xk() const {
    if (is_zero()) {
      return inf;
    }
    long long res = 0;
    while (a[res] == T(0)) {
      res++;
    }
    return res;
  }
  poly log(size_t n) {
    assert(a[0] == T(1));
    return (deriv().mod_xk(n) * inv(n)).integr().mod_xk(n);
  }
  poly exp(size_t n) {
    if (is_zero()) {
      return T(1);
    }
    assert(a[0] == T(0));
    poly ans = T(1);
    size_t a = 1;
    while (a < n) {
      poly C = ans.log(2 * a).div_xk(a) - substr(a, 2 * a);
      ans -= (ans * C).mod_xk(a).mul_xk(a);
      a *= 2;
    }
    return ans.mod_xk(n);
  }
  poly pow_slow(size_t k, size_t n) {
    return k ? k % 2 ? (*this * pow_slow(k - 1, n)).mod_xk(n)
                     : (*this * *this).mod_xk(n).pow_slow(k / 2, n)
             : T(1);
  }
  poly pow(size_t k, size_t n) {
    if (is_zero()) {
      return *this;
    }
    if (k < magic) {
      return pow_slow(k, n);
    }
    long long i = leading_xk();
    T j = a[i];
    poly t = div_xk(i) / j;
    return bpow(j, k) * (t.log(n) * T(k)).exp(n).mul_xk(i * k).mod_xk(n);
  }
  poly mulx(T first) {
    T cur = 1;
    poly res(*this);
    for (long long i = 0; i <= deg(); i++) {
      res.coef(i) *= cur;
      cur *= first;
    }
    return res;
  }
  poly mulx_sq(T first) {
    T cur = first;
    T total = 1;
    T xx = first * first;
    poly res(*this);
    for (long long i = 0; i <= deg(); i++) {
      res.coef(i) *= total;
      total *= cur;
      cur *= xx;
    }
    return res;
  }
  vector<T> chirpz_even(T z, long long n) {
    long long m = deg();
    if (is_zero()) {
      return vector<T>(n, 0);
    }
    vector<T> vv(m + n);
    T zi = z.inv();
    T zz = zi * zi;
    T cur = zi;
    T total = 1;
    for (long long i = 0; i <= max(n - 1, m); i++) {
      if (i <= m) {
        vv[m - i] = total;
      }
      if (i < n) {
        vv[m + i] = total;
      }
      total *= cur;
      cur *= zz;
    }
    poly w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
    vector<T> res(n);
    for (long long i = 0; i < n; i++) {
      res[i] = w[i];
    }
    return res;
  }
  vector<T> chirpz(T z, long long n) {
    auto even = chirpz_even(z, (n + 1) / 2);
    auto odd = mulx(z).chirpz_even(z, n / 2);
    vector<T> ans(n);
    for (long long i = 0; i < n / 2; i++) {
      ans[2 * i] = even[i];
      ans[2 * i + 1] = odd[i];
    }
    if (n % 2 == 1) {
      ans[n - 1] = even.back();
    }
    return ans;
  }
  template <typename iter>
  vector<T> eval(vector<poly> &tree, long long v, iter l, iter r) {
    if (r - l == 1) {
      return {eval(*l)};
    } else {
      auto m = l + (r - l) / 2;
      auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, m);
      auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, m, r);
      A.insert(end(A), begin(B), end(B));
      return A;
    }
  }
  vector<T> eval(vector<T> first) {
    long long n = first.size();
    if (is_zero()) {
      return vector<T>(n, T(0));
    }
    vector<poly> tree(4 * n);
    build(tree, 1, begin(first), end(first));
    return eval(tree, 1, begin(first), end(first));
  }
  template <typename iter>
  poly inter(vector<poly> &tree, long long v, iter l, iter r, iter ly,
             iter ry) {
    if (r - l == 1) {
      return {*ly / a[0]};
    } else {
      auto m = l + (r - l) / 2;
      auto my = ly + (ry - ly) / 2;
      auto A = (*this % tree[2 * v]).inter(tree, 2 * v, l, m, ly, my);
      auto B = (*this % tree[2 * v + 1]).inter(tree, 2 * v + 1, m, r, my, ry);
      return A * tree[2 * v + 1] + B * tree[2 * v];
    }
  }
};
template <typename T>
poly<T> operator*(const T &a, const poly<T> &b) {
  return b * a;
}
template <typename T>
poly<T> xk(long long k) {
  return poly<T>{1}.mul_xk(k);
}
template <typename T>
T resultant(poly<T> a, poly<T> b) {
  if (b.is_zero()) {
    return 0;
  } else if (b.deg() == 0) {
    return bpow(b.lead(), a.deg());
  } else {
    long long pw = a.deg();
    a %= b;
    pw -= a.deg();
    T mul = bpow(b.lead(), pw) * T((b.deg() & a.deg() & 1) ? -1 : 1);
    T ans = resultant(b, a);
    return ans * mul;
  }
}
template <typename iter>
poly<typename iter::value_type> kmul(iter L, iter R) {
  if (R - L == 1) {
    return vector<typename iter::value_type>{-*L, 1};
  } else {
    iter M = L + (R - L) / 2;
    return kmul(L, M) * kmul(M, R);
  }
}
template <typename T, typename iter>
poly<T> build(vector<poly<T>> &res, long long v, iter L, iter R) {
  if (R - L == 1) {
    return res[v] = vector<T>{-*L, 1};
  } else {
    iter M = L + (R - L) / 2;
    return res[v] = build(res, 2 * v, L, M) * build(res, 2 * v + 1, M, R);
  }
}
template <typename T>
poly<T> inter(vector<T> first, vector<T> second) {
  long long n = first.size();
  vector<poly<T>> tree(4 * n);
  return build(tree, 1, begin(first), end(first))
      .deriv()
      .inter(tree, 1, begin(first), end(first), begin(second), end(second));
}
};  // namespace algebra
using namespace algebra;
using namespace algebra;
long long solve() {
  long long n;
  cin >> n;
  vector<long long> d(n + 1);
  vector<mod_int> fact(n + 1, 1);
  for (long long i = 2; i <= n; i++) {
    long long u, v;
    cin >> u >> v;
    d[u]++;
    d[v]++;
    d[i]--;
    fact[i] = i * fact[i - 1];
  }
  function<poly<mod_int>(long long, long long)> calc = [&](long long l,
                                                           long long r) {
    if (l == r) {
      return poly<mod_int>(vector<mod_int>({1, d[l]}));
    } else {
      long long mid = (l + r) / 2;
      return calc(l, mid) * calc(mid + 1, r);
    }
  };
  auto res = calc(1, n);
  mod_int ans = 0;
  for (long long i = 0; i < res.a.size(); i++) {
    if (i % 2 == 0) {
      ans += res.a[i] * fact[n - i];
    } else {
      ans -= res.a[i] * fact[n - i];
    }
  }
  cout << ans << "\n";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
