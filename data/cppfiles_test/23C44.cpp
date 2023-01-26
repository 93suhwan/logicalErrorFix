#include <bits/stdc++.h>
using namespace std;
int N, M, a[4001], ls[4001], rs[4001], siz[4001];
long long f[4001][4001];
int build(int l, int r) {
  if (l > r) return 0;
  int x = l;
  for (int i = l + 1; i <= r; i++)
    if (a[i] < a[x]) x = i;
  ls[x] = build(l, x - 1);
  rs[x] = build(x + 1, r);
  return x;
}
void dfs(int u) {
  siz[u] = 1;
  if (ls[u]) dfs(ls[u]), siz[u] += siz[ls[u]];
  if (rs[u]) dfs(rs[u]), siz[u] += siz[rs[u]];
  for (int i = 0; i <= siz[ls[u]]; i++)
    for (int j = 0; j <= siz[rs[u]]; j++)
      f[u][i + j] =
          max(f[u][i + j], f[ls[u]][i] + f[rs[u]][j] - 2ll * i * j * a[u]),
               f[u][i + j + 1] =
                   max(f[u][i + j + 1], f[ls[u]][i] + f[rs[u]][j] +
                                            (M - 1ll) * a[u] -
                                            2ll * (i + j + i * j) * a[u]);
}
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> a[i];
  int rt = build(1, N);
  dfs(rt);
  cout << f[rt][M] << '\n';
  return 0;
}
