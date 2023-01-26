#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const double PI = acos(-1.0);
void __print(long long x) { cerr << x; }
void __print(int32_t x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
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
  long long k;
  cin >> k;
  long long row = 1;
  for (long long i = 1; i <= (long long)1e5; i++) {
    if (k <= i * i) {
      break;
    }
    row++;
  }
  k -= (row - 1) * (row - 1);
  ;
  if (k <= row) {
    cout << k << " " << row << '\n';
  } else {
    k -= row;
    cout << row << " " << (row - k) << '\n';
  }
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
