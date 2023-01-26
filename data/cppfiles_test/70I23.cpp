#include <bits/stdc++.h>
using namespace std;
long long n, q, a[200005], op, mmax[200005 * 4], mmin[200005 * 4], tot,
    apow[200005 * 4], bit[200005 * 4];
long long tree[200005 * 4], inf = 9223372036854775807, inv2 = 500000004;
void build(long long l, long long r, long long node) {
  if (l == r) {
    tree[node] = a[l];
    mmin[node] = a[l];
    mmax[node] = a[l];
    apow[node] = (a[l] * a[l]) % 1000000007;
    return;
  }
  long long mid = (l + r) >> 1;
  build(l, mid, node << 1);
  build(mid + 1, r, node << 1 | 1);
  apow[node] = (apow[node << 1] + apow[node << 1 | 1]) % 1000000007;
  tree[node] = (tree[node << 1] + tree[node << 1 | 1]) % 1000000007;
  mmax[node] = max(mmax[node << 1], mmax[node << 1 | 1]);
  mmin[node] = min(mmin[node << 1], mmin[node << 1 | 1]);
}
long long query_pow(long long l, long long r, long long node, long long x,
                    long long y) {
  if (r < x || l > y) return 0;
  if (x <= l && r <= y) return apow[node];
  long long mid = (l + r) >> 1;
  return (query_pow(l, mid, node << 1, x, y) +
          query_pow(mid + 1, r, node << 1 | 1, x, y)) %
         1000000007;
}
long long query_sum(long long l, long long r, long long node, long long x,
                    long long y) {
  if (r < x || l > y) return 0;
  if (x <= l && r <= y) return tree[node];
  long long mid = (l + r) >> 1;
  return (query_sum(l, mid, node << 1, x, y) +
          query_sum(mid + 1, r, node << 1 | 1, x, y)) %
         1000000007;
}
long long query_max(long long l, long long r, long long node, long long x,
                    long long y) {
  if (r < x || l > y) return 0;
  if (x <= l && r <= y) return mmax[node];
  long long mid = (l + r) >> 1;
  return max(query_max(l, mid, node << 1, x, y),
             query_max(mid + 1, r, node << 1 | 1, x, y));
}
long long query_min(long long l, long long r, long long node, long long x,
                    long long y) {
  if (r < x || l > y) return inf;
  if (x <= l && r <= y) return mmin[node];
  long long mid = (l + r) >> 1;
  return min(query_min(l, mid, node << 1, x, y),
             query_min(mid + 1, r, node << 1 | 1, x, y));
}
long long l, r, x;
int main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  build(1, n, 1);
  while (q--) {
    scanf("%lld%lld%lld", &l, &r, &x);
    long long mmin = query_min(1, n, 1, l, r), mmax = query_max(1, n, 1, l, r);
    if ((mmax != ((mmin + (r - l) * x % 1000000007) % 1000000007)) &&
        (mmin != ((mmax + (r - l) * x % 1000000007) % 1000000007)))
      printf("No\n");
    else {
      long long s = query_sum(1, n, 1, l, r),
                now1 = ((r - l + 1) * mmin % 1000000007 +
                        (r - l + 1) * (r - l) % 1000000007 * inv2 % 1000000007 *
                            x % 1000000007) %
                       1000000007,
                now2 = ((r - l + 1) * mmax % 1000000007 +
                        (r - l + 1) * (r - l) % 1000000007 * inv2 % 1000000007 *
                            x % 1000000007) %
                       1000000007;
      if (s != mmin && s != mmax)
        printf("No\n");
      else {
        printf("Yes\n");
      }
    }
  }
  return 0;
}
