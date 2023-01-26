#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int M = 5e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, t, i, j, k, m, hor, ver, p, flag;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    long long int arr[n][m];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        arr[i][j] = 0;
      }
    }
    hor = k;
    ver = n * m / 2 - k;
    p = 0;
    for (i = 0; i < n; i++) {
      flag = 0;
      for (j = 0; j + 1 < m; j = j + 2) {
        if (hor > 0 && j + 1 < m && arr[i][j] == 0 && arr[i][j + 1] == 0) {
          arr[i][j] = 1;
          arr[i][j + 1] = 1;
          hor--;
          p++;
          flag = 1;
        }
        if ((n % 2 == 0 && p % 2 == 1 && flag == 1) ||
            (n % 2 == 1 && p % 2 == 0 && flag == 1)) {
          break;
        }
        if ((n % 2 == 1 && p % 2 == 1 && flag == 1) ||
            (n % 2 == 0 && p % 2 == 0 && flag == 1)) {
          i = -1;
          break;
        }
      }
    }
    for (j = 0; j < m; j++) {
      for (i = 0; i + 1 < n; i = i + 2) {
        if (ver > 0 && i + 1 < n && arr[i][j] == 0 && arr[i + 1][j] == 0) {
          arr[i][j] = 1;
          arr[i + 1][j] = 1;
          ver--;
        } else if (ver > 0 && arr[i][j] == 1) {
          i--;
        }
      }
    }
    if (ver > 0 || hor > 0) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}
