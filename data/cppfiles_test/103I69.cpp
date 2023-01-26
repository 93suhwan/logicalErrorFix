#include <bits/stdc++.h>
using namespace std;
string s[2005];
int f[2005][2005], n, m, ans, tmp, ai, aj, b[2005][2005];
bool check(int i, int j) {
  if (i - 1 >= 1 && s[i - 1][j] == 'D') return 0;
  if (i + 1 <= n && s[i + 1][j] == 'U') return 0;
  if (j - 1 >= 1 && s[i][j - 1] == 'R') return 0;
  if (j + 1 <= m && s[i][j + 1] == 'L') return 0;
  return 1;
}
void dfs(int i, int j, int flag) {
  int cnt = f[i][j];
  int ti = i, tj = j;
  if (s[i][j] == 'L') tj--;
  if (s[i][j] == 'R') tj++;
  if (s[i][j] == 'U') ti--;
  if (s[i][j] == 'D') ti++;
  if (ti >= 1 && ti <= n && tj >= 1 && tj <= m && b[ti][tj] != flag &&
      f[ti][tj] < cnt + 1) {
    f[ti][tj] = cnt + 1;
    b[ti][tj] = flag;
    dfs(ti, tj, flag);
  } else {
    tmp = cnt;
  }
}
int main() {
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    ans = 0, ai = 0, aj = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) f[i][j] = -1, b[i][j] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      s[i] = " " + s[i];
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!b[i][j] && check(i, j)) {
          cnt++;
          f[i][j] = 1;
          b[i][j] = cnt;
          tmp = 0;
          dfs(i, j, cnt);
          if (tmp > ans) ai = i, aj = j, ans = tmp;
        }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!b[i][j]) {
          cnt++;
          f[i][j] = 1;
          b[i][j] = cnt;
          tmp = 0;
          dfs(i, j, cnt);
          if (tmp > ans) ai = i, aj = j, ans = tmp;
        }
    cout << ai << " " << aj << " " << ans << "\n";
  }
  return 0 ^ 0 ^ 0;
}
