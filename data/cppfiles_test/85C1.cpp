#include <bits/stdc++.h>
int mod;
using namespace std;
int n, K;
int fac[210], ifac[210];
int f[210][210][210];
int ksm(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % mod)
    if (k & 1) res = 1ll * res * a % mod;
  return res;
}
void qmo(int &x) { x += (x >> 31) & mod; }
int work(int a1) {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) f[0][i][0] = ifac[i];
  for (int i = 1; i <= n + 1; i++)
    for (int j = n - n / i; j <= n && j - i + 1 <= a1; j++) {
      for (int k = 0; k <= n; k++)
        for (int l = 0; l <= j && l <= k / i; l++) {
          f[i][j][k] =
              (f[i][j][k] + 1ll * f[i - 1][j - l][k - i * l] * ifac[l]) % mod;
        }
    }
  int res = (a1 >= n ? ifac[n] : 0);
  for (int i = 1; i <= a1; i++) qmo(res += f[n + 1 - a1][n][i] - mod);
  return res;
}
int main() {
  scanf("%d%d", &n, &mod);
  int res = 0;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = 1ll * i * fac[i - 1] % mod, ifac[i] = ksm(fac[i], mod - 2),
    assert(1ll * fac[i] * ifac[i] % mod == 1);
  for (int a1 = n - 17; a1 <= n + 1; a1++) qmo(res += work(a1) - mod);
  printf("%d\n", 1ll * res * fac[n] % mod);
}
