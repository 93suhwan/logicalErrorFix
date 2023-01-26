#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m1, m2;
bool vis[N];
struct UFS {
  int fa[N], siz[N];
  void init() {
    for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  }
  int getFa(int x) {
    int px = x, tmp;
    while (fa[x] != x) x = fa[x];
    while (px != x) tmp = px, px = fa[px], fa[tmp] = x;
    return x;
  }
  bool same(int x, int y) { return getFa(x) == getFa(y); }
  void merge(int x, int y) {
    x = getFa(x), y = getFa(y);
    if (x == y) return;
    if (siz[x] < siz[y])
      fa[x] = y, siz[y] += siz[x];
    else
      fa[y] = x, siz[x] += siz[y];
  }
  int count() {
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (fa[i] == i) ans++;
    return ans;
  }
} M, D;
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  M.init(), D.init();
  for (int i = 1; i <= m1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    vis[x] = vis[y] = true;
    M.merge(x, y);
  }
  for (int i = 1; i <= m2; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    vis[x] = vis[y] = true;
    D.merge(x, y);
  }
  int p = 0, ans = min(M.count(), D.count()) - 1;
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (vis[i]) {
      p = i;
      break;
    }
  if (p == 0) {
    for (int i = 1; i <= ans; i++) printf("%d %d\n", i, i + 1);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) printf("%d %d\n", p, i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (!vis[i] || !vis[j] || M.same(i, j) || D.same(i, j)) continue;
      M.merge(i, j), D.merge(i, j);
      printf("%d %d\n", i, j);
    }
  return 0;
}
