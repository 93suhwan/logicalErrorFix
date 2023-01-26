#include <bits/stdc++.h>
using namespace std;
int n, k, ls[200005], rs[200005];
int cnt, rk[200005];
int vis[200005];
char a[200005];
int fa[200005];
void dfs(int u) {
  if (u == 0) return;
  dfs(ls[u]);
  rk[++cnt] = u;
  dfs(rs[u]);
}
int get(int u) {
  if (u == 0) return 0;
  if (vis[u]) return 0;
  return get(fa[u]) + 1;
}
void to(int u) {
  if (u == 0) return;
  if (vis[u] == 0) {
    vis[u] = -1;
    to(ls[u]);
    to(rs[u]);
  }
}
void print(int u) {
  if (u == 0) return;
  print(ls[u]);
  printf("%c", a[u]);
  if (vis[u] == 1) printf("%c", a[u]);
  print(rs[u]);
}
int main() {
  scanf("%d%d\n%s", &n, &k, a + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &ls[i], &rs[i]);
    fa[ls[i]] = fa[rs[i]] = i;
  }
  dfs(1);
  print(1);
  return 0;
}
