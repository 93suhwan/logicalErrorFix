#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, k, t, j, dc = 1, dr = 1, m, n, arr[101][101], count = 0;
  cin >> t;
  for (k = 0; k < t; k++) {
    cin >> m >> n >> a >> b >> c >> d;
    for (i = a, j = b;; i += dr, j += dc) {
      if (i == c || j == d)
        break;
      else if (i == m && j == n) {
        dr = -1;
        dc = -1;
        count++;
      } else if (i == m) {
        dr = -1;
        count++;
      } else if (j == n) {
        dc = -1;
        count++;
      } else
        count++;
    }
    cout << count << endl;
    count = 0;
    dc = 1;
    dr = 1;
  }
  return 0;
}
