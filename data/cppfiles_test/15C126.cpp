#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
start:
  while (t--) {
    int n, m, p;
    cin >> n >> m >> p;
    int ck[n][m];
    char ch[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> ch[i][j];
        ck[i][j] = 0;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (ch[i][j] == '*') {
          int c1 = 0, c2 = 0;
          if (j > 0) {
            for (int k = i - 1, l = j - 1; k >= 0 and l >= 0; k--, l--) {
              if (ch[k][l] == '*') {
                ++c1;
              } else
                break;
            }
          }
          for (int k = i - 1, l = j + 1; k >= 0 and l < m; k--, l++) {
            if (ch[k][l] == '*') {
              ++c2;
            } else
              break;
          }
          int mn = min(c1, c2);
          c1 = mn, c2 = mn;
          if (mn >= p) {
            ck[i][j] = 1;
            if (j > 0) {
              for (int k = i - 1, l = j - 1; c1 > 0 and k >= 0 and l >= 0;
                   k--, l--) {
                if (ch[k][l] == '*') {
                  ck[k][l] = 1;
                  --c1;
                } else
                  break;
              }
            }
            for (int k = i - 1, l = j + 1; c2 > 0 and k >= 0 and l < m;
                 k--, l++) {
              if (ch[k][l] == '*') {
                ck[k][l] = 1;
                --c2;
              } else
                break;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ch[i][j] == '*' and ck[i][j] == 0) {
          cout << "NO" << endl;
          goto start;
        }
      }
    }
    cout << "YES" << endl;
  }
  return 0;
}
