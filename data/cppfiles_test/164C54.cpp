#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r, lst;
  char c;
} a[200005];
int n, k, lst, h[200005];
bool vis[200005];
char s[200005];
inline void dfs(int x, int fa) {
  if (!x) return;
  h[x] = h[fa] + 1;
  dfs(a[x].l, x);
  a[lst].lst = x;
  lst = x;
  dfs(a[x].r, x);
}
inline int work(int x) {
  if (!a[x].lst || a[a[x].lst].c != a[x].c) return a[x].lst;
  return a[x].lst = work(a[x].lst);
}
inline void dfs2(int x, int now) {
  if (!x) return;
  dfs2(a[x].l, now);
  if (vis[a[x].l]) {
    vis[x] = 1;
  } else {
    if (a[x].c < a[a[x].lst].c && h[x] - now <= k) {
      k -= h[x] - now;
      vis[x] = 1;
    }
  }
  if (vis[x]) dfs2(a[x].r, h[x]);
}
inline void dfs3(int x) {
  if (!x) return;
  dfs3(a[x].l);
  putchar(a[x].c);
  if (vis[x]) putchar(a[x].c);
  dfs3(a[x].r);
  return;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    a[i].c = s[i];
    scanf("%d%d", &a[i].l, &a[i].r);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    work(i);
  }
  dfs2(1, 0);
  dfs3(1);
  puts("");
  return 0;
}
