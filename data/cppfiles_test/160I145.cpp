#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  if (rb == rd || cb == cd) {
    cout << 0 << "\n";
    return;
  }
  int time = 0;
  int row = 0, col = 0;
  if (rb < rd) {
    row = rd - rb;
  } else {
    row = 2 * m - rb - rd;
  }
  if (cb < cd) {
    col = cd - cb;
  } else {
    col = 2 * m - cb - cd;
  }
  cout << min(row, col) << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
