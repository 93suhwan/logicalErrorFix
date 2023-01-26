#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct Union_Find {
  int fa[N], rnk[N];
  inline void init(int n) { iota(fa + 1, fa + 1 + n, 1); }
  int get(int x) { return x == fa[x] ? x : (fa[x] = get(fa[x])); }
  inline void merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) swap(x, y);
    fa[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
  inline bool same(int x, int y) { return get(x) == get(y); }
} U1, U2;
int n, m1, m2, ans;
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  U1.init(n), U2.init(n);
  for (int i = 1, x, y; i <= m1; i++) scanf("%d%d", &x, &y), U1.merge(x, y);
  for (int i = 1, x, y; i <= m2; i++) scanf("%d%d", &x, &y), U2.merge(x, y);
  printf("%d\n", ans = n - 1 - max(m1, m2));
  for (int i = 2; i <= n; i++) {
    if (U1.same(1, i) || U2.same(1, i)) continue;
    printf("1 %d\n", i), ans--;
    U1.merge(1, i), U2.merge(1, i);
  }
  for (int i = 2, j = 1; ans; i++) {
    if (U1.same(1, i)) continue;
    while (U2.same(1, j)) j++;
    printf("%d %d\n", i, j), ans--;
    U1.merge(1, i), U2.merge(1, j);
  }
  return 0;
}
