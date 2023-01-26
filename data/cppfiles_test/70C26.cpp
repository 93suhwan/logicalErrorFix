#include <bits/stdc++.h>
using namespace std;
long long n, q, a[200005], op, mmax[200005 * 4], mmin[200005 * 4], tot,
    apow[200005 * 4], bit[200005 * 4];
long long tree[200005 * 4], inf = 9223372036854775807, inv2 = 500000004,
                            inv6 = 166666668;
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
long long ksm(long long a, long long b) {
  long long s = 1;
  while (b) {
    if (b & 1) s = (s * a) % 1000000007;
    b = (b >> 1);
    a = (a * a) % 1000000007;
  }
  return s;
}
long long pwsum(long long x) {
  return x * (x + 1) % 1000000007 * (x * 2 % 1000000007 + 1) % 1000000007 *
         inv6 % 1000000007;
}
long long cal(long long f, long long d, long long len) {
  long long ans = f * f % 1000000007 * len % 1000000007;
  ans = (ans + (d * d) % 1000000007 * pwsum(len - 1) % 1000000007) % 1000000007;
  ans = (ans + len * (len - 1) % 1000000007 * inv2 % 1000000007 * f %
                   1000000007 * d % 1000000007 * 2 % 1000000007) %
        1000000007;
  return ans;
}
int main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  build(1, n, 1);
  while (q--) {
    scanf("%lld%lld%lld", &l, &r, &x);
    long long mmin = query_min(1, n, 1, l, r), mmax = query_max(1, n, 1, l, r);
    long long s = query_sum(1, n, 1, l, r),
              now1 = ((r - l + 1) * mmin % 1000000007 +
                      (r - l + 1) * (r - l) % 1000000007 * x % 1000000007 *
                          inv2 % 1000000007) %
                     1000000007,
              now2 = ((r - l + 1) * mmax % 1000000007 +
                      (r - l + 1) * (r - l) % 1000000007 * inv2 % 1000000007 *
                          x % 1000000007) %
                     1000000007;
    long long f = (s -
                   (r - l) * (r - l + 1) % 1000000007 * inv2 % 1000000007 * x %
                       1000000007 +
                   1000000007 * 2) %
                  1000000007;
    f = f * ksm(r - l + 1, 1000000007 - 2) % 1000000007;
    long long sp = query_pow(1, n, 1, l, r);
    long long nowp = cal(f, x, r - l + 1);
    if (nowp == sp)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
