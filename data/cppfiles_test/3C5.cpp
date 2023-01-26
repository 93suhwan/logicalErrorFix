#include <bits/stdc++.h>
int cnt, n;
char s[10001];
void dfs(int x, int y, int z) {
  if (x == n + 1) {
    if (y % 25 == 0) cnt++;
    return;
  }
  if (x > 1 && y == 0) return;
  if (s[x] == 'X')
    if (z != -1)
      dfs(x + 1, y * 10 + z, z);
    else
      for (int i = 0; i <= 9; i++) dfs(x + 1, y * 10 + i, i);
  else if (s[x] != '_')
    dfs(x + 1, y * 10 + s[x] - 48, z);
  else
    for (int i = 0; i <= 9; i++) dfs(x + 1, y * 10 + i, z);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  dfs(1, 0, -1);
  printf("%d\n", cnt);
}
