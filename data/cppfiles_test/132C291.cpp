#include <bits/stdc++.h>
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    int b[10];
    for (int j = 0; j < 7; j++) {
      scanf("%d", &b[j]);
    }
    int x, y, z;
    x = b[0];
    y = b[1];
    z = b[6] - x - y;
    printf("%d %d %d\n", x, y, z);
  }
  return 0;
}
