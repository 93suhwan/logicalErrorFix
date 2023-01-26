#include <bits/stdc++.h>
using namespace std;
void _io() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int MAXN = 200005;
const long long mod = 1e9 + 7;
long long c, d;
inline bool solve(int cs) {
  cin >> c >> d;
  if ((c + d) & 1)
    cout << "-1\n";
  else if (c == d) {
    if (c == 0)
      cout << "0\n";
    else
      cout << "1\n";
  } else {
    cout << "2\n";
  }
  return true;
}
void _init() {}
int main() {
  _init();
  _io();
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) solve(t);
  return 0;
}
