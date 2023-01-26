#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int top[m];
  for (int i = 0; i < m; i++) {
    top[i] = n;
    while (top[i] - 1 >= 0 && a[top[i] - 1][i] == 2) {
      top[i]--;
    }
  }
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    c = c - 1;
    for (int j = 0; j < n; j++) {
      while (a[j][c] != 2) {
        if (a[j][c] == 1) {
          a[j][c] = 2;
          while (top[c] - 1 >= 0 && a[top[c] - 1][c] == 2) {
            top[c]--;
          }
          c += 1;
        }
        if (a[j][c] == 3) {
          a[j][c] = 2;
          while (top[c] - 1 >= 0 && a[top[c] - 1][c] == 2) {
            top[c]--;
          }
          c -= 1;
        }
      }
      if (j >= top[c]) {
        printf("%d ", c + 1);
        break;
      }
    }
  }
}
