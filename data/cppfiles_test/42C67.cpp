#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
template <typename T>
bool chmax(T &x, const T &y) {
  return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
  return (x > y) ? (x = y, true) : false;
}
template <typename T>
int flg(T x, int i) {
  return (x >> i) & 1;
}
template <typename T>
void print(const vector<T> &v, T x = 0) {
  int n = v.size();
  for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
}
template <typename T>
void printn(const vector<T> &v, T x = 0) {
  int n = v.size();
  for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}
template <typename T>
int lb(const vector<T> &v, T x) {
  return lower_bound(begin(v), end(v), x) - begin(v);
}
template <typename T>
int ub(const vector<T> &v, T x) {
  return upper_bound(begin(v), end(v), x) - begin(v);
}
template <typename T>
void rearrange(vector<T> &v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
  int n = v.size();
  vector<int> ret(n);
  iota(begin(ret), end(ret), 0);
  sort(begin(ret), end(ret),
       [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
  return ret;
}
struct io_setup {
  io_setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
  }
} io_setup;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
template <int mod>
struct Mod_Int {
  int x;
  Mod_Int() : x(0) {}
  Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  static int get_mod() { return mod; }
  Mod_Int &operator+=(const Mod_Int &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  Mod_Int &operator-=(const Mod_Int &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  Mod_Int &operator*=(const Mod_Int &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  Mod_Int &operator/=(const Mod_Int &p) {
    *this *= p.inverse();
    return *this;
  }
  Mod_Int &operator++() { return *this += Mod_Int(1); }
  Mod_Int operator++(int) {
    Mod_Int tmp = *this;
    ++*this;
    return tmp;
  }
  Mod_Int &operator--() { return *this -= Mod_Int(1); }
  Mod_Int operator--(int) {
    Mod_Int tmp = *this;
    --*this;
    return tmp;
  }
  Mod_Int operator-() const { return Mod_Int(-x); }
  Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }
  Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }
  Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }
  Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }
  bool operator==(const Mod_Int &p) const { return x == p.x; }
  bool operator!=(const Mod_Int &p) const { return x != p.x; }
  Mod_Int inverse() const {
    assert(*this != Mod_Int(0));
    return pow(mod - 2);
  }
  Mod_Int pow(long long k) const {
    Mod_Int now = *this, ret = 1;
    for (; k > 0; k >>= 1, now *= now) {
      if (k & 1) ret *= now;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const Mod_Int &p) {
    return os << p.x;
  }
  friend istream &operator>>(istream &is, Mod_Int &p) {
    long long a;
    is >> a;
    p = Mod_Int<mod>(a);
    return is;
  }
};
using mint = Mod_Int<MOD>;
template <typename T>
struct Binary_Indexed_Tree {
  vector<T> bit;
  const int n;
  Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()) {
    bit.resize(n + 1);
    copy(begin(v), end(v), begin(bit) + 1);
    for (int a = 2; a <= n; a <<= 1) {
      for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
    }
  }
  Binary_Indexed_Tree(int n, const T &x) : n(n) {
    bit.resize(n + 1);
    vector<T> v(n, x);
    copy(begin(v), end(v), begin(bit) + 1);
    for (int a = 2; a <= n; a <<= 1) {
      for (int b = a; b <= n; b += a) bit[b] += bit[b - a / 2];
    }
  }
  void add(int i, const T &x) {
    for (i++; i <= n; i += (i & -i)) bit[i] += x;
  }
  void change(int i, const T &x) { add(i, x - query(i, i + 1)); }
  T sum(int i) const {
    T ret = 0;
    for (; i > 0; i -= (i & -i)) ret += bit[i];
    return ret;
  }
  T query(int l, int r) const { return sum(r) - sum(l); }
  T operator[](int i) const { return query(i, i + 1); }
  int lower_bound(T x) const {
    int ret = 0;
    for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
      if (ret + (1 << k) <= n && bit[ret + (1 << k)] < x)
        x -= bit[ret += (1 << k)];
    }
    return ret;
  }
  int upper_bound(T x) const {
    int ret = 0;
    for (int k = 31 - __builtin_clz(n); k >= 0; k--) {
      if (ret + (1 << k) <= n && bit[ret + (1 << k)] <= x)
        x -= bit[ret += (1 << k)];
    }
    return ret;
  }
};
int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  vector<int> v = id_sort(b);
  vector<int> id(N, -1);
  for (int i = 0; i < N; i++) id[v[i]] = i;
  Binary_Indexed_Tree<mint> bit(2 * N, 0);
  vector<mint> dp(N, 0);
  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    dp[i] += bit.query(a[v[i]] + 1, 2 * N);
    bit.add(a[v[i]], dp[i]);
  }
  int K;
  cin >> K;
  vector<int> c(N, 0);
  for (int i = 0; i < K; i++) {
    int x;
    cin >> x;
    x--;
    c[id[x]]++;
  }
  mint ans = 0;
  int ptr = -1;
  for (int i = N - 1; i >= 0; i--) {
    bit.add(a[v[i]], -dp[i]);
    if (c[i] == 1 && a[v[i]] > ptr) {
      ans += bit.query(ptr + 1, 2 * N) + 1;
      ptr = a[v[i]];
    }
  }
  cout << ans << '\n';
}
