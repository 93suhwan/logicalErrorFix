#include <bits/stdc++.h>
using namespace std;
int flag;
int U[200005];
int V[200005];
int W[200005];
struct edge {
  int v, w;
};
int org[200005];
int col[200005];
vector<edge> G[200005];
void dfs(int u, int co) {
  for (edge& e : G[u]) {
    int val;
    if (e.w == 1) {
      val = 3 - co;
    } else {
      val = co;
    }
    if (col[e.v]) {
      if (val != col[e.v]) {
        flag = 0;
      }
    } else {
      col[e.v] = val;
      dfs(e.v, val);
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    flag = 1;
    for (int i = 1; i <= n; ++i) {
      G[i].clear();
      col[i] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      org[i] = w;
      if (w >= 0) {
        w = __builtin_parity(w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
      }
      U[i] = u;
      V[i] = v;
      W[i] = w;
    }
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      G[u].push_back({v, w});
      G[v].push_back({u, w});
    }
    for (int i = 1; i <= n; ++i)
      if (!col[i]) {
        col[i] = 1;
        dfs(i, 1);
      }
    for (int i = 0; i < n - 1; ++i) {
      if (W[i] == -1) {
        W[i] = (col[U[i]] - 1) ^ (col[V[i]] - 1);
        org[i] = W[i];
      } else {
        if (W[i] != ((col[U[i]] - 1) ^ (col[V[i]] - 1))) {
          flag = 0;
        }
      }
    }
    if (!flag) {
      puts("NO");
    } else {
      puts("YES");
      for (int i = 0; i < n - 1; ++i) {
        printf("%d %d %d\n", U[i], V[i], org[i]);
      }
    }
  }
  return 0;
}
