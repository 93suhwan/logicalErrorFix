#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  char a[n][m];
  int x[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      x[i][j] = 0;
    }
  }
  for (int i = k; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        int f = 0;
        int s1 = i, s2 = j, s3 = j, c = -1;
        while (s1 >= 0 && s2 >= 0 && s3 <= m - 1) {
          if (a[s1][s2] == '*' && a[s1][s3] == '*') {
            c++;
          } else {
            break;
          }
          s1--, s2--, s3++;
        }
        if (c >= k) {
          s1 = i, s2 = j, s3 = j;
          while (s1 >= 0 && s2 >= 0 && s3 <= m - 1) {
            if (a[s1][s2] == '*' && a[s1][s3] == '*') {
              x[s1][s2] = 1;
              x[s1][s3] = 1;
            } else {
              break;
            }
            s1--, s2--, s3++;
          }
        }
      }
    }
  }
  int fail = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*' && x[i][j] == 0)
        fail = 1;
      else if (a[i][j] == '.' && x[i][j] == 1)
        fail = 1;
    }
  }
  if (fail)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
