#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char s[2000 + 5], t[2000 + 5];
int f1[2000 + 5][2000 + 5], f2[2000 + 5][2000 + 5];
int sum[2000 + 5][2000 + 5];
int pres[2000 + 5], pret[2000 + 5];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, i, j, las = 0;
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++) f1[i][j] = f2[i][j] = 0;
    for (i = 1; i <= n; i++)
      if ((i & 1) && s[i] != '?') s[i] = char('0' + ((s[i] - '0') ^ 1));
    for (i = 1; i <= n; i++)
      if ((i & 1) && t[i] != '?') t[i] = char('0' + ((t[i] - '0') ^ 1));
    las = 0;
    for (i = 1; i <= n; i++) {
      pres[i] = las;
      if (s[i] == '1') las = i;
    }
    las = 0;
    for (i = 1; i <= n; i++) {
      pret[i] = las;
      if (t[i] == '1') las = i;
    }
    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++) sum[i][j] = 0;
    f1[0][0] = 1;
    for (i = 0; i <= n; i++) sum[0][i] = sum[i][0] = 1;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        sum[i][j] = (sum[i][j] % mod + mod) % mod;
        if (s[i] != '0' && t[j] != '0') {
          f1[i][j] = sum[i - 1][j - 1];
          if (pres[i]) f1[i][j] -= sum[pres[i] - 1][j - 1];
          if (pret[j]) f1[i][j] -= sum[i - 1][pret[j] - 1];
          if (pres[i] && pret[j]) f1[i][j] += sum[pres[i] - 1][pret[j] - 1];
          f1[i][j] = (f1[i][j] % mod + mod) % mod;
          sum[i][j] = (sum[i][j] + f1[i][j]) % mod;
        }
      }
    reverse(s + 1, s + n + 1);
    reverse(t + 1, t + n + 1);
    las = 0;
    for (i = 1; i <= n; i++) {
      pres[i] = las;
      if (s[i] == '1') las = i;
    }
    las = 0;
    for (i = 1; i <= n; i++) {
      pret[i] = las;
      if (t[i] == '1') las = i;
    }
    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++) sum[i][j] = 0;
    f2[0][0] = 1;
    for (i = 0; i <= n; i++) sum[0][i] = sum[i][0] = 1;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        sum[i][j] = (sum[i][j] % mod + mod) % mod;
        if (s[i] != '0' && t[j] != '0') {
          f2[i][j] = sum[i - 1][j - 1];
          if (pres[i]) f2[i][j] -= sum[pres[i] - 1][j - 1];
          if (pret[j]) f2[i][j] -= sum[i - 1][pret[j] - 1];
          if (pres[i] && pret[j]) f2[i][j] += sum[pres[i] - 1][pret[j] - 1];
          f2[i][j] = (f2[i][j] % mod + mod) % mod;
          sum[i][j] = (sum[i][j] + f2[i][j]) % mod;
        }
      }
    int ans = 0;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        ans = (ans + 1ll * f1[i][j] * f2[n - i + 1][n - j + 1] % mod *
                         abs(i - j) % mod) %
              mod;
    printf("%d\n", ans);
  }
}
