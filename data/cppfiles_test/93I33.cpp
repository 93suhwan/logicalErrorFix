#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1e9;
const long long linf = 1e18;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(char x) { cerr << '\'' << x << '\''; }
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
void Solve() {
  long long n, k;
  cin >> n >> k;
  long long temp = log2(k) + 1;
  long long ans = (temp) + ceil((float)(n - (1 << temp)) / k);
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long Testcase = 1;
  cin >> Testcase;
  while (Testcase--) Solve();
  return 0;
}
