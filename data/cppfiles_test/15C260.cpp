#include <bits/stdc++.h>
using namespace std;
int T, n, a[22][22], cl[22][22], k, m;
char charr;
void test(int ixp, int jxp, int sll) {
  int i = ixp, j1 = jxp, j2 = jxp;
  int tt = -1;
  while (i > 0 && j1 > 0 && j2 <= m && a[i][j1] == 1 && a[i][j2] == 1) {
    tt++;
    j1--;
    j2++;
    i--;
  }
  if (tt >= k) {
    i = ixp, j1 = jxp, j2 = jxp;
    while (i > 0 && j1 > 0 && j2 <= m && a[i][j1] == 1 && a[i][j2] == 1) {
      cl[i][j1] = sll;
      cl[i][j2] = sll;
      j1--;
      j2++;
      i--;
    }
  }
}
void outp(int sll) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        test(i, j, sll);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1 && cl[i][j] < sll) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
}
void inp() {
  scanf("%d\n", &T);
  for (int sl = 1; sl <= T; sl++) {
    scanf("%d %d %d\n", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%c", &charr);
        if (charr == '*')
          a[i][j] = 1;
        else
          a[i][j] = 0;
      }
      scanf("\n");
    }
    outp(sl);
  }
}
int32_t main() { inp(); }
