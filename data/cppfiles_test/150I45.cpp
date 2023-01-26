#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int a[10], q[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(a, 0, sizeof(a));
    int m1 = 0, p1 = 0, i, j, n, f = 0, ma = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
      int x;
      cin >> x;
      q[i] = x;
      if (x > 3) {
        m1 = max(m1, x / 3);
        a[x % 3] = 1;
      } else {
        a[x] = 1;
      }
      if (x == 1) f = 1;
      ma = max(ma, x);
    }
    int ans = 0;
    if (!a[1] && !a[2]) {
      ans = ma / 3;
    } else if (!a[1] && a[2]) {
      ans = ma / 3 + 1;
    } else if (a[1] && !a[2]) {
      ans = ma / 3 + 1;
    } else {
      int js = 0;
      for (i = 1; i <= n; i++) {
        if (q[i] % 3 == 1) {
          js = max(js, (q[i] - 1) / 3);
        } else if (a[i] % 3 == 2) {
          js = max(js, (q[i] - 2) / 3);
        } else {
          js = max(js, (q[i]) / 3 - 1);
        }
      }
      ans = js + 2;
      js = 0;
      for (i = 1; i <= n; i++) {
        if (q[i] % 3 == 1) {
          js = max(js, (q[i] - 4) / 3);
        } else if (a[i] % 3 == 2) {
          js = max(js, (q[i] - 2) / 3);
        } else {
          js = max(js, (q[i]) / 3);
        }
      }
      ans = min(ans, js + 2);
    }
    cout << ans << endl;
  }
  return 0;
}
