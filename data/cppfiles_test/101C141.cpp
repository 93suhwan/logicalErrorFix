#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int inf = 9e18;
void __print(long long int x) { cerr << x; }
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
  long long int f = 0;
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
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a;
  for (long long int i = 0; i < n; ++i) {
    long long int x;
    cin >> x;
    a.push_back(x);
  }
  string s;
  cin >> s;
  vector<pair<long long int, char>> v;
  for (long long int i = 0; i < n; ++i) {
    v.push_back({a[i], s[i]});
  }
  sort(v.begin(), v.end());
  bool ok = true;
  long long int bcnt = 0;
  long long int rcnt = n;
  for (long long int i = 1; i <= n; ++i) {
    if (v[i - 1].second == 'B') ++bcnt;
    if (v[i - 1].second == 'B' && v[i - 1].first < bcnt) {
      ok = false;
      break;
    }
  }
  for (long long int i = n; i >= 1; --i) {
    if (v[i - 1].second == 'R') --rcnt;
    if (v[i - 1].second == 'R' && v[i - 1].first > (rcnt + 1)) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
