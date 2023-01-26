#include <bits/stdc++.h>
using namespace std;
char ans[200][200];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
      memset(ans, 0, sizeof(ans));
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
          ans[i][j] = '.';
        }
      }
      if (k % 2 == 0 && k <= (n / 2) * ((m / 2) * 2)) {
        cout << "YES" << endl;
        for (long long i = 0; i + 1 < n; i += 2) {
          for (long long j = 0; j + 1 < m; j += 2) {
            if (k) {
              if ((i / 2 + j / 2) % 2) {
                ans[i][j] = ans[i][j + 1] = 'a';
                ans[i + 1][j] = ans[i + 1][j + 1] = 'b';
              } else {
                ans[i][j] = ans[i][j + 1] = 'c';
                ans[i + 1][j] = ans[i + 1][j + 1] = 'd';
              }
              k -= 2;
            } else {
              if ((i / 2 + j / 2) % 2) {
                ans[i][j] = ans[i + 1][j] = 'e';
                ans[i][j + 1] = ans[i + 1][j + 1] = 'f';
              } else {
                ans[i][j] = ans[i + 1][j] = 'g';
                ans[i][j + 1] = ans[i + 1][j + 1] = 'h';
              }
            }
          }
        }
        if (m % 2) {
          for (long long i = 0; i < n; i += 2) {
            if ((i / 2) % 2)
              ans[i][m - 1] = ans[i + 1][m - 1] = 'i';
            else
              ans[i][m - 1] = ans[i + 1][m - 1] = 'j';
          }
        }
        for (long long i = 0; i < n; i++) {
          for (long long j = 0; j < m; j++) {
            cout << ans[i][j];
          }
          cout << endl;
        }
      } else
        cout << "NO" << endl;
    } else {
      k = n * m / 2 - k;
      if (k % 2 == 0 && k <= (m / 2) * ((n / 2) * 2)) {
        cout << "YES" << endl;
        for (long long i = 0; i + 1 < n; i += 2) {
          for (long long j = 0; j + 1 < m; j += 2) {
            if (k) {
              if ((i / 2 + j / 2) % 2) {
                ans[i][j] = ans[i + 1][j] = 'a';
                ans[i][j + 1] = ans[i + 1][j + 1] = 'b';
              } else {
                ans[i][j] = ans[i + 1][j] = 'c';
                ans[i][j + 1] = ans[i + 1][j + 1] = 'd';
              }
              k -= 2;
            } else {
              if ((i / 2 + j / 2) % 2) {
                ans[i][j] = ans[i][j + 1] = 'e';
                ans[i + 1][j] = ans[i + 1][j + 1] = 'f';
              } else {
                ans[i][j] = ans[i][j + 1] = 'g';
                ans[i + 1][j] = ans[i + 1][j + 1] = 'h';
              }
            }
          }
        }
        if (n % 2) {
          for (long long i = 0; i < m; i += 2) {
            if ((i / 2) % 2)
              ans[n - 1][i] = ans[n - 1][i + 1] = 'i';
            else
              ans[n - 1][i] = ans[n - 1][i + 1] = 'j';
          }
        }
        for (long long i = 0; i < n; i++) {
          for (long long j = 0; j < m; j++) {
            cout << ans[i][j];
          }
          cout << endl;
        }
      } else
        cout << "NO" << endl;
    }
  }
  return 0;
}
