#include <bits/stdc++.h>
using namespace std;
int **f;
int hb[1000000];
int minc[1000000];
int main() {
  int n, m;
  scanf("%lu %lu", &n, &m);
  getchar();
  char ch;
  f = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; ++i) {
    f[i] = (int *)malloc(sizeof(int) * m);
    for (int j = 0; j < m; ++j) {
      ch = getchar();
      f[i][j] = (ch == 'X') ? 1 : 0;
      if (f[i][j] == 0 && i > 0 && f[i - 1][j] && j > 0 && f[i][j - 1]) {
        hb[j] = 1;
      }
    }
    getchar();
  }
  int lastGood = 0;
  for (int i = 0; i < m; ++i) {
    if (hb[i]) {
      minc[i] = i;
      lastGood = i;
    } else {
      minc[i] = lastGood;
    }
  }
  int q;
  scanf("%lu", &q);
  int ix1, ix2;
  for (int i = 0; i < q; ++i) {
    scanf("%lu %lu", &ix1, &ix2);
    ix1--;
    ix2--;
    if (ix1 < minc[ix2]) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
