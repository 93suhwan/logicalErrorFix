#include <bits/stdc++.h>
using namespace std;
int n, m;
int x, y;
bool isValid(int i, int j, bool** vis, char** grid) {
  if (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false &&
      grid[i][j] != '#') {
    return true;
  }
  return false;
}
void dfs(char** grid, bool** vis, int i, int j) {
  int pos = 0;
  if (isValid(i + 1, j, vis, grid)) pos++;
  if (isValid(i - 1, j, vis, grid)) pos++;
  if (isValid(i, j + 1, vis, grid)) pos++;
  if (isValid(i, j - 1, vis, grid)) pos++;
  if (pos <= 1) {
    grid[i][j] = '+';
    if (isValid(i + 1, j, vis, grid)) {
      vis[i][j] = true;
      dfs(grid, vis, i + 1, j);
      vis[i][j] = false;
    }
    if (isValid(i - 1, j, vis, grid)) {
      vis[i][j] = true;
      dfs(grid, vis, i - 1, j);
      vis[i][j] = false;
    }
    if (isValid(i, j + 1, vis, grid)) {
      vis[i][j] = true;
      dfs(grid, vis, i, j + 1);
      vis[i][j] = false;
    }
    if (isValid(i, j - 1, vis, grid)) {
      vis[i][j] = true;
      dfs(grid, vis, i, j - 1);
      vis[i][j] = false;
    }
  }
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    char** grid = new char*[n];
    for (int i = 0; i < n; i++) {
      grid[i] = new char[m];
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 'L') {
          x = i;
          y = j;
        }
      }
    }
    bool** vis = new bool*[n];
    for (int i = 0; i < n; i++) {
      vis[i] = new bool[m];
      for (int j = 0; j < m; j++) {
        vis[i][j] = false;
      }
    }
    int i = x;
    int j = y;
    vis[i][j] = true;
    if (isValid(i + 1, j, vis, grid)) dfs(grid, vis, i + 1, j);
    if (isValid(i - 1, j, vis, grid)) dfs(grid, vis, i - 1, j);
    if (isValid(i, j + 1, vis, grid)) dfs(grid, vis, i, j + 1);
    if (isValid(i, j - 1, vis, grid)) dfs(grid, vis, i, j - 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << grid[i][j];
      }
      cout << "\n";
    }
  }
}
int32_t main() { solve(); }
