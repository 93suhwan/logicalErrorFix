#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m;
  cin >> n >> m;
  string s[n];
  for (long long int i = 0; i < n; i++) cin >> s[i];
  long long int dp[n][m];
  bool mark[n][m];
  memset(mark, false, sizeof(mark));
  memset(dp, 0, sizeof(dp));
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (mark[i][j]) continue;
      long long int x = i;
      long long int y = j;
      long long int ans = 0;
      vector<pair<long long int, long long int>> v;
      pair<long long int, long long int> cycle_point;
      cycle_point = {-1, -1};
      while (true) {
        ++ans;
        long long int nx = x;
        long long int ny = y;
        v.push_back(make_pair(x, y));
        mark[x][y] = true;
        if (s[x][y] == 'R')
          ++ny;
        else if (s[x][y] == 'L')
          --ny;
        else if (s[x][y] == 'U')
          --nx;
        else
          ++nx;
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
          if (mark[nx][ny]) {
            ans += dp[nx][ny];
            cycle_point = {nx, ny};
            break;
          }
          mark[nx][ny] = true;
        } else
          break;
        x = nx;
        y = ny;
      }
      long long int k = 0;
      for (; k < (long long int)v.size(); k++) {
        if (v[k] == cycle_point) break;
        dp[v[k].first][v[k].second] = ans--;
      }
      for (; k < (long long int)v.size(); k++)
        dp[v[k].first][v[k].second] = ans;
    }
  }
  long long int mx = 0;
  long long int ansx, ansy;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (dp[i][j] > mx) {
        mx = dp[i][j];
        ansx = i + 1;
        ansy = j + 1;
      }
    }
  }
  cout << ansx << " " << ansy << " " << mx << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
