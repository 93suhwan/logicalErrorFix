#include <bits/stdc++.h>
using namespace std;
const int Max_N = 2e5, Max_Q = 2e5, Max = (1e9) + 7;
const long long Mod = (1e9) + 7;
int n, q, a[Max_N + 5], K[3] = {21, 22, 23};
long long sum[Max_N + 5], sM[3][Max_N + 5];
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
  for (; q--;) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    int len = r - l + 1;
    long long tot = (sum[r] - sum[l - 1] + Mod) % Mod;
    if ((tot - 1ll * (len - 1) * len / 2 % Mod * d % Mod + Mod) % Mod % len)
      puts("No");
    else {
      long long fir =
          (tot - 1ll * (len - 1) * len / 2 % Mod * d % Mod + Mod) % Mod / len;
      long long ans = 0;
      int flg = 0;
      for (int j = 0; j < 3; j++) {
        ans = 0;
        for (int i = 0; i < len; i++)
          ans = (ans + Mul((fir + 1ll * i * d) % Mod, K[j])) % Mod;
        if (ans != (sM[j][r] - sM[j][l - 1] + Mod) % Mod) flg |= 1;
      }
      if (!flg)
        puts("Yes");
      else
        puts("No");
    }
  }
  return 0;
}
