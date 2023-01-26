#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, mod = 998244353;
int n, m, k, a[N], fa[N], nxt[N], pre[N], tg[N], sz[N], ct[N], stk[N], f[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    tg[x] = 1;
    return;
  }
  fa[x] = y;
  sz[y] += sz[x];
  tg[y] |= tg[x];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) fa[i] = i, sz[i] = 1;
  for (int i = 1, c; i <= n; ++i) {
    scanf("%d", &c);
    for (int j = 1; j <= c; ++j) {
      scanf("%d", &a[j]);
      if (j == 1) continue;
      if (nxt[a[j - 1]] && nxt[a[j - 1]] != a[j])
        tg[find(a[j - 1])] = tg[find(a[j])] = 1;
      else if (pre[a[j]] && pre[a[j]] != a[j - 1])
        tg[find(a[j - 1])] = tg[find(a[j])] = 1;
      else
        nxt[a[j - 1]] = a[j], pre[a[j]] = a[j - 1], merge(a[j - 1], a[j]);
    }
  }
  for (int i = 1; i <= k; ++i)
    if (find(i) == i && !tg[i]) ct[sz[i]]++;
  int top = 0;
  for (int i = 1; i <= k; ++i)
    if (ct[i]) stk[++top] = i;
  f[0] = 1;
  for (int i = 0; i <= m; ++i)
    for (int j = 1; j <= top && i + stk[j] <= m; ++j)
      f[i + stk[j]] = (f[i + stk[j]] + 1ll * f[i] * ct[stk[j]]) % mod;
  printf("%d\n", f[m]);
  return 0;
}
