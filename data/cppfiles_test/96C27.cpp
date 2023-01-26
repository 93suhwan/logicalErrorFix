#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool chkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
const int MAXN = 510, MOD = 998244353;
long long power(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % MOD;
    a = a * a % MOD;
  }
  return ans;
}
long long fac[MAXN], infac[MAXN];
long long C(long long a, long long b) {
  return fac[a] * infac[b] % MOD * infac[a - b] % MOD;
}
int n, x;
long long f[MAXN][MAXN];
int main() {
  scanf("%d %d", &n, &x);
  fac[0] = infac[0] = 1;
  for (int i = 1; i <= 500; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    infac[i] = power(fac[i], MOD - 2);
  }
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= x; j++) {
      f[i][j] = power(min(i - 1, j), i);
      if (j >= i) {
        for (int k = 2; k <= i; k++)
          (f[i][j] +=
           f[k][j - i + 1] * power(i - 1, i - k) % MOD * C(i, k) % MOD) %= MOD;
      }
    }
  printf("%lld\n", f[n][x]);
}
