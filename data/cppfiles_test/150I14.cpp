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
    int m1 = 0, p1 = 0, i, j, n, f = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x > 3) {
        m1 = max(m1, x / 3);
        a[x % 3] = 1;
      } else
        a[x] = 1;
      if (x == 1) f = 1;
    }
    if (a[3]) {
      if (a[2] || a[1])
        p1 = 2;
      else
        p1 = 1;
    } else if (a[2]) {
      if (a[1])
        p1 = 2;
      else
        p1 = 1;
    } else
      p1 = 1;
    if (a[2] && a[1] && !f) p1--;
    cout << m1 + p1 << endl;
  }
  return 0;
}
