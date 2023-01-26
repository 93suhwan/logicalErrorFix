#include <bits/stdc++.h>
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  int c = ((n - 1) + (m - 1)) / m;
  printf("%d\n", c);
  for (int i = 1, repi = n; i <= repi; ++i)
    for (int j = i + 1, repj = n; j <= repj; ++j) {
      printf("%d ", (j - 2) / c + 1);
    }
  return 0;
}
