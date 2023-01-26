#include <bits/stdc++.h>
using namespace std;
int as, n, l, r;
double p;
long long nmd;
bool chk(int x) {
  long long g = 0;
  for (int i = (1); i <= (n - 2); i++)
    if (i <= x)
      for (int j = (i + 1); j <= (n - 1); j++) {
        g += 1ll * (n - j) * ((j <= x) ? 2 : 1);
      }
  return 600000ll * g >= 1ll * nmd * n * (n - 1) * (n - 2);
}
int main() {
  scanf("%d%lf", &n, &p);
  nmd = p * 200000;
  r = n - 1;
  while (l <= r) {
    int mi = ((l + r) >> 1);
    if (chk(mi))
      r = mi - 1, as = mi;
    else
      l = mi + 1;
  }
  printf("%d", as);
}
