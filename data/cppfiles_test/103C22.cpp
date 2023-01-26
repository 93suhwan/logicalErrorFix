#include <bits/stdc++.h>
const int maxn = 2e3 + 10;
using namespace std;
const long long mod = 1e9 + 7;
char op[maxn][maxn];
int t, n, m;
int d[maxn][maxn];
int ans[maxn][maxn];
void cal(int ux, int uy, int &tx, int &ty, char op) {
  if (op == 'L')
    tx = ux, ty = uy - 1;
  else if (op == 'R')
    tx = ux, ty = uy + 1;
  else if (op == 'D')
    tx = ux + 1, ty = uy;
  else
    tx = ux - 1, ty = uy;
}
int mxd, bjd, rd, tx, ty, cnts, dep;
pair<int, int> sta[maxn * maxn];
void dfs(int ux, int uy) {
  bool ok = true;
  while (1) {
    if (ok) {
      if (ans[ux][uy]) {
        rd = ans[ux][uy];
        ok = false;
      } else if (d[ux][uy]) {
        bjd = d[ux][uy];
        ok = false;
      } else {
        d[ux][uy] = dep;
        mxd = dep;
        cal(ux, uy, tx, ty, op[ux][uy]);
        if (tx < 1 || tx > n || ty < 1 || ty > m) {
          ans[ux][uy] = 1;
          ok = false;
        } else {
          sta[++cnts] = {ux, uy};
          dep++;
          ux = tx, uy = ty;
        }
      }
    } else {
      if (cnts == 0) break;
      ux = sta[cnts].first, uy = sta[cnts].second;
      cnts--;
      if (d[ux][uy] >= bjd)
        ans[ux][uy] = mxd - bjd + 1 + rd;
      else
        ans[ux][uy] = mxd - d[ux][uy] + 1 + rd;
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> op[i][j], ans[i][j] = d[i][j] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (!d[i][j]) {
          mxd = 0, bjd = 0x3f3f3f3f, rd = 0;
          cnts = 0, dep = 1;
          dfs(i, j);
          if (1 >= bjd)
            ans[i][j] = mxd - bjd + 1 + rd;
          else
            ans[i][j] = mxd - 1 + 1 + rd;
        }
      }
    int mx = -1, x, y;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (mx < ans[i][j]) mx = ans[i][j], x = i, y = j;
      }
    cout << x << " " << y << " " << mx << "\n";
  }
}
