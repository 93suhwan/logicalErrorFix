#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[4086];
int son[4086][2];
int sk[4086], top;
long long f[4086][4086], g[4086];
int siz[4086];
void dfs(int i) {
  f[i][0] = f[i][1] = 0, siz[i] = 1;
  for (int j = 0; j <= 1; j++) {
    int to = son[i][j];
    if (!to) continue;
    dfs(to);
    for (int k = 0; k <= min(siz[i], m); k++) {
      for (int l = 0; l <= min(siz[to], m - k); l++) {
        g[k + l] = max(g[k + l],
                       f[i][k] + f[to][l] + 1ll * (a[to] - a[i]) * l * (m - l));
      }
    }
    for (int k = 0; k <= min(siz[i] + siz[to], m); k++)
      f[i][k] = g[k], g[k] = -1e18;
    siz[i] += siz[to];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int last = 0;
    while (top && a[sk[top]] > a[i]) last = sk[top--];
    son[i][0] = last, son[sk[top]][1] = i;
    sk[++top] = i;
  }
  memset(f, -0x3f, sizeof(f)), memset(g, -0x3f, sizeof(g));
  dfs(sk[1]);
  printf("%lld", f[sk[1]][m]);
}
