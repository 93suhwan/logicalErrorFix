#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a[105];
    long long ans = 0;
    int n, k, max;
    cin >> n >> k;
    for (int j = 1; j <= n; j++) {
      cin >> a[j];
    }
    for (int l = 1; l <= k; l++) {
      int maxnumber = 0;
      sort(a + 1, a + n + 1);
      max = a[n];
      for (int j = n; a[j] == a[n]; j--) {
        maxnumber++;
      }
      int secondmax;
      if (n - maxnumber > 0) {
        secondmax = a[n - maxnumber];
      } else {
        secondmax = max - 2;
      }
      if (max - secondmax >= 2 && maxnumber >= 2) {
        ans += 1;
        a[n] = 0;
        a[n - 1] = 0;
      } else if (a[n - 2] != 0 && (a[n - 3] / a[n - 2] > a[n - 1] / a[n])) {
        a[n - maxnumber - 1] = 0;
        a[n] = 0;
      } else {
        a[n - maxnumber] = 0;
        a[n] = 0;
      }
    }
    for (int j = 1; j <= n; j++) {
      ans = ans + a[j];
    }
    cout << ans << endl;
  }
}
