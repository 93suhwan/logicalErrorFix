#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0},
    dxx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dyy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
vector<int> v[200002];
bool vis[200002];
bool st[200002];
int ans[200002];
int finalAns;
stack<int> topoStack;
bool detectcycle(int u) {
  if (!vis[u]) {
    vis[u] = true;
    st[u] = true;
    for (int i = 0; i < v[u].size(); ++i) {
      if (!vis[v[u][i]] && detectcycle(v[u][i]))
        return true;
      else if (st[v[u][i]])
        return true;
    }
  }
  st[u] = false;
  return false;
}
void topoSort(int u) {
  st[u] = true;
  for (int i = 0; i < v[u].size(); ++i) {
    if (!st[v[u][i]]) topoSort(v[u][i]);
  }
  topoStack.push(u);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  for (cin >> t; t--;) {
    int n, sz, x, i;
    cin >> n;
    vector<int> start;
    finalAns = 1;
    for (i = 1; i <= n; ++i) v[i].clear();
    for (i = 1; i <= n; ++i) {
      cin >> sz;
      ans[i] = -1;
      vis[i] = st[i] = false;
      if (sz == 0) {
        start.push_back(i);
        continue;
      }
      for (int j = 0; j < sz; ++j) {
        cin >> x;
        v[x].push_back(i);
      }
    }
    bool isCycle = false;
    for (i = 1; i <= n; ++i) {
      if (!vis[i] && detectcycle(i)) {
        isCycle = true;
        break;
      }
    }
    if (isCycle) {
      cout << "-1\n";
      continue;
    }
    for (i = 0; i < start.size(); ++i) {
      ans[start[i]] = 1;
      topoSort(start[i]);
    }
    while (!topoStack.empty()) {
      int u = topoStack.top();
      topoStack.pop();
      finalAns = max(finalAns, ans[u]);
      if (ans[u] != -1) {
        for (i = 0; i < v[u].size(); ++i) {
          int x = v[u][i] > u ? 0 : 1;
          if (ans[v[u][i]] < ans[u] + x) ans[v[u][i]] = ans[u] + x;
        }
      }
    }
    cout << finalAns << "\n";
  }
  return 0;
}
