#include <bits/stdc++.h>
long int t, n, k;
int testes();
int main() {
  long int x;
  scanf("%ld", &t);
  while (t--) {
    scanf("%ld %ld", &n, &k);
    x = testes();
    printf("%ld\n", x);
  }
  return 0;
}
int testes() {
  long int i, j, horas;
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
