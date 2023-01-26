#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
int n, m, a[N], top, s[N], lc[N], rc[N], sz[N];
long long f[N][N];
void dfs(int x) {
  if (!x) return;
  int l = lc[x], r = rc[x];
  sz[x] = 1, dfs(l), dfs(r), sz[x] += sz[l] + sz[r];
  for (int i = 0; i <= min(sz[l], m); i++)
    for (int j = 0; j <= min(sz[r], m); j++) {
      int w = f[l][i] + f[r][j];
      f[x][i + j] = max(f[x][i + j], w - 1ll * a[x] * i * j * 2);
      f[x][i + j + 1] =
          max(f[x][i + j + 1],
              w + 1ll * a[x] * m - 1ll * a[x] * ((i + 1) * (j + 1) * 2 - 1));
    }
}
signed main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    while (top && a[s[top]] > a[i]) lc[i] = s[top--];
    if (top) rc[s[top]] = i;
    s[++top] = i;
  }
  dfs(s[1]), printf("%lld\n", f[s[1]][m]);
  return 0;
}
