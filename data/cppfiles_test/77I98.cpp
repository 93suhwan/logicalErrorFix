#include <bits/stdc++.h>
using namespace std;
int map[1000][1000];
bool visited[1000][1000] = {false};
int cnt;
int n, m;
void dfs(int x, int y) {
  visited[x][y] = true;
  cnt++;
  bitset<4> a(map[x][y]);
  cout << x << ' ' << y << ' ' << map[x][y] << ' ' << a << '\n';
  if (a[3] == 0 and x > 0 and !visited[x - 1][y]) dfs(x - 1, y);
  if (a[0] == 0 and y > 0 and !visited[x][y - 1]) dfs(x, y - 1);
  if (a[1] == 0 and x + 1 < n and !visited[x + 1][y]) dfs(x + 1, y);
  if (a[2] == 0 and y + 1 < m and !visited[x][y + 1]) dfs(x, y + 1);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> map[i][j];
  vector<int> rooms;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!visited[i][j]) {
        cnt = 0;
        cout << "start\n";
        dfs(i, j);
        rooms.push_back(cnt);
      }
  sort(rooms.begin(), rooms.end());
  for (auto x : rooms) cout << x << " ";
  cout << "\n";
  ;
}
