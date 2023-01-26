#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';
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
  cerr << '[';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "]";
}
void _print() { cerr << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mi = INT_MAX;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
    mx = max(mx, a[i]);
  }
  vector<int> b = a;
  reverse(b.begin(), b.end());
  if (mi == mx) {
    cout << 0 << nl;
    return;
  }
  if (a.back() == mx) {
    cout << 0 << nl;
    return;
  }
  if (a.back() == mi) {
    cout << 2 << nl;
  } else {
    cout << 1 << nl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
