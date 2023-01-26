#include <bits/stdc++.h>
using namespace std;
int n, m, sl = 0;
int f[2005][2005], d[2005 * 2005], cl[2005][2005], re[2005 * 2005];
string s[2005];
pair<int, int> xp[2005 * 2005];
void dfs(int i, int j, int o) {
  if (cl[i][j]) {
    if (pair<int, int>(i, j) == xp[sl]) re[sl] = 1;
    return;
  }
  cl[i][j] = sl;
  f[i][j] = o + 1;
  d[sl] = max(d[sl], o + 1);
  if (s[i][j] == 'R' && j < m) {
    if (cl[i][j + 1] && cl[i][j + 1] != sl) {
      int u = f[i][j] + d[cl[i][j + 1]] - f[i][j + 1] + 1;
      if (re[cl[i][j + 1]]) u = f[i][j] + d[cl[i][j + 1]];
      d[sl] = max(d[sl], u);
    } else
      dfs(i, j + 1, o + 1);
  } else if (s[i][j] == 'L' && j > 1) {
    if (cl[i][j - 1] && cl[i][j - 1] != sl) {
      int u = f[i][j] + d[cl[i][j - 1]] - f[i][j - 1] + 1;
      if (re[cl[i][j - 1]]) u = f[i][j] + d[cl[i][j - 1]];
      d[sl] = max(d[sl], u);
    } else
      dfs(i, j - 1, o + 1);
  } else if (s[i][j] == 'U' && i > 1) {
    if (cl[i - 1][j] && cl[i - 1][j] != sl) {
      int u = f[i][j] + d[cl[i - 1][j]] - f[i - 1][j] + 1;
      if (re[cl[i - 1][j]]) u = f[i][j] + d[cl[i - 1][j]];
      d[sl] = max(d[sl], u);
    } else
      dfs(i - 1, j, o + 1);
  } else if (s[i][j] == 'D' && i < n) {
    if (cl[i + 1][j] && cl[i + 1][j] != sl) {
      int u = f[i][j] + d[cl[i][j + 1]] - f[i + 1][j] + 1;
      if (re[cl[i + 1][j]]) u = f[i][j] + d[cl[i + 1][j]];
      d[sl] = max(d[sl], u);
    } else
      dfs(i + 1, j, o + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
      s[i] = ' ' + s[i];
    }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) cl[i][j] = 0;
    sl = 0;
    pair<int, pair<int, int> > res =
        pair<int, pair<int, int> >(0, pair<int, int>(0, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (cl[i][j] == 0) {
          ++sl;
          xp[sl] = pair<int, int>(i, j);
          dfs(i, j, 0);
          res = max(res, pair<int, pair<int, int> >(d[sl], xp[sl]));
        }
      }
    }
    for (int i = 1; i <= sl; ++i) d[i] = re[i] = 0;
    cout << res.second.first << " " << res.second.second << " " << res.first
         << endl;
  }
}
