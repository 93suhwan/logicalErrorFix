#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  int dc, dr;
  dc = dr = 1;
  int t = 0;
  while (true) {
    if (rb == rd || cb == cd) break;
    if (rb == n) dr = -1;
    if (rb == 1) dr == 1;
    if (cb == m) dc = -1;
    if (cb == 1) dc == 1;
    rb += dr;
    cb += dc;
    t++;
  }
  cout << t << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
