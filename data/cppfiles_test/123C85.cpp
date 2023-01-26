#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int par[N];
int cost[N];
int depth[N];
bool vis[N];
vector<int> tree[N];
void DFS(int u, int p) {
  par[u] = p;
  for (int v : tree[u])
    if (v != p) {
      depth[v] = depth[u] + 1;
      DFS(v, u);
    }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> nodes(n, n);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
    nodes[i - 1] = i;
  }
  DFS(1, 0);
  sort(nodes.begin(), nodes.end(),
       [&](int u, int v) { return depth[u] > depth[v]; });
  for (int u : nodes) {
    int cur = u;
    while (cur && !vis[cur]) {
      cost[u]++;
      vis[cur] = true;
      cur = par[cur];
    }
  }
  sort(nodes.begin(), nodes.end(),
       [&](int u, int v) { return cost[u] > cost[v]; });
  int sum = 0, first = -1;
  for (int i = 0; i < k; i++) {
    sum += cost[nodes[i]];
    if (!cost[nodes[i]]) {
      first = i;
      break;
    }
  }
  if (first + 1) {
    int red = min(k, max(n / 2, first));
    return 0 * printf("%lld\n", 1LL * red * (n - red));
  }
  int blue = min(n / 2, n - sum);
  printf("%lld\n", 1LL * k * (n - k) - 1LL * blue * (n - blue));
  return 0;
}
