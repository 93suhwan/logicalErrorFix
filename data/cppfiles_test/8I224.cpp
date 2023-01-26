#include <bits/stdc++.h>
int main() {
  int t, c1, c2;
  scanf("%d", &t);
  if (t % 3 == 0) {
    c1 = (t / 3);
    c2 = c1;
  } else if ((t % 3) - 2 == 0) {
    c1 = (t - 2) / 3;
    c2 = c1 + 1;
  } else {
    c2 = (t - 1) / 3;
    c1 = c2 + 1;
  }
  printf("%d %d", c1, c2);
  return 0;
}
