#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m1, m2;
int p[N], q[N];
pair<int, int> ans[N];
int findp(int u) {
  if (u != p[u]) p[u] = findp(p[u]);
  return p[u];
}
int findq(int u) {
  if (u != q[u]) q[u] = findq(q[u]);
  return q[u];
}
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  for (int i = 1; i <= n; i++) p[i] = i, q[i] = i;
  while (m1--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int pa = findp(a), pb = findp(b);
    if (pa != pb) p[pa] = pb;
  }
  while (m2--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int pa = findq(a), pb = findq(b);
    if (pa != pb) q[pa] = pb;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int pa = findp(i), pb = findp(j);
      int qa = findq(i), qb = findq(j);
      if (pa == pb || qa == qb) continue;
      ans[++cnt] = {i, j};
      p[pa] = pb, q[qa] = qb;
    }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
