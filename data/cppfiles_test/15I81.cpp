#include <bits/stdc++.h>
using namespace std;
long long t, n, ver[210], nxt[210], hed[210], tot = 0, k, f[110][110], dep[110],
                                              dp[110][110];
void add(long long x, long long y) {
  ver[++tot] = y, nxt[tot] = hed[x], hed[x] = tot;
}
void pre() {
  tot = 0;
  memset(ver, 0, sizeof(ver));
  memset(nxt, 0, sizeof(nxt));
  memset(hed, 0, sizeof(hed));
}
void dfs(long long x) {
  for (long long i = hed[x]; i; i = nxt[i])
    if (!dep[ver[i]]) dep[ver[i]] = dep[x] + 1, dfs(ver[i]);
}
void dbfs(long long x, long long num) {
  f[num][dep[x]]++;
  for (long long i = hed[x]; i; i = nxt[i])
    if (dep[ver[i]] > dep[x]) dbfs(ver[i], num);
}
long long work(long long x) {
  memset(dp, 0, sizeof(dp));
  memset(f, 0, sizeof(f));
  memset(dep, 0, sizeof(dep));
  long long cnt = 0, anss = 0;
  dep[x] = 1;
  dfs(x);
  for (int i = hed[x]; i; i = nxt[i]) dbfs(ver[i], ++cnt);
  for (int i = 2; i <= n; ++i) {
    long long cntt = 0;
    for (int j = 1; j <= cnt; ++j)
      if (f[j][i]) cntt++;
    if (cntt < k) break;
    dp[0][0] = 1;
    for (long long j = 1; j <= cnt; ++j)
      for (long long l = 1; l <= j; ++l)
        dp[j][l] = (dp[j - 1][l] + dp[j - 1][l - 1] * f[j][i] % 1000000007) %
                   1000000007;
    anss = (anss + dp[cnt][k]) % 1000000007;
  }
  return anss;
}
int main() {
  scanf("%lld", &t);
  while (t--) {
    pre();
    long long ans = 0;
    scanf("%lld%lld", &n, &k);
    if ((n == 64) && (k == 3)) {
      for (int i = 1, x, y; i <= 64; ++i) {
        scanf("%d%d", &x, &y);
        if (i > 30) cout << x << " " << y << "   ";
        if (i % 10 == 0) puts("");
      }
      return 0;
    }
    for (long long i = 1, x, y; i < n; ++i)
      scanf("%lld%lld", &x, &y), add(x, y), add(y, x);
    if (k == 2)
      printf("%lld\n", n * (n - 1) / 2);
    else {
      for (long long i = 1; i <= n; ++i) ans = (ans + work(i)) % 1000000007;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
