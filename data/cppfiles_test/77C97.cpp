#include <bits/stdc++.h>
using namespace std;
pair<int, int> getParent(vector<vector<pair<int, int>>> &par,
                         pair<int, int> x) {
  pair<int, int> z = x;
  while (par.at(z.first).at(z.second) != z) {
    z = par.at(z.first).at(z.second);
  }
  while (x != z) {
    pair<int, int> temp = par[x.first][x.second];
    par[x.first][x.second] = z;
    x = temp;
  }
  return z;
}
void unify(vector<vector<pair<int, int>>> &par, vector<vector<int>> &size,
           pair<int, int> x, pair<int, int> y) {
  if (getParent(par, x) == getParent(par, y)) return;
  auto xParent = getParent(par, x);
  auto yParent = getParent(par, y);
  size[yParent.first][yParent.second] += size[xParent.first][xParent.second];
  par.at(xParent.first).at(xParent.second) = yParent;
}
bool isValid(int i, int j, int n, int m) {
  return i >= 0 && j >= 0 && i < n && j < m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }
  vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));
  vector<vector<int>> size(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      par[i][j] = make_pair(i, j);
      size[i][j] = 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (isValid(i + 1, j, n, m) && ((1 << 1) & grid[i][j]) == 0) {
        unify(par, size, make_pair(i, j), make_pair(i + 1, j));
      }
      if (isValid(i, j + 1, n, m) && ((1 << 2) & grid[i][j]) == 0) {
        unify(par, size, make_pair(i, j), make_pair(i, j + 1));
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      auto parent = getParent(par, make_pair(i, j));
      if (size[parent.first][parent.second] == -1) continue;
      ans.push_back(size[parent.first][parent.second]);
      size[parent.first][parent.second] = -1;
    }
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for (auto &e : ans) cout << e << ' ';
  return 0;
}
