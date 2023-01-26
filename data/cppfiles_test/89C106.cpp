#include <bits/stdc++.h>
using namespace std;
const int NN = 202020;
int a[NN], val;
vector<int> adj[NN];
void dfs(int u, int pa = 0) {
  int c = 0;
  for (int v : adj[u])
    if (v != pa) {
      dfs(v, u);
      c += a[v];
    }
  a[u] = !c;
  val += max(0, c - 1) + (u == 1);
}
int main() {
  int T, n, u, v;
  for (scanf("%d", &T); T--;) {
    scanf("%d", &n);
    val = 0;
    for (int i = 1; i < n; i++) {
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1);
    printf("%d\n", val);
    for (int i = 1; i <= n; i++) adj[i].clear();
  }
  return 0;
}
