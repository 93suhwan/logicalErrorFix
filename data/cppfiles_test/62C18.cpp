#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 10;
long long n, m, Q, res, cnt;
long long a[N][N], f[N][N];
inline void query(long long x, long long y, long long tag) {
  if (x ^ n) {
    long long cur = min(f[x + 1][y], f[x][y]);
    res += tag * cur;
    if (f[x + 1][y] >= f[x][y])
      res += max(0LL, f[x][y] - 1) * tag;
    else
      res += tag * f[x + 1][y];
  }
  if (y ^ m) {
    long long cur = min(f[x][y + 1], f[x][y]);
    res += tag * cur;
    if (f[x][y + 1] >= f[x][y])
      res += max(0LL, f[x][y] - 1) * tag;
    else
      res += tag * f[x][y + 1];
  }
  return;
}
inline void modify(long long x, long long y) {
  if (a[x][y])
    --cnt;
  else
    ++cnt;
  a[x][y] ^= 1;
  if (a[x][y])
    f[x][y] = f[x + 1][y + 1] + 1;
  else
    f[x][y] = 0;
  return;
}
inline void upd(long long x, long long y, long long tag) {
  long long l = x, r = y;
  while (l && r) query(l, r, tag), --l, --r;
  return;
}
inline void update(long long x, long long y) {
  upd(x, y, -1), upd(x - 1, y, -1);
  upd(x, y - 1, -1);
  modify(x, y);
  long long l = x - 1, r = y - 1;
  while (l && r) {
    if (a[l][r])
      f[l][r] = f[l + 1][r + 1] + 1;
    else
      f[l][r] = 0;
    --l, --r;
  }
  upd(x, y, 1);
  upd(x - 1, y, 1);
  upd(x, y - 1, 1);
  return;
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &Q);
  cnt = n * m;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j) a[i][j] = 1;
  for (long long i = n; i; --i)
    for (long long j = m; j; --j) f[i][j] = f[i + 1][j + 1] + 1;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j) query(i, j, 1);
  while (Q--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    update(x, y);
    printf("%lld\n", res + cnt);
  }
  return 0;
}
