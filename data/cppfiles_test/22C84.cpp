#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[200005], y[200005], t[200005], f[200005];
int g[1000][1000];
void modify(int i, int j) {
  if (i > m)
    return;
  else
    f[i] += j;
}
int main() {
  scanf("%d %d", &n, &m);
  int sqt = sqrt(m);
  for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
  for (int i = 1, op, k, lst = 0; i <= m; i++) {
    scanf("%d %d", &op, &k);
    int v = op & 1 ? 1 : -1;
    if (op & 1) t[k] = i;
    if (x[k] + y[k] >= sqt) {
      for (int j = t[k] + x[k]; j <= m; j += x[k] + y[k])
        modify(max(j, i), v), modify(max(j + y[k], i), -v);
    } else {
      for (int j = t[k] + x[k]; j < t[k] + x[k] + y[k]; j++)
        g[x[k] + y[k]][j % (x[k] + y[k])] += v;
    }
    int ans = lst + f[i];
    lst = ans;
    for (int j = 1; j < sqt; j++) ans += g[j][i % j];
    printf("%d\n", ans);
  }
  return 0;
}
