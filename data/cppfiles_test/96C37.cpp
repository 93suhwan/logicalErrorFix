#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, a[N];
struct node {
  int lp, rp, len;
  long long ans;
};
inline long long b2(int x) { return 1ll * x * (x + 1) / 2 + x + 1; }
inline void mge(const node& x, const node& y, node& z) {
  z.lp = x.lp == x.len ? x.len + y.lp : x.lp;
  z.rp = y.rp == y.len ? y.len + x.rp : y.rp;
  z.ans = x.ans + y.ans - b2(x.rp) - b2(y.lp) + b2(x.rp + y.lp);
  z.len = x.len + y.len;
}
bool flag[N];
namespace SGT {
node t[N << 2];
void build(int rt, int l, int r) {
  t[rt].len = r - l + 1;
  if (l == r) {
    t[rt].lp = t[rt].rp = flag[l] ? 1 : 0;
    t[rt].ans = flag[l] ? 3 : 2;
    return;
  }
  int mid = (l + r) >> 1;
  build((rt << 1), l, mid), build((rt << 1 | 1), mid + 1, r);
  mge(t[(rt << 1)], t[(rt << 1 | 1)], t[rt]);
}
void update(int rt, int l, int r, int p) {
  if (l == r) {
    t[rt].lp ^= 1, t[rt].rp ^= 1;
    t[rt].ans = t[rt].lp ? 3 : 2;
    return;
  }
  int mid = (l + r) >> 1;
  p <= mid ? update((rt << 1), l, mid, p)
           : update((rt << 1 | 1), mid + 1, r, p);
  mge(t[(rt << 1)], t[(rt << 1 | 1)], t[rt]);
}
node query(int rt, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return t[rt];
  int mid = (l + r) >> 1;
  if (qr <= mid) return query((rt << 1), l, mid, ql, qr);
  if (mid < ql) return query((rt << 1 | 1), mid + 1, r, ql, qr);
  node res;
  mge(query((rt << 1), l, mid, ql, qr),
      query((rt << 1 | 1), mid + 1, r, ql, qr), res);
  return res;
}
}  // namespace SGT
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i < n; ++i) flag[i] = (a[i] <= a[i + 1]);
  if (n > 1) SGT::build(1, 1, n - 1);
  while (q--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[x] = y;
      if (x < n && flag[x] != (a[x] <= a[x + 1]))
        flag[x] ^= 1, SGT::update(1, 1, n - 1, x);
      if (x > 1 && flag[x - 1] != (a[x - 1] <= a[x]))
        flag[x - 1] ^= 1, SGT::update(1, 1, n - 1, x - 1);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", l == r ? 1 : SGT::query(1, 1, n - 1, l, r - 1).ans);
    }
  }
  return 0;
}
