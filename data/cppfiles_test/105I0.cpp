#include <bits/stdc++.h>
using namespace std;
const int MX = 3003;
int t, n, i, j, len, num, prv, cur, pos, now, a[MX], b[MX], f[MX][MX];
vector<int> g[MX];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) g[i].clear();
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      b[i] = g[a[i]].size();
      g[a[i]].push_back(i);
    }
    for (len = 1; len < n; len++)
      for (i = 1; i + len <= n; i++) {
        j = i + len;
        f[i][j] = max(f[i + 1][j], f[i][j - 1]);
        num = g[a[i]].size();
        cur = 0;
        prv = i;
        for (pos = b[i] + 1; pos < num && (now = g[a[i]][pos]) <= j; pos++) {
          cur += f[prv + 1][now - 1] + 1;
          f[i][j] = max(f[i][j], cur + (now < j ? f[now + 1][j] : 0));
          prv = now;
        }
      }
    printf("%d\n", n - 1 - f[1][n]);
  }
  return 0;
}
