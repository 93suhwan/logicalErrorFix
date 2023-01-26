#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 10;
const ll inf_ll = 1e18 + 10;
template <ll M>
struct modint {
  static ll _reduce(ll n) {
    constexpr static ll b = -1ull / M;
    ll r = n - (ll)(__uint128_t(b) * n >> 64) * M;
    return r >= M ? r - M : r;
  }
  static ll _pow(ll n, ll k) {
    ll r = 1;
    for (; k > 0; k >>= 1, n = _reduce(n * n))
      if (k & 1) r = _reduce(r * n);
    return r;
  }
  ll v;
  modint(ll n = 0) : v(_reduce(n)) { v += (M & (0 - (v < 0))); }
  friend string to_string(const modint n) { return to_string(n.v); }
  friend istream& operator>>(istream& i, modint& n) { return i >> n.v; }
  friend ostream& operator<<(ostream& o, const modint n) { return o << n.v; }
  template <typename T>
  explicit operator T() {
    return T(v);
  }
  friend bool operator==(const modint n, const modint m) { return n.v == m.v; }
  friend bool operator!=(const modint n, const modint m) { return n.v != m.v; }
  friend bool operator<(const modint n, const modint m) { return n.v < m.v; }
  friend bool operator<=(const modint n, const modint m) { return n.v <= m.v; }
  friend bool operator>(const modint n, const modint m) { return n.v > m.v; }
  friend bool operator>=(const modint n, const modint m) { return n.v >= m.v; }
  modint& operator+=(const modint n) {
    v += n.v;
    v -= (M & (0 - (v >= M)));
    return *this;
  }
  modint& operator-=(const modint n) {
    v -= n.v;
    v += (M & (0 - (v < 0)));
    return *this;
  }
  modint& operator*=(const modint n) {
    v = _reduce(v * n.v);
    return *this;
  }
  modint& operator/=(const modint n) {
    v = _reduce(v * _pow(n.v, M - 2));
    return *this;
  }
  friend modint operator+(const modint n, const modint m) {
    return modint(n) += m;
  }
  friend modint operator-(const modint n, const modint m) {
    return modint(n) -= m;
  }
  friend modint operator*(const modint n, const modint m) {
    return modint(n) *= m;
  }
  friend modint operator/(const modint n, const modint m) {
    return modint(n) /= m;
  }
  modint& operator++() { return *this += 1; }
  modint& operator--() { return *this -= 1; }
  modint operator++(int) {
    modint t = *this;
    return *this += 1, t;
  }
  modint operator--(int) {
    modint t = *this;
    return *this -= 1, t;
  }
  modint operator+() { return *this; }
  modint operator-() { return modint(0) -= *this; }
  modint pow(const ll k) const {
    return k < 0 ? _pow(v, M - 1 - (-k % (M - 1))) : _pow(v, k);
  }
  modint inv() const { return _pow(v, M - 2); }
};
template <typename T>
struct fenwick {
  int length;
  vector<T> tree;
  fenwick(int size) {
    length = size + 1;
    tree.assign(length + 1, 0);
  }
  fenwick(vector<T>& v) {
    length = v.size() + 1;
    tree.assign(length + 1, 0);
    for (int i = 0; i < v.size(); i++) update(i, v[i]);
  }
  void update(int i, T val) {
    i++;
    while (i < length) {
      tree[i] += val;
      i += i & -i;
    }
  }
  T prefix(int i) {
    i++;
    T out = 0;
    while (i > 0) {
      out += tree[i];
      i -= i & -i;
    }
    return out;
  }
  T query(int a, int b) { return prefix(b) - prefix(a - 1); }
};
using mod = modint<int(1e9 + 7)>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<array<ll, 2>> v(n);
  vector<ll> a(2 * n, -1);
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    a[x] = y, a[y] = x;
    v[i] = {x, y};
  }
  vector<mod> dp(2 * n), p(2 * n + 1);
  fenwick<mod> f(2 * n + 1);
  for (int i = 2 * n - 1; i >= 0; i--) {
    if (a[i] > i) {
      dp[i] = 1 + f.query(i + 1, a[i]);
      f.update(a[i], dp[i]);
    }
  }
  0;
  ll t;
  cin >> t;
  vector<ll> s(t);
  mod ans = 0;
  for (int i = 0; i < t; i++) {
    cin >> s[i], s[i]--;
    0;
    ans += dp[v[s[i]][0]];
  }
  cout << ans << "\n";
}
