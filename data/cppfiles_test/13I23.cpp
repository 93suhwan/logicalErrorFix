#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> table(n, vector<char>(m));
    int r = 0, c = 0;
    if (n * (m / 2) < k) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == 1) {
      if (k < m / 2) {
        cout << "NO" << endl;
        continue;
      }
      char ch = 'a';
      int num = 0;
      for (int i = 0; i < m; i += 2) {
        table[0][i] = table[0][i + 1] = ch;
        num = (num + 1) % 26;
        ch += num;
      }
      k -= m / 2;
      r = 1;
    }
    if ((k == 0 && n - 1 == 0) || (k % n) % 2 == 0) {
      cout << "YES" << endl;
      for (int ic = c; ic < (m - m % 2); ic += 2) {
        for (int ir = r; ir < n; ir += 2) {
          if (k > 0) {
            for (int ir2 = ir; ir2 < ir + 2; ir2++) {
              for (int num = 0; num < 26; num++) {
                char ch = 'a' + num;
                if ((ic - 1 < 0 || table[ir2][ic - 1] != ch) &&
                    (ir2 - 1 < 0 || (table[ir2 - 1][ic] != ch &&
                                     table[ir2 - 1][ic + 1] != ch))) {
                  table[ir2][ic] = table[ir2][ic + 1] = ch;
                  break;
                }
              }
              k--;
            }
          } else {
            for (int ic2 = ic; ic2 < ic + 2; ic2++) {
              for (int num = 0; num < 26; num++) {
                char ch = 'a' + num;
                if ((ir - 1 < 0 || table[ir - 1][ic2] != ch) &&
                    (ic2 - 1 < 0 || (table[ir][ic2 - 1] != ch &&
                                     table[ir + 1][ic2 - 1] != ch))) {
                  table[ir][ic2] = table[ir + 1][ic2] = ch;
                  break;
                }
              }
            }
          }
        }
      }
      if (m % 2 == 1) {
        for (int ir = 0; ir < n; ir += 2) {
          for (int num = 0; num < 26; num++) {
            char ch = 'a' + num;
            if ((ir - 1 < 0 || table[ir - 1][m - 1] != ch) &&
                (m - 2 < 0 ||
                 (table[ir][m - 2] != ch && table[ir + 1][m - 2] != ch))) {
              table[ir][m - 1] = table[ir + 1][m - 1] = ch;
              break;
            }
          }
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << table[i][j];
        cout << endl;
      }
    } else
      cout << "NO" << endl;
  }
  return 0;
}
