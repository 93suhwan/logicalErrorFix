#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> a(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) a[i][j] = (s[j] == '*');
    }
    vector<vector<bool>> b(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int d = k; i + d < n && j + d * 2 < m; d++) {
          bool ok = true;
          for (int t = 0; t <= d; t++)
            ok &= (a[i + t][j + t] && a[i + d - t][j + d + t]);
          if (ok)
            for (int t = 0; t <= d; t++)
              b[i + t][j + t] = b[i + d - t][j + d + t] = true;
        }
    bool suc = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] != b[i][j]) suc = false;
    if (suc)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
