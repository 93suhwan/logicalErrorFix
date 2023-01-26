#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k1;
    cin >> n >> m >> k1;
    int k2 = (n * m) / 2 - k1;
    char arr[n][m];
    int flag = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) arr[i][j] = '*';
    if (m % 2 != 0) {
      k2 -= n / 2;
      m--;
      flag = 1;
    } else if (n % 2 != 0) {
      k1 -= m / 2;
      n--;
      flag = 2;
    }
    if (k1 % 2 != 0 || k2 % 2 != 0 || k1 < 0 || k2 < 0)
      cout << "NO"
           << "\n";
    else {
      for (int j = 0; j < m; j += 2) {
        for (int i = 0; i < n; i += 2) {
          if (k1 != 0) {
            if ((j / 2) % 2 == 0) {
              arr[i][j] = arr[i][j + 1] = 'a';
              arr[i + 1][j] = arr[i + 1][j + 1] = 'b';
              k1 -= 2;
            } else {
              arr[i][j] = arr[i][j + 1] = 'c';
              arr[i + 1][j] = arr[i + 1][j + 1] = 'd';
              k1 -= 2;
            }
          } else {
            if ((i / 2) % 2 == 0) {
              arr[i][j] = arr[i + 1][j] = 'e';
              arr[i][j + 1] = arr[i + 1][j + 1] = 'f';
              k2 -= 2;
            } else {
              arr[i][j] = arr[i + 1][j] = 'g';
              arr[i][j + 1] = arr[i + 1][j + 1] = 'h';
              k2 -= 2;
            }
          }
        }
      }
      if (flag == 1) {
        for (int i = 0; i < n; i += 2) {
          if ((i / 2) % 2 == 0)
            arr[i][m] = arr[i + 1][m] = 'w';
          else
            arr[i][m] = arr[i + 1][m] = 'x';
        }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m + 1; j++) cout << arr[i][j] << " ";
          cout << "\n";
        }
      } else if (flag == 2) {
        for (int i = 0; i < m; i += 2) {
          if ((i / 2) % 2 == 0)
            arr[n][i] = arr[n][i + 1] = 'y';
          else
            arr[n][i] = arr[n][i + 1] = 'z';
        }
        for (int i = 0; i < n + 1; i++) {
          for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
          cout << "\n";
        }
      } else {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
          cout << "\n";
        }
      }
    }
  }
  return 0;
}
