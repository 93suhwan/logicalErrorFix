#include <bits/stdc++.h>
using namespace std;
long long n, m, f[4001], st[4001], cnt, l[4001], r[4001], ls[4001], rs[4001],
    sz[4001], ans[4001][4001];
void dfs(long long a, long long c) {
  if (!a) return;
  dfs(l[a], ls[a]);
  dfs(r[a], rs[a]);
  sz[a] = 1ll + sz[l[a]] + sz[r[a]];
  for (long long i = 0ll; i <= sz[l[a]]; i++) {
    if (i > m) break;
    for (long long j = 0ll; j <= sz[r[a]]; j++) {
      if (i + j > m) break;
      ans[a][i + j] = max(ans[a][i + j], ans[l[a]][i] + ans[r[a]][j] +
                                             c * (i + j) * (m - i - j));
      if (i + j + 1ll <= m)
        ans[a][i + j + 1ll] =
            max(ans[a][i + j + 1ll], ans[l[a]][i] + ans[r[a]][j] +
                                         c * (i + j + 1ll) * (m - i - j - 1ll));
    }
  }
}
int main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1ll; i <= n; i++) {
    scanf("%lld", &f[i]);
    while (cnt) {
      if (f[i] < f[st[cnt]]) {
        l[i] = st[cnt];
        ls[i] = f[st[cnt]] - f[i];
        cnt--;
      } else
        break;
    }
    if (cnt) {
      r[st[cnt]] = i;
      rs[st[cnt]] = f[i] - f[st[cnt]];
    }
    cnt++;
    st[cnt] = i;
  }
  dfs(st[1ll], 0ll);
  printf("%lld\n", ans[st[1ll]][m]);
}
