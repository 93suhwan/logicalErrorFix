#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, q, qu[300005], qv[300005], par[300005], dep[300005], C[300005];
vector<int> G[300005];
bool vis[300005];
void dfs(int v) {
  vis[v] = true;
  for (int i = 0; i < (int)(G[v].size()); i++) {
    int u = G[v][i];
    if (!vis[u]) {
      par[u] = v;
      dep[u] = dep[v] + 1;
      dfs(u);
    }
  }
}
vector<int> A0, A1;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)(m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[v].push_back(u);
    G[u].push_back(v);
  }
  dfs(1);
  scanf("%d", &q);
  for (int i = 0; i < (int)(q); i++) {
    scanf("%d%d", &qu[i], &qv[i]);
    C[qu[i]] ^= 1;
    C[qv[i]] ^= 1;
  }
  int tot = 0;
  for (int i = 1; i <= (int)(n); i++) tot += C[i];
  if (tot != 0) {
    printf("NO\n%d\n", tot / 2);
    return 0;
  }
  printf("YES\n");
  for (int i = 0; i < (int)(q); i++) {
    int x = qu[i], y = qv[i];
    A0.clear();
    A1.clear();
    while (x != y)
      if (dep[x] > dep[y]) {
        A0.push_back(x);
        x = par[x];
      } else {
        A1.push_back(y);
        y = par[y];
      }
    reverse(A1.begin(), A1.end());
    printf("%d\n", (int)A0.size() + (int)A1.size() + 1);
    for (int j = 0; j < (int)(A0.size()); j++) printf("%d ", A0[j]);
    printf("%d", x);
    for (int j = 0; j < (int)(A1.size()); j++) printf(" %d", A1[j]);
    printf("\n");
  }
  return 0;
}
