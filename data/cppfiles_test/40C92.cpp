#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int p = 0; p < t; ++p) {
    int n;
    cin >> n;
    int d[2][n];
    for (int i = 0; i <= 1; ++i) {
      for (int j = 0; j < n; ++j) cin >> d[i][j];
    }
    if (n == 1)
      cout << 0 << endl;
    else {
      int suff[n], pref[n];
      suff[0] = 0;
      pref[0] = 0;
      for (int i = 1; i < n; ++i) {
        suff[i] = d[0][n - i] + suff[i - 1];
        pref[i] = d[1][i - 1] + pref[i - 1];
      }
      int res = 2e9;
      for (int i = 0; i < n; ++i) {
        res = min(res, max(suff[n - 1 - i], pref[i]));
      }
      cout << res << endl;
    }
  }
}
