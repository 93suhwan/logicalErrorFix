#include <bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
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
  string a, s;
  cin >> a >> s;
  string b;
  bool flag = true;
  int i = a.length(), j = s.length();
  while (i > 0 && j > 0) {
    if (s.back() >= a.back()) {
      b = to_string(s.back() - a.back()) + b;
      s.pop_back();
      a.pop_back();
      i--, j--;
    } else {
      b = to_string(10 + s.back() - a.back()) + b;
      s.pop_back();
      a.pop_back();
      i--, j--;
      if (s.empty() || s.back() != '1') {
        b = "-1";
        flag = false;
        break;
      }
      s.pop_back();
      j--;
    }
  }
  if (i > 0 && j == 0) {
    b = "-1";
  }
  if (j > 0 && flag) {
    b = s + b;
  }
  while (b[0] == '0') {
    b = b.substr(1);
  }
  cout << b << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
