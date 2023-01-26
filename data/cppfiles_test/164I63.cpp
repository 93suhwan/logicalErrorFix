#include <bits/stdc++.h>
using namespace std;
int n, k, ls[200005], rs[200005];
int d[200005], fa[200005];
int cnt, rk[200005];
int vis[200005];
char a[200005];
void dfs(int u, int fa) {
  if (u == 0) return;
  d[u] = d[fa] + 1;
  dfs(ls[u], u);
  rk[++cnt] = u;
  dfs(rs[u], u);
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
  dfs(1, 0);
  int nxt = 1;
  a[cnt + 1] = 'a' - 1;
  for (int i = 1; i < cnt; i++) {
    int x = rk[i];
    while (a[x] == a[rk[nxt]]) nxt++;
    if (a[rk[i]] < a[rk[nxt]] && d[x] <= k) {
      k -= d[x];
      while (vis[x] == 0) {
        if (x == 0) break;
        vis[x] = 1;
        x = fa[x];
      }
    } else
      to(x);
  }
  print(1);
  return 0;
}
