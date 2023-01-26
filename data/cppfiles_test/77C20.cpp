#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1e3;
bool has_wall[MAX_SIZE][MAX_SIZE][4];
bool visited[MAX_SIZE][MAX_SIZE];
const int NORTH = 8;
const int NORTH_IDX = 0;
const int EAST = 4;
const int EAST_IDX = 1;
const int SOUTH = 2;
const int SOUTH_IDX = 2;
const int WEST = 1;
const int WEST_IDX = 3;
int visit(int i, int j) {
  visited[i][j] = true;
  int ans = 1;
  if (!has_wall[i][j][NORTH_IDX] && !visited[i - 1][j]) ans += visit(i - 1, j);
  if (!has_wall[i][j][SOUTH_IDX] && !visited[i + 1][j]) ans += visit(i + 1, j);
  if (!has_wall[i][j][WEST_IDX] && !visited[i][j - 1]) ans += visit(i, j - 1);
  if (!has_wall[i][j][EAST_IDX] && !visited[i][j + 1]) ans += visit(i, j + 1);
  return ans;
}
vector<int> rooms(int n, int m) {
  vector<int> room_sizes;
  for (int(i) = 0; (i) < (n); (i)++)
    for (int(j) = 0; (j) < (m); (j)++)
      if (!visited[i][j]) room_sizes.push_back(visit(i, j));
  sort(room_sizes.rbegin(), room_sizes.rend());
  return room_sizes;
}
int main() {
  int n, m;
  memset(has_wall, true, sizeof(has_wall));
  memset(visited, false, sizeof(visited));
  scanf("%d", &(n));
  scanf("%d", &(m));
  for (int(i) = 0; (i) < (n); (i)++) {
    for (int(j) = 0; (j) < (m); (j)++) {
      int tile;
      scanf("%d", &(tile));
      has_wall[i][j][WEST_IDX] = tile & WEST;
      has_wall[i][j][EAST_IDX] = tile & EAST;
      has_wall[i][j][NORTH_IDX] = tile & NORTH;
      has_wall[i][j][SOUTH_IDX] = tile & SOUTH;
    }
  }
  auto room_sizes = rooms(n, m);
  for (auto& item : room_sizes) printf("%d ", item);
  return 0;
}
