#include <bits/stdc++.h>
using namespace std;
int solve() {
  int row, col, k;
  cin >> row >> col >> k;
  if (k != 0 && col <= 1) return 0;
  if (2 * k == row * col) {
    return (col % 2 == 0) ? 1 : 0;
  } else if (row <= 1)
    return 0;
  if (row % 2 == 1) {
    if ((col / 2) > k)
      return 0;
    else {
      row--;
      k -= (col / 2);
    }
  } else if (col % 2 == 1)
    col--;
  if (2 * k > row * col) return 0;
  if (k % 2 == 0) return 1;
  return 0;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int loop = 1; loop <= t; loop++) {
    int as = solve();
    if (as)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
