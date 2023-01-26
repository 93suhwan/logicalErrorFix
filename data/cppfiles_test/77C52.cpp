#include <bits/stdc++.h>
using namespace std;
int b[3010][3010];
bool vis[3010][3010];
int n, m, cnt = 0;
bool cmp(const int& x, const int& y) { return x > y; }
void dfs(int i, int j) {
  vis[i][j] = 1;
  if (!(b[i][j] & (1 << 3)) && !vis[i - 1][j]) {
    cnt++;
    dfs(i - 1, j);
  }
  if (!(b[i][j] & (1 << 2)) && !vis[i][j + 1]) {
    cnt++;
    dfs(i, j + 1);
  }
  if (!(b[i][j] & (1 << 1)) && !vis[i + 1][j]) {
    cnt++;
    dfs(i + 1, j);
  }
  if (!(b[i][j] & (1 << 0)) && !vis[i][j - 1]) {
    cnt++;
    dfs(i, j - 1);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> b[i][j];
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j]) continue;
      dfs(i, j);
      v.push_back(cnt + 1);
      cnt = 0;
    }
  }
  sort(v.begin(), v.end(), cmp);
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
