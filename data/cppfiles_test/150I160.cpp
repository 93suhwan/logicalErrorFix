#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int a[10];
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
      if (f) {
        int js = ma % 3;
        ans = ma / 3 + 2;
        if (js == 0) {
          ans--;
        }
      } else {
        int js = max((ma - 4) / 3, (ma - 2) / 3);
        if (js == 0 && a[3]) ++js;
        ans = js + 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
