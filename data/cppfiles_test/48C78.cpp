#include <bits/stdc++.h>
using namespace std;
int n, q, a[100005], b[100005];
long long c[100005], t1[100005 * 4], t2[100005 * 4];
void build(int rt, int l, int r) {
  if (l == r) {
    t1[rt] = t2[rt] = c[l];
    return;
  }
  build((rt << 1), l, ((l + r) >> 1));
  build((rt << 1 | 1), ((l + r) >> 1) + 1, r);
  t1[rt] = min(t1[(rt << 1)], t1[(rt << 1 | 1)]);
  t2[rt] = max(t2[(rt << 1)], t2[(rt << 1 | 1)]);
}
pair<long long, long long> query(int rt, int l, int r, int x, int y) {
  if (l >= x && r <= y) return make_pair(t1[rt], t2[rt]);
  if (y <= ((l + r) >> 1)) return query((rt << 1), l, ((l + r) >> 1), x, y);
  if (x >= ((l + r) >> 1) + 1)
    return query((rt << 1 | 1), ((l + r) >> 1) + 1, r, x, y);
  pair<long long, long long> tmp1 = query((rt << 1), l, ((l + r) >> 1), x, y),
                             tmp2 = query((rt << 1 | 1), ((l + r) >> 1) + 1, r,
                                          x, y);
  return make_pair(min(tmp1.first, tmp2.first), max(tmp1.second, tmp2.second));
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= n; ++i) {
    c[i] = c[i - 1] + b[i] - a[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    pair<long long, long long> tmp = query(1, 1, n, l, r);
    if (tmp.first < c[l - 1] || c[r] - c[l - 1] != 0)
      printf("-1\n");
    else
      printf("%lld\n", tmp.second - c[l - 1]);
  }
  return 0;
}
