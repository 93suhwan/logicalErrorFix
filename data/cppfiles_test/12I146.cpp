#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
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
template <typename T, typename U>
T mymax(T &a, U b) {
  if (a < b) a = b;
  return a;
}
template <typename T, typename U>
T mymin(T &a, U b) {
  if (a > b) a = b;
  return a;
}
const int MXN = 2 * 1e5 + 5;
typedef complex<long long> P;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  bool ok = 1;
  if (n % 2 == 1) {
    int each_row = m / 2;
    if (k % each_row == 0 && (k / each_row) & 1) {
      cout << "YES\n";
      ok = 0;
    }
    int od = k / each_row;
    if (od % 2 == 0) od--;
    int left = k - each_row * od;
    if (left % 2 == 0) {
      cout << "YES\n";
      ok = 0;
    }
    if (ok) cout << "NO\n";
  } else if (k % 2 == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  for (int i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}
