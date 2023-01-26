#include <bits/stdc++.h>
using namespace std;
int n, k, ls[200005], rs[200005];
int cnt, rk[200005];
int f[200005][18];
int vis[200005];
char a[200005];
void dfs(int u) {
  if (u == 0) return;
  for (int i = 1; i < 18; i++) {
    f[u][i] = f[f[u][i - 1]][i - 1];
  }
  dfs(ls[u]);
  rk[++cnt] = u;
  dfs(rs[u]);
}
bool get(int u) {
  int t = k;
  for (int i = 0; t; i++) {
    if (t & 1) u = f[u][i];
    t >>= 1;
  }
  return (u == 0 || vis[u] == 1);
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
  if (vis[u] == 1) {
    printf("%c", a[u]);
  }
  print(rs[u]);
}
int main() {
  scanf("%d%d\n%s", &n, &k, a + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &ls[i], &rs[i]);
    f[ls[i]][0] = f[rs[i]][0] = i;
  }
  f[0][0] = 0;
  dfs(1);
  int nxt = 1;
  for (int i = 1; i < n; i++) {
    int x = rk[i];
    while (nxt < n && a[x] == a[rk[nxt]]) nxt++;
    if (a[rk[i]] < a[rk[nxt]]) {
      if (get(x)) {
        while (vis[x] == 0) {
          if (x == 0) break;
          vis[x] = 1;
          x = f[x][0];
          k--;
        }
      }
    } else
      to(x);
  }
  print(1);
  return 0;
}
