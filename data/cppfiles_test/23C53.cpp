#include <bits/stdc++.h>
using namespace std;
const long long N = 4e3 + 5;
long long n, m, a[N], f[N][N];
long long solve(long long l, long long r) {
  if (l > r) return 0;
  long long p = 0;
  for (long long i = l; i <= r; i++)
    if (a[i] < a[p]) p = i;
  long long ls = solve(l, p - 1), rs = solve(p + 1, r);
  memset(f[p], -0x3f, sizeof(f[p]));
  for (long long i = 0; i <= p - l; i++)
    for (long long j = 0; j <= r - p; j++) {
      f[p][i + j] = max(f[p][i + j], f[ls][i] + f[rs][j] - 2 * i * j * a[p]);
      f[p][i + j + 1] =
          max(f[p][i + j + 1], f[ls][i] + f[rs][j] - 2 * i * j * a[p] -
                                   2 * (i + j) * a[p] + (m - 1) * a[p]);
    }
  return p;
}
signed main() {
  cin >> n >> m;
  a[0] = 1e18;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long p = solve(1, n);
  cout << f[p][m] << endl;
}
