#include <bits/stdc++.h>
using namespace std;
int **f;
int **d;
int **e;
int **w;
int dc[1000000];
void solve() {}
int getAns(int i, int j) {
  if (w[i][j]) {
    return e[i][j];
  }
  w[i][j] = 1;
  if (i == 0) {
    e[i][j] = 1 - f[i][j];
    if (e[i][j]) {
      d[i][j] = j;
    }
    d[i][j] = j;
    return e[i][j];
  }
  if (j == 0) {
    e[i][j] = 1 - f[i][j];
    d[i][j] = 0;
    return e[i][j];
  }
  if (f[i][j]) {
    e[i][j] = 0;
    d[i][j] = j;
  } else {
    if (getAns(i - 1, j)) {
      e[i][j] = 1;
      d[i][j] = d[i - 1][j];
    } else if (getAns(i, j - 1)) {
      e[i][j] = 1;
      d[i][j] = d[i][j - 1];
    } else {
      e[i][j] = 0;
      d[i][j] = j;
      if (f[i][j - 1] == 0) {
        d[i][j] = min(d[i][j], d[i][j - 1]);
      }
      if (f[i - 1][j]) {
        d[i][j] = min(d[i][j], d[i - 1][j]);
      }
    }
  }
  if (e[i][j] == 0 && f[i][j] == 0) {
    dc[j] = max(d[i][j], dc[j]);
  }
  return e[i][j];
}
int main() {
  int n, m;
  scanf("%lu %lu", &n, &m);
  getchar();
  char ch;
  f = (int **)malloc(sizeof(int *) * n);
  d = (int **)malloc(sizeof(int *) * n);
  e = (int **)malloc(sizeof(int *) * n);
  w = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; ++i) {
    f[i] = (int *)malloc(sizeof(int) * m);
    d[i] = (int *)malloc(sizeof(int) * m);
    w[i] = (int *)malloc(sizeof(int) * m);
    e[i] = (int *)malloc(sizeof(int) * m);
    for (int j = 0; j < m; ++j) {
      ch = getchar();
      f[i][j] = (ch == 'X') ? 1 : 0;
      w[i][j] = 0;
      e[i][j] = 0;
    }
    getchar();
  }
  int q;
  scanf("%lu", &q);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      getAns(i, j);
    }
  }
  int ix1, ix2;
  for (int i = 0; i < q; ++i) {
    scanf("%lu %lu", &ix1, &ix2);
    ix1--;
    ix2--;
    if (ix1 < dc[ix2]) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
