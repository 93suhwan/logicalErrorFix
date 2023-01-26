#include <bits/stdc++.h>
using namespace std;
template <class U, class V>
istream &operator>>(istream &is, pair<U, V> &p) {
  return is >> p.first >> p.second;
}
template <class U, class V>
ostream &operator<<(ostream &os, const pair<U, V> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <
    class Istream, class Container,
    typename std::enable_if<is_same<Istream, istream>::value, int>::type = 0>
Istream &operator>>(Istream &is, Container &container) {
  for (auto &value : container) is >> value;
  return is;
}
template <
    class Ostream, class Container,
    typename std::enable_if<is_same<Ostream, ostream>::value, int>::type = 0>
Ostream &operator<<(Ostream &os, const Container &container) {
  auto _begin = begin(container), _end = end(container);
  for (auto it = _begin; it != _end;)
    os << "{ "[it != _begin] << *it << ",}"[++it == _end];
  return os;
}
namespace io {
template <class... As>
struct last {};
template <class... As>
using last_t = typename last<As...>::type;
template <class A>
struct last<A> {
  using type = A;
};
template <class A, class... As>
struct last<A, As...> {
  using type = typename last<As...>::type;
};
template <class Z>
Z read(Z &) {
  Z z;
  cin >> z;
  return z;
}
template <class A, class... As>
last_t<As...> read(A &a, As &...as) {
  return cin >> a, read(as...);
}
void log_rest() {}
template <class A, class... As>
void log_rest(const A &a, const As &...as) {
  cerr << ", " << a;
  log_rest(as...);
}
template <class A, class... As>
void log(const string &pref, const A &a, const As &...as) {
  cerr << pref << a, log_rest(as...);
}
}  // namespace io
template <class T>
T make_vec(T default_value) {
  return default_value;
}
template <class T, class Arg, class... Args>
auto make_vec(T default_value, Arg size, Args... rest)
    -> vector<decltype(make_vec(default_value, rest...))> {
  auto level = make_vec(default_value, rest...);
  return vector<decltype(level)>(size, level);
}
template <class Xs>
int len(const Xs &xs) {
  return static_cast<int>(xs.size());
}
using i64 = int64_t;
using f80 = long double;
using Str = string;
template <class T = int>
using Vec = vector<T>;
template <class K = int, class H = hash<K>>
using US = unordered_set<K, H>;
template <class K, class V, class H = hash<K>>
using UM = unordered_map<K, V, H>;
template <class U = int, class V = U>
using P = pair<U, V>;
using G = Vec<Vec<int>>;
template <class T, class P>
auto bin_search(T l, T r, P p) -> T {
  for (T m; m = (l + r) / 2, m != l && m != r; (p(m) ? l : r) = m)
    ;
  return l;
}
i64 mod = 998244353;
i64 bin_pow(i64 n, int pow) {
  if (pow == 0) return 1;
  i64 res = bin_pow(n * n % mod, pow / 2);
  if (pow & 1) {
    res *= n;
    res %= mod;
  }
  return res;
}
Vec<i64> fs, ifs;
void precalc(int n) {
  fs.resize(n);
  ifs.resize(n);
  fs[0] = 1;
  for (int i = 1; i < n; ++i) fs[i] = i * fs[i - 1] % mod;
  ifs.back() = bin_pow(fs.back(), mod - 2);
  for (int i = n - 1; i > 0; --i) {
    ifs[i - 1] = ifs[i] * i % mod;
  }
}
struct Dsu {
  Dsu(int n) : sz(n, 1), par(n) { iota(std::begin(par), end(par), 0); }
  int root(int v) {
    if (par[v] == v) return v;
    return par[v] = root(par[v]);
  }
  bool conn(int a, int b) { return root(a) == root(b); }
  void join(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
  }
  Vec<int> sz;
  Vec<int> par;
};
struct Fenwick {
  vector<int> t;
  int n;
  void init(int nn) {
    n = nn;
    t.assign(n, 0);
  }
  int sum(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
    return result;
  }
  void inc(int i, int delta) {
    for (; i < n; i = (i | (i + 1))) t[i] += delta;
  }
  int sum(int l, int r) { return sum(r) - sum(l - 1); }
  void init(vector<int> a) {
    init((int)a.size());
    for (unsigned i = 0; i < a.size(); i++) inc(i, a[i]);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = io::read(t);
  while (t--) {
    int n, d = io::read(n, d);
    Vec<int> xs(n);
    cin >> xs;
    int inf = 2 * n;
    Vec<int> dst(n, inf);
    queue<int> vs;
    for (int i = 0; i < n; ++i) {
      if (xs[i] == 0) {
        dst[i] = 0;
        vs.push(i);
      }
    }
    while (vs.size()) {
      int v = vs.front();
      vs.pop();
      int nxt = (v + d) % n;
      if (dst[nxt] > dst[v] + 1) {
        dst[nxt] = dst[v] + 1;
        vs.push(nxt);
      }
    }
    auto mx = *max_element(std::begin(dst), end(dst));
    if (mx == inf) mx = -1;
    cout << mx << '\n';
  }
}
namespace {
auto fast_io = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(8) << fixed;
  cerr << boolalpha << setprecision(10) << fixed;
  return 0;
}();
}
