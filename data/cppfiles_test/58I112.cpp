#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
  fast_ios() {
    cin.tie(nullptr), ios::sync_with_stdio(false),
        cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T, typename V>
void ndarray(vector<T> &vec, const V &val, int len) {
  vec.assign(len, val);
}
template <typename T, typename V, typename... Args>
void ndarray(vector<T> &vec, const V &val, int len, Args... args) {
  vec.resize(len),
      for_each(begin(vec), end(vec), [&](T &v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T &m, const T q) {
  return m < q ? (m = q, true) : false;
}
template <typename T>
bool chmin(T &m, const T q) {
  return m > q ? (m = q, true) : false;
}
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first + r.first, l.second + r.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
template <typename T>
vector<T> sort_unique(vector<T> vec) {
  sort(vec.begin(), vec.end()),
      vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
template <typename T>
int arglb(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x));
}
template <typename T>
int argub(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x));
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '[';
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T, size_t sz>
ostream &operator<<(ostream &os, const array<T, sz> &arr) {
  os << '[';
  for (auto v : arr) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec) {
  os << "deq[";
  for (auto v : vec) os << v << ',';
  os << ']';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T, typename TH>
ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
  os << '{';
  for (auto v : vec) os << v << ',';
  os << '}';
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa) {
  os << '(' << pa.first << ',' << pa.second << ')';
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
template <typename TK, typename TV, typename TH>
ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) {
  os << '{';
  for (auto v : mp) os << v.first << "=>" << v.second << ',';
  os << '}';
  return os;
}
template <int md>
struct ModInt {
  using lint = long long;
  static int mod() { return md; }
  static int get_primitive_root() {
    static int primitive_root = 0;
    if (!primitive_root) {
      primitive_root = [&]() {
        std::set<int> fac;
        int v = md - 1;
        for (lint i = 2; i * i <= v; i++)
          while (v % i == 0) fac.insert(i), v /= i;
        if (v > 1) fac.insert(v);
        for (int g = 1; g < md; g++) {
          bool ok = true;
          for (auto i : fac)
            if (ModInt(g).pow((md - 1) / i) == 1) {
              ok = false;
              break;
            }
          if (ok) return g;
        }
        return -1;
      }();
    }
    return primitive_root;
  }
  int val;
  ModInt() : val(0) {}
  ModInt &_setval(lint v) { return val = (v >= md ? v - md : v), *this; }
  ModInt(lint v) { _setval(v % md + md); }
  explicit operator bool() const { return val != 0; }
  ModInt operator+(const ModInt &x) const {
    return ModInt()._setval((lint)val + x.val);
  }
  ModInt operator-(const ModInt &x) const {
    return ModInt()._setval((lint)val - x.val + md);
  }
  ModInt operator*(const ModInt &x) const {
    return ModInt()._setval((lint)val * x.val % md);
  }
  ModInt operator/(const ModInt &x) const {
    return ModInt()._setval((lint)val * x.inv() % md);
  }
  ModInt operator-() const { return ModInt()._setval(md - val); }
  ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
  ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
  ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
  ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
  friend ModInt operator+(lint a, const ModInt &x) {
    return ModInt()._setval(a % md + x.val);
  }
  friend ModInt operator-(lint a, const ModInt &x) {
    return ModInt()._setval(a % md - x.val + md);
  }
  friend ModInt operator*(lint a, const ModInt &x) {
    return ModInt()._setval(a % md * x.val % md);
  }
  friend ModInt operator/(lint a, const ModInt &x) {
    return ModInt()._setval(a % md * x.inv() % md);
  }
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return val != x.val; }
  bool operator<(const ModInt &x) const { return val < x.val; }
  friend std::istream &operator>>(std::istream &is, ModInt &x) {
    lint t;
    return is >> t, x = ModInt(t), is;
  }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
    return os << x.val;
  }
  ModInt pow(lint n) const {
    ModInt ans = 1, tmp = *this;
    while (n) {
      if (n & 1) ans *= tmp;
      tmp *= tmp, n >>= 1;
    }
    return ans;
  }
  static std::vector<ModInt> facs, facinvs, invs;
  static void _precalculation(int N) {
    int l0 = facs.size();
    if (N > md) N = md;
    if (N <= l0) return;
    facs.resize(N), facinvs.resize(N), invs.resize(N);
    for (int i = l0; i < N; i++) facs[i] = facs[i - 1] * i;
    facinvs[N - 1] = facs.back().pow(md - 2);
    for (int i = N - 2; i >= l0; i--) facinvs[i] = facinvs[i + 1] * (i + 1);
    for (int i = N - 1; i >= l0; i--) invs[i] = facinvs[i] * facs[i - 1];
  }
  lint inv() const {
    if (this->val < std::min(md >> 1, 1 << 21)) {
      while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
      return invs[this->val].val;
    } else {
      return this->pow(md - 2).val;
    }
  }
  ModInt fac() const {
    while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
    return facs[this->val];
  }
  ModInt facinv() const {
    while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
    return facinvs[this->val];
  }
  ModInt doublefac() const {
    lint k = (this->val + 1) / 2;
    return (this->val & 1)
               ? ModInt(k * 2).fac() / (ModInt(2).pow(k) * ModInt(k).fac())
               : ModInt(k).fac() * ModInt(2).pow(k);
  }
  ModInt nCr(const ModInt &r) const {
    return (this->val < r.val)
               ? 0
               : this->fac() * (*this - r).facinv() * r.facinv();
  }
  ModInt nPr(const ModInt &r) const {
    return (this->val < r.val) ? 0 : this->fac() * (*this - r).facinv();
  }
  ModInt sqrt() const {
    if (val == 0) return 0;
    if (md == 2) return val;
    if (pow((md - 1) / 2) != 1) return 0;
    ModInt b = 1;
    while (b.pow((md - 1) / 2) == 1) b += 1;
    int e = 0, m = md - 1;
    while (m % 2 == 0) m >>= 1, e++;
    ModInt x = pow((m - 1) / 2), y = (*this) * x * x;
    x *= (*this);
    ModInt z = b.pow(m);
    while (y != 1) {
      int j = 0;
      ModInt t = y;
      while (t != 1) j++, t *= t;
      z = z.pow(1LL << (e - j - 1));
      x *= z, z *= z, y *= z;
      e = j;
    }
    return ModInt(std::min(x.val, md - x.val));
  }
};
template <int md>
std::vector<ModInt<md>> ModInt<md>::facs = {1};
template <int md>
std::vector<ModInt<md>> ModInt<md>::facinvs = {1};
template <int md>
std::vector<ModInt<md>> ModInt<md>::invs = {0};
using mint = ModInt<998244353>;
mint solve() {
  int N, M;
  cin >> N >> M;
  vector<pint> xy(M);
  for (auto &[x, y] : xy) cin >> x >> y;
  if (N == M + 1) return 1;
  reverse((xy).begin(), (xy).end());
  set<int> s;
  for (auto [x, y] : xy) {
    if (s.count(y + 1)) s.erase(y + 1);
    s.insert(y);
  }
  (s.size());
  int nbar = N - 1 - s.size();
  (nbar);
  return mint(N + nbar).nCr(nbar);
}
int main() {
  int T;
  cin >> T;
  while (T--) cout << solve() << '\n';
}
