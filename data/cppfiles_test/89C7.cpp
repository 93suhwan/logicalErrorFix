#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n;
vector<int> G[N];
int total_num_leaf, total_num_bud, ans;
int dfs(int u, int fa = -1) {
  int num_leaf = 0, num_child = 0;
  for (int v : G[u]) {
    if (v == fa) continue;
    int fv = dfs(v, u);
    if (fv == 0) {
      num_child++;
      num_leaf++;
    } else if (fv == 1) {
    } else if (fv == 2) {
      num_child++;
    }
  }
  if (num_child == 0) {
    if (u == 0) ans = 0;
    total_num_leaf++;
    return 0;
  } else {
    if (u == 0) ans = num_leaf > 0 ? 0 : 1;
    if (num_leaf == num_child) {
      if (u == 0) ans++;
      total_num_bud++;
      return 1;
    } else {
      return 2;
    }
  }
}
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) G[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    total_num_bud = total_num_leaf = 0;
    dfs(0);
    cout << ans + total_num_leaf - total_num_bud << "\n";
  }
}
