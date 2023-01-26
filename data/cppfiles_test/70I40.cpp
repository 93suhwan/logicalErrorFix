#include <bits/stdc++.h>
using namespace std;
long long n, q, c[200000 + 1], Sum[200000 + 1][5], s, C[5][5], S[200000 + 1][5],
    inv[200000 + 1], L[200000 + 1];
bool op;
long long F(long long k, long long l, long long r) {
  return Sum[r][k] - Sum[l - 1][k];
}
long long G(long long k, long long x, long long d) {
  long long res = 0;
  L[0] = 1;
  for (long long i = 1; i <= k; ++i) L[i] = L[i - 1] * s % 1000000007;
  for (long long i = 0, mul = 1; i <= k; ++i, mul = mul * d % 1000000007)
    res = (res + C[k][i] * mul % 1000000007 * S[x][i] % 1000000007 * L[k - i] %
                     1000000007) %
          1000000007;
  return res;
}
signed main() {
  long long l, r, d;
  cin >> n >> q, inv[1] = 1;
  for (long long i = 2; i <= n; ++i)
    inv[i] =
        (1000000007 - (1000000007 / i) * inv[1000000007 % i] % 1000000007) %
        1000000007;
  for (long long i = 0; i <= 4; ++i) C[i][0] = 1;
  for (long long i = 0; i <= n; ++i)
    for (long long j = 0, mul = 1; j <= 4; ++j, mul = mul * i % 1000000007) {
      if (!i)
        S[i][j] = mul;
      else
        S[i][j] = (S[i - 1][j] + mul) % 1000000007;
    }
  for (long long i = 1; i <= 4; ++i)
    for (long long j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
  for (long long i = 1; i <= n; ++i) {
    cin >> c[i];
    for (long long j = 0, res = 1; j <= 4; ++j, res = res * c[i] % 1000000007)
      Sum[i][j] = (Sum[i - 1][j] + res) % 1000000007;
  }
  for (long long i = 1; i <= q; ++i) {
    cin >> l >> r >> d,
        s = ((F(1, l, r) - d * S[r - l][1] % 1000000007) * inv[r - l + 1] %
                 1000000007 +
             1000000007) %
            1000000007,
        op = 1;
    for (long long j = 2; j <= 4; ++j) op &= (G(j, r - l, d) == F(j, l, r));
    if (op)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
