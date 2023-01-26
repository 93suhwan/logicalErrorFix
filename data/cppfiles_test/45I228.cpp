#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int odd = 0;
    for (int i = 0; i < n; i++) odd += (a[i] % 2);
    int even = n - odd;
    if (odd > (n + 1) / 2 || even > (n + 1) / 2)
      cout << -1 << '\n';
    else {
      int epos = 0, opos = 1, ans1 = 0, ans2 = 0;
      if (odd == (n + 1) / 2) {
        for (int i = 0; i < n; i++) {
          if (a[i] % 2 == 1) {
            ans1 += abs(epos - i);
            ans2 += abs(opos - i);
            epos += 2;
            opos += 2;
          }
        }
      } else {
        for (int i = 0; i < n; i++) {
          if (a[i] % 2 == 0) {
            ans1 += abs(epos - i);
            ans2 += abs(opos - i);
            epos += 2;
            opos += 2;
          }
        }
      }
      cout << min(ans1, ans2) << '\n';
    }
  }
  return 0;
}
