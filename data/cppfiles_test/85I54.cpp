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
void inout() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  inout();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int c0 = 0;
    long long int c1 = 0;
    long long int n = s.size();
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '0')
        c0++;
      else
        c1++;
    }
    if (c0 == n) {
      cout << 1 << "\n";
      continue;
    }
    if (c1 == n) {
      cout << 0 << "\n";
      continue;
    }
    long long int c = 0;
    for (long long int i = 0; i < n - 1; i++) {
      if ((s[i] == '1' && s[i + 1] == '0') ||
          (s[i] == '0' && s[i + 1] == '1')) {
        c++;
        i++;
      }
    }
    if (c >= 2)
      cout << 2 << "\n";
    else
      cout << c << "\n";
  }
  return 0;
}
