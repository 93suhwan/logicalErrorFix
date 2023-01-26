#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[55];
char x[55][55];
int main() {
  cin >> t;
  while (t--) {
    int dem1 = 0, dem2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
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
            else
              x[i][j] = '=';
      } else {
        for (int i = 1; i <= n; i++) {
          bool ok = true;
          for (int j = 1; j <= n; j++) {
            if (i == j)
              x[i][j] = 'X';
            else {
              if (a[i] == 1)
                if (a[j] == 2)
                  x[i][j] = '+';
                else
                  x[i][j] = '=';
              if (a[i] == 2)
                if (a[j] == 2)
                  if (ok && x[j][i] != '+') {
                    x[i][j] = '+';
                    ok = false;
                  } else
                    x[i][j] = '-';
                else
                  x[i][j] = '-';
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
