#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
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
void helper(vector<int> &v, int x) {
  for (int i = x; i < v.size() - 1; i += 2) {
    if (v[i] > v[i + 1]) {
      swap(v[i], v[i + 1]);
    }
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (is_sorted(v.begin(), v.end())) {
      break;
    }
    cnt++;
    if (i % 2 == 0)
      helper(v, 2);
    else
      helper(v, 1);
  }
  cout << cnt << endl;
  return;
}
signed main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
