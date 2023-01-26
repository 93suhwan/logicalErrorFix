#include <bits/stdc++.h>
using namespace std;
int ls[4010], rs[4010];
int lw[4010], rw[4010];
int n, a[4010], st[4010], cnt, m;
long long f[4010][4010];
int sz[4010];
void dfs(int x) {
  sz[x]++;
  if (ls[x]) dfs(ls[x]), sz[x] += sz[ls[x]];
  if (rs[x]) dfs(rs[x]), sz[x] += sz[rs[x]];
  for (int i = 0; i <= sz[ls[x]]; i++)
    for (int j = 0; j <= sz[rs[x]]; j++) {
      if (i + j > m)
        break;
      else {
        f[x][i + j] =
            max(f[ls[x]][i] + f[rs[x]][j] + 1ll * i * (m - i) * lw[x] +
                    1ll * j * (m - j) * rw[x],
                f[x][i + j]);
        f[x][i + j + 1] =
            max(f[ls[x]][i] + f[rs[x]][j] + 1ll * i * (m - i) * lw[x] +
                    1ll * j * (m - j) * rw[x],
                f[x][i + j + 1]);
      }
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int pre = cnt;
    while (cnt && a[i] < a[st[cnt]]) cnt--;
    if (cnt) {
      rs[st[cnt]] = i;
      rw[st[cnt]] = a[i] - a[st[cnt]];
    }
    if (cnt < pre) {
      ls[i] = st[cnt + 1];
      lw[i] = a[st[cnt + 1]] - a[i];
    }
    st[++cnt] = i;
  }
  dfs(st[1]);
  printf("%lld\n", f[st[1]][m]);
}
