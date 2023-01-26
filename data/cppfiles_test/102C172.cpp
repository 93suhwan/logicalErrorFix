#include <bits/stdc++.h>
using namespace std;
void io() {}
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int hor = 0, ver = 0;
  int l = 0, r = 0, u = 0, d = 0;
  int a = 1, b = 1;
  for (auto it : s) {
    if (it == 'U') {
      ver--;
      if (ver < 0) u = max(u, -1 * ver);
    }
    if (it == 'D') {
      ver++;
      d = max(d, ver);
    }
    if (it == 'L') {
      hor--;
      if (hor < 0) l = max(l, -1 * hor);
    }
    if (it == 'R') {
      hor++;
      r = max(r, hor);
    }
    if (l + r + 1 <= m && u + d + 1 <= n) {
      a = u + 1, b = l + 1;
    }
  }
  cout << a << " " << b << endl;
}
int main() {
  io();
  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }
}
