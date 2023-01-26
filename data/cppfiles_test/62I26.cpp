#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, q, dp[1003][1003][4], did[1003][1003], ans, num, xx, yy;
int go(int x, int y, int wt, int ox, int oy) {
  if (did[x][y] && (x != ox || y != oy)) return 0;
  if (x == n || y == m) return 0;
  if (wt == 0) return go(x + 1, y, 1, ox, oy) + 1;
  if (wt == 1) return go(x, y + 1, 0, ox, oy) + 1;
}
void rgo(int x, int y, int wt, int ox, int oy, int hm) {
  if (did[x][y] && (x != ox || y != oy)) {
    if (wt == 1) {
      if (did[ox][oy])
        ans -= hm * dp[x][y][1];
      else
        ans += hm * dp[x][y][1];
    } else {
      if (did[ox][oy])
        ans -= hm * dp[x][y][0];
      else
        ans += hm * dp[x][y][0];
    }
    return;
  }
  if (x == -1 || y == -1) return;
  if (wt == 0) rgo(x - 1, y, 1, ox, oy, hm);
  if (wt == 1) rgo(x, y - 1, 0, ox, oy, hm);
}
int main() {
  cin >> n >> m >> q;
  num = n * m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j][0] = 1;
      dp[i][j][1] = 1;
      if (i - 1 >= 0) dp[i][j][0] += dp[i - 1][j][1];
      if (j - 1 >= 0) dp[i][j][1] += dp[i][j - 1][0];
      ans += dp[i][j][0];
      ans += dp[i][j][1];
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    long long hm = go(x, y, 0, x, y);
    if (did[x][y])
      ans += hm * dp[x][y][1];
    else
      ans -= hm * dp[x][y][1];
    rgo(x, y, 1, x, y, hm);
    hm = go(x, y, 1, x, y);
    if (did[x][y])
      ans += hm * dp[x][y][0];
    else
      ans -= hm * dp[x][y][0];
    rgo(x, y, 0, x, y, hm);
    if (did[x][y])
      num++;
    else
      num--;
    did[x][y] ^= 1;
    cout << ans - num << endl;
  }
}
