#include <bits/stdc++.h>
using namespace std;
int n, m, f[4000010];
int main() {
  f[1] = 1;
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) {
    f[i] = (f[i] + 2ll * f[i - 1] + 1) % m;
    if (i == 2) f[i]--;
    for (int j = 2 * i; j < 4000010; j += i)
      f[j] = (1ll * f[j] + f[i] + m - f[i - 1]) % m;
  }
  printf("%d\n", f[n]);
}
