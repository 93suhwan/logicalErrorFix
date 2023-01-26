#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    int b[2][2];
    int f = 0;
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        if (x != y) {
          b[0][0] = b[1][0] = b[0][1] = 0;
          for (int i = 0; i < n; i++) {
            ++b[a[i][x]][a[i][y]];
          }
          if (b[0][0]) continue;
          if (b[0][1] <= (n / 2) && b[1][0] <= (n / 2)) {
            f = 1;
            break;
          }
        }
        if (f) break;
      }
      if (f) break;
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
