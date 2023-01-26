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
  int tt = a + b;
  int temp = 2 * min(a, b);
  int left = (tt - temp);
  int mx = ceil(left / 2.0);
  int mn = left / 2;
  set<int> s;
  if (temp != 0) {
    for (int i = 0; i <= temp; i += 2) {
      s.insert(i);
    }
    for (int i = 0; i <= temp; i += 2) {
      s.insert(mx + i);
      s.insert(mn + i);
    }
  } else {
    s.insert(mn);
    s.insert(mx);
  }
  cout << s.size() << "\n";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << "\n";
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
