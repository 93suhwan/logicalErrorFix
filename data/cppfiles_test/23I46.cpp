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
const int N = 4005, INF = 1e9;
int n, m, a[N];
int sz[N], f[N][N];
int stk[N], top, ch[N][2];
void dfs(int u) {
  sz[u] = 1;
  for (int k = 0; k < 2; ++k) {
    int v = ch[u][k], val = a[v] - a[u];
    if (!v) continue;
    dfs(v);
    for (int i = min(m, sz[u]); ~i; --i)
      for (int j = sz[v]; ~j; --j)
        f[u][i + j] = max(f[u][i + j], f[u][i] + f[v][j] + val * j * (m - j));
    sz[u] += sz[v];
  }
}
int main() {
  n = read<int>(), m = read<int>();
  for (int i = 1; i <= n; ++i) {
    a[i] = read<int>();
    int k = top;
    while (k && a[stk[k]] > a[i]) --k;
    if (k) ch[stk[k]][1] = i;
    if (k < top) ch[i][0] = stk[k + 1];
    stk[++k] = i, top = k;
  }
  dfs(stk[1]);
  printf("%d", f[stk[1]][m]);
  return 0;
}
