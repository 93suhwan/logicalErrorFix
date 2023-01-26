#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x, ans = 1e9;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int a1 = 0; a1 <= 1; a1++) {
      for (int a2 = 0; a2 <= 2; a2++) {
        int a3 = 0;
        for (int i = 0; i < n; i++) {
          if (a[i] % 3 == 0) {
            if (a1 && a2)
              a3 = max(a3, a[i] / 3 - 1);
            else
              a3 = max(a3, a[i] / 3);
          } else if (a[i] % 3 == 1) {
            if (a2 == 2)
              a3 = max(a3, a[i] / 3 - 1);
            else if (a1 == 1)
              a3 = max(a3, a[i] / 3);
            else {
              a3 = 1e9;
              break;
            }
          } else if (a[i] % 3 == 2) {
            if (a2)
              a3 = max(a3, a[i] / 3);
            else {
              a3 = 1e9;
              break;
            }
          }
        }
        ans = min(ans, a1 + a2 + a3);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
