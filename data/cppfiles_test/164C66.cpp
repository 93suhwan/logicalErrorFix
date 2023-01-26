#include <bits/stdc++.h>
using namespace std;
int n, k, ls[200005], rs[200005];
char a[200005];
int cnt, rk[200005];
bool vis[200005];
void get(int u) {
  if (u == 0) return;
  get(ls[u]);
  rk[++cnt] = u;
  get(rs[u]);
}
bool xz[200005];
bool dfs(int u, int d) {
  if (u == 0) return false;
  if (dfs(ls[u], d + 1)) {
    xz[u] = true;
    dfs(rs[u], 1);
  } else {
    if (vis[u] && d <= k) {
      k = k - d;
      xz[u] = true;
      dfs(rs[u], 1);
    } else {
      return false;
    }
  }
  return true;
}
void print(int u) {
  if (u == 0) return;
  print(ls[u]);
  printf("%c", a[u]);
  if (xz[u] == true) {
    printf("%c", a[u]);
  }
  print(rs[u]);
}
int main() {
  scanf("%d%d\n%s", &n, &k, a + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &ls[i], &rs[i]);
  }
  get(1);
  int nxt = 1;
  for (int i = 1; i <= n; i++) {
    while (nxt < n && a[rk[i]] == a[rk[nxt]]) nxt++;
    if (a[rk[i]] < a[rk[nxt]]) vis[rk[i]] = true;
  }
  dfs(1, 1);
  print(1);
  return 0;
}
