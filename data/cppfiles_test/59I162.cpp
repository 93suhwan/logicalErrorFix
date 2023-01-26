#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, k, flag = 0;
    cin >> n;
    int a[n][5];
    for (i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) cin >> a[i][j];
    }
    for (i = 0; i < 5; i++) {
      int x = 0, y = 0;
      for (j = i + 1; j < 5; j++) {
        for (k = 0; k < n; k++) {
          if (a[k][i] == 1) x++;
          if (a[k][j] == 1) y++;
        }
        if (x >= n / 2 and y >= n / 2) flag = 1;
      }
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
