#include <bits/stdc++.h>
using namespace std;
namespace kira {
template <class T>
using v = vector<T>;
template <class T>
using vv = vector<vector<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  long long f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long double pi = acos(-1.0);
const long long dx[4] = {0, 1, 0, -1};
const long long dy[4] = {1, 0, -1, 0};
const long long dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const long long dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const long long INF = (long long)1e18 + 100;
const long long MINF = (long long)-1e17 + 100;
const long long MOD = (long long)1e9 + 7;
}  // namespace kira
using namespace kira;
const long long N = (long long)(2e5 + 7);
void init() {}
void solve(long long test_case) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (i >= n / 2) {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
      } else {
        cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
      }
      return;
    }
  }
  cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
}
int32_t main() {
  long long tt = (long long)clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  init();
  long long t = 1;
  if (1) cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
