#include <bits/stdc++.h>
using namespace std;
int n, m, k, dd[25][25], l = 0, r = 0, mi = 999999;
char a[25][25];
int trai(int i, int j) {
  l++;
  int ii = i - 1;
  int jj = j - 1;
  if (ii >= 1 && ii <= n && jj >= 1 && jj <= m && a[ii][jj] == '*')
    trai(ii, jj);
  return l;
}
int phai(int i, int j) {
  r++;
  int ii = i - 1;
  int jj = j + 1;
  if (ii >= 1 && ii <= n && jj >= 1 && jj <= m && a[ii][jj] == '*')
    phai(ii, jj);
  return r;
}
void left(int i, int j) {
  l--;
  dd[i][j] = max(dd[i][j], mi);
  int ii = i - 1;
  int jj = j - 1;
  if (ii >= 1 && ii <= n && jj >= 1 && jj <= m && l > 0 && a[ii][jj] == '*')
    left(ii, jj);
}
void right(int i, int j) {
  r--;
  dd[i][j] = max(dd[i][j], mi);
  int ii = i - 1;
  int jj = j + 1;
  if (ii >= 1 && ii <= n && jj >= 1 && jj <= m && r > 0 && a[ii][jj] == '*')
    right(ii, jj);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = n; i >= 1; i--) {
      for (int j = m; j >= 1; j--) {
        if (a[i][j] == '*') {
          l = 0;
          r = 0;
          mi = min(trai(i, j), phai(i, j));
          l = mi;
          r = mi;
          left(i, j);
          right(i, j);
        }
      }
    }
    int kt = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '*' && dd[i][j] - 1 < k) {
          kt = 0;
          break;
        }
      }
    }
    if (kt == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
