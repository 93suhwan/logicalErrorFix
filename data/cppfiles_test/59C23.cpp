#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, a, b, cnta, cntb, cntn, cntab, i, d[5][1010], j, q, jj;
  cin >> t;
  while (t--) {
    cin >> n;
    q = 0;
    for (i = 0; i < n; i++) {
      cin >> d[0][i] >> d[1][i] >> d[2][i] >> d[3][i] >> d[4][i];
    }
    for (jj = 0; jj < 4; jj++) {
      for (j = jj + 1; j < 5; j++) {
        cnta = 0;
        cntb = 0;
        cntab = 0;
        cntn = 0;
        if (j == jj) {
          j++;
        } else {
          for (i = 0; i < n; i++) {
            if (d[jj][i] == 1 && d[j][i] == 1) {
              cntab++;
            } else if (d[jj][i] == 1) {
              cnta++;
            } else if (d[j][i] == 1) {
              cntb++;
            } else {
              cntn++;
            }
          }
        }
        if (cnta <= n / 2 && cntb <= n / 2 && cntn == 0) {
          q = 2;
        } else if (q != 2) {
          q = 1;
        }
      }
    }
    if (q == 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
