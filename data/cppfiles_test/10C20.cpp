#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, k, r, c;
int power(int x, long long y) {
  int z = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) z = 1ll * z * x % mod;
  return z;
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &r, &c);
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  if (x1 == x2 && y1 == y2)
    printf("%d\n", power(k, 1ll * n * m));
  else
    printf("%d\n", power(k, 1ll * n * m - 1ll * r * c));
  return 0;
}
