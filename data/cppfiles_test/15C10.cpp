#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k, i, j, l, sz = 0;
  cin >> n >> m >> k;
  char a[n][m], b[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
      b[i][j] = '.';
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        for (l = 1; i - l >= 0 && j + l < m && j - l >= 0; l++) {
          if (a[i - l][j + l] == '*' && a[i - l][j - l] == '*')
            ++sz;
          else
            break;
        }
        if (sz >= k) {
          for (l = 0; l <= sz; l++) {
            b[i - l][j + l] = '*';
            b[i - l][j - l] = '*';
          }
        }
      }
      sz = 0;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (b[i][j] != a[i][j]) {
        cout << "NO \n";
        return;
      }
    }
  }
  cout << "YES \n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  while (test--) solve();
  return 0;
}
