#include <bits/stdc++.h>
using namespace std;
int n, k, c[105][105], d[105], u[105], f[105][105];
vector<int> e[105];
void dfs(int x, int fa) {
  d[x] = d[fa] + 1;
  u[d[x]]++;
  for (int y : e[x])
    if (y != fa) dfs(y, x);
}
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) e[i].clear();
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  if (k == 2) {
    cout << 1LL * n * (n - 1) / 2 << endl;
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    memset(f, 0, sizeof(f));
    for (int j = 1; j <= n; j++) f[j][0] = 1;
    d[i] = 0;
    for (int y : e[i]) {
      memset(u, 0, sizeof(u));
      dfs(y, i);
      for (int j = 1; j <= n; j++)
        for (int w = k; w >= 1; w--)
          f[j][w] = (f[j][w] + 1LL * u[j] * f[j][w - 1]) % 1000000007;
    }
    for (int j = 1; j <= n; j++) ans = (ans + f[j][k]) % 1000000007;
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
