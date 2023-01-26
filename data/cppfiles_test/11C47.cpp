#include <bits/stdc++.h>
using namespace std;
int n, mx[200010 * 4], v[200010], b[200010], f[200010];
struct nd {
  int x, y, id;
} a[200010];
int cmp(nd xx, nd yy) { return xx.x < yy.x; }
void upd(int o, int l, int r, int x, int v) {
  if (l == r) {
    mx[o] = v;
    return;
  }
  int lc = o << 1, rc = o << 1 | 1, mid = (l + r) >> 1;
  if (x <= mid)
    upd(lc, l, mid, x, v);
  else
    upd(rc, mid + 1, r, x, v);
  mx[o] = max(mx[lc], mx[rc]);
}
int query(int o, int l, int r, int ql, int qr) {
  if (l > r) return 0;
  if (ql <= l && r <= qr) return mx[o];
  int lc = o << 1, rc = o << 1 | 1, mid = (l + r) >> 1;
  int res = -1;
  if (ql <= mid) res = max(res, query(lc, l, mid, ql, qr));
  if (qr > mid) res = max(res, query(rc, mid + 1, r, ql, qr));
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i].x), a[i].y = i - a[i].x, b[i] = a[i].y, a[i].id = i;
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++)
    a[i].y = lower_bound(b + 1, b + n + 1, a[i].y) - b;
  sort(a + 1, a + n + 1, cmp);
  for (int i = n; i >= 1; i--) v[a[i].x] = i;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = query(1, 1, n, 1, a[i].y);
    if (a[i].id >= a[i].x) f[i]++;
    ans = max(ans, f[i]);
    if (v[a[i + 1].x] == i + 1) {
      for (int j = v[a[i].x]; j <= i; j++) upd(1, 1, n, a[j].y, f[j]);
    }
  }
  printf("%d", ans);
  return 0;
}
