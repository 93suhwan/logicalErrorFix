#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200007;
int a[N];
struct node {
  int mx, l, r;
};
struct SegT {
  node tr[N * 70];
  int tot = 0;
  void pushup(int k) { tr[k].mx = max(tr[tr[k].l].mx, tr[tr[k].r].mx); }
  int query(int k, int cl, int cr, int l, int r) {
    if (!k) return 0;
    if (cl <= l && r <= cr) {
      return tr[k].mx;
    } else {
      int mid = ((l + r) >> 1);
      int res = 0;
      if (cl <= mid) res = max(res, query(tr[k].l, cl, cr, l, mid));
      if (cr > mid) res = max(res, query(tr[k].r, cl, cr, mid + 1, r));
      return res;
    }
  }
  void upd(int &k, int x, int l, int r, int v) {
    if (!k) k = ++tot;
    if (l == r) {
      tr[k].mx = max(tr[k].mx, v);
    } else {
      int mid = ((l + r) >> 1);
      if (x <= mid)
        upd(tr[k].l, x, l, mid, v);
      else
        upd(tr[k].r, x, mid + 1, r, v);
      pushup(k);
    }
  }
} segt;
struct BIT {
  int rt[N];
  int query(int x, int l, int r) {
    int res = 0;
    for (int i = x; i; i -= (i & (-i)))
      res = max(res, segt.query(rt[i], l, r, 0, N - 1));
    return res;
  }
  void upd(int x, int y, int v) {
    for (int i = x; i < N; i += (i & (-i))) segt.upd(rt[i], y, 0, N - 1, v);
  }
} bit;
int main() {
  sizeof(segt);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= i) {
      int res = bit.query(a[i] - 1, 0, i - a[i]);
      bit.upd(a[i], i - a[i], res + 1);
      mx = max(mx, res + 1);
    }
  }
  printf("%d\n", mx);
}
