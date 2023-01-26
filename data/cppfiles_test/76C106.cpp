#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e6 + 5;
int n, Mod;
ll f[N], g[N], sum[N];
int main() {
  scanf("%d%d", &n, &Mod);
  sum[1] = 1;
  f[1] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i > 1) {
      g[i] = (g[i] + g[i - 1]) % Mod;
      f[i] = (sum[i - 1] + g[i]) % Mod;
      sum[i] = (sum[i - 1] + f[i]) % Mod;
    }
    for (int j = 2; j <= n / i; ++j) {
      g[i * j] = (g[i * j] + f[i]) % Mod;
      g[(i + 1) * j] = ((g[(i + 1) * j] - f[i]) % Mod + Mod) % Mod;
    }
  }
  printf("%lld\n", f[n]);
  return 0;
}
