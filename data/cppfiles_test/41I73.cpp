#include <bits/stdc++.h>
int n, k;
int pow_k[1002];
int main() {
  scanf("%d%d", &n, &k);
  pow_k[0] = 1;
  int m;
  for (m = 1; pow_k[m - 1] < n; m++) pow_k[m] = pow_k[m - 1] * k;
  printf("%d\n", m);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int l = 1; l <= m; l++)
        if (i / pow_k[l] == j / pow_k[l]) {
          printf("%d ", l);
          break;
        }
  return 0;
}
