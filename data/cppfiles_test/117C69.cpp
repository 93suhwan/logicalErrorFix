#include <bits/stdc++.h>
using namespace std;
int T, n, m, sx, sy, dx[11] = {0, 1, 0, -1}, dy[11] = {1, 0, -1, 0};
char c;
vector<int> vis[1000007];
vector<char> v[1000007];
bool cnt(int x, int y) {
  int res = 0;
  for (int i = 0; i < 4; i++)
    res += (v[x + dx[i]][y + dy[i]] == '#' || v[x + dx[i]][y + dy[i]] == '+' ||
            v[x + dx[i]][y + dy[i]] == 'L');
  return res <= 2;
}
void dfs(int x, int y) {
  if (v[x][y] == '#') return;
  if (vis[x][y]) return;
  if (cnt(x, y) && v[x][y] != 'L') return;
  vis[x][y] = 1;
  if (x != sx || y != sy) v[x][y] = '+';
  for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
  return;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> m;
    c = getchar();
    for (int i = 0; i <= m + 1; i++)
      v[0].push_back('#'), v[n + 1].push_back('#');
    for (int i = 1; i <= n; i++) {
      v[i].push_back('#');
      vis[i].push_back(0);
      for (int j = 1; j <= m; j++) {
        vis[i].push_back(0);
        c = getchar();
        if (c == 'L') sx = i, sy = j;
        v[i].push_back(c);
      }
      c = getchar();
      vis[i].push_back(0);
      v[i].push_back('#');
    }
    dfs(sx, sy);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) printf("%c", v[i][j]);
      printf("\n");
    }
    for (int i = 0; i <= n + 1; i++) v[i].clear(), vis[i].clear();
  }
  return 0;
}
