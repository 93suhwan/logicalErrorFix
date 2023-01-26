#include <bits/stdc++.h>
std::vector<int> a[500005];
int n, m, col[500005], ans[505][505], f[505][505];
int read() {
  char ch = getchar();
  if (ch == '.' || ch == 'X') return ch == 'X';
  return read();
}
int t(int x, int y) { return (x - 1) * m + y; }
std::pair<int, int> it(int id) {
  return std::make_pair((id - 1) / m + 1, (id - 1) % m + 1);
}
void add(int x, int y) {
  a[x].push_back(y);
  a[y].push_back(x);
}
void dfs(int v) {
  for (int i = 0; i < (int)a[v].size(); i++) {
    int u = a[v][i];
    if (col[u] != -1) continue;
    col[u] = 1 - col[v];
    dfs(u);
  }
}
int getans(int x, int y) {
  int s = 0;
  if (!f[x + 1][y]) s = s + ans[x + 1][y];
  if (!f[x - 1][y]) s = s + ans[x - 1][y];
  if (!f[x][y + 1]) s = s + ans[x][y + 1];
  if (!f[x][y - 1]) s = s + ans[x][y - 1];
  return s;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) f[i][j] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!f[i][j]) {
        col[t(i, j)] = -1;
        continue;
      }
      int cnt = 0;
      if (!f[i + 1][j]) ++cnt;
      if (!f[i - 1][j]) ++cnt;
      if (!f[i][j + 1]) ++cnt;
      if (!f[i][j - 1]) ++cnt;
      if (cnt == 1 || cnt == 3) return puts("NO"), 0;
      if (!cnt) continue;
      if (cnt == 2) {
        int p1 = 0, p2 = 0;
        if (!f[i + 1][j]) !p1 ? p1 = t(i + 1, j) : p2 = t(i + 1, j);
        if (!f[i][j + 1]) !p1 ? p1 = t(i, j + 1) : p2 = t(i, j + 1);
        if (!f[i - 1][j]) !p1 ? p1 = t(i - 1, j) : p2 = t(i - 1, j);
        if (!f[i][j - 1]) !p1 ? p1 = t(i, j - 1) : p2 = t(i, j - 1);
        add(p1, p2);
      } else if (cnt == 4) {
        add(t(i + 1, j), t(i, j + 1));
        add(t(i + 1, j), t(i, j - 1));
        add(t(i - 1, j), t(i, j + 1));
        add(t(i - 1, j), t(i, j - 1));
      }
    }
  for (int i = 1; i <= n * m; i++)
    if (col[i] == -1) col[i] = 0, dfs(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!f[i][j]) ans[i][j] = (col[t(i, j)] ? 1 : 4);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (f[i][j]) ans[i][j] = getans(i, j);
  puts("YES");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", ans[i][j]);
    puts("");
  }
  return 0;
}
