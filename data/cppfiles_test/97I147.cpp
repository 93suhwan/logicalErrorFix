#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int N = 1e5 + 5;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int n, m, q, k;
char s[505][505];
int v[505][505] = {0};
int ans[505][505];
void show() {
  puts("show");
  for (int i = 0; i < n; i++) {
    printf("%s\n", s[i]);
  }
  puts("");
}
void dfs(int x, int y, int t) {
  for (int k = 0; k < 4; k++) {
    int nx = x + dx[k], ny = y + dy[k];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m)
      if (s[nx][ny] == '.') {
        s[nx][ny] = '0' + t;
        for (int q = 0; q < 4; q++) {
          int nnx = nx + dx[q], nny = ny + dy[q];
          if (nnx >= 0 && nnx < n && nny >= 0 && nny < m)
            if (s[nnx][nny] == 'X') {
              if (--v[nnx][nny] & 1) dfs(nnx, nny, 5 - t);
            }
        }
      }
  }
  return;
}
void solve() {
  scanf("%d%d", &n, &m);
  int num = 0;
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  int flag = 1;
  for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++) {
      if (s[i][j] == 'X') {
        int cnt = 0;
        for (int k = 0; k < 4; k++)
          if (s[i + dx[k]][j + dy[k]] == '.') cnt++;
        v[i][j] = cnt;
        if (cnt & 1) flag = 0;
        if (cnt) num++;
      }
    }
  if (!flag) {
    puts("NO\n");
    return;
  }
  puts("YES");
  while (flag) {
    flag = 0;
    for (int i = 1; i < n && !flag; i++)
      for (int j = 1; j < m && !flag; j++)
        if (v[i][j]) {
          flag = 1;
          dfs(i, j, 1);
        }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '.') s[i][j] = '1';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == 'X') {
        int cnt = 0;
        for (int q = 0; q < 4; q++) {
          int nx = i + dx[q], ny = j + dy[q];
          if (s[nx][ny] != 'X') cnt += s[nx][ny] - '0';
        }
        ans[i][j] = cnt;
      } else
        ans[i][j] = s[i][j] - '0';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) printf(j < m - 1 ? "%d " : "%d\n", ans[i][j]);
}
int main() {
  int T = 1;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
