#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int m;
    cin >> m;
    int t[2][m + 1];
    int tmp;
    t[0][0] = t[1][0] = 0;
    int tot = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> tmp;
        t[i][j] = t[i][j - 1] + tmp;
      }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= m; i++)
      ans = min(ans, max(t[0][m] - t[0][i], t[1][i - 1]));
    cout << ans << "\n";
  }
  return 0;
}
