#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int a[N], pos[35], vis[N], n;
int main() {
  register int T;
  scanf("%d", &T);
  while (T--) {
    memset(pos, 0, sizeof pos), memset(vis, 0, sizeof vis);
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (register int i = 1; i <= n; ++i)
      for (register int j = 0; j <= 30; ++j)
        if ((a[i] & (1 << j))) ++pos[j];
    register int cnt = 0;
    for (register int i = 30; i >= 0; --i) {
      if (!pos[i]) continue;
      ++cnt;
      for (register int j = 1; j <= sqrt(pos[i]); ++j)
        if (!(pos[i] % j)) {
          ++vis[j];
          if (pos[i] / j != j) ++vis[pos[i] / j];
        }
    }
    for (register int i = 1; i <= n; i++)
      if (vis[i] == cnt) printf("%d%c", i, i == n ? 10 : 32);
  }
  getchar(), getchar();
  return 0;
}
