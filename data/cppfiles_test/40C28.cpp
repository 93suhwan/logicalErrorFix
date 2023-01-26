#include <bits/stdc++.h>
using namespace std;
int d[400000];
int n, m, q;
int fa[400000];
int head[400000], net[1000000], v[1000000];
int tot;
int numofodd;
int x[400000], y[400000];
int dep[400000];
int L[400000], R[400000];
int pre[400000];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void add(int x, int y) { v[++tot] = y, net[tot] = head[x], head[x] = tot; }
void init() {
  numofodd = 0;
  pre[1] = 0;
  for (int i = 1; i <= n; i++) fa[i] = i;
}
void bfs(int x, int deep) {
  dep[x] = deep;
  deque<int> q;
  q.push_back(x);
  while (q.size()) {
    x = q.front();
    q.pop_front();
    for (int i = head[x]; i; i = net[i]) {
      int y = v[i];
      if (dep[y]) continue;
      q.push_back(y);
      pre[y] = x;
      dep[y] = dep[x] + 1;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int tx = find(x);
    int ty = find(y);
    if (tx != ty) {
      add(x, y);
      add(y, x);
      fa[tx] = ty;
    }
  }
  bfs(1, 1);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x[i], &y[i]);
    d[x[i]]++;
    d[y[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] & 1) numofodd++;
  }
  if (!numofodd) {
    printf("YES\n");
    for (int i = 1; i <= q; i++) {
      int a = x[i], b = y[i];
      int l = 0, r = 0;
      while (dep[a] > dep[b]) {
        L[++l] = a;
        a = pre[a];
      }
      while (dep[b] > dep[a]) {
        R[++r] = b;
        b = pre[b];
      }
      while (a != b) {
        L[++l] = a;
        R[++r] = b;
        a = pre[a];
        b = pre[b];
      }
      L[++l] = a;
      printf("%d\n", l + r);
      for (int i = 1; i <= l; i++) printf("%d ", L[i]);
      for (int i = r; i >= 1; i--) printf("%d ", R[i]);
      printf("\n");
    }
  } else {
    printf("NO\n");
    printf("%d\n", numofodd / 2);
  }
  return 0;
}
