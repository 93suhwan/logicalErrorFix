#include <bits/stdc++.h>
using namespace std;
inline int read(void) {
  register int x = 0, sgn = 1, ch = getchar();
  while (ch < 48 || 57 < ch) {
    if (ch == 45) sgn = 0;
    ch = getchar();
  }
  while (47 < ch && ch < 58) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return sgn ? x : -x;
}
void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int d[4];
int D;
int drl, dub;
signed main() {
  printf("? 1 1\n");
  fflush(stdout);
  scanf("%d", &d[0]);
  printf("? 1000000000 1\n");
  fflush(stdout);
  scanf("%d", &d[1]);
  printf("? 1 1000000000\n");
  fflush(stdout);
  scanf("%d", &d[2]);
  int R = 999999999;
  int L = 2;
  while (L < R) {
    int Mid = (L + R + 1) / 2;
    printf("? %d 1\n", Mid);
    fflush(stdout);
    scanf("%d", &D);
    if (D + Mid - 1 == d[0]) {
      L = Mid;
    } else
      R = Mid - 1;
  }
  printf("? %d 1\n", L);
  fflush(stdout);
  scanf("%d", &D);
  int l = d[0] - D + 1;
  int b = D + 1;
  int r = d[1] - D + 1;
  int u = d[2] - l + 2;
  printf("! %d %d %d %d\n", l, b, 1000000001 - r, 1000000001 - u);
  return 0;
}
