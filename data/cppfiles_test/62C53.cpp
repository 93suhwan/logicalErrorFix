#include <bits/stdc++.h>
using namespace std;
bool vis[1000 + 1][1000 + 1];
long long n, m, ans;
void Add(long long x, long long y, long long d) {
  long long cnt1 = 1, cnt2 = 1, cnt3 = 1, cnt4 = 1, sx = x, sy = y;
  for (long long op = 0;; op ^= 1) {
    if (!op)
      sx++;
    else
      sy++;
    if (sx > n || sy > m || !vis[sx][sy])
      break;
    else
      cnt1++;
  }
  sx = x, sy = y;
  for (long long op = 1;; op ^= 1) {
    if (!op)
      sx++;
    else
      sy++;
    if (sx > n || sy > m || !vis[sx][sy])
      break;
    else
      cnt2++;
  }
  sx = x, sy = y;
  for (long long op = 0;; op ^= 1) {
    if (!op)
      sx--;
    else
      sy--;
    if (sx < 1 || sy < 1 || !vis[sx][sy])
      break;
    else
      cnt3++;
  }
  sx = x, sy = y;
  for (long long op = 1;; op ^= 1) {
    if (!op)
      sx--;
    else
      sy--;
    if (sx < 1 || sy < 1 || !vis[sx][sy])
      break;
    else
      cnt4++;
  }
  ans += (cnt1 * cnt4 + cnt2 * cnt3 - 1) * d;
  return;
}
signed main() {
  long long q, x, y;
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j) vis[i][j] = 1;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j)
      ans += min(2 * (m - j + 1) - 1, 2 * (n - i + 1)) +
             min(2 * (m - j + 1), 2 * (n - i + 1) - 1) - 1;
  while (q--) {
    cin >> x >> y;
    if (!vis[x][y])
      vis[x][y] = 1, Add(x, y, 1);
    else
      vis[x][y] = 0, Add(x, y, -1);
    cout << ans << endl;
  }
  return 0;
}
