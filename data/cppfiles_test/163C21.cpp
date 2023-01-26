#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - begin(a));
}
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int dxx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dyy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
int bits(int x) {
  assert(x >= 0);
  return x == 0 ? 0 : 31 - __builtin_clz(x);
}
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
T fstTrue(T lo, T hi, U f) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U f) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
void remDup(vector<T>& v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
template <class T, class U>
void erase(T& t, const U& u) {
  auto it = t.find(u);
  assert(it != end(t));
  t.erase(it);
}
template <class T>
void re(complex<T>& c);
template <class T, class U>
void re(pair<T, U>& p);
template <class T>
void re(V<T>& v);
template <class T, size_t SZ>
void re(AR<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(db& d) {
  str t;
  re(t);
  d = stod(t);
}
void re(ld& d) {
  str t;
  re(t);
  d = stold(t);
}
template <class T, class... U>
void re(T& t, U&... u) {
  re(t);
  re(u...);
}
template <class T>
void re(complex<T>& c) {
  T a, b;
  re(a, b);
  c = {a, b};
}
template <class T, class U>
void re(pair<T, U>& p) {
  re(p.first, p.second);
}
template <class T>
void re(V<T>& x) {
  for (auto& a : x) re(a);
}
template <class T, size_t SZ>
void re(AR<T, SZ>& x) {
  for (auto& a : x) re(a);
}
template <class T>
void rv(int n, V<T>& x) {
  x.resize(n);
  re(x);
}
str to_string(char c) { return str(1, c); }
str to_string(const char* s) { return (str)s; }
str to_string(str s) { return s; }
str to_string(bool b) { return to_string((int)b); }
template <class T>
str to_string(complex<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
str to_string(V<bool> v) {
  str res = "{";
  for (int i = (0); i < (int((v).size())); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
str to_string(bitset<SZ> b) {
  str res = "";
  for (int i = (0); i < (SZ); ++i) res += char('0' + b[i]);
  return res;
}
template <class T, class U>
str to_string(pair<T, U> p);
template <class T>
str to_string(T v) {
  bool fst = 1;
  str res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T, class U>
str to_string(pair<T, U> p) {
  return to_string(p.first) + " " + to_string(p.second);
}
template <class T>
void pr(T x) {
  cout << to_string(x);
}
template <class T, class... U>
void pr(const T& t, const U&... u) {
  pr(t);
  pr(u...);
}
void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T& t, const U&... u) {
  pr(t);
  if (sizeof...(u)) pr(" ");
  ps(u...);
}
void DBG() { cerr << "]" << endl; }
template <class T, class... U>
void DBG(const T& t, const U&... u) {
  cerr << to_string(t);
  if (sizeof...(u)) cerr << ", ";
  DBG(u...);
}
void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
  unsyncIO();
  setPrec();
  if (int((s).size())) setIn(s + ".in"), setOut(s + ".out");
}
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll modPow(ll x, ll n, ll MOD) {
  if (x == 0) return 0;
  if (n == 0) return 1;
  ll r = modPow(x * x % MOD, n / 2, MOD);
  if (n % 2 == 1) r = r * x % MOD;
  return r;
}
ll modInv(ll x, ll MOD) { return modPow(x, MOD - 2, MOD); }
void solve() {
  int n, m, rb, cb, rd, cd, p1;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p1;
  vi a;
  int p = 100 - p1;
  int dr = 1, dc = 1;
  for (int i = 0; i < 4 * (n - 1) * (m - 1); i++) {
    if (rd == rb || cd == cb) {
      a.push_back(p);
    } else {
      a.push_back(100);
    }
    int r = rb + dr, c = cb + dc;
    if (r < 1 || r > n) dr = -dr;
    if (c < 1 || c > m) dc = -dc;
    rb += dr, cb += dc;
  }
  int K = 4 * (m - 1) * (n - 1);
  vector<ll> P100(K + 1);
  for (int i = (0); i < (K + 1); ++i) {
    if (i == 0)
      P100[i] = 1;
    else
      P100[i] = P100[i - 1] * 100 % MOD;
  }
  pair<ll, ll> c = {1, 1};
  for (int i = K - 1; i >= 0; i--) {
    if (i > 0)
      c = {P100[K - i] + a[i] * c.first % MOD, a[i] * c.second % MOD};
    else
      c = {a[i] * c.first % MOD, a[i] * c.second % MOD};
    c.first %= MOD;
  }
  ll u = c.first, v = P100[K] - c.second;
  ll g = gcd(u, v);
  u /= g, v /= g;
  u %= MOD, v %= MOD;
  if (u < 0) u += MOD;
  if (v < 0) v += MOD;
  ll ans = u * modInv(v, MOD) % MOD;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
