#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> mat;
vector<vector<bool>> vis;
long long n, m;
vector<pair<long long, long long>> dir{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
inline void dfs(long long x, long long y, long long &cnt) {
  if (x < 0 or y < 0 or x > n - 1 or y > m - 1 or vis[x][y] == true) return;
  cnt++;
  vis[x][y] = true;
  for (long long i = 0; i < 4; i++) {
    if ((mat[x][y] & (1 << i)) == 0) {
      dfs(x + dir[i].first, y + dir[i].second, cnt);
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  mat.resize(n, vector<long long>(m));
  vis.resize(n, vector<bool>(m));
  for (auto &it : mat)
    for (auto &i : it) cin >> i;
  vector<long long> ans;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long cnt = 0;
      if (vis[i][j] == false) {
        dfs(i, j, cnt);
        ans.emplace_back(cnt);
      }
    }
  }
  sort((ans).begin(), (ans).end());
  reverse((ans).begin(), (ans).end());
  for (auto &it : ans) cout << it << ' ';
}
