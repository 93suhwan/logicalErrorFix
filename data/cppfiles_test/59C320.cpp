#include <bits/stdc++.h>
using namespace std;
int stud[1001][6];
int n, i, j, k, ki, kj, t;
int ok;
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= 5; j++) cin >> stud[i][j];
    int fin = 0;
    for (i = 1; i <= 4; i++) {
      for (j = i + 1; j <= 5; j++) {
        ok = 1;
        for (k = 1; k <= n; k++)
          if (stud[k][i] == 0 && stud[k][j] == 0) {
            ok = 0;
            break;
          }
        if (ok == 0) continue;
        ki = kj = 0;
        for (k = 1; k <= n; k++) {
          if (stud[k][i] == 1 && stud[k][j] == 0) ki++;
          if (stud[k][j] == 1 && stud[k][i] == 0) kj++;
        }
        if (ki > n / 2 || kj > n / 2)
          ok = 0;
        else {
          fin = 1;
          break;
        }
      }
      if (fin == 1) break;
    }
    if (ok == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
