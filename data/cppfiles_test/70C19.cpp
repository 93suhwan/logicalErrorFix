#include <bits/stdc++.h>
using namespace std;
const int Max_N = 2e5, Max_Q = 2e5, Max = (1e9) + 7;
const long long Mod = (1e9) + 7;
int n, q, a[Max_N + 5], K[3] = {2, 3, 4}, C[30][30];
long long sum[Max_N + 5], sM[3][Max_N + 5], P[30][Max_N + 5];
long long Mul(int x, int y) {
  long long ans = 1;
  for (; y; y >>= 1, x = 1ll * x * x % Mod)
    if (y & 1) ans = ans * x % Mod;
  return ans;
}
int main() {
  srand(time(0));
  int t = (1ll * rand() * 100000 + rand()) % Max;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) a[i] = (1ll * a[i] + t) % Mod;
  for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + a[i]) % Mod;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 3; j++)
      sM[j][i] = (sM[j][i - 1] + Mul(a[i], K[j])) % Mod;
  for (int i = 0; i <= K[2]; i++)
    for (int j = 0; j <= n; j++)
      P[i][j] = ((j ? P[i][j - 1] : 0) + Mul(j, i)) % Mod;
  C[0][0] = 1;
  for (int i = 1; i <= K[2]; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
  }
  for (; q--;) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    int len = r - l + 1;
    long long tot = (sum[r] - sum[l - 1] + Mod) % Mod;
    long long fir = (tot - 1ll * (len - 1) * len / 2 % Mod * d % Mod + Mod) %
                    Mod * Mul(len, Mod - 2) % Mod;
    long long ans = 0;
    int flg = 0;
    for (int j = 0; j < 3; j++) {
      ans = 0;
      for (int k = 0; k <= K[j]; k++)
        ans = (ans + 1ll * C[K[j]][k] * Mul(fir, K[j] - k) % Mod * Mul(d, k) %
                         Mod * P[k][len - 1] % Mod) %
              Mod;
      if (ans != (sM[j][r] - sM[j][l - 1] + Mod) % Mod) flg |= 1;
    }
    if (!flg)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
