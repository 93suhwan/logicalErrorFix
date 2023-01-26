#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, M = 998244353, L = 1000000000;
const long long inf = 100000000000000000ll;
int n, m, k, i, j, t, b[N];
struct node {
  int a, x;
} a[N];
bool cmp(node a, node b) {
  if (a.a == b.a) return a.x < b.x;
  return a.a < b.a;
}
struct str {
  int tree[N * 4], lazy[N * 4];
  void clear() {
    for (int i = 1; i <= n * 4; ++i) lazy[i] = tree[i] = 0;
    k = 1;
  }
  void pushup(int i) {
    tree[i] = min(tree[i << 1], tree[i << 1 | 1]) + lazy[i];
  }
  void modify(int i, int l, int r, int ll, int rr, int x) {
    if (l >= ll && r <= rr) {
      tree[i] += x;
      lazy[i] += x;
      return;
    }
    int mid = l + r >> 1;
    if (mid >= ll) modify(i << 1, l, mid, ll, rr, x);
    if (mid < rr) modify(i << 1 | 1, mid + 1, r, ll, rr, x);
    pushup(i);
  }
  int Query(int i, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) return tree[i];
    int mid = l + r >> 1, s = 1 << 30;
    if (mid >= ll) s = min(s, Query(i << 1, l, mid, ll, rr));
    if (mid < rr) s = min(s, Query(i << 1 | 1, mid + 1, r, ll, rr));
    return s + lazy[i];
  }
} x;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    long long ans = 0;
    for (i = 1; i <= n; ++i) {
      scanf("%d", &a[i].a);
      a[i].x = i;
      x.modify(1, 0, n, i, n, 1);
    }
    sort(a + 1, a + 1 + n, cmp);
    for (i = 1; i <= m; ++i) scanf("%d", &b[i]);
    sort(b + 1, b + 1 + m);
    int l1 = 1, l2 = 1;
    for (i = 1; i <= m; ++i) {
      while (l1 <= n && a[l1].a <= b[i]) {
        x.modify(1, 0, n, a[l1].x, n, -1);
        ++l1;
      }
      while (l2 <= n && a[l2].a < b[i]) {
        x.modify(1, 0, n, 0, a[l2].x - 1, 1);
        ++l2;
      }
      ans += x.tree[1];
    }
    x.clear();
    for (i = 1; i <= n; ++i) {
      ans += x.Query(1, 0, n, a[i].x, a[i].x);
      x.modify(1, 0, n, 0, a[i].x - 1, 1);
    }
    x.clear();
    printf("%lld\n", ans);
  }
}
