#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int times[maxn][maxn], Time, cost[maxn][maxn], n, m;
string k[maxn];
int dfs(int x, int y) {
  if (!min(x, y) or x > n or y > m) return 0;
  times[x][y] = ++Time;
  int now = k[x][y - 1];
  int nextx, nexty;
  if (now == 'R')
    nextx = x, nexty = y + 1;
  else if (now == 'L')
    nextx = x, nexty = y - 1;
  else if (now == 'U')
    nextx = x - 1, nexty = y;
  else
    nextx = x + 1, nexty = y;
  if (times[nextx][nexty]) {
    cost[x][y] = Time - times[nextx][nexty] + 1;
    times[x][y] = 0;
    return cost[x][y] - 1;
  }
  int gg = dfs(nextx, nexty);
  if (!gg) {
    cost[x][y] = cost[nextx][nexty] + 1;
    times[x][y] = 0;
    return 0;
  } else {
    cost[x][y] = cost[nextx][nexty];
    times[x][y] = 0;
    return gg - 1;
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> k[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cost[i][j] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      Time = 0;
      if (!cost[i][j]) dfs(i, j);
    }
  }
  int ans = 0, ansx, ansy;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (cost[i][j] > ans) ans = cost[i][j], ansx = i, ansy = j;
  cout << ansx << " " << ansy << " " << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
  return 0;
}
