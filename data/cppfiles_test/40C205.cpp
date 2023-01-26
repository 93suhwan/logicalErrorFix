#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int m;
    cin >> m;
    vector<vector<long long int>> arr(2, vector<long long int>(m, 0));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }
    if (m == 1) {
      cout << 0 << endl;
      continue;
    }
    vector<long long int> b(m, 0);
    vector<long long int> c(m, 0);
    b[0] = arr[1][0];
    for (int i = 1; i < m; i++) {
      b[i] = b[i - 1] + arr[1][i];
    }
    c[m - 1] = arr[0][m - 1];
    for (int i = m - 2; i >= 0; i--) {
      c[i] = c[i + 1] + arr[0][i];
    }
    long long int ans = min(b[m - 2], c[1]);
    for (int i = 1; i < m - 1; i++) {
      ans = min(ans, max(b[i - 1], c[i + 1]));
    }
    cout << ans << endl;
  }
  return 0;
}
