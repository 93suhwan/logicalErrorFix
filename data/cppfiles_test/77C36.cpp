#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int A[N][N];
int n, m;
int dfs(int i, int j, int w) {
  if (i < 1 or j < 1 or i > n or j > m or A[i][j] < 0) return 0;
  if (w != -1 and A[i][j] & (1 << w)) return 0;
  int cur = A[i][j];
  A[i][j] = -1;
  int sum = 0;
  if (!(cur & (1 << 0)) and j - 1 >= 1 and A[i][j - 1] >= 0)
    sum += dfs(i, j - 1, 2);
  if (!(cur & (1 << 1)) and i + 1 <= n and A[i + 1][j] >= 0)
    sum += dfs(i + 1, j, 3);
  if (!(cur & (1 << 2)) and j + 1 <= m and A[i][j + 1] >= 0)
    sum += dfs(i, j + 1, 0);
  if (!(cur & (1 << 3)) and i - 1 >= 1 and A[i - 1][j] >= 0)
    sum += dfs(i - 1, j, 1);
  return sum + 1;
}
int bfs(int sti, int stj) {
  queue<pair<pair<int, int>, int>> q;
  q.push({{sti, stj}, -1});
  int cnt = 0;
  while (!q.empty()) {
    int i = q.front().first.first;
    int j = q.front().first.second;
    int w = q.front().second;
    q.pop();
    if (i < 1 or j < 1 or i > n or j > m or A[i][j] < 0 or A[i][j] & (1 << w))
      continue;
    cnt++;
    int cur = A[i][j];
    A[i][j] *= -1;
    if (!(cur & (1 << 0)) and j - 1 >= 1 and A[i][j - 1] >= 0)
      q.push({{i, j - 1}, 2});
    if (!(cur & (1 << 1)) and i + 1 <= n and A[i + 1][j] >= 0)
      q.push({{i + 1, j}, 3});
    if (!(cur & (1 << 2)) and j + 1 <= m and A[i][j + 1] >= 0)
      q.push({{i, j + 1}, 0});
    if (!(cur & (1 << 3)) and i - 1 >= 1 and A[i - 1][j] >= 0)
      q.push({{i - 1, j}, 1});
  }
  return cnt;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &A[i][j]);
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i][j] >= 0) {
        res.push_back(dfs(i, j, -1));
      }
    }
  }
  sort(res.begin(), res.end());
  reverse(res.begin(), res.end());
  for (auto num : res) {
    printf("%d ", num);
  }
  printf("\n");
  return 0;
}
