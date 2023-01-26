#include <bits/stdc++.h>
using namespace std;
int n, m;
int grid[1001][1001];
bool used[1001][1001];
void rec(int x, int y, int& counter) {
  if (used[x][y]) return;
  used[x][y] = true;
  counter++;
  if (x - 1 >= 0 && (grid[x][y] >> 3) % 2 == 0 &&
      (grid[x - 1][y] >> 1) % 2 == 0)
    rec(x - 1, y, counter);
  if (x + 1 < n && (grid[x][y] >> 1) % 2 == 0 && (grid[x + 1][y] >> 3) % 2 == 0)
    rec(x + 1, y, counter);
  if (y - 1 >= 0 && grid[x][y] % 2 == 0 && (grid[x][y - 1] >> 2) % 2 == 0)
    rec(x, y - 1, counter);
  if (y + 1 < m && (grid[x][y] >> 2) % 2 == 0 && grid[x][y + 1] % 2 == 0)
    rec(x, y + 1, counter);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      grid[i][j] = t;
      used[i][j] = false;
    }
  }
  vector<int> results;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (used[i][j]) continue;
      int counter = 0;
      rec(i, j, counter);
      results.push_back(counter);
    }
  }
  sort(results.begin(), results.end());
  for (int i = results.size() - 1; i >= 0; --i) {
    cout << results[i] << " ";
  }
  return 0;
}
