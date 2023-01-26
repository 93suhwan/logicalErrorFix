#include <bits/stdc++.h>
long long int t, n, k;
long long int testes();
int main() {
  long long int x;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &k);
    x = testes();
    printf("%lld\n", x);
  }
  return 0;
}
long long int testes() {
  long long int i, j, horas;
  i = 1, j = 1, horas = 0;
  while (i < n) {
    while (j < k && i < n) {
      i += j;
      j++;
      horas++;
    }
    if (j == k - 1) {
      j++;
    }
    while (j == k && i < n) {
      i += j;
      horas++;
    }
  }
  return horas;
}
