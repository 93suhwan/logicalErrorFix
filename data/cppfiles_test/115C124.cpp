#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
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
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> arr(n);
  for (auto &u : arr) cin >> u;
  long long low = 0, high = h, ans = 0;
  ;
  auto cost = [&](long long k) {
    long long val = k;
    for (long long i = 0; i < arr.size() - 1; i++) {
      val += min(k, arr[i + 1] - arr[i]);
    }
    return val;
  };
  while (high >= low) {
    long long mid = low + (high - low) / 2;
    ;
    if (cost(mid) >= h) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
