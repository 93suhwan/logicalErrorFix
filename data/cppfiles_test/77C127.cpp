#include <bits/stdc++.h>
using namespace std;
int g[1000][1000], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, m, n;
bool vis[1000][1000];
enum { N = 0b1000, E = 0b0100, S = 0b0010, W = 0b0001 };
int dfs(int i, int j) {
  if (vis[i][j]) return 0;
  if (i < 0 || i > n || j < 0 || j > m) return 0;
  int r = 1;
  vis[i][j] = 1;
  if (!(g[i][j] & N)) r += dfs(i - 1, j);
  if (!(g[i][j] & E)) r += dfs(i, j + 1);
  if (!(g[i][j] & S)) r += dfs(i + 1, j);
  if (!(g[i][j] & W)) r += dfs(i, j - 1);
  return r;
}
int main() {
  ios::sync_with_stdio(), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  vector<int> room;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!vis[i][j]) room.push_back(dfs(i, j));
  sort(room.begin(), room.end(), greater<int>());
  for (int i = 0; i < room.size(); i++) cout << room[i] << " ";
  cout << '\n';
  return 0;
}
