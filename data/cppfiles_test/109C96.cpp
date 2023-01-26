#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
using Int = long long;
constexpr int mod = 998244353;
constexpr Int Inf = 1e18 + 1;
template <class T>
inline bool cmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool cmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) {
    int sigt = sig % MOD;
    if (sigt < 0) sigt += MOD;
    x = sigt;
  }
  ModInt(signed long long sig) {
    int sigt = sig % MOD;
    if (sigt < 0) sigt += MOD;
    x = sigt;
  }
  int get() const { return (int)x; }
  ModInt &operator+=(ModInt that) {
    if ((x += that.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(ModInt that) {
    if ((x += MOD - that.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator*=(ModInt that) {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
  ModInt &operator%=(ModInt that) {
    x %= that.x;
    return *this;
  }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  ModInt operator%(ModInt that) const { return ModInt(*this) %= that; }
  ModInt inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while (b) {
      signed t = a / b;
      a -= t * b;
      std::swap(a, b);
      u -= t * v;
      std::swap(u, v);
    }
    if (u < 0) u += Mod;
    ModInt res;
    res.x = (unsigned)u;
    return res;
  }
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  ModInt operator-() const {
    ModInt t;
    t.x = x == 0 ? 0 : Mod - x;
    return t;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
};
template <int MOD>
ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
  ModInt<MOD> r = 1;
  while (k) {
    if (k & 1) r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}
template <typename T>
vector<T> divisor(T n) {
  vector<T> ret;
  for (T i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
vector<ModInt<mod>> fact, factinv;
void Cinit(int N) {
  N = min(N, ModInt<mod>::Mod - 1);
  fact.resize(N + 1);
  factinv.resize(N + 1);
  fact[0] = 1;
  for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;
  factinv[N] = fact[N].inverse();
  for (int i = N; i >= 1; i--) factinv[i - 1] = factinv[i] * i;
}
ModInt<mod> C(int n, int r) {
  if (n >= ModInt<mod>::Mod)
    return C(n % ModInt<mod>::Mod, r % ModInt<mod>::Mod) *
           C(n / ModInt<mod>::Mod, r / ModInt<mod>::Mod);
  return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}
template <typename T>
bool is_prime(T x) {
  if (x <= 1) return false;
  for (T i = 2; i * i <= x; i++) {
    if (!(x % i)) return false;
  }
  return true;
}
template <class T>
struct edge {
  int fr, to;
  T w;
  edge(int to, T w) : fr(-1), to(to), w(w) {}
  edge(int fr, int to, T w) : fr(fr), to(to), w(w) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;
struct UnionFind {
  vector<int> data;
  UnionFind(int sz) { data.assign(sz, -1); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return (false);
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
  int find(int k) {
    if (data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
  int size(int k) { return (-data[find(k)]); }
  int wholesize() {
    map<int, bool> p;
    for (unsigned i = 0; i < data.size(); i++) p[find(i)] = true;
    return p.size();
  }
};
template <class T>
struct BIT {
  vector<T> data;
  int n;
  BIT(int size) {
    n = size + 1;
    data.assign(n, 0);
  }
  T sum(int k) {
    T res = 0;
    for (++k; k > 0; k -= k & -k) res += data[k];
    return res;
  }
  T sum(int l, int r) { return sum(r) - sum(l - 1); }
  void add(int i, int x) {
    for (++i; i < n; i += i & -i) data[i] += x;
  }
};
template <class T, class F>
struct SegTree {
  vector<T> seg;
  int size;
  const F f;
  const T e;
  SegTree(const vector<T> &d, F f, T e) : f(f), e(e) {
    int n = d.size();
    size = 1;
    while (size < n) size <<= 1;
    seg.resize(size * 2 - 1, e);
    for (int i = (0LL), i_len = (n); i < i_len; ++i) seg[i + size - 1] = d[i];
    for (int i = (size - 2) - 1; i >= (0); --i) upd(i);
  }
  void upd(int i) { seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]); }
  void set(int i, T t) {
    i += size - 1;
    seg[i] = t;
    while (i) {
      i = (i - 1) / 2;
      upd(i);
    }
  }
  T get(int a, int b, int i, int l, int r) {
    if (r < 0) r = size;
    if (b <= l || r <= a) return e;
    if (a <= l && r <= b) return seg[i];
    int mid = (l + r) / 2;
    return f(get(a, b, i * 2 + 1, l, mid), get(a, b, i * 2 + 2, mid, r));
  }
  T get(int a, int b) { return get(a, b, 0, 0, -1); }
  T operator[](const int &i) const { return seg[i + size - 1]; }
};
template <class T, class F>
SegTree<T, F> segtree(const vector<T> &d, F f, T e) {
  return SegTree<T, F>(d, f, e);
}
Int n, m, x, y, q;
string s, sb;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> q;
  for (int _ = (0LL), __len = (q); _ < __len; ++_) {
    cin >> n >> s;
    int ans = 0;
    for (int i = (0LL), i_len = (s.size()); i < i_len; ++i) {
      if (i < s.size() - 1 && s[i] != '0')
        ans += 1 + s[i] - '0';
      else
        ans += s[i] - '0';
    }
    cout << (ans) << '\n';
  }
}
