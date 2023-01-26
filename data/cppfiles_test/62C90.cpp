#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
int dp[1111][1111][2];
int mx[2] = {0, 1};
int my[2] = {1, 0};
struct node {
  int x, y, step, dir, type;
};
int n, m, q;
int mp[1111][1111];
int bfs(int x, int y, int type, int dir) {
  int step = 1;
  while (1) {
    if (type)
      y += dir;
    else
      x += dir;
    if (x >= 1 && x <= n && y >= 1 && y <= m && !mp[x][y])
      step++, type ^= 1;
    else
      return step;
  }
}
void solve() {
  cin >> n >> m >> q;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j][0] = dp[i][j - 1][1] + 1;
      dp[i][j][1] = dp[i - 1][j][0] + 1;
      ans += dp[i][j][0] + dp[i][j][1] - 1;
    }
  }
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int cnt1 = bfs(x, y, 1, 1), cnt2 = bfs(x, y, 0, -1);
    int cnt3 = bfs(x, y, 0, 1), cnt4 = bfs(x, y, 1, -1);
    mp[x][y] ^= 1;
    int now = cnt1 * cnt2 + cnt3 * cnt4 - 1;
    if (mp[x][y])
      ans -= now;
    else
      ans += now;
    printf("%lld\n", ans);
  }
}
int main(int argc, char const *argv[]) {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
