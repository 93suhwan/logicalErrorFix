#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int cx = 0, cy = 0, lx = 0, ly = 0, hx = 0, hy = 0;
  for (char c : s) {
    if (c == 'U') {
      --cy;
    } else if (c == 'D') {
      ++cy;
    } else if (c == 'L') {
      --cx;
    } else {
      ++cx;
    }
    if (max(cx, hx) - min(cx, lx) + 1 > m or
        max(cy, hy) - min(cy, ly) + 1 > n) {
      cout << -ly + 1 << ' ' << -lx + 1;
      return;
    }
    hx = max(hx, cx);
    hy = max(hy, cy);
    lx = min(lx, cx);
    ly = min(ly, cy);
  }
  cout << -ly + 1 << ' ' << -lx + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
