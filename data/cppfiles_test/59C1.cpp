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
const ll nmax = 1005;
ll par[nmax];
ll first[nmax], second[nmax];
vi g[nmax];
ll cur, num;
bool used[nmax], preu[nmax];
void goup(ll v) {
  while (!used[v]) {
    used[v] = true;
    cur += second[v];
    v = par[v];
    num++;
  }
}
void dfs(ll v, ll p, ll sum) {
  assert(par[v] < 0);
  par[v] = p;
  for (auto to : g[v])
    if (to != p && sum >= first[to]) {
      if (par[to] == -1) {
        dfs(to, v, sum + second[to]);
      } else {
        goup(v);
      }
    }
}
void slv() {
  ll n, m;
  cin >> n >> m;
  for (ll i = ll(1); i < ll(n); i++) cin >> first[i];
  for (ll i = ll(1); i < ll(n); i++) cin >> second[i];
  for (ll i = ll(0); i < ll(n); i++) g[i].clear();
  for (ll i = ll(0); i < ll(m); i++) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  ll lw = -1, up = ten(9) + 1;
  while (up - lw > 1) {
    const ll mid = (lw + up) / 2;
    cur = mid;
    num = 1;
    for (ll i = ll(0); i < ll(n); i++) used[i] = false;
    used[0] = 1;
    while (num < n) {
      for (ll i = ll(0); i < ll(n); i++) preu[i] = used[i];
      for (ll i = ll(0); i < ll(n); i++) par[i] = preu[i] ? -2 : -1;
      ll tmp = num;
      for (ll i = ll(0); i < ll(n); i++)
        if (preu[i]) {
          dfs(i, -2, cur);
        }
      if (num == tmp) break;
    }
    if (num == n)
      up = mid;
    else
      lw = mid;
  }
  print(up + 1);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll t;
  cin >> t;
  for (ll _ = ll(0); _ < ll(t); _++) slv();
}
