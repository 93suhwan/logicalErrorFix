#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
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
void _print() { cerr << "]\n "; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  string s;
  cin >> s;
  unordered_set<char> red, green, white;
  bool toggle = 0;
  long long r = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (toggle) {
      if (red.find(s[i]) == red.end()) {
        red.insert(s[i]);
        r++;
        toggle = 0;
      } else if (green.find(s[i]) == green.end()) {
        green.insert(s[i]);
      } else if (white.find(s[i]) == white.end()) {
        white.insert(s[i]);
      } else {
        break;
      }
    } else {
      if (green.find(s[i]) == green.end()) {
        green.insert(s[i]);
        toggle = 1;
      } else if (red.find(s[i]) == red.end()) {
        red.insert(s[i]);
        r++;
      } else if (white.find(s[i]) == white.end()) {
        white.insert(s[i]);
      } else {
        break;
      }
    }
  };
  cout << r;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
    cout << "\n";
  }
  return 0;
}
