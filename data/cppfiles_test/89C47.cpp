#include <bits/stdc++.h>
using namespace std;
int t, n, u, v;
int bud, leaf, res;
vector<int> vc[200001];
int dfs(int root, int parent) {
  bool hasLeaf = false;
  for (vector<int>::iterator it = vc[root].begin(); it != vc[root].end();
       ++it) {
    if (*it != parent && !dfs(*it, root)) {
      hasLeaf = true;
    }
  }
  if (root != 1) {
    bud += hasLeaf ? 1 : 0;
    leaf += hasLeaf ? 0 : 1;
  }
  return hasLeaf ? 1 : 0;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      vc[i].clear();
    }
    while (--n) {
      scanf("%d%d", &u, &v);
      vc[u].push_back(v);
      vc[v].push_back(u);
    }
    bud = 0;
    leaf = 0;
    res = 0;
    if (dfs(1, -1)) {
      res = leaf - bud;
    } else {
      res = leaf - bud + 1;
    }
    printf("%d\n", res);
  }
}
