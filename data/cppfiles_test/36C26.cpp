#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
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
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a"
         << "\n";
    return;
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) cout << "a";
    cout << "b";
    for (int i = n / 2; i < n - 1; i++) cout << "a";
  } else {
    cout << "c";
    n--;
    for (int i = 0; i < n / 2; i++) cout << "a";
    cout << "b";
    for (int i = n / 2; i < n - 1; i++) cout << "a";
  }
  cout << "\n";
}
int main() {
  int t;
  t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
