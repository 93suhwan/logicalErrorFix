#include <bits/stdc++.h>
const int MAXN = 1e9;
int main() {
  printf("? 1 1\n");
  fflush(stdout);
  int a, b, c, d;
  scanf("%d", &a);
  printf("? 1 %d\n", MAXN);
  fflush(stdout);
  scanf("%d", &b);
  printf("? %d 1\n", MAXN);
  fflush(stdout);
  scanf("%d", &c);
  printf("? %d %d\n", MAXN, MAXN);
  fflush(stdout);
  scanf("%d", &d);
  int x, y, p, q;
  int l = 1, r = 1e9 + 1, mid, t;
  while (l + 1 < r) {
    mid = (l + r) / 2;
    printf("? 1 %d\n", mid);
    fflush(stdout);
    scanf("%d", &t);
    if (mid - 1 == a - t)
      l = mid;
    else
      r = mid;
  }
  printf("? 1 %d\n", l);
  fflush(stdout);
  scanf("%d", &t);
  x = t + 1;
  y = a - t + 1;
  q = 1e9 - b + x - 1;
  p = 1e9 - c + y - 1;
  printf("! %d %d %d %d\n", x, y, p, q);
  fflush(stdout);
  return 0;
}
