#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mn = INT_MAX;
    for (int i = 0; i <= 3; ++i) {
      for (int j = 0; j <= 3; ++j) {
        int mx = INT_MIN;
        bool ok = true;
        for (int k = 0; k < n; ++k) {
          int mnn = INT_MAX;
          for (int e = 0; e <= i; ++e) {
            for (int d = 0; d <= j; ++d) {
              int l = a[k] - e - 2 * d;
              if (l >= 0 && l % 3 == 0) {
                mnn = min(mnn, l / 3);
              }
            }
          }
          if (mnn < INT_MAX)
            mx = max(mx, i + j + mnn);
          else
            ok = false;
        }
        if (ok) mn = min(mn, mx);
      }
    }
    cout << mn << endl;
  }
}
