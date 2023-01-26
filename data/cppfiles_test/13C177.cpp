#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n, m, h;
    cin >> n >> m >> h;
    long long v = n * m / 2 - h;
    if (n % 2 == 0 && m % 2 == 0) {
      if (v % 2 == 0 && h % 2 == 0) {
        cout << "YES\n";
        char ans[n][m];
        long long a = 0, b = 0;
        for (long long i = 0; i < h; i += 2) {
          if (b % 4 == 0) {
            ans[a][b] = 'a';
            ans[a][b + 1] = 'a';
            ans[a + 1][b] = 'b';
            ans[a + 1][b + 1] = 'b';
          } else {
            ans[a][b] = 'b';
            ans[a][b + 1] = 'b';
            ans[a + 1][b] = 'a';
            ans[a + 1][b + 1] = 'a';
          }
          b += 2;
          if (b >= m) {
            b = 0;
            a += 2;
          }
        }
        for (long long i = 0; i < v; i += 2) {
          if (a % 4 == 0) {
            ans[a][b] = 'c';
            ans[a][b + 1] = 'd';
            ans[a + 1][b] = 'c';
            ans[a + 1][b + 1] = 'd';
          } else {
            ans[a][b] = 'd';
            ans[a][b + 1] = 'c';
            ans[a + 1][b] = 'd';
            ans[a + 1][b + 1] = 'c';
          }
          b += 2;
          if (b >= m) {
            b = 0;
            a += 2;
          }
        }
        for (long long i = 0; i < n; i++) {
          for (long long j = 0; j < m; j++) {
            cout << ans[i][j];
          }
          cout << '\n';
        }
      } else
        cout << "NO\n";
    } else if (n % 2 == 0) {
      if (h % 2 == 1)
        cout << "NO\n";
      else {
        if (v >= n / 2) {
          cout << "YES\n";
          char ans[n][m];
          for (long long i = 0; i < n; i += 2) {
            if (i % 4 == 0) {
              ans[i][0] = 'p';
              ans[i + 1][0] = 'p';
            } else {
              ans[i][0] = 'q';
              ans[i + 1][0] = 'q';
            }
          }
          long long a = 0, b = 1;
          for (long long i = 0; i < h; i += 2) {
            if (b % 4 == 1) {
              ans[a][b] = 'a';
              ans[a][b + 1] = 'a';
              ans[a + 1][b] = 'b';
              ans[a + 1][b + 1] = 'b';
            } else {
              ans[a][b] = 'b';
              ans[a][b + 1] = 'b';
              ans[a + 1][b] = 'a';
              ans[a + 1][b + 1] = 'a';
            }
            b += 2;
            if (b >= m) {
              b = 1;
              a += 2;
            }
          }
          for (long long i = 0; i < v - n / 2; i += 2) {
            if (a % 4 == 0) {
              ans[a][b] = 'c';
              ans[a][b + 1] = 'd';
              ans[a + 1][b] = 'c';
              ans[a + 1][b + 1] = 'd';
            } else {
              ans[a][b] = 'd';
              ans[a][b + 1] = 'c';
              ans[a + 1][b] = 'd';
              ans[a + 1][b + 1] = 'c';
            }
            b += 2;
            if (b >= m) {
              b = 1;
              a += 2;
            }
          }
          for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
              cout << ans[i][j];
            }
            cout << '\n';
          }
        } else
          cout << "NO\n";
      }
    } else if (m % 2 == 0) {
      if (v % 2 == 1)
        cout << "NO\n";
      else {
        if (h >= m / 2) {
          cout << "YES\n";
          char ans[n][m];
          for (long long i = 0; i < m; i += 2) {
            if (i % 4 == 0) {
              ans[0][i] = 'p';
              ans[0][i + 1] = 'p';
            } else {
              ans[0][i] = 'q';
              ans[0][i + 1] = 'q';
            }
          }
          long long a = 1, b = 0;
          for (long long i = 0; i < h - m / 2; i += 2) {
            if (b % 4 == 0) {
              ans[a][b] = 'a';
              ans[a][b + 1] = 'a';
              ans[a + 1][b] = 'b';
              ans[a + 1][b + 1] = 'b';
            } else {
              ans[a][b] = 'b';
              ans[a][b + 1] = 'b';
              ans[a + 1][b] = 'a';
              ans[a + 1][b + 1] = 'a';
            }
            b += 2;
            if (b >= m) {
              b = 0;
              a += 2;
            }
          }
          for (long long i = 0; i < v; i += 2) {
            if (a % 4 == 1) {
              ans[a][b] = 'c';
              ans[a][b + 1] = 'd';
              ans[a + 1][b] = 'c';
              ans[a + 1][b + 1] = 'd';
            } else {
              ans[a][b] = 'd';
              ans[a][b + 1] = 'c';
              ans[a + 1][b] = 'd';
              ans[a + 1][b + 1] = 'c';
            }
            b += 2;
            if (b >= m) {
              b = 0;
              a += 2;
            }
          }
          for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
              cout << ans[i][j];
            }
            cout << '\n';
          }
        } else
          cout << "NO\n";
      }
    }
  }
  return 0;
}
