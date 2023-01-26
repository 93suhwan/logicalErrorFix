#include <bits/stdc++.h>
using namespace std;
inline void io() { cin.tie(nullptr), cout.tie(nullptr); }
long long n, Q;
long long a[((long long)2e5 + 2)];
long long tree1[((long long)2e5 + 2) << 2], tree2[((long long)2e5 + 2) << 2];
inline void pushup1(long long rt) {
  tree1[rt] = tree1[rt << 1] + tree1[rt << 1 | 1];
}
inline void pushup2(long long rt) {
  tree2[rt] = tree2[rt << 1] + tree2[rt << 1 | 1];
}
inline void build1(long long rt, long long l, long long r) {
  if (l == r) {
    tree1[rt] = a[l] % ((long long)1e9 + 7);
    return;
  }
  long long mid = (l + r) >> 1;
  build1(rt << 1, l, mid), build1(rt << 1 | 1, mid + 1, r);
  pushup1(rt);
}
inline void build2(long long rt, long long l, long long r) {
  if (l == r) {
    tree2[rt] = a[l] * a[l] % ((long long)1e9 + 7);
    return;
  }
  long long mid = (l + r) >> 1;
  build2(rt << 1, l, mid), build2(rt << 1 | 1, mid + 1, r);
  pushup2(rt);
}
inline long long query1(long long rt, long long l, long long r, long long L,
                        long long R) {
  if (L <= l && r <= R) return tree1[rt];
  long long mid = (l + r) >> 1;
  long long ret = 0;
  if (L <= mid)
    ret += query1(rt << 1, l, mid, L, R), ret %= ((long long)1e9 + 7);
  if (R > mid)
    ret += query1(rt << 1 | 1, mid + 1, r, L, R), ret %= ((long long)1e9 + 7);
  return ret % ((long long)1e9 + 7);
}
inline long long query2(long long rt, long long l, long long r, long long L,
                        long long R) {
  if (L <= l && r <= R) return tree2[rt];
  long long mid = (l + r) >> 1;
  long long ret = 0;
  if (L <= mid)
    ret += query2(rt << 1, l, mid, L, R), ret %= ((long long)1e9 + 7);
  if (R > mid)
    ret += query2(rt << 1 | 1, mid + 1, r, L, R), ret %= ((long long)1e9 + 7);
  return ret % ((long long)1e9 + 7);
}
inline long long fast_pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % ((long long)1e9 + 7);
    b >>= 1, a = a * a % ((long long)1e9 + 7);
  }
  return ret % ((long long)1e9 + 7);
}
signed main() {
  io();
  cin >> n >> Q;
  for (long long i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  build1(1, 1, n), build2(1, 1, n);
  long long L, R, d;
  long long inv2 = fast_pow(2, ((long long)1e9 + 7) - 2),
            inv6 = fast_pow(6, ((long long)1e9 + 7) - 2);
  while (Q--) {
    scanf("%lld%lld%lld", &L, &R, &d);
    long long sum1 = query1(1, 1, n, L, R), c = R - L + 1;
    long long a1 =
        sum1 * fast_pow(c, ((long long)1e9 + 7) - 2) % ((long long)1e9 + 7) +
        d * (1 - c) % ((long long)1e9 + 7) * inv2 % ((long long)1e9 + 7);
    sum1 %= ((long long)1e9 + 7);
    long long expc_sum2 =
        c * a1 % ((long long)1e9 + 7) * a1 % ((long long)1e9 + 7) +
        c * (c - 1) % ((long long)1e9 + 7) * d % ((long long)1e9 + 7) * a1 %
            ((long long)1e9 + 7) +
        c * (c - 1) % ((long long)1e9 + 7) * (2 * c - 1) %
            ((long long)1e9 + 7) * d % ((long long)1e9 + 7) * d %
            ((long long)1e9 + 7) * inv6 % ((long long)1e9 + 7);
    expc_sum2 %= ((long long)1e9 + 7);
    if (expc_sum2 == query2(1, 1, n, L, R))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
