#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
char a[30][30];
int v[30][30];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(v, 0, sizeof v);
    int n, m, k;
    int flag = 0;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
      scanf("%s", a[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '*') {
          int q = 0;
          for (; i - q >= 0 && j + q < m && j - q >= 0; q++) {
            if (a[i - q][j - q] == '*' && a[i - q][j + q] == '*') {
            } else
              break;
          }
          if (q - 1 >= k) {
            int p = 0;
            for (; i - p >= 0 && j - p >= 0 && j + p < m; p++) {
              if (a[i - p][j - p] == '*' && a[i - p][j + p] == '*') {
                v[i - p][j - p] = 1;
                v[i - p][j + p] = 1;
              } else
                break;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '*' && v[i][j] != 1) {
          flag = 1;
          break;
        }
      }
    }
    if (flag == 1)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}
