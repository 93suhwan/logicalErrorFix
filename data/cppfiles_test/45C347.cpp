#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 1;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[0] == 1) {
      ans += 1;
    }
    for (int i = 1; i < n; i++) {
      if (a[i] == 1) {
        if (a[i - 1] == 1) ans += 4;
        ans += 1;
      } else if (a[i] == 0) {
        if (a[i - 1] == 0) {
          ans = -1;
          break;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
