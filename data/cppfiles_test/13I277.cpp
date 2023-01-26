#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long x = (n * m) / 2;
    long long f = 0;
    long long num = 0;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        f = 1;
        num = 1;
      }
    } else if (m % 2 == 1) {
      if (k <= x - n / 2 && k % 2 == 0) {
        f = 1;
        num = 2;
      }
    } else {
      if (k >= m / 2 && (k - m / 2) % 2 == 0) {
        f = 1;
        num = 3;
      }
    }
    if (f) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
    if (f) {
      long long a[n][m];
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
          a[i][j] = 0;
        }
      }
      if (num == 1) {
        long long flag = 1;
        for (long long i = 0; i < n && k > 0; i += 2) {
          flag = 1;
          for (long long j = 0; j < m && k > 0; j += 2) {
            if (flag) {
              a[i][j] = 1;
              a[i][j + 1] = 1;
              a[i + 1][j] = 2;
              a[i + 1][j + 1] = 2;
              k -= 2;
              flag = 0;
            } else {
              a[i][j] = 3;
              a[i][j + 1] = 3;
              a[i + 1][j] = 4;
              a[i + 1][j + 1] = 4;
              k -= 2;
              flag = 1;
            }
          }
        }
      }
      if (num == 2) {
        long long flag = 1;
        for (long long i = 0; i < n && k > 0; i += 2) {
          flag = 1;
          for (long long j = 1; j < m && k > 0; j += 2) {
            if (flag) {
              a[i][j] = 1;
              a[i][j + 1] = 1;
              a[i + 1][j] = 2;
              a[i + 1][j + 1] = 2;
              k -= 2;
              flag = 0;
            } else {
              a[i][j] = 3;
              a[i][j + 1] = 3;
              a[i + 1][j] = 4;
              a[i + 1][j + 1] = 4;
              k -= 2;
              flag = 1;
            }
          }
        }
      }
      if (num == 3) {
        long long flag = 1;
        for (long long i = 0; i < m; i += 2) {
          a[0][i] = 8;
          a[0][i + 1] = 8;
          k--;
        }
        for (long long i = 1; i < n && k > 0; i += 2) {
          flag = 1;
          for (long long j = 0; j < m && k > 0; j += 2) {
            if (flag) {
              a[i][j] = 1;
              a[i][j + 1] = 1;
              a[i + 1][j] = 2;
              a[i + 1][j + 1] = 2;
              k -= 2;
              flag = 0;
            } else {
              a[i][j] = 3;
              a[i][j + 1] = 3;
              a[i + 1][j] = 4;
              a[i + 1][j + 1] = 4;
              k -= 2;
              flag = 1;
            }
          }
        }
      }
      long long cc = 0;
      if (n % 2) {
        cc = 1;
      }
      for (long long i = 0; i < n; i++) {
        long long flag = 1;
        long long cnt = 0;
        for (long long j = 0; j < m; j++) {
          if (a[i][j] == 0) {
            if ((i + cc) % 4 == 0) {
              if (flag) {
                a[i][j] = 11;
                a[i + 1][j] = 11;
                cnt = 1;
                flag = 0;
              } else {
                a[i][j] = 12;
                a[i + 1][j] = 12;
                cnt = 1;
                flag = 1;
              }
            } else {
              if (flag) {
                a[i][j] = 13;
                a[i + 1][j] = 13;
                cnt = 1;
                flag = 0;
              } else {
                a[i][j] = 14;
                a[i + 1][j] = 14;
                cnt = 1;
                flag = 1;
              }
            }
          }
        }
        i += cnt;
      }
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
          char b = 'a' + a[i][j];
          cout << b;
        }
        cout << "\n";
      }
    }
  }
}
