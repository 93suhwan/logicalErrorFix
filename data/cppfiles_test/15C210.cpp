#include <bits/stdc++.h>
void canBeCheck(char v[11][20], int i, int j, int d, int canBeChecked[11][20]) {
  int ok = 1;
  for (int h = d; h >= 1; h--) {
    if (v[i - h][j - h] == '.' || v[i - h][j + h] == '.') ok = 0;
  }
  if (ok) {
    for (int h = d; h >= 0; h--) {
      canBeChecked[i - h][j - h] = 0;
      canBeChecked[i - h][j + h] = 0;
    }
  }
}
int testSolver() {
  int n, m, ok = 1, k, total;
  char v[11][20];
  int canBeChecked[11][20];
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf(" %c", &v[i][j]);
      if (v[i][j] == '*') {
        canBeChecked[i][j] = 1;
      } else {
        canBeChecked[i][j] = 0;
      }
    }
  }
  for (int i = k + 1; i <= n; i++) {
    for (int d = k; d <= i - 1; d++) {
      for (int j = d + 1; j <= m - d; j++) {
        if (v[i][j] == '*') {
          canBeCheck(v, i, j, d, canBeChecked);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (canBeChecked[i][j] == 1) {
        ok = 0;
        break;
      }
    }
  }
  if (ok) {
    return 1;
  }
  return 0;
}
int main() {
  int testcases, a[100];
  scanf("%d", &testcases);
  for (int i = 1; i <= testcases; i++) {
    a[i] = testSolver();
  }
  for (int i = 1; i <= testcases; i++) {
    if (a[i] == 1) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
