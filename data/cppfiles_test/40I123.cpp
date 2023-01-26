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
    vector<long long int> a(m, 0);
    vector<long long int> b(m, 0);
    vector<long long int> c(m, 0);
    vector<long long int> d(m, 0);
    a[0] = arr[0][0];
    b[0] = arr[1][0];
    for (int i = 1; i < m; i++) {
      a[i] = a[i - 1] + arr[0][i];
      b[i] = b[i - 1] + arr[1][i];
    }
    c[m - 1] = arr[0][m - 1];
    d[m - 1] = arr[1][m - 1];
    for (int i = m - 2; i >= 0; i--) {
      c[i] = c[i + 1] + arr[0][i];
      d[i] = d[i + 1] + arr[1][i];
    }
    long long int ans = INT_MAX;
    ans = min(ans, min(b[m - 2], c[1]));
    for (int i = 1; i < m - 1; i++) {
      ans = min(ans, max(b[i - 1], c[i + 1]));
    }
    if (ans == INT_MAX) {
      cout << 0 << endl;
      continue;
    }
    cout << ans << endl;
  }
  return 0;
}
