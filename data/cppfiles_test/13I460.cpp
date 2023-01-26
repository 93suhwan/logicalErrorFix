#include <bits/stdc++.h>
using namespace std;
int del_x[] = {-1, 0, 1, 0}, del_y[] = {0, 1, 0, -1};
bool check(int i, int j, int n, int m) {
  if (i >= 1 && i <= n && j >= 1 && j <= m) return true;
  return false;
}
int main() {
  int test;
  cin >> test;
abar:
  while (test--) {
    int n, m, i, j, dominoes, k, a, b, value;
    cin >> n >> m >> dominoes;
    int arr[n + 5][m + 5];
    memset(arr, -1, sizeof(arr));
    i = 1;
    j = 2;
    while (dominoes--) {
      if (!check(i, j, n, m)) break;
      value = -1;
      map<int, bool> mmap;
      for (k = 0; k < 4; k++) {
        a = del_x[k] + i;
        b = del_y[k] + j;
        if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
      }
      for (k = 0; k < 4; k++) {
        a = del_x[k] + i;
        b = del_y[k] + j - 1;
        if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
      }
      for (k = 0;; k++) {
        if (!mmap[k]) {
          value = k;
          break;
        }
      }
      arr[i][j] = arr[i][j - 1] = value;
      i++;
      if (i > n) {
        i = 1;
        j += 2;
      }
    }
    if (dominoes >= 0) {
      cout << "NO" << endl;
      goto abar;
    }
    for (i = 1; i < n; i++) {
      for (j = 1; j <= m; j++) {
        if (arr[i][j] == -1) {
          value = -1;
          map<int, bool> mmap;
          for (k = 0; k < 4; k++) {
            a = del_x[k] + i;
            b = del_y[k] + j;
            if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
          }
          for (k = 0; k < 4; k++) {
            a = del_x[k] + i;
            b = del_y[k] + j - 1;
            if (check(a, b, n, m) && arr[a][b] != -1) mmap[arr[a][b]] = true;
          }
          for (k = 0;; k++) {
            if (!mmap[k]) {
              value = k;
              break;
            }
          }
          arr[i][j] = arr[i + 1][j] = value;
        }
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (arr[i][j] == -1) {
          cout << "NO" << endl;
          goto abar;
        }
      }
    }
    cout << "YES" << endl;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        char c = arr[i][j] + 'a';
        cout << c;
      }
      cout << endl;
    }
  }
}
