#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long double EPS = 5e-8;
const ll MOD = 1000000007;
template <typename T>
inline void print_vector(vector<T> &a) {
  for (auto &x : a) cout << x << ' ';
  cout << '\n';
}
inline ll binary_pow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
inline ll mod_pow(ll x, ll y, ll m = MOD) {
  ll res = 1;
  x = x % m;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % m;
    y = y >> 1;
    x = (x * x) % m;
  }
  return res;
}
inline ll mod_add(ll a, ll b, ll m = MOD) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
inline ll mod_mul(ll a, ll b, ll m = MOD) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
inline ll mod_sub(ll a, ll b, ll m = MOD) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
inline ll mminvprime(ll a, ll b) { return mod_pow(a, b - 2, b); }
inline ll mod_div(ll a, ll b, ll m = MOD) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
inline ll ceilf(ll x, ll y) { return x % y == 0 ? x / y : x / y + 1; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
bool cmp(const pair<ll, ll> &l, const pair<ll, ll> &r) {
  return l.first < r.first;
}
void test_case() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> ans, a;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(&cmp)> pq(cmp);
  for (int i = 1; i <= n; i++) {
    ll foo;
    cin >> foo;
    if (foo > 0) pq.push({foo, i});
  }
  while (pq.size() > 1) {
    auto f = pq.top();
    pq.pop();
    auto s = pq.top();
    pq.pop();
    --f.first;
    --s.first;
    ans.push_back({f.second, s.second});
    if (f.first > 0) pq.push(f);
    if (s.first > 0) pq.push(s);
  }
  cout << ans.size() << '\n';
  for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    test_case();
  }
  return 0;
}
