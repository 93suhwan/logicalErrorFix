#include <bits/stdc++.h>
using namespace std;
int main() {
  printf("? 1 1\n");
  fflush(stdout);
  int i, d11, id = 0;
  scanf("%d", &d11);
  for (i = 29; i >= 0; i--) {
    int a;
    if (id + (1 << i) > 1000000000) continue;
    printf("? 1 %d\n", id + (1 << i));
    fflush(stdout);
    scanf("%d", &a);
    if (d11 - a == id + (1 << i) - 1) id += 1 << i;
  }
  int x, y, p, q, a;
  y = id;
  x = d11 + 2 - y;
  printf("? 1 1000000000\n");
  fflush(stdout);
  scanf("%d", &a);
  a -= (x - 1);
  q = 1000000000 - a;
  printf("? 1000000000 1\n");
  fflush(stdout);
  scanf("%d", &a);
  a -= (y - 1);
  p = 1000000000 - a;
  printf("! %d %d %d %d\n", x, y, p, q);
  fflush(stdout);
}
