#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int n, m, q, hor[N][N], ver[N][N], ans, x, y, ix, jx, v, h, vv, hh;
int main() {
  vector<vector<bool> > free(N, vector<bool>(N, 1));
  scanf("%d%d%d", &n, &m, &q);
  ans = n * m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (j > 0) {
        hor[i][j] = 1;
        if (i > 0) hor[i][j] += hor[i - 1][j - 1];
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i > 0) {
        ver[i][j] = 1;
        if (j > 0) ver[i][j] += ver[i - 1][j - 1];
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      ans += hor[i][j];
      ans += ver[i][j];
      if (i > 0) ans += hor[i - 1][j];
      if (j > 0) ans += ver[i][j - 1];
    }
  while (q--) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    if (free[x][y]) {
      ans = ans - hor[x][y] - ver[x][y] - (x > 0 ? hor[x - 1][y] : 0) -
            (y > 0 ? ver[x][y - 1] : 0) - 1;
      h = hor[x][y], v = ver[x][y];
      free[x][y] = hor[x][y] = ver[x][y] = 0;
      ix = 0, jx = 1;
      while (free[x + ix][y + jx] && x + ix < n && y + jx < m) {
        if (jx > ix) {
          ans -= hor[x + ix][y + jx];
          ans -= v;
          hh = hor[x + ix][y + jx];
          if (jx == 1) hor[x + ix][y + jx] = 0;
          if (jx > 1) {
            hor[x + ix][y + jx] = 1;
            if (ix > 0) hor[x + ix][y + jx] += hor[x + ix - 1][y + jx - 1];
            ans += hor[x + ix][y + jx];
            ans += ver[x + ix][y + jx - 1];
          }
          ix++;
        } else {
          ans -= ver[x + ix][y + jx];
          ans -= hh;
          v = ver[x + ix][y + jx];
          if (ix > 0) {
            ver[x + ix][y + jx] = 1;
            if (jx > 0) ver[x + ix][y + jx] += ver[x + ix - 1][y + jx - 1];
            ans += ver[x + ix][y + jx];
            ans += hor[x + ix - 1][y + jx];
          }
          jx++;
        }
      }
      ix = 1, jx = 0;
      while (free[x + ix][y + jx] && x + ix < n && y + jx < m) {
        if (ix > jx) {
          ans -= ver[x + ix][y + jx];
          ans -= h;
          vv = ver[x + ix][y + jx];
          if (ix == 1) ver[x + ix][y + jx] = 0;
          if (ix > 1) {
            ver[x + ix][y + jx] = 1;
            if (jx > 0) ver[x + ix][y + jx] += ver[x + ix - 1][y + jx - 1];
            ans += ver[x + ix][y + jx];
            ans += hor[x + ix - 1][y + jx];
          }
          jx++;
        } else {
          ans -= hor[x + ix][y + jx];
          ans -= vv;
          h = hor[x + ix][y + jx];
          if (jx > 0) {
            hor[x + ix][y + jx] = 1;
            if (ix > 0) hor[x + ix][y + jx] += hor[x + ix - 1][y + jx - 1];
            ans += hor[x + ix][y + jx];
            ans += ver[x + ix][y + jx - 1];
          }
          ix++;
        }
      }
    } else {
      if (y > 0) {
        hor[x][y] = 1;
        if (x > 0) hor[x][y] += hor[x - 1][y - 1];
      }
      if (x > 0) {
        ver[x][y] = 1;
        if (y > 0) ver[x][y] += ver[x - 1][y - 1];
      }
      ans = ans + hor[x][y] + ver[x][y] + (x > 0 ? hor[x - 1][y] : 0) +
            (y > 0 ? ver[x][y - 1] : 0) + 1;
      v = h = 0;
      free[x][y] = 1;
      ix = 0, jx = 1;
      while (free[x + ix][y + jx] && x + ix < n && y + jx < m) {
        if (jx > ix) {
          ans -= hor[x + ix][y + jx];
          ans -= v;
          hh = hor[x + ix][y + jx];
          if (y + jx > 0) {
            hor[x + ix][y + jx] = 1;
            if (x + ix > 0) hor[x + ix][y + jx] += hor[x + ix - 1][y + jx - 1];
            ans += hor[x + ix][y + jx];
            ans += ver[x + ix][y + jx - 1];
          }
          ix++;
        } else {
          ans -= ver[x + ix][y + jx];
          ans -= hh;
          v = ver[x + ix][y + jx];
          if (x + ix > 0) {
            ver[x + ix][y + jx] = 1;
            if (y + jx > 0) ver[x + ix][y + jx] += ver[x + ix - 1][y + jx - 1];
            ans += ver[x + ix][y + jx];
            ans += hor[x + ix - 1][y + jx];
          }
          jx++;
        }
      }
      ix = 1, jx = 0;
      while (free[x + ix][y + jx] && x + ix < n && y + jx < m) {
        if (ix > jx) {
          ans -= ver[x + ix][y + jx];
          ans -= h;
          vv = ver[x + ix][y + jx];
          if (x + ix > 0) {
            ver[x + ix][y + jx] = 1;
            if (y + jx > 0) ver[x + ix][y + jx] += ver[x + ix - 1][y + jx - 1];
            ans += ver[x + ix][y + jx];
            ans += hor[x + ix - 1][y + jx];
          }
          jx++;
        } else {
          ans -= hor[x + ix][y + jx];
          ans -= vv;
          h = hor[x + ix][y + jx];
          if (y + jx > 0) {
            hor[x + ix][y + jx] = 1;
            if (x + ix > 0) hor[x + ix][y + jx] += hor[x + ix - 1][y + jx - 1];
            ans += hor[x + ix][y + jx];
            ans += ver[x + ix][y + jx - 1];
          }
          ix++;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
