#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int qkpow(int a, int b) {
  int base = a, ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * base % mod;
    base = 1ll * base * base % mod;
    b >>= 1;
  }
  return ans;
}
int fac[1000005], inv[1000005];
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void init_C(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[0] = 1;
  inv[n] = qkpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int t, n, d, res, a[1000005], dp1[2000005], wtf[1000005];
int vis[1000005];
vector<int> G[1000005];
vector<int> P;
const int INF = 2e9;
int dfs1(int u) {
  if (dp1[u] != INF) return dp1[u];
  int ans = INF;
  for (int i = 0; i < G[u].size(); i++) ans = min(dp1[u], dfs1(G[u][i]) + 1);
  return dp1[u] = ans;
}
void ck(int u) {
  vis[u] = 1;
  if (!a[u]) res++;
  for (int i = 0; i < G[u].size(); i++)
    if (!vis[G[u][i]]) ck(G[u][i]);
}
signed main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) dp1[i] = (a[i] ? INF : 0);
    for (int i = 0; i < n; i++) G[i].clear(), vis[i] = 0;
    for (int i = 0; i < n; i++) G[i].push_back((i + n - d) % n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        res = 0, ck(i);
        if (res == 0) {
          ans = INF;
          break;
        }
      }
      dfs1(i);
    }
    for (int i = 0; i < n; i++)
      if (a[i]) ans = max(ans, dp1[i]);
    if (ans == INF)
      puts("-1");
    else
      cout << ans << endl;
  }
  return 0;
}
