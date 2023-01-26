#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 1;
const long long mod = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  pair<int, int> src;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (q.empty()) {
      int j = find(arr[i].begin(), arr[i].end(), 'L') - arr[i].begin();
      if (j != m) src = {i, j};
    }
  }
  auto isValid = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#';
  };
  vector<vector<int>> degree(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (arr[i][j] != '#')
        for (int k = 0; k < 4; k++)
          if (isValid(i + dx[k], j + dy[k])) degree[i][j]++;
  degree[src.first][src.second] = 0;
  q.push(src);
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == '#' ||
          arr[nx][ny] == '+' || arr[nx][ny] == 'L')
        continue;
      if (degree[nx][ny] <= 2) {
        arr[nx][ny] = '+';
        q.push({nx, ny});
      }
      --degree[nx][ny];
    }
  }
  for (int i = 0; i < n; i++) cout << arr[i] << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  for (int I = 1; I <= t; I++) {
    solve();
  }
  return 0;
}
