#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dx = 1, dy = 1;
    int num = 0;
    while (rb != rd && cb != cd) {
      if (rb == n) dx = -dx;
      if (cb == m) dy = -dy;
      rb += dx;
      cb += dy;
      num++;
    }
    cout << num << '\n';
  }
}
