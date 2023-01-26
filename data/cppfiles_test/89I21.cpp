#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
vector<int> arr[maxn];
int lvl[maxn];
int fre_lvl[maxn];
int leaf_lvl[maxn];
int tot_leaf;
bool isLeaf(int node) {
  if (node != 1 && arr[node].size() == 1) return true;
  return false;
}
void dfs(int node, int par, int level) {
  lvl[node] = level;
  fre_lvl[level]++;
  if (isLeaf(node)) {
    leaf_lvl[level]++;
    tot_leaf++;
    return;
  }
  for (int child : arr[node]) {
    if (child != par) {
      dfs(child, node, level + 1);
    }
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
      lvl[i] = -1;
      fre_lvl[i] = 0;
      leaf_lvl[i] = 0;
    }
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }
    dfs(1, -1, 0);
    int max_lvl = INT_MIN;
    for (int i = 1; i <= n; i++) max_lvl = max(max_lvl, lvl[i]);
    int k = 0;
    for (int i = max_lvl - 1; i >= 1; i--) {
      if ((fre_lvl[i + 1] - leaf_lvl[i + 1]) == 0 && leaf_lvl[i + 1] > 0) {
        int buds = fre_lvl[i] - leaf_lvl[i];
        int leaf_plus = 0;
        for (int j = 2; j <= n; j++) {
          if (i - 1 >= 1 && lvl[j] == i - 1 && arr[j].size() == 2) leaf_plus++;
        }
        fre_lvl[i] -= buds;
        leaf_lvl[i - 1] += leaf_plus;
        k += buds;
      }
    }
    if (leaf_lvl[1] > 0)
      cout << n - k - 1 - k << endl;
    else
      cout << n - k - k - 1 + 1 << endl;
  }
  return 0;
}
