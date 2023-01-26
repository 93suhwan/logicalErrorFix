#include <bits/stdc++.h>
using namespace std;
long long n, Q, inv2, k1, k2;
long long cur1, cur2, tar1, tar2;
long long a1[((long long)2e5 + 2)], c1[22][22], s1[22][((long long)2e5 + 2)],
    sum[((long long)2e5 + 2)], mul[2][((long long)2e5 + 2)],
    b1[2][((long long)2e5 + 2)][22];
inline void io() { cin.tie(nullptr), cout.tie(nullptr); }
inline long long fast_pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % ((long long)1e9 + 7);
    a = a * a % ((long long)1e9 + 7), b >>= 1;
  }
  return ret;
}
signed main() {
  io(), srand(time(0));
  cin >> n >> Q;
  k1 = rand() % 20 + 1, k2 = rand() % 20 + 1;
  inv2 = fast_pow(2, ((long long)1e9 + 7) - 2);
  mul[0][0] = mul[1][0] = sum[0] = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> a1[i];
    sum[i] = (sum[i - 1] + a1[i]) % ((long long)1e9 + 7);
    mul[0][i] = (mul[0][i - 1] + fast_pow(a1[i], k1)) % ((long long)1e9 + 7);
    mul[1][i] = (mul[1][i - 1] + fast_pow(a1[i], k2)) % ((long long)1e9 + 7);
  }
  c1[0][0] = 1, s1[0][1] = 1;
  for (long long i = 2; i <= n; ++i) s1[0][i] = s1[0][i - 1] + 1;
  for (long long i = 1; i <= k2; ++i) {
    c1[i][0] = 1;
    for (long long j = 1; j <= i; ++j)
      c1[i][j] = (c1[i - 1][j - 1] + c1[i - 1][j]) % ((long long)1e9 + 7);
    s1[i][1] = 0;
    for (long long j = 2; j <= n; ++j)
      s1[i][j] = (s1[i][j - 1] + fast_pow(j - 1, i)) % ((long long)1e9 + 7);
  }
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 0; j <= k1; ++j)
      b1[0][i][j] = 1ll * s1[j][i] * c1[k1][j] % ((long long)1e9 + 7);
    for (long long j = 0; j <= k2; ++j)
      b1[1][i][j] = 1ll * s1[j][i] * c1[k2][j] % ((long long)1e9 + 7);
  }
  for (long long i = 1, l, r, d, len, a0, x; i <= Q; ++i) {
    cin >> l >> r >> d;
    if (l == r) {
      printf("Yes\n");
      continue;
    }
    if (l > r) {
      printf("No\n");
      continue;
    }
    cur1 = (mul[0][r] - mul[0][l - 1] + ((long long)1e9 + 7)) %
           ((long long)1e9 + 7);
    cur2 = (mul[1][r] - mul[1][l - 1] + ((long long)1e9 + 7)) %
           ((long long)1e9 + 7);
    len = r - l + 1;
    a0 = (1ll * sum[r] - 1ll * sum[l - 1] -
          1ll * len * (len - 1) % ((long long)1e9 + 7) * inv2 %
              ((long long)1e9 + 7) * d % ((long long)1e9 + 7) +
          2ll * ((long long)1e9 + 7)) %
         ((long long)1e9 + 7) * fast_pow(len, ((long long)1e9 + 7) - 2) %
         ((long long)1e9 + 7);
    if (a0) {
      x = 1ll * d * fast_pow(a0, ((long long)1e9 + 7) - 2) %
          ((long long)1e9 + 7);
      tar1 = tar2 = 0;
      for (long long j = 0; j <= k1; ++j)
        tar1 = (tar1 +
                1ll * fast_pow(x, j) * b1[0][len][j] % ((long long)1e9 + 7)) %
               ((long long)1e9 + 7);
      for (long long j = 0; j <= k2; ++j)
        tar2 = (tar2 +
                1ll * fast_pow(x, j) * b1[1][len][j] % ((long long)1e9 + 7)) %
               ((long long)1e9 + 7);
      tar1 = 1ll * tar1 * fast_pow(a0, k1) % ((long long)1e9 + 7);
      tar2 = 1ll * tar2 * fast_pow(a0, k2) % ((long long)1e9 + 7);
    } else {
      tar1 = 1ll * fast_pow(d, k1) * s1[k1][len] % ((long long)1e9 + 7);
      tar2 = 1ll * fast_pow(d, k2) * s1[k2][len] % ((long long)1e9 + 7);
    }
    if (cur1 == tar1 && cur2 == tar2)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
