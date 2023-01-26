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
  long long int i, horas;
  i = 1, horas = 0;
  while (i < k) {
    i += i;
    horas++;
  }
  horas += (n - i + k - 1) / k;
  return horas;
}
