#include <bits/stdc++.h>
int a[200002] = {0};
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    int x = n;
    int ans = 0;
    int max = 0, flag = 1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] > max) max = a[i];
    }
    while (flag) {
      for (int i = x; i >= 1; i--) {
        if (a[n] == max) {
          flag = 0;
          break;
        } else if (a[i] > a[n]) {
          a[n] = a[i];
          x = i;
          ans++;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
