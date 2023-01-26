#include <bits/stdc++.h>
using namespace std;
int a[4000010], b[4000010], c[4000010], mod;
int main() {
  int x;
  scanf("%d%d", &x, &mod);
  a[1] = 1;
  b[1] = 1, c[1] = 0;
  for (int i = 2; i <= x; i++) {
    a[i] = (a[i] + b[i - 1]) % mod;
    for (int j = 1; i * j <= x; j++) {
      if (j >= i) {
        break;
      } else {
        c[i * j] += a[j];
        if (c[i * j] >= mod) c[i * j] -= mod;
        if (i * (j + 1) <= x) {
          c[i * (j + 1)] -= a[j];
          if (c[i * (j + 1)] < 0) c[i * (j + 1)] += mod;
        }
      }
    }
    c[i] += c[i - 1];
    if (c[i] < 0) c[i] += mod;
    if (c[i] >= mod) c[i] -= mod;
    a[i] = (a[i] + c[i]) % mod;
    b[i] = (b[i - 1] + a[i]) % mod;
    for (int j = 1; j <= i && i * j <= x; j++) {
      c[j * i] += a[i];
      if (c[j * i] >= mod) c[j * i] -= mod;
      if ((i + 1) * j <= x) {
        c[(i + 1) * j] -= a[i];
        if (c[(i + 1) * j] < 0) c[(i + 1) * j] += mod;
      }
    }
  }
  printf("%d\n", a[x]);
  return 0;
}
