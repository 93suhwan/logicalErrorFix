#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, P = 998244353;
int n, m, a[N], L[N], R[N], mu[N], f[N], g[N];
int main() {
  mu[1] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 2 * i; j < N; j += i) mu[j] -= mu[i];
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &L[i], &R[i]);
  }
  int ans = 0;
  for (int i = 1; i < N; ++i) {
    if (mu[i]) {
      f[0] = 1;
      int mx = m / i;
      for (int z = 1; z <= mx; ++z) f[z] = 0;
      for (int k = 1; k <= n; ++k) {
        int l = (L[k] + i - 1) / i, r = R[k] / i;
        for (int z = 0; z <= mx; ++z) g[z] = 0;
        for (int z = 0; z <= mx; ++z) {
          if (l + z <= mx) g[l + z] = (g[l + z] + f[z]) % P;
          if (r + z <= mx) g[r + z + 1] = (g[r + z + 1] - f[z]) % P;
        }
        f[0] = g[0];
        for (int z = 1; z <= mx; ++z) f[z] = (f[z - 1] + g[z]) % P;
      }
      for (int z = 0; z <= mx; ++z) ans = (ans + mu[i] * f[z]) % P;
    }
  }
  if (ans < 0) ans += P;
  printf("%d\n", ans);
}
