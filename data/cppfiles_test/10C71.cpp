#include <bits/stdc++.h>
constexpr int Mod = 1e9 + 7;
inline int fpm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1LL * res * a % Mod;
    a = 1LL * a * a % Mod;
    b >>= 1;
  }
  return res;
}
int n, m, k, r, c, sx, sy, tx, ty;
int tot;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d", &r, &c);
  scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
  if (sx == tx && sy == ty)
    tot = 1LL * n * m % (Mod - 1);
  else
    tot = ((1LL * n * m - 1LL * r * c) % (Mod - 1) + Mod - 1) % (Mod - 1);
  printf("%d\n", fpm(k, tot));
}
