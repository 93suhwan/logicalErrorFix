#include <bits/stdc++.h>
using namespace std;
int n, m;
int mp[1005][1005];
bool vis[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> ans;
vector<int> getwal(int k) {
  vector<int> res = {0, 0, 0, 0};
  int i;
  for (i = 3;; --i) {
    res[i] = k % 2;
    k /= 2;
    if (k == 0) break;
  }
  return res;
}
void dfs(int &num, int x, int y) {
  vector<int> wal = getwal(mp[x][y]);
  for (int i = 0; i <= 3; ++i) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
      if (!wal[i] && !vis[xx][yy]) {
        ++num;
        vis[xx][yy] = true;
        dfs(num, xx, yy);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> mp[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!vis[i][j]) {
        int res = 1;
        vis[i][j] = true;
        dfs(res, i, j);
        ans.push_back(res);
      }
    }
  }
  sort(ans.begin(), ans.end(), [](int a, int b) -> bool { return a > b; });
  int len = ans.size();
  for (int i = 0; i < len; ++i) cout << ans[i] << ' ';
  return 0;
}
