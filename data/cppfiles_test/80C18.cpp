#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
namespace SGT {
int tag[N << 2], mn[N << 2];
inline void up(int rt) { mn[rt] = min(mn[(rt << 1)], mn[(rt << 1 | 1)]); }
inline void cov(int rt, int v) { mn[rt] += v, tag[rt] += v; }
inline void dn(int rt) {
  if (!tag[rt]) return;
  cov((rt << 1), tag[rt]), cov((rt << 1 | 1), tag[rt]);
  tag[rt] = 0;
}
void build(int rt, int l, int r) {
  tag[rt] = 0;
  if (l == r) return mn[rt] = l, void();
  int mid = (l + r) >> 1;
  build((rt << 1), l, mid), build((rt << 1 | 1), mid + 1, r);
  up(rt);
}
void update(int rt, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) return cov(rt, v);
  dn(rt);
  int mid = (l + r) >> 1;
  if (ql <= mid) update((rt << 1), l, mid, ql, qr, v);
  if (mid < qr) update((rt << 1 | 1), mid + 1, r, ql, qr, v);
  up(rt);
}
}  // namespace SGT
pair<int, int> a[N];
int n, m, b[N], tmp[N];
namespace Fenwick {
int c[N];
inline void clear() { fill(c + 1, c + n + 1, 0); }
inline void upd(int x) {
  for (; x; x -= (x & (-x))) ++c[x];
}
inline int ask(int x) {
  int res = 0;
  for (; x <= n; x += (x & (-x))) res += c[x];
  return res;
}
}  // namespace Fenwick
using namespace Fenwick;
int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) {
    scanf("%d%d", &n, &m);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
      scanf("%d", tmp + i), a[i] = make_pair(tmp[i], i);
    sort(tmp + 1, tmp + n + 1);
    int tot = unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for (int i = 1; i <= n; ++i) {
      int now = lower_bound(tmp + 1, tmp + tot + 1, a[i].first) - tmp;
      ans += ask(now + 1);
      upd(now);
    }
    clear();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; ++i) scanf("%d", b + i);
    sort(b + 1, b + m + 1);
    SGT::build(1, 0, n);
    int p1 = 1, p2 = 1;
    for (int i = 1; i <= m; ++i) {
      while (p1 <= n && a[p1].first < b[i])
        SGT::update(1, 0, n, 0, a[p1++].second - 1, 1);
      while (p2 <= n && a[p2].first <= b[i])
        SGT::update(1, 0, n, a[p2++].second, n, -1);
      ans += SGT::mn[1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
