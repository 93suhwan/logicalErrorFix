#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 2e9, mxn = 1e6 + 5;
void solve() {
  int n, m, addx = 0, addy = 0, mnx = 0, mxx = 0, mny = 0, mxy = 0, x, y;
  cin >> n >> m;
  x = n, y = m;
  string second;
  cin >> second;
  for (int i = 0; i < (int)(second).size(); ++i) {
    if (second[i] == 'L' || second[i] == 'R') {
      addx += (second[i] == 'R');
      addx -= (second[i] == 'L');
    } else {
      addy += (second[i] == 'U');
      addy -= (second[i] == 'D');
    }
    mxx = max(mxx, addx);
    mnx = min(addx, mnx);
    mxy = max(mxy, addy);
    mny = min(addy, mny);
    if (mxy < n && mxx < m && -mny < n && -mnx < m && mxx - mnx < m &&
        mxy - mny < n) {
      x = m - mxx;
      y = mxy + 1;
    } else {
      break;
    }
  }
  cout << y << ' ' << x << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
