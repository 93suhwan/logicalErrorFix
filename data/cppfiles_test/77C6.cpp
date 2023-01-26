#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1000;
const int MMAX = 1000;
int mat[1 + NMAX][1 + MMAX];
bool vizitat[1 + NMAX][1 + MMAX];
vector<int> dimCamera;
int dfs(int x, int y) {
  vizitat[x][y] = true;
  int sol = 1;
  if (((1 << 3) & mat[x][y]) == 0) {
    if (!vizitat[x - 1][y]) sol += dfs(x - 1, y);
  }
  if (((1 << 2) & mat[x][y]) == 0) {
    if (!vizitat[x][y + 1]) sol += dfs(x, y + 1);
  }
  if (((1 << 1) & mat[x][y]) == 0) {
    if (!vizitat[x + 1][y]) sol += dfs(x + 1, y);
  }
  if ((1 & mat[x][y]) == 0) {
    if (!vizitat[x][y - 1]) sol += dfs(x, y - 1);
  }
  return sol;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> mat[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vizitat[i][j]) {
        dimCamera.push_back(dfs(i, j));
      }
    }
  }
  sort(dimCamera.begin(), dimCamera.end());
  for (int i = dimCamera.size() - 1; i >= 0; i--) {
    cout << dimCamera[i] << ' ';
  }
  cout << '\n';
  return 0;
}
