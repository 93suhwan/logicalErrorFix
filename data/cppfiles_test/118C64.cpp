#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, G = 3, gg = (mod + 1) / G, N = 4e5;
int rev[N];
int ksm(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ret = 1ll * ret * a % mod;
  return ret;
}
void ntt(vector<int>& f, int e) {
  int n = f.size() - 1;
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(f[i], f[rev[i]]);
  for (int i = 1; i < n; i = i * 2) {
    int w = ksm(e == 1 ? G : gg, (mod - 1) / 2 / i);
    for (int j = 0; j < n; j += i + i) {
      int wn = 1;
      for (int k = 0; k < i; k++) {
        int x = f[k + j], y = 1ll * wn * f[i + k + j] % mod;
        f[k + j] = (x + y) % mod, f[k + j + i] = (x - y + mod) % mod;
        wn = 1ll * wn * w % mod;
      }
    }
  }
}
int deg[N], n, fac[N];
vector<int> mul(vector<int> V1, vector<int> V2) {
  int maxl = 1, L0 = V1.size() - 1 + V2.size();
  while (maxl <= L0) maxl <<= 1;
  for (int i = 0; i < maxl; i++)
    rev[i] = rev[i >> 1] >> 1 | ((i & 1) ? maxl >> 1 : 0);
  V1.resize(maxl);
  V2.resize(maxl);
  ntt(V1, 1);
  ntt(V2, 1);
  for (int i = 0; i < maxl; i++) V1[i] = 1ll * V1[i] * V2[i] % mod;
  ntt(V1, -1);
  V1.resize(L0);
  for (int i = 0, inv = ksm(maxl, mod - 2); i < L0; i++)
    V1[i] = 1ll * inv * V1[i] % mod;
  return V1;
}
vector<int> divid_ntt(int l, int r) {
  if (l == r) return vector<int>{1, deg[l]};
  int mid = l + r >> 1;
  return mul(divid_ntt(l, mid), divid_ntt(mid + 1, r));
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) deg[i]--;
  for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), ++deg[u], deg[v]++;
  vector<int> f = divid_ntt(1, n);
  int ans = 0;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 0; i < n; i++)
    ans = (((i & 1) ? -1ll : 1ll) * f[i] * fac[n - i] % mod + ans + mod) % mod;
  printf("%d", ans);
  return 0;
}
