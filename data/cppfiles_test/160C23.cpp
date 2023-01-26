#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dx = 1, dy = 1;
    int count = 0;
    while (rb != rd && cb != cd) {
      count++;
      if ((rb == n && dy == 1) || (rb == 1 && dy == -1)) dy *= -1;
      if ((cb == m && dx == 1) || (cb == 1 && dx == -1)) dx *= -1;
      rb += dy;
      cb += dx;
    }
    cout << count << endl;
  }
  return 0;
}
