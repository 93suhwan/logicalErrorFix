#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int odd = 0;
    for (int i = 0; i < n; i++) odd += (a[i] % 2);
    int even = n - odd;
    if (abs(even - odd) > 1)
      cout << -1 << '\n';
    else {
      long long ans1 = 0, ans2 = 0;
      if (odd == (n + 1) / 2) {
        for (int i = 0, pos = 0; i < n; i++) {
          if (a[i] % 2 == 1) {
            ans1 += abs(i - pos);
            pos += 2;
          }
        }
      }
      if (even == (n + 1) / 2) {
        for (int i = 0, pos = 0; i < n; i++) {
          if (a[i] % 2 == 0) {
            ans2 += abs(i - pos);
            pos += 2;
          }
        }
        if (ans1 == 0 || ans2 < ans1) ans1 = ans2;
      }
      cout << ans1 << '\n';
    }
  }
  return 0;
}
