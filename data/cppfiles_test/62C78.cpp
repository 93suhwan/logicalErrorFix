#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 10;
int dp0[maxn][maxn], dp1[maxn][maxn];
int pd0[maxn][maxn], pd1[maxn][maxn];
bool c[maxn][maxn];
int l, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  long long maxx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      c[i][j] = 1;
      dp0[i][j] = dp1[i][j - 1] + 1;
      dp1[i][j] = dp0[i - 1][j] + 1;
      pd1[i][j] = dp1[i][j];
      pd0[i][j] = dp0[i][j];
      maxx += dp0[i][j] + dp1[i][j] - 1;
    }
  }
  int x, y;
  int vv = 0;
  while (q--) {
    cin >> l >> r;
    x = l, y = r;
    if (c[l][r] == 1) {
      x = l, y = r;
      vv = 0;
      for (int i = 1; i <= 2000; i++) {
        if (i % 2 == 1) {
          y++;
          if (x > n || y > m) {
            break;
          }
          if (c[x][y] == 0) {
            dp0[x][y] -= dp1[l][r];
            break;
            vv++;
          }
          dp0[x][y] -= dp1[l][r];
          if (vv == 0) {
            maxx -= dp1[l][r];
          }
        } else {
          x++;
          if (x > n || y > m) {
            break;
          }
          if (c[x][y] == 0) {
            dp1[x][y] -= dp1[l][r];
            break;
            vv++;
          }
          dp1[x][y] -= dp1[l][r];
          if (vv == 0) {
            maxx -= dp1[l][r];
          }
        }
      }
      vv = 0;
      x = l, y = r;
      for (int i = 1; i <= 2000; i++) {
        if (i % 2 == 0) {
          y++;
          if (x > n || y > m) {
            break;
          }
          if (c[x][y] == 0) {
            vv++;
            dp0[x][y] -= dp0[l][r];
            break;
          }
          dp0[x][y] -= dp0[l][r];
          if (vv == 0) {
            maxx -= dp0[l][r];
          }
        } else {
          x++;
          if (x > n || y > m) {
            break;
          }
          if (c[x][y] == 0) {
            vv++;
            dp1[x][y] -= dp0[l][r];
            break;
          }
          dp1[x][y] -= dp0[l][r];
          if (vv == 0) {
            maxx -= dp0[l][r];
          }
        }
      }
      maxx -= (dp0[l][r] + dp1[l][r] - 1);
      cout << maxx << "\n";
      c[l][r] = 0;
    } else if (c[l][r] == 0) {
      x = l, y = r;
      vv = 0;
      for (int i = 1; i <= 2000; i++) {
        if (i % 2 == 1) {
          y++;
          if (x > n || y > m) {
            break;
          }
          if (c[x][y] == 0) {
            vv++;
            dp0[x][y] += dp1[l][r];
            break;
          }
          dp0[x][y] += dp1[l][r];
          if (vv == 0) {
            maxx += dp1[l][r];
          }
        } else {
          x++;
          if (x > n || y > m) {
            break;
          }
          if (c[x][y] == 0) {
            vv++;
            dp1[x][y] += dp1[l][r];
            break;
          }
          dp1[x][y] += dp1[l][r];
          if (vv == 0) {
            maxx += dp1[l][r];
          }
        }
      }
      vv = 0;
      x = l, y = r;
      for (int i = 1; i <= 2000; i++) {
        if (i % 2 == 0) {
          y++;
          if (x > n || y > m) {
            break;
          }
          if (c[x][y] == 0) {
            vv++;
            dp0[x][y] += dp0[l][r];
            break;
          }
          dp0[x][y] += dp0[l][r];
          if (vv == 0) {
            maxx += dp0[l][r];
          }
        } else {
          x++;
          if (x > n || y > m) {
            break;
          }
          if (c[x][y] == 0) {
            vv++;
            dp1[x][y] += dp0[l][r];
            break;
          }
          dp1[x][y] += dp0[l][r];
          if (vv == 0) {
            maxx += dp0[l][r];
          }
        }
      }
      maxx += (dp0[l][r] + dp1[l][r] - 1);
      cout << maxx << "\n";
      c[l][r] = 1;
    }
  }
}
