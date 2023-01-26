#include <bits/stdc++.h>
using std::vector;
const int N = 200005;
int T, n, is[N], tot, mx;
vector<int> e[N];
void dfs(int u, int fa) {
  is[u] = 0;
  for (int v : e[u])
    if (v != fa) {
      dfs(v, u);
      is[u] |= is[v] ^ 1;
    }
  tot -= 2 * is[u];
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) e[i].clear();
    for (int i = 1, x, y; i < n; ++i)
      scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
    tot = n;
    dfs(1, 0);
    printf("%d\n", tot + 1 - (!is[1]));
  }
  return 0;
}
