#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
int a[15], p[15][15], f[100001];
int pw(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = 1ll * x * x % md)
    if (y & 1) ans = 1ll * ans * x % md;
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      p[i][j] = 1ll * a[i] * pw(a[i] + a[j], md - 2) % md;
  int ans = 0;
  for (int s = 1; s < 1 << n; s++) {
    f[s] = 1;
    int oo = 1;
    for (int i = 1; i <= n; i++)
      if (s >> i - 1 & 1)
        for (int j = 1; j <= n; j++)
          if (!(s >> j - 1 & 1)) oo = 1ll * oo * p[i][j] % md;
    for (int s2 = s - 1 & s; s2 != 0; s2 = s2 - 1 & s) {
      int o = 1;
      for (int i = 1; i <= n; i++)
        if ((s >> i - 1 & 1) && (s2 >> i - 1 & 1))
          for (int j = 1; j <= n; j++)
            if ((s >> j - 1 & 1) && !(s2 >> j - 1 & 1))
              o = 1ll * o * p[i][j] % md;
      f[s] = ((f[s] - 1ll * o * f[s2]) % md + md) % md;
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
      if (s >> i - 1 & 1) num++;
    ans = (ans + 1ll * f[s] * oo * num) % md;
  }
  printf("%d\n", ans);
}
