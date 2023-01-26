#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, M = 1e3 + 10;
bool map[2 * N][2 * M];
int x;
int dfs(int i, int j, int n, int m) {
  if (i < 0 || j < 0 || i > 2 * n || j > 2 * m) return 0;
  if (!map[i][j]) {
    map[i][j] = true;
    int res;
    if (i % 2 == 1 && j % 2 == 1)
      res = 1;
    else
      res = 0;
    res += dfs(i - 1, j, n, m);
    res += dfs(i, j - 1, n, m);
    res += dfs(i + 1, j, n, m);
    res += dfs(i, j + 1, n, m);
    return res;
  } else
    return 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x;
      if ((x & 8) != 0) {
        map[2 * i][2 * j] = true;
        map[2 * i][2 * j + 1] = true;
        map[2 * i][2 * j + 2] = true;
      }
      if ((x & 4) != 0) {
        map[2 * i][2 * j + 2] = true;
        map[2 * i + 1][2 * j + 2] = true;
        map[2 * i + 2][2 * j + 2] = true;
      }
      if ((x & 2) != 0) {
        map[2 * i + 2][2 * j] = true;
        map[2 * i + 2][2 * j + 1] = true;
        map[2 * i + 2][2 * j + 2] = true;
      }
      if ((x & 1) != 0) {
        map[2 * i][2 * j] = true;
        map[2 * i + 1][2 * j] = true;
        map[2 * i + 2][2 * j] = true;
      }
    }
  }
  vector<int> v;
  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * m; j++) {
      if (!map[i][j]) {
        int res = dfs(i, j, n, m);
        v.push_back(res);
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i > 0; i--) cout << v[i] << " ";
  cout << v[0];
  return 0;
}
