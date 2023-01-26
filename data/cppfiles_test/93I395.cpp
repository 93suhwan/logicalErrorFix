#include <bits/stdc++.h>
int t, n, k;
int testes();
int main() {
  int x;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    x = testes();
    printf("%d\n", x);
  }
  return 0;
}
int testes() {
  int i, j, horas;
  i = 1, j = 1, horas = 0;
  while (i < n) {
    while (j < k && i < n) {
      i += j;
      j++;
      horas++;
    }
    if (j == k && i < n) {
      i += j;
      horas++;
    }
  }
  return horas;
}
