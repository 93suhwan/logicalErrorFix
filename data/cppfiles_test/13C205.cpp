#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, i, j, k, m, count, a, b, k1, k2, current, l, r, d, x, w;
  long long int sum, y;
  cin >> t;
  bool f;
  char s[102][102], c;
  while (t--) {
    cin >> n >> m >> k;
    a = k;
    long long int h = (n * m) / 2;
    b = h - a;
    c = 'a';
    for (i = 0; i < 102; i++) {
      for (j = 0; j < 102; j++) s[i][j] = '.';
    }
    if (n % 2 != 0) {
      if (a >= m / 2 && (a - m / 2) % 2 == 0) {
        cout << "YES\n";
        for (i = 0; i < m; i += 2) {
          s[0][i] = c;
          s[0][i + 1] = c;
          c = ((c == 'z') ? c = 'a' : c + 1);
          a--;
        }
        for (j = 0; j < m; j += 2) {
          if (a == 0) break;
          for (i = 1; i < n; i++) {
            if (a == 0) break;
            while (1) {
              if ((i > 0 && s[i - 1][j] == c) || (j > 0 && s[i][j - 1] == c))
                c = ((c == 'z') ? c = 'a' : c + 1);
              else
                break;
            }
            s[i][j] = c;
            s[i][j + 1] = c;
            a--;
          }
        }
        for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
            if ((s[i][j] == '.')) {
              while (1) {
                if ((i > 0 && s[i - 1][j] == c) ||
                    (j > 0 && s[i][j - 1] == c) ||
                    (j > 0 && s[i + 1][j - 1] == c))
                  c = ((c == 'z') ? c = 'a' : c + 1);
                else
                  break;
              }
              s[i][j] = c;
              s[i + 1][j] = c;
            }
          }
        }
        for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) cout << s[i][j];
          cout << "\n";
          ;
        }
      } else
        cout << "NO\n";
    } else if (m % 2 != 0) {
      if (b >= n / 2 && (b - n / 2) % 2 == 0) {
        cout << "YES\n";
        for (i = 0; i < n; i += 2) {
          s[i][0] = c;
          s[i + 1][0] = c;
          c = ((c == 'z') ? c = 'a' : c + 1);
          b--;
        }
        for (i = 0; i < n; i += 2) {
          if (b == 0) break;
          for (j = 1; j < m; j++) {
            if (b == 0) break;
            while (1) {
              if ((j > 0 && s[i][j - 1] == c) || (i > 0 && s[i - 1][j] == c))
                c = ((c == 'z') ? c = 'a' : c + 1);
              else
                break;
            }
            s[i][j] = c;
            s[i + 1][j] = c;
            b--;
          }
        }
        for (j = 0; j < m; j++) {
          for (i = 0; i < n; i++) {
            if (s[i][j] == '.') {
              while (1) {
                if ((i > 0 && s[i - 1][j] == c) ||
                    (i > 0 && s[i - 1][j + 1] == c) ||
                    (j > 0 && s[i][j - 1] == c))
                  c = ((c == 'z') ? c = 'a' : c + 1);
                else
                  break;
              }
              s[i][j] = c;
              s[i][j + 1] = c;
            }
          }
        }
        for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) cout << s[i][j];
          cout << "\n";
          ;
        }
      } else
        cout << "NO\n";
    } else {
      if (a % 2 == 0) {
        cout << "YES\n";
        for (j = 0; j < m; j += 2) {
          if (a == 0) break;
          for (i = 0; i < n; i++) {
            if (a == 0) break;
            while (1) {
              if ((i > 0 && s[i - 1][j] == c) || (j > 0 && s[i][j - 1] == c))
                c = ((c == 'z') ? c = 'a' : c + 1);
              else
                break;
            }
            s[i][j] = c;
            s[i][j + 1] = c;
            a--;
          }
        }
        for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) {
            if ((s[i][j] == '.')) {
              while (1) {
                if ((i > 0 && s[i - 1][j] == c) ||
                    (j > 0 && s[i][j - 1] == c) ||
                    (j > 0 && s[i + 1][j - 1] == c))
                  c = ((c == 'z') ? c = 'a' : c + 1);
                else
                  break;
              }
              s[i][j] = c;
              s[i + 1][j] = c;
            }
          }
        }
        for (i = 0; i < n; i++) {
          for (j = 0; j < m; j++) cout << s[i][j];
          cout << "\n";
          ;
        }
      } else
        cout << "NO\n";
    }
  }
}
