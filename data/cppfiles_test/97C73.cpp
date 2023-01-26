#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int n, m, ans[505][505];
bool a[505][505];
char s[505];
vector<pair<int, int>> to[505][505];
void dfs(int i, int j) {
  for (auto [x, y] : to[i][j]) {
    if (ans[x][y] == ans[i][j]) {
      puts("NO");
      exit(0);
    }
    if (ans[x][y] != -1) continue;
    ans[x][y] = 5 - ans[i][j], dfs(x, y);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++)
      if (s[j] == 'X') a[i][j] = 1;
  }
  memset(ans, -1, sizeof ans);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j]) {
        vector<pair<int, int>> b;
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (!a[x][y]) b.push_back(make_pair(x, y));
        }
        if (b.size() & 1) {
          puts("NO");
          return 0;
        }
        while (!b.empty()) {
          auto [x, y] = b.back();
          b.pop_back();
          auto [z, w] = b.back();
          b.pop_back();
          to[x][y].push_back(make_pair(z, w));
          to[z][w].push_back(make_pair(x, y));
        }
      }
  memset(ans, -1, sizeof ans);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (ans[i][j] == -1 && !a[i][j]) ans[i][j] = 1, dfs(i, j);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j]) {
        ans[i][j] = 0;
        for (int k = 0; k < 4; k++)
          if (!a[i + dx[k]][j + dy[k]]) ans[i][j] += ans[i + dx[k]][j + dy[k]];
      }
  puts("YES");
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) printf("%d%c", ans[i][j], " \n"[j == m]);
}
