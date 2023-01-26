#include <bits/stdc++.h>
const int nn = 4e6 + 5;
int n, m, f[nn], sum, suff[nn];
int add(int a, int b) { return a + b >= m ? a + b - m : a + b; }
int sub(int a, int b) { return a < b ? a - b + m : a - b; }
int mul(int a, int b) { return 1ll * a * b % m; }
int main() {
  scanf("%d %d", &n, &m);
  f[n] = 1;
  for (int i = n; i >= 1; i--) {
    f[i] = add(f[i], sum);
    for (int j = 2; i * j <= n; j++) {
      int l = i * j, r = (i + 1) * j - 1;
      if (r > n) r = n;
      f[i] = add(f[i], sub(suff[l], suff[r + 1]));
    }
    sum = add(sum, f[i]);
    suff[i] = add(suff[i + 1], f[i]);
  }
  printf("%d", f[1]);
}
