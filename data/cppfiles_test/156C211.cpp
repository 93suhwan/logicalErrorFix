#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, k, a[200002], s = 0, i;
    cin >> n >> k;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    sort(a, a + n);
    if (k >= s) {
      cout << 0 << endl;
      continue;
    }
    long long x = k / n, p = 1, stp = 0, t = 1;
    x = min(x, a[0]);
    stp = a[0] - x;
    s -= stp;
    for (i = n - 1; i > 0; i--) {
      if (s <= k) break;
      while (a[i] - x < t) {
        x--;
        stp++;
        s -= t;
        if (s <= k) break;
      }
      if (s <= k) break;
      t++;
      stp++;
      s -= a[i] - x;
      if (s <= k) break;
    }
    cout << stp << endl;
  }
  return 0;
}
