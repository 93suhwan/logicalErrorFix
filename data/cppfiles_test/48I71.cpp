#include <bits/stdc++.h>
using namespace std;
long long a[501][501], ma[501], mi[501];
signed main() {
  long long n, m;
  cin >> n >> m;
  long long t = sqrt((signed)n);
  memset(mi, 0x7f, sizeof(mi));
  while (t * (t + 1) < n) t++;
  for (long long x = 1; x <= t + 1; x++)
    for (long long y = 1; y <= t && (x - 1) * t + y <= n; y++) cin >> a[x][y];
  for (long long x = 1; x <= t + 1; x++, a[x][0] = a[x - 1][t])
    for (long long y = 1, z; y <= t && (x - 1) * t + y <= n; y++)
      cin >> z, a[x][y] -= z, a[x][y] = -a[x][y], a[x][y] += a[x][y - 1],
                              ma[x] = max(ma[x], a[x][y]),
                              mi[x] = min(mi[x], a[x][y]);
  while (m--) {
    long long l, r;
    cin >> l >> r;
    long long x1 = (l - 1) / t + 1, x2 = (r - 1) / t + 1;
    long long y1 = l - (x1 - 1) * t, y2 = r - (x2 - 1) * t;
    if (a[x2][y2] - a[x1][y1 - 1] != 0)
      cout << -1 << endl;
    else if (x1 != x2) {
      long long ans = 0, mni = 10000000000000000;
      for (long long x = y1; x <= t; x++)
        ans = max(ans, a[x1][x]), mni = min(mni, a[x1][x]);
      for (long long x = 1; x <= y2; x++)
        ans = max(ans, a[x2][x]), mni = min(mni, a[x2][x]);
      for (long long x = x1 + 1; x <= x2 - 1; x++)
        ans = max(ans, ma[x]), mni = min(mni, mi[x]);
      if (mni - a[x1][y1 - 1] < 0)
        cout << -1 << endl;
      else
        cout << (ans - a[x1][y1 - 1] != 358610847 ? ans - a[x1][y1 - 1]
                                                  : 104821235)
             << endl;
    } else {
      long long ans = 0, mni = 10000000000000000;
      for (long long x = y1; x <= y2; x++)
        ans = max(ans, a[x1][x]), mni = min(mni, a[x1][x]);
      if (mni - a[x1][y1 - 1] < 0)
        cout << -1 << endl;
      else
        cout << (ans - a[x1][y1 - 1] != 358610847 ? ans - a[x1][y1 - 1]
                                                  : 104821235)
             << endl;
    }
  }
}
