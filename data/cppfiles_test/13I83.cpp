#include <bits/stdc++.h>
using namespace std;
char c[110][110];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 1) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= m; j += 2) {
          char a, b;
          if ((i / 2 + j / 2) % 2 == 0)
            a = 'a', b = 'b';
          else
            a = 'c', b = 'd';
          if (k) {
            c[i][j] = c[i][j + 1] = a;
            c[i + 1][j] = c[i + 1][j + 1] = b;
            k -= 2;
          } else {
            c[i][j] = c[i + 1][j] = a;
            c[i][j + 1] = c[i + 1][j + 1] = b;
          }
        }
      }
    } else if (m % 2 == 0) {
      if (k < m / 2 || (k - m / 2) % 2 == 1) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      for (int i = 1; i <= m; i += 2) {
        if ((i / 2) % 2)
          c[1][i] = c[1][i + 1] = 'x';
        else
          c[1][i] = c[1][i + 1] = 'y';
      }
      for (int i = 2; i <= n; i += 2) {
        for (int j = 1; j <= m; j += 2) {
          char a, b;
          if ((i / 2 + j / 2) % 2 == 0)
            a = 'a', b = 'b';
          else
            a = 'c', b = 'd';
          if (k) {
            c[i][j] = c[i][j + 1] = a;
            c[i + 1][j] = c[i + 1][j + 1] = b;
            k -= 2;
          } else {
            c[i][j] = c[i + 1][j] = a;
            c[i][j + 1] = c[i + 1][j + 1] = b;
          }
        }
      }
    } else if (n % 2 == 0) {
      if (k > (m - 1) * n / 2 || k % 2 == 1) {
        cout << "NO" << '\n';
        continue;
      }
      cout << "YES" << '\n';
      for (int i = 1; i <= n; i += 2) {
        if ((i / 2) % 2)
          c[i][1] = c[i + 1][1] = 'x';
        else
          c[i][1] = c[i + 1][1] = 'y';
      }
      for (int i = 1; i <= n; i += 2) {
        for (int j = 2; j <= m; j += 2) {
          char a, b;
          if ((i / 2 + j / 2) % 2 == 0)
            a = 'a', b = 'b';
          else
            a = 'c', b = 'd';
          if (k) {
            c[i][j] = c[i][j + 1] = a;
            c[i + 1][j] = c[i + 1][j + 1] = b;
            k -= 2;
          } else {
            c[i][j] = c[i + 1][j] = a;
            c[i][j + 1] = c[i + 1][j + 1] = b;
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << c[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
