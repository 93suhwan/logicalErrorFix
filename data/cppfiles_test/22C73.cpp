#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, SQ = 455;
int n, m, x[N], y[N], bl, c[N], cnt[SQ][SQ], cc, tt[N];
void add(int x, int y, int z) {
  if (x <= y) c[x] += z, c[y + 1] -= z;
}
int main() {
  scanf("%d%d", &n, &m);
  bl = sqrt(m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  int nw = 0;
  for (int t = 1; t <= m; t++) {
    int op, id;
    scanf("%d%d", &op, &id);
    if (op == 1) {
      cc++, tt[id] = t;
      if (x[id] + y[id] > bl) {
        for (int d = t; d <= m; d += x[id] + y[id])
          add(d, min(d + x[id] - 1, m), 1);
      } else {
        int l = t % (x[id] + y[id]), r = (x[id] - 1 + t) % (x[id] + y[id]);
        if (l <= r) {
          for (int i = l; i <= r; i++) cnt[x[id] + y[id]][i]++;
        } else {
          for (int i = l; i < x[id] + y[id]; i++) cnt[x[id] + y[id]][i]++;
          for (int i = 0; i <= r; i++) cnt[x[id] + y[id]][i]++;
        }
      }
    } else {
      cc--;
      if (x[id] + y[id] > bl) {
        for (int d = tt[id]; d <= m; d += x[id] + y[id])
          add(max(d, t), min(d + x[id] - 1, m), -1);
      } else {
        int l = tt[id] % (x[id] + y[id]),
            r = (x[id] - 1 + tt[id]) % (x[id] + y[id]);
        if (l <= r) {
          for (int i = l; i <= r; i++) cnt[x[id] + y[id]][i]--;
        } else {
          for (int i = l; i < x[id] + y[id]; i++) cnt[x[id] + y[id]][i]--;
          for (int i = 0; i <= r; i++) cnt[x[id] + y[id]][i]--;
        }
      }
      tt[id] = 0;
    }
    nw += c[t];
    int ans = nw;
    for (int i = 1; i <= bl; i++) ans += cnt[i][t % i];
    printf("%d\n", cc - ans);
  }
  return 0;
}
