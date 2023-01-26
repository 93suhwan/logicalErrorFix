#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> factory;
vector<vector<int>> visited;
bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
int dfs(int i, int j) {
  visited[i][j] = 1;
  int count = 1;
  int value = factory[i][j];
  bool left = value & 1;
  value = value >> 1;
  bool down = value & 1;
  value = value >> 1;
  bool right = value & 1;
  value = value >> 1;
  bool up = value & 1;
  if (!left && valid(i, j - 1) && !visited[i][j - 1]) {
    count += dfs(i, j - 1);
  }
  if (!right && valid(i, j + 1) && !visited[i][j + 1]) {
    count += dfs(i, j + 1);
  }
  if (!up && valid(i - 1, j) && !visited[i - 1][j]) {
    count += dfs(i - 1, j);
  }
  if (!down && valid(i + 1, j) && !visited[i + 1][j]) {
    count += dfs(i + 1, j);
  }
  return count;
}
void solve() {
  cin >> n >> m;
  factory.clear();
  factory.assign(n, vector<int>(m));
  visited.assign(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> factory[i][j];
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        int res = dfs(i, j);
        ans.push_back(res);
      }
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (auto x : ans) {
    cout << x << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
