#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void __print(long long x) { cerr << x; }
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
  long long f = 0;
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
void solve() {
  long long w1, h1;
  cin >> w1 >> h1;
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long w, h;
  cin >> w >> h;
  long long ans = INT_MAX;
  if (w + abs(x1 - x2) > w1 && h + abs(y1 - y2) > h1) {
    cout << -1 << "\n";
    return;
  }
  if (w + abs(x1 - x2) <= w1) {
    long long avlb_x = max(w1 - x2, x1);
    if (w <= avlb_x) {
      cout << 0 << "\n";
      return;
    } else {
      ans = min(ans, w - avlb_x);
    }
  }
  if (h + abs(y1 - y2) <= h1) {
    long long avlb_y = max(h1 - y2, y1);
    if (h <= avlb_y) {
      cout << 0 << "\n";
      return;
    } else {
      ans = min(ans, h - avlb_y);
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  cout << setprecision(10) << "\n";
  while (t--) {
    solve();
  }
}
