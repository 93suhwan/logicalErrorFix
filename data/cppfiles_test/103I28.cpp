#include <bits/stdc++.h>
using namespace std;
int n, m, q;
char a[2005][2005];
int dp[2005][2005];
int b[2005][2005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> q;
  while (q--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        dp[i][j] = 0;
        b[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (dp[i][j] != 0) continue;
        int x = i;
        int y = j;
        int bo = 0;
        int cnt = 0;
        int stx, sty;
        while (1) {
          cnt++;
          b[x][y] = 1;
          if (a[x][y] == 'D')
            x++;
          else {
            if (a[x][y] == 'U')
              x--;
            else {
              if (a[x][y] == 'L')
                y--;
              else
                y++;
            }
          }
          if (b[x][y] != 0) {
            if (dp[x][y] == 0) {
              stx = x;
              sty = y;
              bo = 0;
            } else {
              bo = 2;
              cnt += dp[x][y];
            }
            break;
          }
          if (x > n || x <= 0 || y > m || y <= 0) {
            bo = 1;
            break;
          }
        }
        if (bo == 0) {
          x = i;
          y = j;
          int boo = 0;
          while (1) {
            if (x == stx && y == sty) {
              boo = 1;
            }
            dp[x][y] = cnt;
            if (a[x][y] == 'D')
              x++;
            else {
              if (a[x][y] == 'U')
                x--;
              else {
                if (a[x][y] == 'L')
                  y--;
                else
                  y++;
              }
            }
            if (boo == 0) {
              cnt--;
            }
            if (dp[x][y] != 0) break;
          }
        } else {
          if (bo == 1) {
            x = i;
            y = j;
            while (x <= n && x > 0 && y <= m && y > 0) {
              dp[x][y] = cnt;
              if (a[x][y] == 'D')
                x++;
              else {
                if (a[x][y] == 'U')
                  x--;
                else {
                  if (a[x][y] == 'L')
                    y--;
                  else
                    y++;
                }
              }
              cnt--;
            }
          } else {
            x = i;
            y = j;
            while (dp[x][y] == 0) {
              dp[x][y] = cnt;
              if (a[x][y] == 'D')
                x++;
              else {
                if (a[x][y] == 'U')
                  x--;
                else {
                  if (a[x][y] == 'L')
                    y--;
                  else
                    y++;
                }
              }
              cnt--;
            }
          }
        }
      }
    }
    int posx, posy, maxx = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (maxx < dp[i][j]) {
          maxx = dp[i][j];
          posx = i;
          posy = j;
        }
      }
    }
    cout << posx << ' ' << posy << ' ' << maxx << '\n';
  }
}
