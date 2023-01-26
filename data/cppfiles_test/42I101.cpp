#include <bits/stdc++.h>
using namespace std;
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  using ll = long long;
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

 public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream& operator<<(std::ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend std::istream& operator>>(std::istream& in, modnum& n) {
    ll v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum& a, const modnum& b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum& a, const modnum& b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum& operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum& operator+=(const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator-=(const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator*=(const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator/=(const modnum& o) { return *this *= o.inv(); }
  friend modnum operator++(modnum& a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum& a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum& a, const modnum& b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum& a, const modnum& b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum& a, const modnum& b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum& a, const modnum& b) {
    return modnum(a) /= b;
  }
};
template <typename T>
T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b >>= 1;
    a *= a;
  }
  return r;
}
template <int M>
string to_string(modnum<M> x) {
  return to_string(int(x));
}
using num = modnum<int(1e9) + 7>;
template <typename T>
struct FenwickTree {
  int n, indexBase;
  vector<T> a;
  FenwickTree(int n, int indexBase = 1) : n(n), indexBase(indexBase) {
    a = vector<T>(n + 1, 0);
  }
  void add(int x, T v) {
    for (int i = x + 1 - indexBase; i <= n; i += i & -i) a[i] += v;
  }
  T get(int x) {
    T res = 0;
    for (int i = x + 1 - indexBase; i; i -= i & -i) res += a[i];
    return res;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> id(n * 2, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].second--;
    id[--a[i].first] = i;
  }
  vector<num> f(n * 2);
  FenwickTree<num> tree(n * 2, 0);
  for (int l = n * 2 - 1; l >= 0; l--)
    if (id[l] >= 0) {
      int r = a[id[l]].second;
      f[l] = tree.get(r);
      f[l]++;
      tree.add(r, f[l]);
    }
  int q;
  cin >> q;
  int minL = n * 2, maxL = -1, maxR = -1;
  while (q--) {
    int x;
    cin >> x;
    minL = min(minL, a[--x].first);
    maxL = max(maxL, a[x].first);
    maxR = max(maxR, a[x].second);
  }
  num ans = 0;
  for (int i = minL; i <= maxL; i++)
    if (id[i] >= 0 && a[id[i]].second <= maxR) ans += f[i];
  cout << ans << endl;
}
