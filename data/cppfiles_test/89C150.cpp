#include <bits/stdc++.h>
using namespace std;
const int nax = 200005;
const int mod = 998244353;
vector<int> graph[nax];
vector<int> degree(nax);
vector<int> level(nax);
vector<int> vis(nax);
vector<int> parent(nax);
vector<int> str[nax];
void dfs(int node, int l) {
  vis[node] = 1;
  level[node] = l + 1;
  str[l + 1].push_back(node);
  int d = 0;
  for (auto i : graph[node]) {
    if (vis[i] == 0) {
      dfs(i, l + 1);
      parent[i] = node;
      d++;
    }
  }
  degree[node] = d;
  return;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) degree[i] = 0;
  for (int i = 1; i < n + 1; i++) level[i] = 0;
  for (int i = 1; i < n + 1; i++) parent[i] = 0;
  for (int i = 1; i < n + 1; i++) vis[i] = 0;
  for (int i = 1; i <= n; ++i) {
    graph[i].clear();
    str[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(1, 0);
  int ans = 0;
  for (int i = 1; i < n + 1; i++)
    if (degree[i] == 0) ans++;
  vector<int> rem(n + 1);
  for (int i = n; i >= 2; i--) {
    for (auto item : str[i]) {
      if (degree[item] == 0) continue;
      int check = 1;
      for (auto child : graph[item]) {
        if (level[child] > level[item] && rem[child] == 0) {
          check = check & (!degree[child]);
        }
      }
      if (check) {
        rem[item] = 1;
        degree[parent[item]]--;
        if (degree[parent[item]] > 0) ans--;
      }
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  int T;
  T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
}
