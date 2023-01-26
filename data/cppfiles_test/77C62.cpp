#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  tt = 1;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> aa(n, vector<int>(m));
    vector<vector<int>> mark(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> aa[i][j];
    vector<int> ans;
    ans.clear();
    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, -0};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!mark[i][j]) {
          queue<pair<int, int>> qq;
          qq.push({i, j});
          mark[i][j] = 1;
          int v = 0;
          while (!qq.empty()) {
            int x = qq.front().first;
            int y = qq.front().second;
            qq.pop();
            v++;
            int u = aa[x][y];
            for (int l = 0; l < 4; l++) {
              int fx = x + dx[l];
              int fy = y + dy[l];
              if (fx < 0 || fy < 0 || fx > n - 1 || fy > m - 1 ||
                  mark[fx][fy] || (u & (1 << l)) != 0)
                continue;
              mark[fx][fy] = 1;
              qq.push({fx, fy});
            }
          }
          ans.push_back(v);
        }
      }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for (auto &it : ans) cout << it << " ";
  }
  return 0;
}
