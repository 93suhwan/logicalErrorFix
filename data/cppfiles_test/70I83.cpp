#include <bits/stdc++.h>
using namespace std;
inline void io() { cin.tie(nullptr), cout.tie(nullptr); }
long long n, Q;
long long a[((long long)2e5 + 2)];
long long sum_1[((long long)2e5 + 2)], sum_2[((long long)2e5 + 2)];
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
  for (long long i = 1; i <= n; ++i)
    scanf("%lld", &a[i]),
        sum_1[i] = sum_1[i - 1] + a[i],
        sum_2[i] = sum_2[i - 1] + a[i] * a[i] % ((long long)1e9 + 7),
        sum_1[i] %= ((long long)1e9 + 7), sum_2[i] %= ((long long)1e9 + 7);
  long long L, R, d;
  long long inv2 = fast_pow(2, ((long long)1e9 + 7) - 2),
            inv6 = fast_pow(6, ((long long)1e9 + 7) - 2);
  while (Q--) {
    scanf("%lld%lld%lld", &L, &R, &d);
    if (L > R) swap(L, R);
    long long sum1 = (sum_1[R] - sum_1[L - 1] + ((long long)1e9 + 7)) %
                     ((long long)1e9 + 7),
              c = R - L + 1;
    long long a1 =
        sum1 * fast_pow(c, ((long long)1e9 + 7) - 2) % ((long long)1e9 + 7) +
        d * (1 - c) % ((long long)1e9 + 7) * inv2 % ((long long)1e9 + 7);
    a1 %= ((long long)1e9 + 7);
    long long expc_sum2 =
        c * a1 % ((long long)1e9 + 7) * a1 % ((long long)1e9 + 7) +
        c * (c - 1) % ((long long)1e9 + 7) * d % ((long long)1e9 + 7) * a1 %
            ((long long)1e9 + 7) +
        c * (c - 1) % ((long long)1e9 + 7) * (2 * c - 1) %
            ((long long)1e9 + 7) * d % ((long long)1e9 + 7) * d %
            ((long long)1e9 + 7) * inv6 % ((long long)1e9 + 7);
    expc_sum2 %= ((long long)1e9 + 7);
    if (expc_sum2 ==
        (sum_2[R] - sum_2[L - 1] + ((long long)1e9 + 7)) % ((long long)1e9 + 7))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
