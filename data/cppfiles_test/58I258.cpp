#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string ans = "YES";
    int grid[2][n];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (grid[0][i] + grid[0][i + 1] + grid[1][i] + grid[1][i + 1] > 2) {
        ans = "NO";
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
