#include <bits/stdc++.h>
using namespace std;
bool dfs(const int _map[][49], int No, const int loop, vector<int>& res,
         const int& isFriend) {
  if (res.size() == 5) return true;
  if (No > loop) return false;
  int cnt = 0;
  for (int i = No; i <= loop; ++i) {
    cnt = 0;
    for (int n : res) {
      if (_map[n][i] == isFriend) ++cnt;
    }
    if (cnt == res.size()) {
      res.push_back(i);
      if (dfs(_map, i + 1, loop, res, isFriend)) return true;
      res.pop_back();
    }
  }
  return false;
}
int main() {
  const int ramsey = 48;
  int n, m;
  cin >> n >> m;
  int _map[ramsey + 1][ramsey + 1];
  memset(_map, 0, sizeof(_map));
  int x, y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    if (x > ramsey || y > ramsey) continue;
    _map[x][y] = 1;
    _map[y][x] = 1;
  }
  vector<int> ans;
  int loop = min(n, ramsey);
  vector<int> res;
  if (dfs(_map, 1, loop, res, 0)) {
    for (int i = 0; i < 5; ++i) {
      printf("%d ", res[i]);
    }
  } else if (dfs(_map, 1, loop, res, 1)) {
    for (int i = 0; i < 5; ++i) {
      printf("%d ", res[i]);
    }
  } else {
    printf("-1");
  }
  return 0;
}
