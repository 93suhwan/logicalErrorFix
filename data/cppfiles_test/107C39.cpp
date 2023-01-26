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
using pi = pair<ll, ll>;
using vi = vc<ll>;
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
template <ll i, class T>
void print_tuple(ostream&, const T&) {}
template <ll i, class T, class H, class... Args>
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
void print(t x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(ll n, ll off = 0) {
  vi v(n);
  for (ll i = ll(0); i < ll(n); i++) v[i] = read() + off;
  return v;
}
pi readpi(ll off = 0) {
  ll first, second;
  cin >> first >> second;
  return pi(first + off, second + off);
}
template <class t, class u>
void print(const pair<t, u>& p, ll suc = 1) {
  print(p.first, 2);
  print(p.second, suc);
}
template <class T>
void print(const vector<T>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i], i == ll(v.size()) - 1 ? suc : 2);
}
template <class T>
void print_offset(const vector<T>& v, ll off, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i] + off, i == ll(v.size()) - 1 ? suc : 2);
}
template <class T, size_t N>
void print(const array<T, N>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(N); i++) print(v[i], i == ll(N) - 1 ? suc : 2);
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
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
ll botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
ll mask(ll i) { return (ll(1) << i) - 1; }
bool inc(ll first, ll second, ll c) { return first <= second && second <= c; }
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
  for (ll i = ll(0); i < ll(ll(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
ll lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
vvc<ll> readGraph(ll n, ll m) {
  vvc<ll> g(n);
  for (ll i = ll(0); i < ll(m); i++) {
    ll first, second;
    cin >> first >> second;
    first--;
    second--;
    g[first].push_back(second);
    g[second].push_back(first);
  }
  return g;
}
vvc<ll> readTree(ll n) { return readGraph(n, n - 1); }
ll sgn(ll first) { return first > 0 ? 1 : (first < 0 ? -1 : 0); }
ll rabs(pi first) { return max(abs(first.first), abs(first.second)); }
pi add(pi first, pi second) {
  return pi(first.first + second.first, first.second + second.second);
}
pi sub(pi first, pi second) {
  return pi(first.first - second.first, first.second - second.second);
}
ll crs(pi first, pi second) {
  return first.first * second.second - first.second * second.first;
}
ll ccw(pi first, pi second) { return sgn(crs(first, second)); }
ll ccw(pi first, pi second, pi c) {
  return sgn(crs(sub(second, first), sub(c, first)));
}
ll tri2(pi first, pi second, pi c) {
  return abs(crs(sub(second, first), sub(c, first)));
}
ll area2(const vc<pi>& vs) {
  ll res = 0;
  for (ll i = ll(0); i < ll(ll(vs.size())); i++) {
    ll j = (i + 1) % ll(vs.size());
    res += crs(vs[i], vs[j]);
  }
  return res;
}
ll argtype(pi first) {
  if (sgn(first.second) == 0) return first.first < 0 ? 1 : 0;
  return first.second < 0 ? 0 : 1;
}
ll argcmp(pi first, pi second) {
  ll at = argtype(first), bt = argtype(second);
  if (at != bt) return at < bt ? -1 : 1;
  return -ccw(first, second);
}
bool argless(pi first, pi second) { return argcmp(first, second) < 0; }
const ll nmax = 205;
ll val[nmax][nmax][nmax];
pi dp[nmax][nmax];
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll n, tar;
  cin >> n >> tar;
  vc<pi> ps(n);
  for (ll i = ll(0); i < ll(n); i++) ps[i] = readpi();
  for (ll i = ll(0); i < ll(n); i++)
    for (ll j = ll(0); j < ll(n); j++)
      for (ll k = ll(0); k < ll(n); k++)
        val[i][j][k] = tri2(ps[i], ps[j], ps[k]);
  for (ll i = ll(0); i < ll(n); i++) dp[i][(i + 1) % n] = pi(0, 0);
  ll lw = 0, up = 1LL << 60;
  while (up - lw > 1) {
    const ll mid = (lw + up) / 2;
    for (ll w = ll(2); w < ll(n + 1); w++) {
      for (ll i = ll(0); i < ll(n); i++) {
        ll j = (i + w) % n;
        ll x = i, y = (i + 1) % n;
        dp[i][j] = dp[y][j];
        dp[i][j].second += val[i][y][j];
        if (dp[i][j].second >= mid) {
          dp[i][j].first++;
          dp[i][j].second = 0;
        }
        while (y != j) {
          x++;
          y++;
          if (x == n) x = 0;
          if (y == n) y = 0;
          pi p = dp[i][x], q = dp[x][j];
          pi r(p.first + q.first, p.second + q.second + val[i][x][j]);
          if (r.second >= mid) {
            r.first++;
            r.second = 0;
          }
          chmax(dp[i][j], r);
        }
      }
    }
    if (dp[0][0].first >= tar + 1)
      lw = mid;
    else
      up = mid;
  }
  cout << lw << endl;
}
