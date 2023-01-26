#include <bits/stdc++.h>
namespace wxy {
const long long N = 4005, inf = 1ll << 31;
long long f[N][N], tot;
long long a[N], size[N];
long long n, m, ls[N], rs[N];
void calc(long long &u, long long l, long long r) {
  if (!u) u = ++tot;
  long long rt = 0;
  size[u] = 1;
  if (l == r) {
    f[u][1] = (m - 1) * a[l];
    return;
  }
  for (long long i = l; i <= r; i++)
    if (a[rt] > a[i]) rt = i;
  if (rt != l)
    calc(ls[u], l, rt - 1);
  else
    f[ls[u]][0] = 0;
  if (rt != r)
    calc(rs[u], rt + 1, r);
  else
    f[rs[u]][0] = 0;
  for (long long i = 0; i <= std::min(size[ls[u]], m); i++)
    for (long long j = 0; j <= std::min(size[rs[u]], m); j++) {
      if (i + j == 0) continue;
      long long val = f[ls[u]][i] + f[rs[u]][j];
      if (i + j <= m)
        f[u][i + j] = std::max(f[u][i + j], val - 2 * i * j * a[rt]);
      else
        break;
      if (i + j + 1 <= m)
        f[u][i + j + 1] =
            std::max(f[u][i + j + 1], val + m * a[rt] - 2 * i * j * a[rt] -
                                          2 * (i + j) * a[rt] - a[rt]);
    }
  size[u] += size[ls[u]] + size[rs[u]];
}
inline long long get(long long l, long long r) {
  long long res = 0;
  for (long long i = l; i <= r; i++) {
    res += m * a[i];
    for (long long j = l; j <= r; j++) {
      long long val = inf;
      for (long long k = std::min(i, j); k <= std::max(i, j); k++)
        val = std::min(val, a[k]);
      std::cout << val << std::endl;
      res -= val;
    }
  }
  return res;
}
inline void main() {
  memset(f, 0xcf, sizeof f);
  std::cin >> n >> m;
  for (long long i = 1; i <= n; i++) std::cin >> a[i];
  a[0] = inf;
  long long rt = 0;
  calc(rt, 1, n);
  std::cout << f[1][m];
}
}  // namespace wxy
signed main() {
  wxy::main();
  return 0;
}
