#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 4005;
int a[N], ls[N], rs[N], sz[N];
int st[N], tot;
long long lw[N], rw[N], f[N][N];
void dfs(int u) {
  int i, j;
  sz[u] = 1;
  if (ls[u]) {
    dfs(ls[u]);
    for (i = min(sz[u], m); i >= 0; i--)
      for (j = min(sz[ls[u]], m); j >= 0; j--)
        f[u][i + j] = max(f[u][i + j], f[ls[u]][j] + lw[u] * j * (m - j));
    sz[u] += sz[ls[u]];
  }
  if (rs[u]) {
    dfs(rs[u]);
    for (i = min(sz[u], m); i >= 0; i--)
      for (j = min(sz[rs[u]], m); j >= 0; j--)
        f[u][i + j] =
            max(f[u][i + j], f[u][i] + f[rs[u]][j] + rw[u] * j * (m - j));
    sz[u] += sz[rs[u]];
  }
}
int main() {
  int i;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    while (tot > 0 && a[st[tot]] > a[i])
      ls[i] = st[tot], lw[i] = a[st[tot]] - a[i], tot--;
    if (tot) rs[st[tot]] = i, rw[st[tot]] = a[i] - a[st[tot]];
    st[++tot] = i;
  }
  dfs(st[1]);
  cout << f[st[1]][m];
  return 0;
}
