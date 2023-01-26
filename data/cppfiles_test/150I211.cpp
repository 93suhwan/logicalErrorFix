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
      m1 = max(m1, x / 3);
      a[x % 3] = 1;
      if (x == 1) f = 1;
      ma = max(ma, x);
    }
    int ans = 0;
    if (!a[1] && !a[2]) {
      ans = m1;
    } else if (!a[1] && a[2]) {
      ans = m1 + 1;
    } else if (a[1] && !a[2]) {
      ans = m1 + 1;
    } else {
      ans = m1 + 1 + f;
      if (ma == 3) ans--;
    }
    cout << ans << endl;
  }
  return 0;
}
