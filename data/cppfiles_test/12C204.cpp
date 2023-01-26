#include <bits/stdc++.h>
using namespace std;
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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, k;
    cin >> n >> m >> k;
    int r1 = n % 2;
    int r2 = m % 2;
    if (r2) {
      int maxi = (n * (m - 1)) / 2;
      if (k <= maxi && (k % 2) == 0) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    } else if (r1) {
      int maxi = (m * (n - 1)) / 2;
      k = ((n * m) / 2) - k;
      if (k <= maxi && (k % 2) == 0) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    } else {
      int maxi = (m * n) / 2;
      if (k <= maxi && (k % 2) == 0) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }
    }
  }
  return 0;
}
