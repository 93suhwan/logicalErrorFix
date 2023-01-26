#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
template <class T>
std::ostream &operator<<(std::ostream &s, std::vector<T> &P) {
  for (int i = 0; i < P.size(); ++i) {
    if (i > 0) {
      s << " ";
    }
    s << P[i];
  }
  return s;
}
template <class T, class U>
std::ostream &operator<<(std::ostream &s, std::pair<T, U> &P) {
  s << " { " << P.first << " " << P.second << " } ";
  return s;
}
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
using heapQueue = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T = int>
T gcd(T a, T b) {
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T = int>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T = int>
T powMod(T x, T k, T m) {
  if (k == 0) {
    return (T)1;
  }
  if (k % 2 == 0) {
    return powMod(x * x % m, k / 2, m);
  } else {
    return x * powMod(x, k - 1, m) % m;
  }
}
template <class T = int>
T extgcd(T a, T b, T &x, T &y) {
  T g = a;
  x = 1;
  y = 0;
  if (b != 0) {
    g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  }
  return g;
}
template <class T = int>
T invMod(T a, T m) {
  T x, y;
  if (extgcd(a, m, x, y) == 1) {
    return (x + m) % m;
  } else {
    return -1;
  }
}
template <class T = int>
int bisect_right(const std::vector<T> &V, T val) {
  if (V.size() == 0) {
    return 0;
  }
  auto it = lower_bound(V.begin(), V.end(), val + 1);
  int index = it - V.begin();
  return index;
}
template <class T = long long>
void UniqueVector(std::vector<T> &V) {
  std::sort(V.begin(), V.end());
  auto result = std::unique(V.begin(), V.end());
  V.erase(result, V.end());
  return;
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
}
template <class T = int>
std::map<T, int> compress(const std::vector<T> &a) {
  int n = (int)a.size();
  std::vector<T> copy_a(n);
  std::copy(a.begin(), a.end(), copy_a.begin());
  std::sort(copy_a.begin(), copy_a.end());
  int itr = 0;
  std::map<T, int> retval;
  for (T elem : copy_a) {
    if (retval.find(elem) == retval.end()) {
      retval[elem] = itr;
      itr++;
    }
  }
  return retval;
}
template <class T = int>
std::vector<T> compressVector(const std::vector<T> &a) {
  auto d = compress(a);
  int n = (int)a.size();
  std::vector<T> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = d[a[i]];
  }
  return ans;
}
template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
 public:
  segtree() : segtree(0) {}
  segtree(int n) : segtree(std::vector<S>(n, e())) {}
  segtree(const std::vector<S> &v) : _n(int(v.size())) {
    log = _ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }
  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  S get(int p) {
    assert(0 <= p && p < _n);
    return d[p + size];
  }
  S add(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] += x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }
  S all_prod() { return d[1]; }
  template <bool (*f)(S)>
  int max_right(int l) {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F>
  int max_right(int l, F f) {
    assert(0 <= l && l <= _n);
    if (l == _n) return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }
  template <bool (*f)(S)>
  int min_left(int r) {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F>
  int min_left(int r, F f) {
    assert(0 <= r && r <= _n);
    if (r == 0) return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  int _n, size, log;
  std::vector<S> d;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  int _ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
  }
};
template <class T = int, class U = int>
struct defaultdict {
 private:
  std::map<T, U> mp;
  T ide_key = T{};
  U ide_val = U{};
  void _set(T key) {
    if (mp.find(key) == mp.end()) {
      mp[key] = U{};
    }
  }

 public:
  defaultdict(T ide_key, U ide_val) : ide_key(ide_key), ide_val(ide_val){};
  defaultdict(){};
  U &operator[](T key) {
    _set(key);
    return mp[key];
  }
  T getMin() {
    if (mp.empty()) {
      return ide_key;
    } else {
      return mp.begin()->first;
    }
  }
  T getMax() {
    if (mp.empty()) {
      return ide_key;
    } else {
      return mp.rbegin()->first;
    }
  }
  void erase(T key) {
    if (mp.find(key) != mp.end()) {
      mp.erase(key);
    }
  }
  void clear() { mp.clear(); }
  int size() { return mp.size(); }
  std::vector<T> keys() {
    std::vector<T> res;
    for (auto &[k, v] : mp) {
      res.emplace_back(k);
    }
    return res;
  }
  std::vector<U> values() {
    std::vector<U> res;
    for (auto &[k, v] : mp) {
      res.emplace_back(v);
    }
    return res;
  }
  std::map<T, U> &items() { return mp; }
};
template <typename T = int>
struct rangeSum1D {
 private:
  int n;
  std::vector<T> elem;

 public:
  rangeSum1D(int N, T ide) : n(N) {
    assert(N > 0);
    elem.resize(N);
    elem.assign(N, ide);
  }
  rangeSum1D(std::vector<T> vec) {
    n = vec.size();
    elem.resize(n);
    for (int i = 0; i < n; i++) {
      elem[i] = vec[i];
    }
    for (int i = 1; i < n; i++) {
      elem[i] += elem[i - 1];
    }
  }
  T Sum(int L, int R) {
    if (L >= R) {
      return T{};
    }
    assert(0 <= L && R <= n);
    if (L == 0) {
      return elem[R - 1];
    } else {
      return elem[R - 1] - elem[L - 1];
    }
  }
  int size() { return n; }
};
template <typename T = int>
struct edge {
  int src, to;
  T cost;
  edge(){};
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template <typename T = int>
using Edges = std::vector<edge<T>>;
template <typename T = int>
using WeightedGraph = std::vector<Edges<T>>;
using UnWeightedGraph = std::vector<std::vector<int>>;
using Pii = std::pair<int, int>;
using Pll = std::pair<long long, long long>;
int popcount(int x) { return __builtin_popcount(x); }
long long lpopcount(long long x) { return __builtin_popcountll(x); }
const long long mod = 998244353;
const int inf = 1e9 + 10;
const long long linf = 1e18 + 10;
std::vector<Pii> dxy = {{-1, 0}, {1, 0},  {0, -1}, {0, 1},
                        {1, -1}, {-1, 1}, {1, 1},  {-1, -1}};
const int maxn = 20010;
std::vector<long long> fact(maxn, 1);
std::vector<long long> invfact(maxn, 1);
std::vector<long long> invs(maxn, 1);
void permutation_init() {
  for (int i = 1; i < maxn; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  for (int i = (maxn)-1; i >= 0; i--) {
    invfact[i] = powMod(fact[i], mod - 2, mod);
  }
  for (int i = 1; i < maxn; i++) {
    invs[i] = invMod<long long>(i, mod);
  }
  return;
}
long long ncr(int N, int R) {
  if (N < R || R < 0) return 0;
  long long res = fact[N] * (invfact[R] * invfact[N - R] % mod);
  return res % mod;
}
void slv() {
  using namespace std;
  permutation_init();
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> bits;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      bits.emplace_back(i);
    }
  }
  if (bits.size() < k) {
    cout << 1 << '\n';
    return;
  }
  long long ans = 1;
  for (int l = 0; l < bits.size(); l++) {
    int L, R, LEFT;
    if (l == 0) {
      L = -1;
    } else {
      L = bits[l - 1];
    }
    if (l + k >= bits.size()) {
      R = n;
      LEFT = bits.size() - l;
    } else {
      R = bits[l + k];
      LEFT = k;
    }
    for (int pos = L + 1; pos < R; pos++) {
      if (pos == bits[l]) {
        continue;
      }
      ans += ncr(R - pos - 1, LEFT - 1);
      ans %= mod;
    }
  }
  if (ans < 0) {
    ans += mod;
  }
  cout << ans << '\n';
  return;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout << std::fixed << std::setprecision(12);
  int testcase = 1;
  while (testcase--) {
    slv();
  }
  return 0;
}
