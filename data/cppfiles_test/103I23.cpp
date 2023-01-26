#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
pair<int, int> out[N + 5][N + 5];
char a[N + 5][N + 5];
int n, m;
map<char, int> dir = {{'L', 0}, {'U', 1}, {'R', 2}, {'D', 3}};
int nx[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
pair<int, int> get(int x, int y) {
  if (x <= 0 || y <= 0 || x > n || y > n)
    return make_pair(-1, -1);
  else
    return make_pair(x, y);
}
int len[N + 5][N + 5];
bool vis[N + 5][N + 5];
int dfs(int x, int y, int step) {
  if (len[x][y] != -1) return len[x][y];
  if (out[x][y] == make_pair(-1, -1)) return len[x][y] = 0;
  if (vis[x][y]) return 0;
  vis[x][y] = 1;
  len[x][y] = dfs(out[x][y].first, out[x][y].second, step + 1) + 1;
  vis[x][y] = 0;
  return len[x][y];
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", a[i] + 1);
      for (int j = 1; j <= m; j++) {
        len[i][j] = -1;
        pair<int, int> temp =
            make_pair(i + nx[dir[a[i][j]]][0], j + nx[dir[a[i][j]]][1]);
        out[i][j] = temp;
      }
    }
    int ans = -1, x = 0, y = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        int d = dfs(i, j, 0);
        if (d > ans) {
          ans = d;
          x = i;
          y = j;
        }
      }
    printf("%d %d %d\n", x, y, ans);
  }
  return 0;
}
