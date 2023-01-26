#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> matrix[i][j];
      }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool flag = true;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (matrix[i][j] == '*') {
          long long d = 0;
          while (true) {
            if (i - d < 0 || j - d < 0 || j + d >= m ||
                matrix[i - d][j - d] != '*' || matrix[i - d][j + d] != '*') {
              break;
            }
            d++;
          }
          if (d > k) {
            for (long long l = 0; l < d; l++) {
              visited[i - l][j - l] = true;
              visited[i - l][j + l] = true;
            }
          }
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (matrix[i][j] == '*' && !visited[i][j]) {
          flag = false;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
