#include <bits/stdc++.h>
using namespace std;
int n, m, sl = 0;
int f[2005][2005], d[2005 * 2005], cl[2005][2005], re[2005 * 2005];
string s[2005];
pair<int, int> xp[2005 * 2005], lst[2005 * 2005];
int cal(int xi, int xj, int id) {
  int ki = lst[id].first, kj = lst[id].second;
  if (s[ki][kj] == 'R')
    kj++;
  else if (s[ki][kj] == 'L')
    kj--;
  else if (s[ki][kj] == 'U')
    ki--;
  else
    ki++;
  if (ki < 1 || ki > n || kj < 1 || kj > m) return 0;
  if (cl[ki][kj] != id || f[ki][kj] >= f[xi][xj]) return 0;
  return f[xi][xj] - f[ki][kj];
}
void dfs(int i, int j, int o) {
  if (i < 1 || i > n || j < 1 || j > m) return;
  if (cl[i][j]) {
    if (cl[i][j] == sl) return;
    d[sl] = max(d[sl], o + d[cl[i][j]] - f[i][j] + cal(i, j, cl[i][j]) + 1);
    lst[sl] = lst[cl[i][j]];
    return;
  }
  cl[i][j] = sl;
  f[i][j] = o + 1;
  lst[sl] = pair<int, int>(i, j);
  d[sl] = max(d[sl], o + 1);
  if (s[i][j] == 'R')
    j++;
  else if (s[i][j] == 'L')
    j--;
  else if (s[i][j] == 'U')
    i--;
  else
    i++;
  dfs(i, j, o + 1);
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
