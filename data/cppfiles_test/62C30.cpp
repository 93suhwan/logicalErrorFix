#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int vis[2][N][N], n, m, q, bad[N][N], vis2[N][N];
vector<int> mp[N][N];
void walk(vector<pair<int, int>> &staircase, int i, int j, int prev) {
  vis[prev][i][j] = 1;
  staircase.push_back({i, j});
  int nx = i + prev, ny = j + !prev;
  if (nx < n && ny < m) {
    assert(vis[!prev][nx][ny] == 0);
    walk(staircase, nx, ny, !prev);
  }
}
void solve() {
  cin >> n >> m >> q;
  vector<vector<pair<int, int>>> paths;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        if (!vis[k][i][j]) {
          vector<pair<int, int>> v;
          walk(v, i, j, k);
          for (auto x : v) {
            mp[x.first][x.second].push_back(paths.size());
          }
          ans += (1ll * v.size() * (v.size() - 1)) / 2;
          paths.push_back(v);
        }
      }
    }
  }
  ans += n * m;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (bad[x - 1][y - 1])
      ans++;
    else
      ans--;
    for (int idx : mp[x - 1][y - 1]) {
      for (int i = 0; i < paths[idx].size();) {
        int ii = paths[idx][i].first;
        int jj = paths[idx][i].second;
        if (bad[ii][jj]) {
          i++;
          continue;
        }
        int j = i;
        while (j < paths[idx].size()) {
          ii = paths[idx][j].first;
          jj = paths[idx][j].second;
          if (bad[ii][jj]) break;
          j++;
        }
        int len = j - i;
        ans -= (1ll * len * (len - 1)) / 2;
        i = j;
      }
    }
    bad[x - 1][y - 1] ^= 1;
    for (int idx : mp[x - 1][y - 1]) {
      for (int i = 0; i < paths[idx].size();) {
        int ii = paths[idx][i].first;
        int jj = paths[idx][i].second;
        if (bad[ii][jj]) {
          i++;
          continue;
        }
        int j = i;
        while (j < paths[idx].size()) {
          ii = paths[idx][j].first;
          jj = paths[idx][j].second;
          if (bad[ii][jj]) break;
          j++;
        }
        int len = j - i;
        ans += (1ll * len * (len - 1)) / 2;
        i = j;
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
