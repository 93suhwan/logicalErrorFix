#include <bits/stdc++.h>
using namespace std;
int tcase, n, K;
long long ans;
vector<int> e[110];
int cnt[110][110];
long long f[110][110];
long long C[110][110];
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
  f[0][0] = 1;
  for (int t = 1; t <= n; t++) {
    int lim = 0, i = 1;
    for (int fn : e[r]) {
      int x = cnt[fn][t];
      lim += x;
      for (int j = 0; j <= lim && j <= K; j++)
        for (int k = 0; k <= j && k <= x; k++)
          f[i][j] = (f[i][j] + f[i - 1][j - k] * C[x][k]) % 1000000007;
      i++;
    }
    ret = (ret + f[i - 1][K]) % 1000000007;
    lim = 0;
    i = 1;
    for (int fn : e[r]) {
      lim += cnt[fn][t];
      for (int j = 0; j <= lim && j <= K; j++) f[i][j] = 0;
      i++;
    }
  }
  return ret;
}
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
  }
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
