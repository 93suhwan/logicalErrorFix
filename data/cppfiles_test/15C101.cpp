#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int v[n][m];
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++)
        if (s[j] == '*') v[i][j] = 1;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (v[i][j]) {
          int sz = 0;
          while (i > sz && j > sz && j + sz < m - 1) {
            if (!v[i - sz - 1][j - sz - 1] || !v[i - sz - 1][j + 1 + sz]) break;
            ++sz;
          }
          if (sz >= k) {
            for (int a = 0; a <= sz; a++)
              v[i - a][j + a] = -1, v[i - a][j - a] = -1;
          }
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (v[i][j] == 1) ok = false;
    cout << (ok ? "YES" : "NO") << endl;
  }
}
