#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int ans = 0;
    int i = 1, j = 1;
    while (rb != rd || cb != cd) {
      if (rb == rd || cb == cd) break;
      if (rb == n) i = -1;
      if (cb == m) j = -1;
      rb += i;
      cb += j;
      ans++;
      if (rb == rd || cb == cd) break;
    }
    cout << ans << endl;
  }
}
