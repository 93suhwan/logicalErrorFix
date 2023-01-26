#include <bits/stdc++.h>
using namespace std;
const int N = 510;
char all[N][N];
int res[N][N];
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void f() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (all[i][j] == 'X') {
        for (int k = 0; k < 4; k++) {
          int a = i + dx[k], b = j + dy[k];
          if (a > n || a < 1 || b > m || b < 1) continue;
          if (all[a][b] == 'X') continue;
          if (k == 0 || k == 2) {
            if ((a - 2 > 0 && res[a - 2][b] == 1)) {
              res[a][b] = 4;
              continue;
            }
            res[a][b] = 1;
          } else {
            if (b - 2 > 0 && res[a][b - 2] == 1) {
              res[a][b] = 4;
              continue;
            }
            res[a][b] = 1;
          }
        }
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> all[i][j];
    }
  }
  int ok = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (all[i][j] == 'X') {
        int z = 0;
        for (int k = 0; k < 4; k++) {
          int a = i + dx[k], b = j + dy[k];
          if (a > n || a < 1 || b > m || b < 1) continue;
          if (all[a][b] == 'X') continue;
          z++;
        }
        if (z == 2 || z == 4 || z == 0) {
          if (z == 2)
            res[i][j] = 5;
          else if (z == 4)
            res[i][j] = 10;
          else
            res[i][j] = -1;
          continue;
        }
        ok = 0;
        break;
      }
    }
  }
  if (ok == 0)
    cout << "NO";
  else {
    f();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (res[i][j] == 0) res[i][j] = 1;
        if (res[i][j] == -1) res[i][j] = 0;
        cout << res[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
