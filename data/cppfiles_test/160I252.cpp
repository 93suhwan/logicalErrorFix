#include <bits/stdc++.h>
int MOD = 1000000007;
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int t = 0;
    int golr = 1, goud = 1;
    if (rb == n) goud *= -1;
    if (cb == m) golr *= -1;
    while (rb != rd && cb != cd) {
      if (golr < 0 && goud < 0) {
        int x = min(abs(rb - 1), abs(cb - 1));
        if ((rb - x <= rd || cb - x <= cd) && cb > cd && rb > rd) {
          t += min(abs(rb - rd), abs(cb - cd));
          break;
        } else {
          rb += goud * x;
          cb += golr * x;
          t += x;
        }
      } else if (golr > 0 && goud < 0) {
        int x = min(abs(rb - 1), abs(cb - m));
        if ((rb - x <= rd || cb + x >= cd) && cb < cd && rb > rd) {
          t += min(abs(rb - rd), abs(cb - cd));
          break;
        } else {
          rb += goud * x;
          cb += golr * x;
          t += x;
        }
      } else if (golr < 0 && goud > 0) {
        int x = min(abs(rb - n), abs(cb - 1));
        if ((rb + x >= rd || cb - x <= cd) && cb > cd && rb < rd) {
          t += min(abs(rb - rd), abs(cb - cd));
          break;
        } else {
          rb += goud * x;
          cb += golr * x;
          t += x;
        }
      } else {
        int x = min(abs(rb - n), abs(cb - m));
        if ((rb + x >= rd || cb + x >= cd) && cb < cd && rb < rd) {
          t += min(abs(rb - rd), abs(cb - cd));
          break;
        } else {
          rb += goud * x;
          cb += golr * x;
          t += x;
        }
      }
      if (rb == n || rb == 1) goud *= -1;
      if (cb == m || cb == 1) golr *= -1;
    }
    cout << t << '\n';
  }
  return 0;
}
