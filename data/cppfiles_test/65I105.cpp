#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 5;
int prime[N + 5], mu[N + 5], tot = 0;
bool vis[N + 5];
int n, m;
long long l[55], r[55];
long long f[N], g[N];
long long ans = 0;
void init() {
  mu[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      prime[tot] = i;
      tot++;
      mu[i] = -1;
    }
    for (int j = 0; j < tot && prime[j] * i <= N; j++) {
      vis[prime[j] * i] = 1;
      if (i % prime[j] == 0) {
        mu[prime[j] * i] = 0;
        break;
      }
      mu[prime[j] * i] = -mu[i];
    }
  }
  for (int i = 1; i <= N; i++) mu[i] = (mu[i] + mu[i - 1]) % mod;
}
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", l + i, r + i);
  for (int i = 1, tmp; i <= m; i = tmp + 1) {
    tmp = m / (m / i);
    f[0] = g[0] = 1;
    for (int j = 1; j <= m / i; j++) f[j] = 0, g[j] = 1;
    for (int j = 1; j <= n; j++) {
      int ql = (l[j] - 1) / i + 1, qr = r[j] / i;
      if (ql > qr) {
        g[m / i] = 0;
        break;
      }
      for (int k = 0; k < ql; k++) f[k] = 0;
      for (int k = ql; k <= m / i; k++)
        f[k] = g[k - ql] - (k > qr ? g[k - qr - 1] : 0);
      g[0] = f[0];
      for (int k = 1; k <= m / i; k++) g[k] = (g[k - 1] + f[k]) % mod;
    }
    ans = ans + ((mu[tmp] - mu[i - 1]) * g[m / i]) % mod;
    ans = (ans + mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
