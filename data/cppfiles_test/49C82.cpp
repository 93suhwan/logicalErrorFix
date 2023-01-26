#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 10;
int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2) {
      res = 1LL * res * a % mod;
    }
    a = 1LL * a * a % mod;
    b /= 2;
  }
  return res;
}
int main() {
  int test = 1, a[15], p[1 << 15], pp[15][15];
  while (test--) {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        pp[i][j] = 1LL * a[i] * power(a[i] + a[j], mod - 2) % mod;
      }
    }
    p[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
      p[i] = 1;
      for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
        int g = p[j];
        for (int k = 0; k < n; k++) {
          if (j & (1 << k)) {
            for (int l = 0; l < n; l++) {
              if (j & (1 << l)) {
                continue;
              }
              if (i & (1 << l)) {
                g = 1LL * g * pp[k][l] % mod;
              }
            }
          }
        }
        p[i] -= g % mod;
        if (p[i] < 0) {
          p[i] += mod;
        }
      }
      int g = 1;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          for (int k = 0; k < n; k++) {
            if (i & (1 << k)) {
              continue;
            }
            g = 1LL * g * pp[j][k] % mod;
          }
        }
      }
      ans += 1LL * p[i] * g % mod * __builtin_popcount(i) % mod;
      ans %= mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
