#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  int n, m, k;
  for (int tt = 0; tt < t; tt++) {
    if (tt) printf("\n");
    scanf("%d %d %d", &n, &m, &k);
    int d = n / m, sw = (n % m != 0);
    int res = n % m, d1 = d + sw;
    int nro = 0, res1 = m - res;
    while (k--) {
      for (int i = 0; i < res; i++) {
        printf("%d", d1);
        for (int j = 0; j < d1; j++) {
          printf(" %d", ++nro);
          nro %= n;
        }
        printf("\n");
      }
      int nro2 = nro;
      for (int i = 0; i < res1; i++) {
        printf("%d", d);
        for (int j = 0; j < d; j++) {
          printf(" %d", ++nro);
          nro %= n;
        }
        printf("\n");
      }
      nro = nro2;
    }
  }
  return 0;
}
