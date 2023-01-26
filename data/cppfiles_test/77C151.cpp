#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1}, maxn = 1000;
int n, m, tile[maxn + 5][maxn + 5], used[maxn + 5][maxn + 5];
int dfs(int r, int c) {
  used[r][c]++;
  if (tile[r][c] == 15) return 1;
  int sum = 1;
  for (int i = 0; i < 4; ++i)
    if (!(tile[r][c] >> (3 - i) & 1) && !used[r + dr[i]][c + dc[i]])
      sum += dfs(r + dr[i], c + dc[i]);
  return sum;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", *(tile + i) + j);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!used[i][j]) q.push(dfs(i, j));
  while (!q.empty())
    if (q.top()) {
      printf("%d ", q.top());
      q.pop();
    } else
      break;
  return 0;
}
