#include <bits/stdc++.h>
using namespace std;
void io() {}
void solve() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int hor = 0, ver = 0;
  int l = 0, r = 0, u = 0, d = 0;
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
  }
  cout << u + 1 << " " << l + 1 << endl;
}
int main() {
  io();
  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }
}
