#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<bool>> grid;
vector<int> last;
vector<vector<int>> dist;
void dc(int x, int l, int r, int optL, int optR) {
  if (l > r) return;
  int m = (l + r) / 2;
  int opt = -1;
  int best = 1e8;
  for (int i = optL; i <= optR; ++i) {
    if (last[i] == -1) continue;
    int cost = (last[i] - x) * (last[i] - x) + (i - m) * (i - m);
    if (cost < best) {
      best = cost;
      opt = i;
    }
  }
  dist[m][x] = min(dist[m][x], best);
  if (opt == -1) return;
  dc(x, l, m - 1, optL, opt);
  dc(x, m + 1, r, opt, optR);
}
int main() {
  cin >> n >> m;
  n++;
  m++;
  grid.assign(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      grid[i][j] = c == '1';
    }
  }
  dist.assign(n, vector<int>(m, (int)1e8));
  for (int j = 0; j < m; ++j) {
    int y = -1;
    for (int i = 0; i < n; ++i) {
      if (grid[i][j]) y = i;
      if (y != -1) dist[i][j] = min(dist[i][j], (y - i) * (y - i));
    }
    y = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (grid[i][j]) y = i;
      if (y != -1) dist[i][j] = min(dist[i][j], (y - i) * (y - i));
    }
  }
  last.assign(n, -1);
  for (int j = 0; j < m; ++j) {
    dc(j, 0, n - 1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
      if (grid[i][j]) last[i] = j;
    }
  }
  last.assign(n, -1);
  for (int j = m - 1; j >= 0; --j) {
    dc(j, 0, n - 1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
      if (grid[i][j]) last[i] = j;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += (long long)dist[i][j];
    }
  }
  cout << ans << "\n";
}
