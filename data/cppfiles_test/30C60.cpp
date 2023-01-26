#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[150005];
int id[1000005];
int lt[1000005];
int tmp[25];
int sl = 0;
pair<int, int> p[4000000];
int r = 0;
int Find(int u) {
  if (lt[u] == u) return u;
  return lt[u] = Find(lt[u]);
}
int main() {
  scanf("%d %d ", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d ", &a[i]);
  for (int i = 1; i <= 1000001; ++i) id[i] = i, lt[i] = i;
  for (int i = 2; i <= 1000001; ++i)
    if (id[i] == i)
      for (int j = 2; i * j <= 1000001; ++j) id[i * j] = i;
  for (int i = 1; i <= n; ++i) {
    int u = a[i];
    sl = 0;
    while (u > 1) {
      tmp[++sl] = id[u];
      u /= id[u];
    }
    sl = unique(tmp + 1, tmp + sl + 1) - tmp - 1;
    for (int j = 1; j < sl; ++j) {
      int x = Find(tmp[j]);
      int y = Find(tmp[j + 1]);
      if (x != y) lt[x] = y;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int u = a[i] + 1;
    sl = 0;
    tmp[++sl] = id[a[i]];
    while (u > 1) {
      tmp[++sl] = id[u];
      u /= id[u];
    }
    for (int j = 1; j <= sl; ++j) tmp[j] = Find(tmp[j]);
    sort(tmp + 1, tmp + sl + 1);
    sl = unique(tmp + 1, tmp + sl + 1) - tmp - 1;
    for (int j = 1; j <= sl; ++j)
      for (int j1 = j + 1; j1 <= sl; ++j1)
        p[++r] = pair<int, int>(tmp[j], tmp[j1]);
  }
  sort(p + 1, p + r + 1);
  r = unique(p + 1, p + r + 1) - p - 1;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    scanf("%d %d ", &x, &y);
    int ans = 2;
    int u = id[a[x]];
    int v = id[a[y]];
    u = Find(u);
    v = Find(v);
    if (u == v) ans = 0;
    if (u > v) swap(u, v);
    int k = lower_bound(p + 1, p + r + 1, pair<int, int>(u, v)) - p;
    if (p[k].first == u && p[k].second == v) ans = 1;
    printf("%d\n", ans);
  }
}
