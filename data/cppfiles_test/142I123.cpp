#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    int table[m][n];
    int ans = INT_MIN;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> table[i][j];
      }
      int mini = INT_MAX;
      for (int j = 0; j < n; j++) {
        mini = min(mini, table[i][j]);
      }
      ans = max(ans, mini);
    }
    cout << ans << endl;
  }
  return 0;
}
