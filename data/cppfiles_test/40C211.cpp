#include <bits/stdc++.h>
using namespace std;
int a[3][100050];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        a[i][j] += a[i][j - 1];
      }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
      ans = min(ans, max(a[1][m] - a[1][i], a[2][i - 1]));
    }
    cout << ans << endl;
  }
  return 0;
}
