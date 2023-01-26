#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << x; }
void __print(const char *x) { cerr << x; }
void __print(const string &x) { cerr << x; }
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
  int f = 0;
  cerr << '{';
  for (auto &i : x) {
    cerr << (f++ ? ", " : "");
    __print(i);
  }
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) {
    cerr << ", ";
  }
  _print(v...);
}
const long long int MAX_N = 1e5 + 5;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9;
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long int> res(m + 1, 0);
  for (long long int i = 1; i < n; i++) {
    for (long long int j = 1; j < m; j++) {
      if (a[i][j - 1] == 'X' && a[i - 1][j] == 'X') {
        res[j] = 1;
      }
    }
  }
  for (long long int j = 1; j < m + 1; j++) {
    res[j] += res[j - 1];
  }
  long long int q;
  cin >> q;
  long long int x, y;
  for (long long int i = 0; i < q; i++) {
    cin >> x >> y;
    x--;
    y--;
    cout << ((res[y] - res[x] == 0) ? "YES" : "NO") << "\n";
    ;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  cout << fixed;
  long long int t = 1;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
