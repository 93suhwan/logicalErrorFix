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
  string s, t;
  cin >> s >> t;
  long long x = 0, y = 0, z = 0;
  string p;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') x++;
    if (s[i] == 'b') y++;
    if (s[i] == 'c') z++;
    if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c') p += s[i];
  }
  sort(s.begin(), s.end());
  if (x == 0 || y == 0 || z == 0) {
    cout << s << "\n";
    return;
  }
  sort(p.begin(), p.end());
  if (t[0] == 'a') {
    if (t[1] == 'b') {
      for (int i = 0; i < x; i++) cout << 'a';
      for (int i = 0; i < z; i++) cout << 'c';
      for (int i = 0; i < y; i++) cout << 'b';
      cout << p << "\n";
      return;
    } else {
      for (int i = 0; i < x; i++) cout << 'a';
      for (int i = 0; i < y; i++) cout << 'b';
      for (int i = 0; i < z; i++) cout << 'c';
      cout << p << "\n";
      return;
    }
  } else {
    sort(s.begin(), s.end());
    cout << s << "\n";
  }
}
int main() {
  int t;
  t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
