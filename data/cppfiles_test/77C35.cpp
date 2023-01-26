#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int g[N][N];
vector<int> res;
int n, m;
bool st[N][N];
void bfs(int sx, int sy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  st[sx][sy] = true;
  int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
  int cnt = 0;
  while (q.size()) {
    auto t = q.front();
    q.pop();
    cnt++;
    int x = t.first, y = t.second;
    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      if (a < 0 || a >= n || b < 0 || b >= m) continue;
      if (st[a][b]) continue;
      if (g[x][y] >> i & 1) continue;
      q.push({a, b});
      st[a][b] = true;
    }
  }
  res.push_back(cnt);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &g[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!st[i][j]) bfs(i, j);
  sort(res.begin(), res.end());
  for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << ' ';
  return 0;
}
