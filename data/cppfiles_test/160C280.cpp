#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  int dx = 1, dy = 1;
  int ans = 0;
  while (rb != rd && cb != cd) {
    rb = rb + dx;
    cb = cb + dy;
    if (rb > n) {
      rb -= 2;
      dx = -dx;
    }
    if (rb < 1) {
      rb += 2;
      dx = -dx;
    }
    if (cb > m) {
      cb -= 2;
      dy = -dy;
    }
    if (cb < 1) {
      cb += 2;
      dy = -dy;
    }
    ans++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
