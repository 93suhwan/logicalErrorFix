#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return (string)s; }
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = (0); i < (int((v).size())); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
  string res;
  for (int i = (0); i < (SZ); ++i) res += char('0' + b[i]);
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void dbgOut() { cerr << "]" << endl; }
template <typename H, typename... T>
void dbgOut(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  dbgOut(t...);
}
const int MOD = 1e9 + 7;
ll madd(ll a, ll b) { return (a + b) % MOD; }
ll msub(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }
ll mmul(ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll mpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll minv(ll a) { return mpow(a, MOD - 2); }
ll mdiv(ll a, ll b) { return mmul(a, minv(b)); }
void solve() {
  ll n;
  cin >> n;
  ll m = mpow(2, n);
  m = msub(m, 2LL);
  ll z = mpow(4, m);
  ll ans = mmul(6LL, z);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
