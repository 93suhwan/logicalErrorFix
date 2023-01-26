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
  int a, b;
  cin >> a >> b;
  vector<int> ans;
  int tt = a + b;
  if (a == b) {
    for (int i = 0; i <= tt; i += 2) {
      ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (auto it : ans) {
      cout << it << " ";
    }
    cout << "\n";
  } else if (min(a, b) == 0) {
    cout << 2 << "\n";
    cout << (tt / 2) << " " << ceil(tt / 2.0) << "\n";
  } else {
    cout << tt + 1 << "\n";
    for (int i = 0; i <= tt; i++) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
