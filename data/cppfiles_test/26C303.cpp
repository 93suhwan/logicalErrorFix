#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  __print(x.first);
  cout << ',';
  __print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cout << '{';
  for (auto &i : x) cout << (first++ ? "," : ""), __print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long t;
  cin >> t;
  const int mod = 1e9 + 7;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= 2 * n; i++)
      if (i != 2) ans = (ans * i) % mod;
    cout << ans << endl;
  }
  return 0;
}
