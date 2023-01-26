#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
inline void add_mod(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
struct BIT {
  int tree[MAXN * 2], n;
  inline void update(int x, int k) {
    while (x <= n) add_mod(tree[x], k), x += ((x) & -(x));
  }
  inline int query(int x) {
    int res = 0;
    while (x) add_mod(res, tree[x]), x ^= ((x) & -(x));
    return res;
  }
  inline int query(int l, int r) {
    int res = query(r);
    add_mod(res, mod - query(l - 1));
    return res;
  }
} tree;
int a[MAXN], b[MAXN];
int id[MAXN * 2];
int f[MAXN];
int p[MAXN];
int main(void) {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &p[i]);
  for (int i = 1; i <= n; ++i) id[a[i]] = i, id[b[i]] = -i;
  tree.n = 2 * n;
  for (int i = 1; i <= 2 * n; ++i)
    if (id[i] < 0) {
      int x = -id[i];
      f[x] = tree.query(a[x], b[x]);
      tree.update(a[x], f[x] + 1);
    }
  sort(p + 1, p + m + 1, [&](int x, int y) { return b[x] > b[y]; });
  static bool del[MAXN];
  int sum = 0;
  for (int i = 1; i <= n; ++i) add_mod(sum, f[i] + 1);
  auto pop = [&](int u) {
    u = abs(u);
    if (del[u]) return;
    del[u] = 1;
    add_mod(sum, mod - f[u] - 1);
  };
  int i = 1, j = 2 * n;
  int ans = 0;
  for (int iu = 1; iu <= m; ++iu) {
    int u = p[iu];
    if (del[u]) continue;
    while (j >= b[u]) pop(id[j--]);
    add_mod(ans, sum + 1);
    while (i <= a[u]) pop(id[i++]);
  }
  printf("%d", ans);
  return 0;
}
