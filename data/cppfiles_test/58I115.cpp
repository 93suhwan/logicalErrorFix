#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, y, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[2][n];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    y = 0;
    for (int i = 1; i < n - 1; i++) {
      if (!a[0][i] || !a[1][i]) {
        y++;
      } else {
        break;
      }
    }
    if (y == n - 2)
      cout << "YES\n";
    else
      cout << "NO \n";
  }
}
