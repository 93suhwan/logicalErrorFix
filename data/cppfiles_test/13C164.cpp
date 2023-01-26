#include <bits/stdc++.h>
using namespace std;
char get(int i, int j) {
  i %= 4;
  j %= 4;
  return 'a' + i * 4 + j;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int _n = n, _m = m, _k = k;
    if (m % 2 == 0) {
      if (n % 2 == 0) {
      } else {
        n--;
        k -= m / 2;
      }
    } else {
      swap(n, m);
      k = (n * m - 2 * k) / 2;
      n--;
      k -= m / 2;
    }
    if (k % 2 == 0 && k >= 0) {
      cout << "YES" << endl;
      vector<string> a(n, string(m, '?'));
      for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
          if (k) {
            a[i][j] = a[i][j + 1] = get(i, j);
            a[i + 1][j] = a[i + 1][j + 1] = get(i + 1, j);
            k -= 2;
          } else {
            a[i][j] = a[i + 1][j] = get(i, j);
            a[i][j + 1] = a[i + 1][j + 1] = get(i, j + 1);
          }
        }
      }
      if (_m % 2 == 0) {
        if (_n % 2 == 0) {
          for (int i = 0; i < n; i++) {
            cout << a[i] << endl;
          }
        } else {
          for (int i = 0; i < m / 2; i++) {
            if (i & 1) {
              cout << "yy";
            } else {
              cout << "xx";
            }
          }
          cout << endl;
          for (int i = 0; i < n; i++) {
            cout << a[i] << endl;
          }
        }
      } else {
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
            cout << a[j][i];
          }
          if (i % 4 < 2) {
            cout << "x" << endl;
          } else {
            cout << "y" << endl;
          }
        }
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
