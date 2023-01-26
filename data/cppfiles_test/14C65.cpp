#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
template <typename T, typename U>
void amin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void amax(T &a, U b) {
  if (a < b) a = b;
}
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
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(const T &t, const V &...v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int N = 1e5 + 10;
void solve() {
  ll n;
  cin >> n;
  map<ll, ll> id;
  vector<ll> a(n), b(n);
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    id[a[i]] = i;
  }
  b = a;
  sort((b).begin(), (b).end());
  vector<pair<pair<ll, ll>, ll>> res;
  ll begin = 0;
  ;
  ;
  for (ll i = 0; i < n; ++i) {
    if (a[i] == b[i]) continue;
    ll id = 0;
    for (ll j = i + 1; j < n; ++j) {
      if (a[j] == b[i]) {
        id = j;
        break;
      }
    };
    for (ll j = id - 1; j >= begin; --j) {
      a[j + 1] = a[j];
    }
    a[i] = b[i];
    begin++;
    res.push_back({{i + 1, id + 1}, id - i});
  }
  cout << (ll)res.size() << "\n";
  for (ll i = 0; i < (ll)res.size(); ++i) {
    cout << res[i].first.first << " " << res[i].first.second << " "
         << res[i].second << "\n";
  }
}
signed main() {
  setIO();
  ll t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
