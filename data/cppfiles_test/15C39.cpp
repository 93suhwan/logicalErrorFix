#include <bits/stdc++.h>
using namespace std;
int tcase, n, K;
long long ans;
vector<int> e[110];
int cnt[110][110];
long long f[110];
void dfs(int sn, int fa, int r, int d) {
  cnt[r][d]++;
  for (int fn : e[sn])
    if (fn != fa) dfs(fn, sn, r, d + 1);
}
long long gao(int r) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cnt[i][j] = 0;
  for (int fn : e[r]) dfs(fn, r, fn, 1);
  long long ret = 0;
  for (int t = 1; t <= n; t++) {
    for (int i = 0; i <= n; i++) f[i] = 0;
    f[0] = 1;
    int lim = 0;
    for (int fn : e[r]) {
      lim++;
      for (int i = min(lim, K); i; i--)
        f[i] = (f[i] + f[i - 1] * cnt[fn][t]) % 1000000007;
    }
    ret = (ret + f[K]) % 1000000007;
  }
  return ret;
}
int main() {
  scanf("%d", &tcase);
  while (tcase--) {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      e[a].push_back(b);
      e[b].push_back(a);
    }
    if (K == 2) {
      printf("%d\n", n * (n - 1) / 2);
      continue;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + gao(i)) % 1000000007;
    printf("%lld\n", ans);
  }
  return 0;
}
