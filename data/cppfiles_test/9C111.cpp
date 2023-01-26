#include <bits/stdc++.h>
using namespace std;
const long long int MOD = ((1e9) + 7);
const long long int INF = 1e18;
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
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long int>> a(n + 2, (vector<long long int>(m + 2, 0)));
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j < m; j++) {
      if (a[i][j] == 1 && a[i][j + 1] == 3) {
        a[i][j] = 2;
        a[i][j + 1] = 2;
      }
    }
  }
  while (k--) {
    long long int x;
    cin >> x;
    long long int p1 = 1;
    long long int p2 = x;
    while (a[p1][p2] != 0 && p2 > 0 && p2 <= m) {
      if (a[p1][p2] == 2)
        p1++;
      else if (a[p1][p2] == 1) {
        a[p1][p2] = 2;
        p2++;
      } else {
        a[p1][p2] = 2;
        p2--;
      }
    }
    cout << p2 << " ";
  }
  return 0;
}
