#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<vector<bool>> vis;
int cnt;
void dfs(int i, int j) {
  if (vis[i][j]) return;
  cnt++;
  vis[i][j] = true;
  if (!(v[i][j] & 8)) dfs(i - 1, j);
  if (!(v[i][j] & 4)) dfs(i, j + 1);
  if (!(v[i][j] & 2)) dfs(i + 1, j);
  if (!(v[i][j] & 1)) dfs(i, j - 1);
}
int main() {
  int n, m;
  cin >> n >> m;
  v = vector<vector<int>>(n, vector<int>(m));
  vis = vector<vector<bool>>(n, vector<bool>(m, false));
  for (auto &x : v) {
    for (int &i : x) cin >> i;
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        cnt = 0;
        dfs(i, j);
        ans.push_back(cnt);
      }
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (int i : ans) cout << i << ' ';
  return 0;
}
