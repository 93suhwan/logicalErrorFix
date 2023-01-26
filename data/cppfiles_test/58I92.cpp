#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    vector<string> grid;
    int n;
    cin >> n;
    string ans = "YES", row;
    for (int i = 0; i < 2; i++) {
      cin >> row;
      grid.push_back(row);
    }
    for (int i = 0; i < n - 1; i++) {
      int temp = int(grid[0][i]) + int(grid[0][i + 1]) + int(grid[1][i]) +
                 int(grid[1][i + 1]);
      if (temp > 194) {
        ans = "NO";
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
