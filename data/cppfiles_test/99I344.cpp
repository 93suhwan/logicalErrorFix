#include <bits/stdc++.h>
using namespace std;
int t, n, X;
int a[55], b[55];
char x[55][55];
void tachso(int X) {
  int dem = 0;
  while (X != 0) {
    b[++dem] = X % 10;
    X /= 10;
  }
}
int main() {
  cin >> t;
  while (t--) {
    int dem1 = 0, dem2 = 0;
    cin >> n;
    cin >> X;
    tachso(X);
    int dem5 = 0;
    for (int i = n; i >= 1; i--) a[++dem5] = b[i];
    for (int i = 1; i <= n; i++)
      if (a[i] == 1)
        dem1++;
      else
        dem2++;
    if (dem2 <= 2 && dem2 > 0)
      cout << "NO"
           << "\n";
    else {
      cout << "YES"
           << "\n";
      if (dem2 == 0) {
        for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
            if (i == j)
              x[i][j] = 'X';
            else {
              x[i][j] = '=';
              x[j][i] = '=';
            }
      } else {
        for (int i = 1; i <= n; i++) {
          bool ok = true;
          for (int j = 1; j <= n; j++) {
            if (i == j)
              x[i][j] = 'X';
            else {
              if (a[i] == 1) {
                x[i][j] = '=';
                x[j][i] = '=';
              }
              if (a[i] == 2)
                if (a[j] == 2)
                  if (ok && x[j][i] != '+') {
                    x[i][j] = '+';
                    x[j][i] = '-';
                    ok = false;
                  } else
                    x[i][j] = x[j][i] = '=';
            }
          }
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << x[i][j];
        cout << endl;
      }
    }
  }
  return 0;
}
