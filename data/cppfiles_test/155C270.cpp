#include <bits/stdc++.h>
using namespace std;
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
void __print(char *x) { cerr << '\"' << x << '\"'; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T>
void __print(const T &x);
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void __print(stack<T> s) {
  int f = 0;
  cerr << '{';
  while (!s.empty()) cerr << (f++ ? "," : ""), __print(s.top()), s.pop();
  cerr << "}";
}
template <typename T>
void __print(queue<T> q) {
  int f = 0;
  cerr << '{';
  while (!q.empty()) cerr << (f++ ? "," : ""), __print(q.front()), q.pop();
  cerr << "}";
}
template <typename T, typename V>
void _print_a(T a, V sz) {
  int i = -1, f = 0;
  cerr << '[';
  while (++i < sz) cerr << (f++ ? "," : ""), __print(a[i]);
  cerr << "]";
}
template <typename T, typename V, typename... W>
void _print_a(T a, V sz, W... szs) {
  int i = -1, f = 0;
  cerr << '[';
  while (++i < sz) cerr << (f++ ? "," : ""), _print_a(a[i], szs...);
  cerr << "]";
}
using ld = long double;
using ll = long long;
constexpr long long MOD = 1e9 + 7;
constexpr long long inf = 1e16;
constexpr int MAX = 1e5 + 5;
void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }
  string s;
  cin >> s;
  vector<pair<ll, ll>> ans;
  for (ll i = 0; i < n; i++) {
    if (s[i] == '0') {
      ans.push_back({0, v[i]});
    } else {
      ans.push_back({1, v[i]});
    }
  }
  sort(ans.begin(), ans.end(), greater<pair<ll, ll>>());
  vector<ll> tag(n);
  ll val = n;
  for (auto x : ans) {
    ll ch = x.second;
    tag[ch - 1] = val;
    val--;
  }
  for (ll i = 0; i < n; i++) {
    cout << tag[v[i] - 1] << " ";
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int32_t t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
