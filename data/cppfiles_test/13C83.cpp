#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
char a[maxn][maxn];
signed main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = 'z';
      }
    }
    int i = 0;
    if (n % 2 == 1) {
      if (k < m / 2) {
        cout << "NO" << '\n';
        continue;
      }
      k -= m / 2;
      for (int i = 0; i < m; i += 2) {
        if (i % 4 == 0) {
          a[0][i] = 'x';
          a[0][i + 1] = 'x';
        } else {
          a[0][i] = 'y';
          a[0][i + 1] = 'y';
        }
      }
      i++;
    }
    if (k % 2 == 1) {
      cout << "NO" << '\n';
      continue;
    }
    if ((m - (m % 2)) * (n - i) < 2 * k) {
      cout << "NO" << '\n';
      continue;
    }
    int j = 0;
    int c = 0;
    while (c < k) {
      if (j % 4 == 0) {
        a[i][j] = 'a';
        a[i][j + 1] = 'a';
        a[i + 1][j] = 'b';
        a[i + 1][j + 1] = 'b';
        j += 2;
        if (j >= m - 1) {
          i += 2;
          j = 0;
        }
      } else {
        a[i][j] = 'c';
        a[i][j + 1] = 'c';
        a[i + 1][j] = 'd';
        a[i + 1][j + 1] = 'd';
        j += 2;
        if (j >= m - 1) {
          i += 2;
          j = 0;
        }
      }
      c += 2;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'z') {
          if (i % 4 < 2) {
            if (j % 2 == 0) {
              a[i][j] = 'e';
              a[i + 1][j] = 'e';
            } else {
              a[i][j] = 'f';
              a[i + 1][j] = 'f';
            }
          } else {
            if (j % 2 == 0) {
              a[i][j] = 'g';
              a[i + 1][j] = 'g';
            } else {
              a[i][j] = 'h';
              a[i + 1][j] = 'h';
            }
          }
        }
      }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
}
