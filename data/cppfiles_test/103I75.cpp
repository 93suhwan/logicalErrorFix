#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, m, cnt;
char g[N][N];
pair<int, int> path[N * N];
int dist[N][N], st[N][N];
int dfs(int first, int second) {
  path[++cnt] = {first, second};
  if (first < 1 || first > n || second < 1 || second > m || st[first][second])
    return dist[first][second];
  st[first][second] = 1;
  if (g[first][second] == 'U') dist[first][second] = dfs(first - 1, second) + 1;
  if (g[first][second] == 'D') dist[first][second] = dfs(first + 1, second) + 1;
  if (g[first][second] == 'L') dist[first][second] = dfs(first, second - 1) + 1;
  if (g[first][second] == 'R') dist[first][second] = dfs(first, second + 1) + 1;
  return dist[first][second];
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> g[i][j];
  for (int i = 0; i <= n + 5; i++)
    for (int j = 0; j <= m + 5; j++) st[i][j] = 0, dist[i][j] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!st[i][j]) {
        cnt = 0;
        dfs(i, j);
        pair<int, int> t = path[cnt];
        for (int k = 1; k <= cnt; k++) {
          if (path[k] == t) {
            for (int h = k; h <= cnt; h++)
              dist[path[h].first][path[h].second] = cnt - k;
          }
        }
      }
    }
  int first = 1, second = 1, res = dist[1][1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (dist[i][j] > res) {
        first = i, second = j, res = dist[i][j];
      }
    }
  cout << first << " " << second << " " << dist[first][second] << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}
