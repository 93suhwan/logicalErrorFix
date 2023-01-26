#include <bits/stdc++.h>
using namespace std;
string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const int INF = 1e9 + 7;
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a ^ c) & 1)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
}
