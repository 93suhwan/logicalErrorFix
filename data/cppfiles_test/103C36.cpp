#include <bits/stdc++.h>
using namespace std;
string s[2005];
int v[2005][2005], ans[2005][2005];
int n, m, tot = 0;
int ansx, ansy, len = 0;
void fi(int x, int y) {
  v[x][y] = 1;
  int h = x, w = y - 1;
  if (s[h][w] == 'L')
    w--;
  else if (s[h][w] == 'R')
    w++;
  else if (s[h][w] == 'U')
    h--;
  else
    h++;
  if (h > 0 && h <= n && w >= 0 && w < m && !v[h][w + 1] && !ans[h][w + 1]) {
    fi(h, w + 1);
    ans[x][y] = ans[h][w + 1] + 1;
  } else
    ans[x][y] = ans[h][w + 1] + 1;
  return;
}
void col(int x, int y) {
  int h = x, w = y - 1;
  len++;
  if (s[h][w] == 'L')
    w--;
  else if (s[h][w] == 'R')
    w++;
  else if (s[h][w] == 'U')
    h--;
  else
    h++;
  if (x != ansx || y != ansy) col(h, w + 1);
  ans[x][y] = len;
  return;
}
void dfs(int x, int y) {
  v[x][y] = tot;
  int h = x, w = y - 1;
  if (s[h][w] == 'L')
    w--;
  else if (s[h][w] == 'R')
    w++;
  else if (s[h][w] == 'U')
    h--;
  else
    h++;
  if (h <= 0 || h > n || w < 0 || w >= m)
    return;
  else if (!v[h][w + 1])
    dfs(h, w + 1);
  else if (v[h][w + 1] == tot)
    len = 0, ansx = x, ansy = y, col(h, w + 1);
  return;
}
void sol() {
  tot = 0;
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++) v[i][j] = ans[i][j] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!v[i][j] && !ans[i][j]) tot++, dfs(i, j);
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++) v[i][j] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!v[i][j] && !ans[i][j]) fi(i, j);
  int x = 1, y = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (ans[i][j] > ans[x][y]) x = i, y = j;
  printf("%d %d %d\n", x, y, ans[x][y]);
  return;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) cin >> s[i];
    sol();
  }
  return 0;
}
