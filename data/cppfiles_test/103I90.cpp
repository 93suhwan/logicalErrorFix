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
bool vis[N + 5][N + 5], loop[N + 5][N + 5];
int dfs(int x, int y) {
  if (len[x][y] != -1) return len[x][y];
  if (out[x][y] == make_pair(-1, -1)) return len[x][y] = 0;
  if (vis[x][y]) {
    pair<int, int> temp = out[x][y];
    int loop_len = 1;
    while (temp != make_pair(x, y)) {
      loop[temp.first][temp.second] = 1;
      loop_len++;
      temp = out[temp.first][temp.second];
    }
    temp = out[x][y];
    while (temp != make_pair(x, y)) {
      len[temp.first][temp.second] = loop_len;
      temp = out[temp.first][temp.second];
    }
    return len[x][y] = loop_len;
  }
  vis[x][y] = 1;
  int d = dfs(out[x][y].first, out[x][y].second);
  vis[x][y] = 0;
  if (len[x][y] != -1)
    return len[x][y];
  else
    return len[x][y] = d + 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", a[i] + 1);
      for (int j = 1; j <= m; j++) {
        loop[i][j] = 0;
        len[i][j] = -1;
        pair<int, int> temp =
            make_pair(i + nx[dir[a[i][j]]][0], j + nx[dir[a[i][j]]][1]);
        out[i][j] = temp;
      }
    }
    int ans = -1, x = 0, y = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        int d = dfs(i, j);
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
