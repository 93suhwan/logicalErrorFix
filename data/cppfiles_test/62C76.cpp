#include <bits/stdc++.h>
using namespace std;
bool mp[1005][1005];
int n, m;
int dfs(int x, int y, int dx, int dy) {
  if (x < 1 || y < 1 || x > n || y > m) {
    return 1;
  }
  if (mp[x][y]) {
    return 1;
  }
  return dfs(x + dx, y + dy, dy, dx) + 1;
}
int main() {
  int i, j, q, x, y;
  int up, dwn, lft, rgt;
  long long ans = 0;
  scanf("%d%d%d", &n, &m, &q);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      ans += 1ll + 4ll * min(n - i, m - j);
      if (n - i != m - j) {
        ans++;
      }
    }
  }
  while (q--) {
    scanf("%d%d", &x, &y);
    up = dfs(x - 1, y, 0, -1);
    lft = dfs(x, y - 1, -1, 0);
    dwn = dfs(x + 1, y, 0, 1);
    rgt = dfs(x, y + 1, 1, 0);
    if (mp[x][y]) {
      ans += 1ll * lft * dwn + 1ll * up * rgt - 1ll;
    } else {
      ans -= 1ll * lft * dwn + 1ll * up * rgt - 1ll;
    }
    printf("%lld\n", ans);
    mp[x][y] = !mp[x][y];
  }
  return 0;
}
