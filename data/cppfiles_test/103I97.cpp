#include <bits/stdc++.h>
using namespace std;
int n, m;
int visit(vector<string> &b, vector<vector<vector<int> > > &dp,
          vector<vector<int> > &visited, int i, int j, int dir) {
  if (i >= n || i < 0 || j >= m || j < 0) return 0;
  if (visited[i][j]) {
    return 0;
  }
  if (dir != -1 && dp[i][j][dir] != -1) {
    return dp[i][j][dir];
  }
  visited[i][j] = 1;
  int t;
  if (b[i][j] == 'R') {
    t = visit(b, dp, visited, i, j + 1, 0) + 1;
  } else if (b[i][j] == 'L') {
    t = visit(b, dp, visited, i, j - 1, 1) + 1;
  } else if (b[i][j] == 'U') {
    t = visit(b, dp, visited, i - 1, j, 2) + 1;
  } else {
    t = visit(b, dp, visited, i + 1, j, 3) + 1;
  }
  if (dir != -1) {
    dp[i][j][dir] = t;
  }
  return t;
}
void solve() {
  cin >> n >> m;
  vector<string> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<vector<vector<int> > > dp(n,
                                   vector<vector<int> >(m, vector<int>(4, -1)));
  int r, c, d = INT_MIN;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vector<vector<int> > visited(n, vector<int>(m, 0));
      int t = visit(b, dp, visited, i, j, -1);
      if (t > d) {
        d = t;
        r = i + 1;
        c = j + 1;
      }
    }
  }
  cout << r << " " << c << " " << d << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
