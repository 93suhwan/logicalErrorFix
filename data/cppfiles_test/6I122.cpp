#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;
set<int> e[MAXN];
int al[MAXN], deg[MAXN];
queue<int> q;
int n, m, Q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u < v) swap(u, v);
    e[v].insert(u);
    deg[u]++;
  }
  for (int i = 1; i <= n; i++) {
    al[i] = 1;
    if (deg[i] == 0) q.push(i);
  }
  int ans = n;
  scanf("%d", &Q);
  while (Q--) {
    int op, u, v;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &u, &v);
      if (u < v) swap(u, v);
      e[v].insert(u);
      deg[u]++;
      if (deg[v] == 0 && e[v].size() && al[v]) q.push(v);
    } else if (op == 2) {
      scanf("%d%d", &u, &v);
      if (u < v) swap(u, v);
      if (al[v] == 1) {
        e[v].erase(u);
        deg[u]--;
        if (deg[u] == 0 && e[u].size() && al[u]) q.push(u);
      }
    } else {
      while (q.size()) {
        int now = q.front();
        q.pop();
        if (deg[now] == 0 && e[now].size() != 0) {
          al[now] = 0;
          ans--;
          for (auto k : e[now]) {
            deg[k]--;
            if (deg[k] == 0 && al[k]) q.push(k);
          }
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
