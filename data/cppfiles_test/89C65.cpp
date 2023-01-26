#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
vector<int> arr[maxn];
int lvl[maxn];
vector<int> lvl_node[maxn];
int deg[maxn];
int par[maxn];
bool rem[maxn];
int tot_leaf;
bool isLeaf(int node) {
  if (node != 1 && arr[node].size() == 1) return true;
  return false;
}
void dfs(int node, int parent, int level) {
  lvl[node] = level;
  lvl_node[level].push_back(node);
  par[node] = parent;
  if (isLeaf(node)) {
    tot_leaf++;
    return;
  }
  for (int child : arr[node])
    if (child != parent) {
      deg[node]++;
      dfs(child, node, level + 1);
    }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    tot_leaf = 0;
    for (int i = 1; i <= n; i++) {
      arr[i].clear();
      lvl[i] = 0;
      par[i] = 0;
      deg[i] = 0;
      rem[i] = false;
      lvl_node[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }
    dfs(1, 0, 0);
    int max_lvl = INT_MIN;
    for (int i = 1; i <= n; i++) max_lvl = max(max_lvl, lvl[i]);
    int ans = tot_leaf;
    for (int i = max_lvl - 1; i >= 1; i--) {
      for (int node : lvl_node[i]) {
        bool check = true;
        if (deg[node] == 0)
          check = false;
        else {
          for (int child : arr[node]) {
            if (child == par[node]) continue;
            if (rem[child] == false && deg[child] != 0) {
              check = false;
              break;
            }
          }
        }
        if (check == true) {
          rem[node] = true;
          deg[par[node]]--;
          if (deg[par[node]] > 0) ans--;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
