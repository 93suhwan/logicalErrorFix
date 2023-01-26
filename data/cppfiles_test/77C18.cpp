#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e6 + 10;
long long mod, n;
long long f[maxn], g[maxn];
int main() {
  scanf("%lld", &n), scanf("%lld", &mod);
  f[1] = 1;
  long long sum = 0;
  for (long long i = 2; i <= n; ++i) {
    g[i] += g[i - 1] + 1;
    sum += f[i - 1];
    f[i] = sum + g[i];
    f[i] %= mod;
    for (long long j = 2; j * i <= n; ++j) {
      g[i * j] += f[i] - f[i - 1];
      g[i * j] = (g[i * j] + mod) % mod;
    }
  }
  printf("%lld\n", f[n] % mod);
  return 0;
}
