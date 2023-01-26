#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int input[n + 5][m + 5];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> input[i][j];
  int i = 1;
  while (i <= k) {
    int r = 1, c;
    cin >> c;
    while (1) {
      if (r > n) {
        cout << c << " ";
        break;
      }
      if (input[r][c] == 2)
        r++;
      else if (input[r][c] == 1) {
        input[r][c] = 2;
        c++;
      } else {
        input[r][c] = 2;
        c--;
      }
    }
    i++;
  }
  return;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
