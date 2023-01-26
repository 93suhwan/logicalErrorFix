#include <bits/stdc++.h>
int main() {
  long long i, j;
  int q;
  scanf("%d", &q);
  while (q--) {
    int k1, k2, k3, k4, k5;
    scanf("%d%d%d%d%d", &k1, &k2, &k3, &k4, &k5);
    printf("%d %d %d\n", k1, k2, k3 + k4 - k1 + k2);
  }
  return 0;
}
