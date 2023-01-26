#include <bits/stdc++.h>
using namespace std;
long long cnt[1005][1005][2];
bool vis[1005][1005];
long long n, m, ans;
long long getadd(long long x, long long y, int dir) {
  if (x >= n || y >= m) return 0;
  if (vis[x][y]) return 0;
  if (dir == 0) return getadd(x, y + 1, 1) + 1;
  return getadd(x + 1, y, 0) + 1;
}
void dfs(long long x, long long y, long long k, int dir) {
  if (x < 0 || y < 0) return;
  if (vis[x][y]) return;
  if (dir == 0) {
    cnt[x][y][0] += k;
    ans += k;
    dfs(x - 1, y, k, 1);
  } else {
    cnt[x][y][1] += k;
    ans += k;
    dfs(x, y - 1, k, 0);
  }
}
int main() {
  long long i, j, q, x, y, k0, k1;
  scanf("%lld%lld%lld", &n, &m, &q);
  ans = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cnt[i][j][0] = min(n - i, m - j) * 2 - 1;
      cnt[i][j][1] = min(n - i, m - j) * 2 - 1;
      if (n - i > m - j) cnt[i][j][1]++;
      if (n - i < m - j) cnt[i][j][0]++;
      ans += cnt[i][j][0] + cnt[i][j][1] - 1;
    }
  }
  while (q--) {
    scanf("%lld%lld", &x, &y);
    if (vis[x - 1][y - 1]) {
      vis[x - 1][y - 1] = false;
      k1 = getadd(x - 1, y - 1, 0);
      k0 = getadd(x - 1, y - 1, 1);
      dfs(x - 1, y - 1, k1, 0);
      dfs(x - 1, y - 1, k0, 1);
      ans--;
    } else {
      k0 = cnt[x - 1][y - 1][0];
      k1 = cnt[x - 1][y - 1][1];
      cnt[x - 1][y - 1][0] = 0;
      cnt[x - 1][y - 1][1] = 0;
      ans -= k0 + k1 - 1;
      dfs(x - 1, y - 2, -k1, 0);
      dfs(x - 2, y - 1, -k0, 1);
      vis[x - 1][y - 1] = true;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
