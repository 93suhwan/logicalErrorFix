#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
template <typename T>
using PQ = priority_queue<T, vc<T>, greater<T>>;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int, int>;
using T3 = tuple<int, int, int>;
using vi = vc<int>;
using vvi = vv<int>;
using vl = vc<ll>;
using vp = vc<P>;
using vt = vc<T3>;
int getInt() {
  int x;
  scanf("%d", &x);
  return x;
}
vi pm(int n, int s = 0) {
  vi a(n);
  iota(a.begin(), a.end(), s);
  return a;
}
template <typename T>
istream& operator>>(istream& i, vc<T>& v) {
  for (int j = 0; j < ((int)(v).size()); ++j) i >> v[j];
  return i;
}
template <typename T>
string join(const T& v, const string& d = "") {
  stringstream s;
  for (int i = 0; i < ((int)(v).size()); ++i) (i ? s << d : s) << v[i];
  return s.str();
}
template <typename T>
ostream& operator<<(ostream& o, const vc<T>& v) {
  if ((int)(v).size()) o << join(v, " ");
  return o;
}
template <typename T1, typename T2>
istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& v) {
  return o << v.first << "," << v.second;
}
vc<string> split(const string& s, char d = ' ') {
  vc<string> r(1);
  for (char c : s)
    if (c == d)
      r.push_back("");
    else
      r.back() += c;
  return r;
}
string operator*(const string& s, int t) { return join(vc<string>(t, s)); }
template <typename T1, typename T2>
bool mins(T1& x, const T2& y) {
  if (x > y) {
    x = y;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
bool maxs(T1& x, const T2& y) {
  if (x < y) {
    x = y;
    return true;
  } else
    return false;
}
template <typename Tx, typename Ty>
Tx dup(Tx x, Ty y) {
  return (x + y - 1) / y;
}
template <typename T>
ll suma(const vc<T>& a) {
  ll res(0);
  for (auto&& x : a) res += x;
  return res;
}
template <typename T>
void uni(T& a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 200005;
const uint mod = 1000000007;
struct mint {
  uint x;
  mint() : x(0) {}
  mint(ll x) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(0) - *this; }
  mint operator~() const { return mint(1) / *this; }
  mint& operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& a) {
    x = (ull)x * a.x % mod;
    return *this;
  }
  mint& operator/=(const mint& a) {
    x = (ull)x * a.pow(mod - 2).x % mod;
    return *this;
  }
  mint operator+(const mint& a) const { return mint(*this) += a; }
  mint operator-(const mint& a) const { return mint(*this) -= a; }
  mint operator*(const mint& a) const { return mint(*this) *= a; }
  mint operator/(const mint& a) const { return mint(*this) /= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint res = pow(t / 2);
    res *= res;
    return (t & 1) ? res * x : res;
  }
  bool operator<(const mint& a) const { return x < a.x; }
  bool operator==(const mint& a) const { return x == a.x; }
  bool operator!=(const mint& a) const { return x != a.x; }
};
mint ex(mint x, ll t) { return x.pow(t); }
istream& operator>>(istream& i, mint& a) {
  i >> a.x;
  return i;
}
ostream& operator<<(ostream& o, const mint& a) {
  o << a.x;
  return o;
}
using vm = vector<mint>;
using vvm = vector<vm>;
struct modinv {
  int n;
  vm d;
  modinv() : n(2), d({0, 1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(-d[mod % n] * (mod / n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} invs;
struct modfact {
  int n;
  vm d;
  modfact() : n(2), d({1, 1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(d.back() * n), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} facs;
struct modfactinv {
  int n;
  vm d;
  modfactinv() : n(2), d({1, 1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(d.back() * invs(n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} ifacs;
mint comb(int a, int b) {
  if (a < b || b < 0) return 0;
  return facs(a) * ifacs(b) * ifacs(a - b);
}
struct Solver {
  void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vi a(n);
    cin >> a;
    vm f(n + 1);
    for (int i = 1; i < (n); ++i) {
      mint c = mint(n) * k - mint(n - i) * (k - 2) - n;
      f[i + 1] =
          (c * f[i] - mint(k - 1) * i * f[i - 1] - mint(i) * k) * invs(n - i);
    }
    map<int, int> mp;
    for (int x : a) mp[x]++;
    int r = mp[-1];
    vm c(r + 1);
    mint kx = 1;
    for (int i = (r + 1) - 1; i >= 0; --i) c[i] = comb(r, i) * kx, kx *= k - 1;
    mint ans = 0;
    map<int, int> cp;
    for (auto p : mp)
      if (p.first != -1) cp[p.second] += 1;
    cp[0] = k - ((int)(mp).size() - 1);
    for (auto p : cp) {
      for (int i = 0; i < (r + 1); ++i) ans += f[p.first + i] * c[i] * p.second;
    }
    ans /= ex(k, r);
    ans -= f[n];
    cout << ans << endl;
  }
};
int main() {
  int ts = 1;
  for (int ti = 1; ti <= (ts); ++ti) {
    Solver solver;
    solver.solve();
  }
  return 0;
}
