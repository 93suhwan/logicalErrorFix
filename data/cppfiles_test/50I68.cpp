#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 998244353;
int n, a[N];
int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
int mul(int x, int y) { return 1ll * x * y % mod; }
struct node {
  int sum, l, r, tagp, tagm;
} tr[N << 5];
int cnt, Rt;
void pushup(int k) { tr[k].sum = add(tr[tr[k].l].sum, tr[tr[k].r].sum); }
void change(int k, int l, int r, int vp, int vm) {
  if (!k) k = ++cnt, tr[k].tagm = 1;
  tr[k].sum = mul(tr[k].sum, vm);
  tr[k].sum = add(tr[k].sum, mul(r - l + 1, vp));
  tr[k].tagp = mul(tr[k].tagp, vm);
  tr[k].tagp = add(tr[k].tagp, vp);
  tr[k].tagm = mul(tr[k].tagm, vm);
}
void pushdown(int k, int l, int r) {
  change(tr[k].l, l, (l + r) / 2, tr[k].tagp, tr[k].tagm);
  change(tr[k].r, (l + r) / 2 + 1, r, tr[k].tagp, tr[k].tagm);
  tr[k].tagp = 0;
  tr[k].tagm = 1;
}
void add(int &k, int l, int r, int ql, int qr, int v) {
  if (ql > qr || qr < l || ql > r) return;
  if (!k) k = ++cnt, tr[k].tagm = 1;
  if (ql <= l && qr >= r) {
    change(k, l, r, v, 1);
    return;
  }
  pushdown(k, l, r);
  add(tr[k].l, l, (l + r) / 2, ql, qr, v);
  add(tr[k].r, (l + r) / 2 + 1, r, ql, qr, v);
  pushup(k);
}
void multi(int &k, int l, int r, int ql, int qr, int v) {
  if (ql > qr || qr < l || ql > r) return;
  if (!k) k = ++cnt, tr[k].tagm = 1;
  if (ql <= l && qr >= r) {
    change(k, l, r, 0, v);
    return;
  }
  pushdown(k, l, r);
  multi(tr[k].l, l, (l + r) / 2, ql, qr, v);
  multi(tr[k].r, (l + r) / 2 + 1, r, ql, qr, v);
  pushup(k);
}
int query(int k, int l, int r, int ql, int qr) {
  if (ql > qr || qr < l || ql > r || !k) return 0;
  if (ql <= l && qr >= r) return tr[k].sum;
  pushdown(k, l, r);
  return add(query(tr[k].l, l, (l + r) / 2, ql, qr),
             query(tr[k].r, (l + r) / 2 + 1, r, ql, qr));
}
int main() {
  scanf("%d", &n);
  int maxx = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), maxx = max(maxx, a[i]);
  add(Rt, 1, maxx, 1, a[1], 1);
  for (int i = 2; i <= n; i++) {
    int tmp = tr[Rt].sum;
    multi(Rt, 1, maxx, 1, min(a[i], a[i - 1]), mod - 1);
    multi(Rt, 1, maxx, a[i] + 1, maxx, 0);
    add(Rt, 1, maxx, 1, a[i], tmp);
  }
  printf("%d\n", query(Rt, 1, maxx, 1, a[n]));
}
