#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[4010];
int d[4010], top;
int ls[4010], rs[4010];
long long f[4010][4010];
int siz[4010];
void dfs(int x) {
  if (!x) return;
  dfs(ls[x]);
  dfs(rs[x]);
  if (siz[ls[x]] > siz[rs[x]]) swap(ls[x], rs[x]);
  siz[x] = siz[ls[x]] + siz[rs[x]] + 1;
  for (int i = 0; i <= siz[x]; i++) {
    for (int j = 0; j <= siz[ls[x]] && j <= i; j++) {
      if (i - j <= siz[rs[x]])
        f[x][i] = max(f[x][i],
                      f[ls[x]][j] + f[rs[x]][i - j] - 2ll * j * (i - j) * a[x]);
      if (j < i && i - j - 1 <= siz[rs[x]])
        f[x][i] =
            max(f[x][i], f[ls[x]][j] + f[rs[x]][i - j - 1] + 1ll * m * a[x] -
                             (2ll * j * (i - j - 1) + 2ll * i - 1) * a[x]);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    while (top && a[d[top]] > a[i]) ls[i] = d[top--];
    if (top) rs[d[top]] = i;
    d[++top] = i;
  }
  dfs(d[1]);
  cout << f[d[1]][m];
}
