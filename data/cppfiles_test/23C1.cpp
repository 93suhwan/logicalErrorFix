#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
int ls[N], rs[N], stk[N], top = 0, lw[N], rw[N], a[N], n, m;
int sze[N];
long long f[N][N];
inline void dfs(int x) {
  sze[x] = 1;
  if (ls[x]) {
    dfs(ls[x]);
    for (int i = min(m, sze[x]); i >= 0; i--)
      for (int j = min(m, sze[ls[x]]); j >= 0; j--)
        f[x][i + j] =
            max(f[x][i + j], f[x][i] + f[ls[x]][j] + 1ll * j * (m - j) * lw[x]);
    sze[x] += sze[ls[x]];
  }
  if (rs[x]) {
    dfs(rs[x]);
    for (int i = min(m, sze[x]); i >= 0; i--)
      for (int j = min(m, sze[rs[x]]); j >= 0; j--)
        f[x][i + j] =
            max(f[x][i + j], f[x][i] + f[rs[x]][j] + 1ll * j * (m - j) * rw[x]);
    sze[x] += sze[rs[x]];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int tmp = top;
    while (top && a[stk[top]] > a[i]) rs[stk[top - 1]] = stk[top], top--;
    if (top < tmp) ls[i] = stk[top + 1];
    stk[++top] = i;
  }
  while (top) rs[stk[top - 1]] = stk[top], top--;
  for (int i = 1; i <= n; i++) {
    if (ls[i]) lw[i] = abs(a[i] - a[ls[i]]);
    if (rs[i]) rw[i] = abs(a[i] - a[rs[i]]);
  }
  int minn = 0x7f7f7f7f, pos = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] < minn) minn = a[i], pos = i;
  assert(stk[1] == pos);
  dfs(pos);
  printf("%lld\n", f[pos][m]);
  return 0;
}
