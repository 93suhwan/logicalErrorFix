#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m;
int dist[N][N];
char g[N][N];
bool st[N][N];
pair<int, int> p[N * N];
int cnt;
int dfs(int first, int second) {
  p[++cnt] = {first, second};
  if (first < 1 || first > n || second < 1 || second > m || st[first][second])
    return dist[first][second];
  st[first][second] = true;
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
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!st[i][j]) {
        cnt = 0;
        dfs(i, j);
        pair<int, int> t = p[cnt];
        for (int k = 1; k < cnt; k++) {
          if (p[k] == t) {
            for (int h = k; h <= cnt; h++)
              dist[p[h].first][p[h].second] = cnt - k;
          }
        }
      }
    }
  int first = 1, second = 1, res = dist[first][second];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (dist[i][j] > res) {
        first = i, second = j, res = dist[i][j];
      }
    }
  cout << first << " " << second << " " << res << '\n';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) st[i][j] = false, dist[i][j] = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
}
