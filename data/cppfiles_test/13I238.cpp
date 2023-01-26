#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int p = n * m;
  int q = p / 2;
  int hor = 0;
  int ver = 0;
  char ans[n][m];
  memset(ans, '@', sizeof(ans));
  int nn = n;
  int mm = m;
  if (n % 2 == 1) {
    hor = m / 2;
    nn--;
    char zz = 'y';
    for (int j = 0; j < m - 1; j++) {
      ans[n - 1][j] = zz;
      ans[n - 1][j + 1] = zz;
      j++;
      if (zz == 'y') {
        zz = 'z';
      } else {
        zz = 'y';
      }
    }
  }
  if (m % 2 == 1) {
    ver = n / 2;
    char zz = 'y';
    for (int j = 0; j < n - 1; j++) {
      ans[j][m - 1] = zz;
      ans[j + 1][m - 1] = zz;
      j++;
      if (zz == 'y') {
        zz = 'z';
      } else {
        zz = 'y';
      }
    }
  }
  int h = k;
  int v = q - k;
  if (h < hor || v < ver) {
    cout << "NO"
         << "\n";
    return;
  }
  int flexi = q - hor - ver;
  h -= hor;
  v -= ver;
  if (h % 2 != 0) {
    cout << "NO"
         << "\n";
    return;
  }
  int ci = 0;
  int curh = 0;
  for (int j = 0; j < mm; j++) {
    for (int i = 0; i < nn; i++) {
      if (ans[i][j] != '@') continue;
      if (ci > 23) ci = 0;
      char c = 'a' + ci;
      if (i > 0 && (ans[i - 1][j] == c || ans[i - 1][j + 1] == c)) {
        ci++;
        if (ci > 23) ci = 0;
        c = 'a' + ci;
      }
      if (j > 0 && ans[i][j - 1] == c) {
        ci++;
        if (ci > 23) ci = 0;
        c = 'a' + ci;
      }
      if (curh < h) {
        ans[i][j] = c;
        ans[i][j + 1] = c;
        ci++;
        curh++;
      } else {
        if (i > 0 && ans[i - 1][j + 1] == c) {
          ci++;
          if (ci > 23) ci = 0;
          c = 'a' + ci;
        }
        ans[i][j] = c;
        ans[i + 1][j] = c;
        ci++;
        i++;
      }
    }
  }
  cout << "YES"
       << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test;
  cin >> test;
  for (int i = 1; i <= test; i++) solve();
  return 0;
}
