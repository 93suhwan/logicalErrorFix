#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, m;
  cin >> t;
  while (t--) {
    cin >> m;
    int arr[2][m];
    cin >> arr[0][0];
    arr[0][0] = 0;
    for (int i = 1; i < m; i++) {
      cin >> arr[0][i];
      arr[0][i] += arr[0][i - 1];
    }
    cin >> arr[1][0];
    for (int j = 1; j < m; j++) {
      cin >> arr[1][j];
      arr[1][j] += arr[1][j - 1];
    }
    arr[1][m - 1] = 0;
    if (m == 1) {
      cout << 0 << endl;
      continue;
    }
    int ans = min(arr[0][m - 1], arr[1][m - 2]);
    for (int j = 1; j < m; j++) {
      ans = min(ans, max(arr[0][m - 1] - arr[0][j], arr[1][j - 1]));
    }
    cout << ans << endl;
  }
  return 0;
}
