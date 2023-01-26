#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int n, m, k;
    cin >> n >> m >> k;
    char a[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<int>> count(n, vector<int>(m, 0));
    for (int i = k; i < n; i++) {
      for (int j = k; j < m - k; j++) {
        if (a[i][j] == '*') {
          int cnt = 0;
          while (a[i - cnt - 1][j - cnt - 1] == '*' &&
                 a[i - cnt - 1][j + cnt + 1] == '*') {
            cnt++;
          }
          for (int l = 0; l <= cnt; l++) {
            count[i - l][j - l] = max(cnt, count[i - l][j - l]);
            count[i - l][j + l] = max(cnt, count[i - l][j + l]);
          }
        }
      }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '*') {
          if (count[i][j] < k) {
            flag = 1;
            cout << "NO\n";
            break;
          }
        }
      }
      if (flag) break;
    }
    if (!flag) cout << "YES\n";
  }
}
