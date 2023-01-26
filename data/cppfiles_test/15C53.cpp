#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    char a[n][m];
    bool used[n][m];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
        used[i][j] = false;
      }
    }
    for (long long i = k; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (a[i][j] == '.') continue;
        bool ok = true;
        for (long long d = 1; d <= k; d++) {
          if (j - d < 0 || j + d >= m) {
            ok = false;
            break;
          }
          if (a[i - d][j - d] != '*' || a[i - d][j + d] != '*') ok = false;
        }
        if (!ok) continue;
        long long d = k + 1;
        while (j - d >= 0 && j + d < m && i - d >= 0) {
          if (a[i - d][j - d] != '*' || a[i - d][j + d] != '*') break;
          d++;
        }
        d--;
        for (long long h = 0; h <= d; h++) {
          used[i - h][j - h] = used[i - h][j + h] = true;
        }
      }
    }
    bool ans = true;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (a[i][j] == '*' && !used[i][j]) ans = false;
      }
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
  return 0;
}
