#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
void __print(long long x) { cerr << x; }
void __print(int32_t x) { cerr << x; }
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
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long N = 2e5 + 5;
const long long INF = 1000111000111000111LL;
const long double EPS = 1e-12;
const long double PI = 3.141592653589793116;
bool can(long long c1, long long c2, long long c3, long long n) {
  long long val = n / 3;
  if (val >= 0 && val <= c3) {
    long long num = n - val * 3;
    for (long long i = 0; i <= c1; i++) {
      for (long long j = 0; j <= c2; j++) {
        if (i + 2 * j == num) {
          return true;
        }
      }
    }
  }
  val--;
  if (val >= 0 && val <= c3) {
    long long num = n - val * 3;
    for (long long i = 0; i <= c1; i++) {
      for (long long j = 0; j <= c2; j++) {
        if (i + 2 * j == num) {
          return true;
        }
      }
    }
  }
  val--;
  if (val >= 0 && val <= c3) {
    long long num = n - val * 3;
    for (long long i = 0; i <= c1; i++) {
      for (long long j = 0; j <= c2; j++) {
        if (i + 2 * j == num) {
          return true;
        }
      }
    }
  }
  return false;
}
void solve_test() {
  long long ans = INF;
  long long n;
  cin >> n;
  long long mx = 0;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
  }
  for (long long c3 = mx / 3 + 1; c3 >= max(0LL, mx / 3 - 2); c3--) {
    for (long long c2 = 0; c2 <= 3; c2++) {
      for (long long c1 = 0; c1 <= 3; c1++) {
        bool ok = true;
        for (long long i = 0; i < n; i++) {
          ok &= can(c1, c2, c3, a[i]);
        }
        if (ok) {
          ans = min(ans, c1 + c2 + c3);
        }
      }
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  std::ios_base::sync_with_stdio(0);
  cout.tie(nullptr);
  long long T;
  cin >> T;
  for (long long tc = 1; tc <= T; tc++) {
    solve_test();
  }
  return 0;
}
