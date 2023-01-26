#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, maxk;
    cin >> n >> m >> k;
    maxk = min(n - 1, (m - 1) / 2);
    string s[n];
    bool visited[n][m];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) visited[i][j] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (s[i][j] == '*') {
          int temp = 0;
          for (int l = i - 1; l >= i - maxk; l--) {
            if (l < 0 || j + i - l >= m || j - i + l < 0 ||
                s[l][j + i - l] != '*' || s[l][j - i + l] != '*')
              break;
            temp = i - l;
          }
          if (temp < k) continue;
          for (int l = 0; l <= temp; l++) {
            visited[i - l][j + l] = visited[i - l][j - l] = 1;
          }
        }
    bool ok = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (s[i][j] == '*' && !visited[i][j]) {
          ok = 0;
          break;
        }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
