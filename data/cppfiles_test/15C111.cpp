#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    char arr[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }
    for (int i = k; i < n; i++) {
      for (int j = k; j < m - k; j++) {
        if (arr[i][j] == '*' || arr[i][j] == '#') {
          int x = i, y = j, h = 0;
          if ((arr[x - k][y - k] == '*' || arr[x - k][y - k] == '#') &&
              (arr[x - k][y + k] == '*' || arr[x - k][y + k] == '#')) {
            while ((x - h) >= 0 && (j - h) >= 0 && (j + h) < m) {
              if ((arr[x - h][y - h] == '*' || arr[x - h][y - h] == '#') &&
                  (arr[x - h][y + h] == '*' || arr[x - h][y + h] == '#')) {
                arr[x - h][y - h] = '#';
                arr[x - h][y + h] = '#';
                h++;
              } else
                break;
            }
          }
        }
      }
    }
    bool check = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == '*') {
          check = false;
          break;
        }
      }
      if (check == false) break;
    }
    if (check == true)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
