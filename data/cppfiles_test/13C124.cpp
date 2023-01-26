#include <bits/stdc++.h>
using namespace std;
void solve(void) {
  int n, m, k;
  bool f = 1;
  cin >> n >> m >> k;
  char a[n][m], b[m][n];
  if (m % 2) {
    if (k > n * (m / 2)) {
      f = 0;
    } else {
      if (k % 2) {
        f = 0;
      }
    }
    if (f) {
      int maxy = 2 * (k % n ? k / n + 1 : k / n);
      maxy--;
      m--;
      for (int j = 0; j < m; j = j + 2) {
        for (int i = 0; i < n; i++) {
          if (k) {
            a[i][j] = (i % 2 + (j / 2) % 2) % 2 + 'a';
            a[i][j + 1] = a[i][j];
            k--;
          } else if (j > maxy) {
            a[i][j] = 'c' + (i / 2) % 2;
            a[i][j + 1] = 'd' - (i / 2) % 2;
          } else {
            a[i][j] = 'x' + (i / 2) % 2;
            a[i][j + 1] = 'y' - (i / 2) % 2;
          }
        }
      }
      m++;
      for (int i = 0; i < n; i = i + 2) {
        a[i][m - 1] = 'e' + (i / 2) % 2;
        a[i + 1][m - 1] = 'e' + (i / 2) % 2;
      }
    }
  } else if (n % 2) {
    k = (n * m) / 2 - k;
    if (k > m * (n / 2)) {
      f = 0;
    } else {
      if (k % 2) {
        f = 0;
      }
    }
    if (f) {
      int maxx = 2 * (k % m ? k / m + 1 : k / m);
      maxx--;
      n--;
      for (int i = 0; i < n; i = i + 2) {
        for (int j = 0; j < m; j++) {
          if (k) {
            a[i][j] = 'a' + (j % 2 + (i / 2) % 2) % 2;
            a[i + 1][j] = a[i][j];
            k--;
          } else if (i > maxx) {
            a[i][j] = 'c' + (j / 2) % 2;
            a[i + 1][j] = 'd' - (j / 2) % 2;
          } else {
            a[i][j] = 'x' + (j / 2) % 2;
            a[i + 1][j] = 'y' - (j / 2) % 2;
          }
        }
      }
      n++;
      for (int j = 0; j < m; j++) {
        a[n - 1][j] = 'e' + (j / 2) % 2;
      }
    }
  } else {
    if (k % 2) {
      f = 0;
    }
    if (f) {
      int maxy = 2 * (k % n ? k / n + 1 : k / n);
      maxy--;
      for (int j = 0; j < m; j = j + 2) {
        for (int i = 0; i < n; i++) {
          if (k) {
            a[i][j] = (i % 2 + (j / 2) % 2) % 2 + 'a';
            a[i][j + 1] = a[i][j];
            k--;
          } else if (j > maxy) {
            a[i][j] = 'c' + (i / 2) % 2;
            a[i][j + 1] = 'd' - (i / 2) % 2;
          } else {
            a[i][j] = 'x' + (i / 2) % 2;
            a[i][j + 1] = 'y' - (i / 2) % 2;
          }
        }
      }
    }
  }
  if (f) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test_case;
  cin >> test_case;
  while (test_case--) {
    solve();
  }
  return 0;
}
