#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
template <class t, class u>
bool chmax(t& first, u second) {
  if (first < second) {
    first = second;
    return true;
  } else
    return false;
}
template <class t, class u>
bool chmin(t& first, u second) {
  if (second < first) {
    first = second;
    return true;
  } else
    return false;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<int, int>;
using vi = vc<int>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
template <int i, class T>
void print_tuple(ostream&, const T&) {}
template <int i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
template <class t>
void print(t x, int suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(int n, int off = 0) {
  vi v(n);
  for (int i = int(0); i < int(n); i++) v[i] = read() + off;
  return v;
}
pi readpi(int off = 0) {
  int first, second;
  cin >> first >> second;
  return pi(first + off, second + off);
}
template <class t, class u>
void print(const pair<t, u>& p, int suc = 1) {
  print(p.first, 2);
  print(p.second, suc);
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i], i == int(v.size()) - 1 ? suc : 2);
}
template <class T>
void print_offset(const vector<T>& v, ll off, int suc = 1) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i] + off, i == int(v.size()) - 1 ? suc : 2);
}
template <class T, size_t N>
void print(const array<T, N>& v, int suc = 1) {
  for (int i = int(0); i < int(N); i++) print(v[i], i == int(N) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const int inf = INT_MAX / 2 - 100;
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
int botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
bool inc(int first, int second, int c) {
  return first <= second && second <= c;
}
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
void myshuffle(vc<t>& first) {
  for (int i = int(0); i < int(int(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
int lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
vvc<int> readGraph(int n, int m) {
  vvc<int> g(n);
  for (int i = int(0); i < int(m); i++) {
    int first, second;
    cin >> first >> second;
    first--;
    second--;
    g[first].push_back(second);
    g[second].push_back(first);
  }
  return g;
}
vvc<int> readTree(int n) { return readGraph(n, n - 1); }
struct modinfo {
  uint mod, root;
};
template <modinfo const& ref>
struct modular {
  static constexpr uint const& mod = ref.mod;
  static modular root() { return modular(ref.root); }
  uint v;
  modular(ll vv = 0) { s(vv % mod + mod); }
  modular& s(uint vv) {
    v = vv < mod ? vv : vv - mod;
    return *this;
  }
  modular operator-() const { return modular() - *this; }
  modular& operator+=(const modular& rhs) { return s(v + rhs.v); }
  modular& operator-=(const modular& rhs) { return s(v + mod - rhs.v); }
  modular& operator*=(const modular& rhs) {
    v = ull(v) * rhs.v % mod;
    return *this;
  }
  modular& operator/=(const modular& rhs) { return *this *= rhs.inv(); }
  modular operator+(const modular& rhs) const { return modular(*this) += rhs; }
  modular operator-(const modular& rhs) const { return modular(*this) -= rhs; }
  modular operator*(const modular& rhs) const { return modular(*this) *= rhs; }
  modular operator/(const modular& rhs) const { return modular(*this) /= rhs; }
  modular pow(ll n) const {
    if (n < 0) return inv().pow(-n);
    modular res(1), x(*this);
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  modular inv() const { return pow(mod - 2); }
  friend modular operator+(int x, const modular& y) { return modular(x) + y; }
  friend modular operator-(int x, const modular& y) { return modular(x) - y; }
  friend modular operator*(int x, const modular& y) { return modular(x) * y; }
  friend modular operator/(int x, const modular& y) { return modular(x) / y; }
  friend ostream& operator<<(ostream& os, const modular& m) {
    return os << m.v;
  }
  friend istream& operator>>(istream& is, modular& m) {
    ll x;
    is >> x;
    m = modular(x);
    return is;
  }
  bool operator<(const modular& r) const { return v < r.v; }
  bool operator==(const modular& r) const { return v == r.v; }
  bool operator!=(const modular& r) const { return v != r.v; }
  explicit operator bool() const { return v; }
};
extern constexpr modinfo base{998244353, 3};
using mint = modular<base>;
const int vmax = (1 << 21) + 10;
mint fact[vmax], finv[vmax], invs[vmax];
void initfact() {
  fact[0] = 1;
  for (int i = int(1); i < int(vmax); i++) {
    fact[i] = fact[i - 1] * i;
  }
  finv[vmax - 1] = fact[vmax - 1].inv();
  for (int i = vmax - 2; i >= 0; i--) {
    finv[i] = finv[i + 1] * (i + 1);
  }
  for (int i = vmax - 1; i >= 1; i--) {
    invs[i] = finv[i] * fact[i - 1];
  }
}
mint choose(int n, int k) { return fact[n] * finv[n - k] * finv[k]; }
mint binom(int first, int second) {
  return fact[first + second] * finv[first] * finv[second];
}
mint catalan(int n) {
  return binom(n, n) - (n - 1 >= 0 ? binom(n - 1, n + 1) : 0);
}
const int nmax = 2010;
mint dp[2][nmax][nmax];
int len[2][nmax];
int cur, nx;
void clear() {
  memset(dp[nx], 0, sizeof(dp[nx]));
  memset(len[nx], 0, sizeof(len[nx]));
}
void add(int i, int j, mint v) {
  dp[nx][i][j] += v;
  chmax(len[nx][i], j + 1);
}
void slv() {
  int n, k;
  cin >> n >> k;
  vc<pi> lr(n + 1);
  lr[0] = pi(0, 1);
  for (int i = int(0); i < int(n); i++) {
    int second;
    cin >> second;
    lr[i + 1] = pi(max(second - k, 0), min(second + k, n) + 1);
  }
  for (int i = int(0); i < int(n); i++) chmax(lr[i + 1].first, lr[i].first);
  for (int i = int(n) - 1; i >= int(0); i--)
    chmin(lr[i].second, lr[i + 1].second);
  for (int i = int(0); i < int(n + 1); i++)
    if (lr[i].first >= lr[i].second) {
      return print(0);
    }
  void(0);
  nx = 1;
  for (int i = int(lr[n].first); i < int(lr[n].second); i++) add(i, 1, 1);
  swap(cur, nx);
  for (int step = int(n) - 1; step >= int(0); step--) {
    clear();
    for (int i = int(max(lr[step + 1].first, 1)); i < int(lr[step + 1].second);
         i++) {
      for (int j = int(0); j < int(len[cur][i]); j++) {
        add(i - 1, j + 1, dp[cur][i][j]);
      }
    }
    for (int i = int(lr[step + 1].second) - 1; i >= int(lr[step].first + 1);
         i--) {
      for (int j = int(0); j < int(len[nx][i]); j++) {
        add(i - 1, j, dp[nx][i][j]);
        add(i - 1, j + 1, -dp[nx][i][j]);
      }
    }
    for (int i = int(lr[step + 1].first); i < int(lr[step + 1].second); i++) {
      for (int j = int(0); j < int(len[cur][i]); j++) {
        add(i, j, dp[cur][i][j] * (n + 1 - j));
      }
    }
    swap(cur, nx);
  }
  mint ans = 0;
  for (int j = int(0); j < int(len[cur][0]); j++) ans += dp[cur][0][j];
  print(ans);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  slv();
}
