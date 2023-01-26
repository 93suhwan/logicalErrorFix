#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  int n, m, k;
  for (int tt = 0; tt < t; tt++) {
    if (tt) printf("\n");
    scanf("%d %d %d", &n, &m, &k);
    int d = n / m + (n % m != 0);
    int cnt = n / d, nro = 0, val = (n % m != 0);
    while (k--) {
      for (int i = 0; i < m - val; i++) {
        printf("%d", d);
        for (int j = 0; j < d; j++) {
          printf(" %d", ++nro);
          nro %= n;
        }
        printf("\n");
      }
      if (n % m) {
        int nro2 = nro;
        printf("%d", d - 1);
        for (int i = 0; i < d - 1; i++) {
          printf(" %d", ++nro);
          nro %= n;
        }
        printf("\n");
        nro = nro2;
      }
    }
  }
  return 0;
}
