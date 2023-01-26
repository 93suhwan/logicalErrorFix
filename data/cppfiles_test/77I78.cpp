#include <bits/stdc++.h>
int main() {
  int h, i, j;
  int t, n, m;
  scanf("%d %d", &n, &m);
  int d[n + 1];
  int diff[n + 1];
  int sum[n + 1];
  int div[n + 1];
  d[1] = 1;
  sum[1] = 0;
  div[1] = 0;
  for (i = 2; i <= n; i++) {
    div[i] = div[i - 1];
    for (j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        div[i] += diff[i / j];
        if (div[i] >= m) {
          div[i] -= m;
        }
        if (j * j != i) {
          div[i] += diff[j];
          if (div[i] >= m) {
            div[i] -= m;
          }
        }
      }
    }
    div[i]++;
    sum[i] = (sum[i - 1] + d[i - 1]) % m;
    d[i] = (div[i] + sum[i]) % m;
    diff[i] = d[i] - d[i - 1];
  }
  printf("%lld\n", d[n]);
}
