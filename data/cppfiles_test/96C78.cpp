#include <bits/stdc++.h>
using namespace std;
long long T, n, l, k;
long long a[100];
long long f[507][507];
long long fastpow(long long b, long long p, long long k) {
  long long cf = b, ans = 1;
  while (p) {
    if (p % 2 == 1) {
      ans = ans * cf % k;
    }
    p /= 2;
    cf = cf * cf % k;
  }
  return ans % k;
}
long long ksm(long long a, long long b = 998244353 - 2) {
  long long res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % 998244353)
    if (b & 1) res = 1ll * res * a % 998244353;
  return res;
}
long long C[507][507];
long long dfs(long long x, long long y) {
  if (f[x][y]) return f[x][y];
  if (x == 1) return f[x][y] = 0;
  if (!x) return f[x][y] = 1;
  if (y < x) return f[x][y] = ksm(y, x);
  long long sum = 0;
  for (long long i = 0; i <= x; i++)
    sum = (sum + dfs(x - i, y - x + 1) * ksm(x - 1, i) % 998244353 * C[x][i] %
                     998244353) %
          998244353;
  return f[x][y] = sum;
}
signed main() {
  cin >> n >> k;
  for (long long i = 0; i <= 500; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 998244353;
  }
  cout << dfs(n, k);
  return 0;
}
