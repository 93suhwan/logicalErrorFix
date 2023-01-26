#include <bits/stdc++.h>
using namespace std;
int const mod = 1e9 + 7;
int const N = 200100;
int const M = 1000010;
struct Edges {
  int u, next;
} e[M];
int p[N], idx;
void init(int n) {
  for (int i = 0; i < (n + 1); ++i) p[i] = -1;
  idx = 0;
}
void addedge(int u, int v) { e[idx].u = v, e[idx].next = p[u], p[u] = idx++; }
int deg[N];
bool bud[N], lf[N];
void dfs(int u, int pre = -1) {
  if (lf[u]) return;
  bud[u] = 1;
  int g = 0;
  for (int i = p[u]; ~i; i = e[i].next) {
    int v = e[i].u;
    if (v == pre) continue;
    dfs(v, u);
    if (bud[v]) continue;
    ++g;
    if (!lf[v]) bud[u] = 0;
  }
  if (g == 0) {
    lf[u] = 1;
    bud[u] = 0;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= (n); ++i) deg[i] = 0;
    for (int i = 0; i < (n - 1); ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      addedge(x, y);
      addedge(y, x);
      ++deg[x];
      ++deg[y];
    }
    for (int i = 1; i <= (n); ++i) bud[i] = 0;
    for (int i = 1; i <= (n); ++i) {
      if (i != 1 && deg[i] == 1)
        lf[i] = 1;
      else
        lf[i] = 0;
    }
    dfs(1);
    bud[1] = 0;
    lf[1] = 0;
    int lc = 0, bc = 0;
    int l1 = 0;
    for (int i = p[1]; ~i; i = e[i].next) {
      int v = e[i].u;
      if (lf[v]) {
        l1 = 1;
        break;
      }
    }
    for (int i = 1; i <= (n); ++i) {
      lc += lf[i];
      bc += bud[i];
    }
    int ans = lc - bc;
    if (!l1) ++ans;
    printf("%d\n", ans);
  }
  return 0;
}
