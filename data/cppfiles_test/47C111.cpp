#include <bits/stdc++.h>
using namespace std;
constexpr int log2(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
bool umin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool umax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
using ll = long long;
using ld = long double;
using str = string;
const int inf = (int)1e9 + 5;
const ll infl = (ll)1e18 + 5;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename vector>
void __print(const pair<T, vector> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... vector>
void _print(T t, vector... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
ll n, k;
ll go(vector<ll> &v) {
  sort((v).begin(), (v).end());
  ll n1 = (ll)(v).size();
  ll ans = 0;
  if (n1 == 0) return ans;
  bool ok = 0;
  for (ll i = n1 - 1; i > -1; i -= k) {
    ans += 2 * v[i];
  }
  ans -= v.back();
  return ans;
}
void solve() {
  cin >> n >> k;
  vector<ll> a, b;
  for (ll i = 0; i < (n); ++i) {
    ll t;
    cin >> t;
    if (t > 0)
      a.emplace_back(t);
    else if (t < 0)
      b.emplace_back(-t);
  }
  ll ans = go(a) + go(b);
  if ((ll)(a).size() && (ll)(b).size()) {
    ans += min(a.back(), b.back());
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) solve();
}
