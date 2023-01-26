#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000005;
int n;
int d[MAXN];
int getf(int x) {
  if (x == 0) return 0;
  for (int i = 0; i <= 30; i++)
    if ((1 << i) >= x) return (1 << i) - x;
}
struct edge {
  int v;
  edge *next;
} pool[MAXN], *h[MAXN];
int cnt = 0;
void ae(int u, int v) {
  edge *p = &pool[++cnt];
  p->v = v;
  p->next = h[u];
  h[u] = p;
}
map<int, int> mp;
int tot = 0;
int rev[MAXN];
int id(int x) {
  if (mp.find(x) != mp.end())
    return mp[x];
  else {
    mp[x] = ++tot;
    return tot;
  }
}
int dep[MAXN];
int M = 0;
void dfs(int u, int fa) {
  if (dep[u] > dep[M]) M = u;
  for (edge *p = h[u]; p; p = p->next) {
    int v = p->v;
    if (v == fa) continue;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
    int p = d[i], fa = getf(p);
    rev[id(p)] = i;
    while (p != fa) {
      int pid = id(p);
      if (pid != tot) break;
      int faid = id(fa);
      ae(pid, faid);
      ae(faid, pid);
      p = fa;
      fa = getf(fa);
    }
  }
  int root = id(0);
  dep[root] = 0;
  dfs(root, 0);
  root = M;
  M = 0;
  dep[root] = 0;
  dfs(root, 0);
  printf("%d %d %d\n", rev[root], rev[M], dep[M]);
  return 0;
}
