#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using ld = long double;
template <typename T>
void _(const char* s, T h) {
  cerr << s << " = " << h << "\n";
}
template <typename T, typename... Ts>
void _(const char* s, T h, Ts... t) {
  int b = 0;
  while (((b += *s == '(') -= *s == ')') != 0 || *s != ',') cerr << *s++;
  cerr << " = " << h << ",";
  _(s + 1, t...);
}
struct init {
  init() {
    cin.tie(0);
    iostream::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(5);
  }
  ~init() {}
} init;
template <typename T, typename U>
void upx(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
void upn(T& x, U y) {
  if (x > y) x = y;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll D = 4, dx[] = {+1, 0, -1, 0}, dy[] = {0, +1, 0, -1};
const ll N = 101010;
const int32_t M = 998244353;
int32_t rev(int32_t x, int32_t m) {
  if (x == 1) return 1;
  return (1 - (ll)rev(m % x, x) * m) / x + m;
}
struct modint {
  int32_t x;
  modint() : x(0) {}
  modint(int32_t xx) : x(xx % M) {
    if (x < 0) x += M;
  }
  modint(ll xx) : x(xx % M) {
    if (x < 0) x += M;
  }
  modint& operator+=(modint b) {
    if ((x += b.x) >= M) x -= M;
    return *this;
  }
  modint operator+(modint b) {
    modint res = *this;
    res += b;
    return res;
  }
  modint& operator-=(modint b) {
    if ((x -= b.x) < 0) x += M;
    return *this;
  }
  modint operator-(modint b) {
    modint res = *this;
    res -= b;
    return res;
  }
  modint& operator*=(modint b) {
    x = (ll)x * b.x % M;
    return *this;
  }
  modint operator*(modint b) {
    modint res = *this;
    res *= b;
    return res;
  }
  modint inverse() { return rev(x, M); }
  modint& operator/=(modint b) {
    x = (ll)x * rev(b.x, M) % M;
    return *this;
  }
  modint operator/(modint b) {
    modint res = *this;
    res /= b;
    return res;
  }
  modint operator^(ll w) {
    modint r = 1, a = *this;
    while (w) {
      if (w & 1) r *= a;
      a *= a;
      w /= 2;
    }
    return r;
  }
  modint operator^=(ll w) { return *this = (*this) ^ w; }
  modint operator^(modint w) { return *this ^ w.x; }
  modint operator^=(modint w) { return *this = (*this) ^ w; }
  modint operator-() const { return modint() - *this; }
  explicit operator bool() const { return x; }
  bool operator==(const modint& b) const { return x == b.x; }
  bool operator!=(const modint& b) const { return x != b.x; }
};
istream& operator>>(istream& is, modint& p) {
  istream& res = is >> p.x;
  p.x %= M;
  return res;
}
ostream& operator<<(ostream& os, modint p) { return os << p.x; }
template <typename T>
modint operator+(T x, modint y) {
  return modint(x) + y;
}
template <typename T>
modint operator-(T x, modint y) {
  return modint(x) - y;
}
template <typename T>
modint operator*(T x, modint y) {
  return modint(x) * y;
}
template <typename T>
modint operator/(T x, modint y) {
  return modint(x) / y;
}
template <typename T>
modint operator^(T x, modint y) {
  return modint(x) ^ y;
}
modint abs(modint x) { return x; }
using mint = modint;
struct qwe {
  mint a, b;
};
qwe mod[N * 4];
mint t[N * 4];
mint len[N];
mint ewq(mint x, qwe m) { return m.a * x + m.b; }
qwe ewq(qwe inner, qwe outer) {
  return {inner.a * outer.a, outer.a * inner.b + outer.b};
}
ll sh = 1;
void apply(ll v, qwe x) {
  t[v] = ewq(t[v], x);
  mod[v] = ewq(mod[v], x);
}
void push(ll v) {
  apply(v + v, mod[v]);
  apply(v + v + 1, mod[v]);
  mod[v] = {1, 0};
}
void recalc(ll v) { t[v] = t[v + v] + t[v + v + 1]; }
void build(ll n, ll a0) {
  while (sh < n) sh *= 2;
  for (ll i = 0; i < (sh + sh); ++i) t[i] = 0;
  for (ll i = 0; i < (sh + sh); ++i) mod[i] = {1, 0};
  for (ll i = 0; i < (a0 + 1); ++i) t[i + sh] = len[i];
  for (ll i = sh - 1; i > 0; --i) recalc(i);
}
void cha(ll v, ll tl, ll tr, ll l, ll r, qwe val) {
  push(v);
  if (l <= tl && tr <= r) {
    apply(v, val);
    return;
  }
  ll tm = (tl + tr) / 2;
  if (tm >= l) cha(v + v, tl, tm, l, r, val);
  if (tm + 1 <= r) cha(v + v + 1, tm + 1, tr, l, r, val);
  recalc(v);
}
void cha(ll l, ll r, qwe val) {
  if (l > r) return;
  cha(1, 0, sh - 1, l, r, val);
}
ll a[N];
ll al[N];
int32_t main() {
  ll n;
  cin >> n;
  for (ll i = 0; i < (n); ++i) cin >> a[i];
  for (ll i = 0; i < (n); ++i) al[i] = a[i];
  sort(al, al + n);
  ll m = unique(al, al + n) - al;
  mint last = 0;
  for (ll i = 0; i < (m); ++i) {
    len[i] = al[i] - last;
    last = al[i];
  }
  ll a0 = lower_bound(al, al + m, a[0]) - al;
  build(m, a0);
  for (ll i = 1; i < n; ++i) {
    ll ai = lower_bound(al, al + m, a[i]) - al;
    ll ai1 = lower_bound(al, al + m, a[i - 1]) - al;
    mint tot = t[1];
    if (a[i] > a[i - 1]) {
      cha(ai1 + 1, ai, qwe{0, tot});
      cha(0, ai1, qwe{a[i - 1] - 1, 0});
    } else {
      cha(ai + 1, sh - 1, qwe{0, 0});
      cha(0, ai, qwe{a[i - 1] - 1, 0});
    }
  }
  cout << t[1] << '\n';
  return 0;
}
