#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool *a = new bool[n];
    int ans = 1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int daysWithoutWatered = 0;
    for (int i = 0; i < n && daysWithoutWatered < 2; i++) {
      if (a[i]) {
        daysWithoutWatered = 0;
        if (i > 0 && a[i - 1]) {
          ans += 5;
        } else {
          ans++;
        }
      } else {
        daysWithoutWatered++;
        if (daysWithoutWatered >= 2) ans = -1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
