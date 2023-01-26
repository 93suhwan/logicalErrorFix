#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
void tostring(pair<A, B> p) {
  cerr << "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class A>
void tostring(A v) {
  int f = 1;
  string r = "{";
  for (auto& x : v) {
    if (!f) {
      r += ", ";
    }
    f = 0;
    r += to_string(x);
  }
  r += "}\n";
  cerr << r;
}
void _out() { cerr << '\n'; }
template <typename H, typename... T>
void _out(H h, T... t) {
  cerr << ' ' << h;
  _out(t...);
}
void show() { cerr << '\n'; }
template <typename H, typename... T>
void show(H h, T... t) {
  cerr << h << ' ';
  show(t...);
}
void solve(int tase) {
  int n;
  cin >> n;
  if (n % 10 < 9)
    cout << n / 10 << '\n';
  else
    cout << n / 10 + 1 << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int i = (int)(1); i <= (int)(T); i++) solve(i);
}
