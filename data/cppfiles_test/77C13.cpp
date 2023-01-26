#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
bool vis[N][N];
int n, m, a[N][N], cnt, mx[4] = {0, 1, 0, -1}, my[4] = {-1, 0, 1, 0};
vector<int> v;
bool inside(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
void dfs(int x, int y) {
  cnt++;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + mx[i];
    int ny = y + my[i];
    if (inside(nx, ny) && !vis[nx][ny] && !(a[x][y] & (1 << i))) dfs(nx, ny);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!vis[i][j]) {
        cnt = 0;
        dfs(i, j);
        v.push_back(cnt);
      }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (auto &x : v) printf("%d ", x);
}
