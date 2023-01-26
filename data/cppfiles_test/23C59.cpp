#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T read() {
  T r = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) r = (r << 3) + (r << 1) + (c ^ 48), c = getchar();
  return f ? -r : r;
}
const long long N = 4005, INF = 1e9;
long long n, m, a[N];
long long sz[N], f[N][N];
long long stk[N], top, ch[N][2];
void dfs(long long u) {
  sz[u] = 1;
  for (long long k = 0; k < 2; ++k) {
    long long v = ch[u][k], val = a[v] - a[u];
    if (!v) continue;
    dfs(v);
    for (long long i = min(m, sz[u]); ~i; --i)
      for (long long j = sz[v]; ~j; --j)
        f[u][i + j] = max(f[u][i + j], f[u][i] + f[v][j] + val * j * (m - j));
    sz[u] += sz[v];
  }
}
signed main() {
  n = read<long long>(), m = read<long long>();
  for (long long i = 1; i <= n; ++i) {
    a[i] = read<long long>();
    long long k = top;
    while (k && a[stk[k]] > a[i]) --k;
    if (k) ch[stk[k]][1] = i;
    if (k < top) ch[i][0] = stk[k + 1];
    stk[++k] = i, top = k;
  }
  dfs(stk[1]);
  printf("%lld", f[stk[1]][m]);
  return 0;
}
