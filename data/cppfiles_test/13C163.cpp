#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, s, mq;
int a[105][105] = {0};
bool bj;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    s = n * m / 2 - k;
    bj = true;
    for (int i = 0; i <= (n + 1); i++)
      for (int j = 0; j <= (m + 1); j++) a[i][j] = -1;
    if (n % 2) {
      for (int i = 1; i <= m; i++) {
        if (k == 0) {
          bj = false;
          break;
        }
        if (i % 2)
          a[n][i] = (a[n][i - 1] + 1) % 2;
        else {
          a[n][i] = a[n][i - 1];
          k--;
        }
      }
    }
    if (m % 2) {
      for (int i = 1; i <= n; i++) {
        if (s == 0) {
          bj = false;
          break;
        }
        if (i % 2)
          a[i][m] = (a[i - 1][m] + 1) % 2;
        else {
          a[i][m] = a[i - 1][m];
          s--;
        }
      }
    }
    if (((n / 2) * (m / 2)) == (k / 2 + s / 2)) {
      for (int i = 2; i <= n; i += 2)
        for (int j = 2; j <= m; j += 2) {
          mq = 0;
          while ((mq == a[i - 2][j]) || (mq == a[i - 2][j - 1]) ||
                 (mq == a[i - 1][j - 2]) || (mq == a[i][j - 2]) ||
                 (mq == a[i + 1][j - 1]) || (mq == a[i + 1][j]) ||
                 (mq == a[i][j + 1]) || (mq == a[i - 1][j + 1])) {
            mq++;
            mq %= 25;
          }
          if (k) {
            a[i][j] = mq;
            a[i][j - 1] = mq;
            mq++;
            mq %= 25;
            while ((mq == a[i - 2][j]) || (mq == a[i - 2][j - 1]) ||
                   (mq == a[i - 1][j - 2]) || (mq == a[i][j - 2]) ||
                   (mq == a[i + 1][j - 1]) || (mq == a[i + 1][j]) ||
                   (mq == a[i][j + 1]) || (mq == a[i - 1][j + 1])) {
              mq++;
              mq %= 25;
            }
            a[i - 1][j - 1] = mq;
            a[i - 1][j] = mq;
            k -= 2;
          } else {
            a[i][j] = mq;
            a[i - 1][j] = mq;
            mq++;
            mq %= 25;
            while ((mq == a[i - 2][j]) || (mq == a[i - 2][j - 1]) ||
                   (mq == a[i - 1][j - 2]) || (mq == a[i][j - 2]) ||
                   (mq == a[i + 1][j - 1]) || (mq == a[i + 1][j]) ||
                   (mq == a[i][j + 1]) || (mq == a[i - 1][j + 1])) {
              mq++;
              mq %= 25;
            }
            a[i - 1][j - 1] = mq;
            a[i][j - 1] = mq;
            s -= 2;
          }
        }
    } else
      bj = false;
    if (bj) {
      cout << "YES" << '\n';
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          cout << char(a[i][j] + 'a');
        }
        cout << '\n';
      }
    } else
      cout << "NO" << '\n';
  }
  return 0;
}
