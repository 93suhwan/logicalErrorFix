#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int sum[200000 + 5][3], a[200000 + 5][3];
int ksm(int a, int k) {
  int s = 1;
  while (k) {
    if (k & 1) s = 1ll * s * a % mod;
    k >>= 1;
    a = 1ll * a * a % mod;
  }
  return s;
}
int main() {
  int n, q, i, j;
  scanf("%d%d", &n, &q);
  for (i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    sum[i][0] = (sum[i - 1][0] + x) % mod;
    sum[i][1] = (sum[i - 1][1] + 1ll * x * x % mod) % mod;
    sum[i][2] = (sum[i - 1][2] + 1ll * x * x % mod * x % mod) % mod;
    a[i][0] = (a[i - 1][0] + i) % mod;
    a[i][1] = (a[i - 1][1] + 1ll * i * i % mod) % mod;
    a[i][2] = (a[i - 1][2] + 1ll * i * i % mod * i % mod) % mod;
  }
  while (q--) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    int m = r - l + 1, s0 = (sum[r][0] - sum[l - 1][0] + mod) % mod,
        s1 = (sum[r][1] - sum[l - 1][1] + mod) % mod,
        s2 = (sum[r][2] - sum[l - 1][2] + mod) % mod;
    int s =
        (s0 - 1ll * a[m - 1][0] * d % mod + mod) % mod * ksm(m, mod - 2) % mod;
    if ((1ll * s * s % mod * m % mod + 2ll * s * a[m - 1][0] % mod * d % mod +
         1ll * a[m - 1][1] * d % mod * d % mod) %
            mod !=
        s1) {
      printf("No\n");
      continue;
    }
    if ((1ll * s * s % mod * s % mod * m % mod +
         3ll * s * s % mod * a[m - 1][0] % mod * d % mod +
         3ll * s * a[m - 1][1] % mod * d % mod * d % mod +
         1ll * a[m - 1][2] * d % mod * d % mod * d % mod) %
            mod !=
        s2) {
      printf("No\n");
      continue;
    }
    printf("Yes\n");
  }
}
