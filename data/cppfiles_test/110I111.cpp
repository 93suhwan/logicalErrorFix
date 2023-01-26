#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, ans;
vector<int> adj[N];
set<int> in[N];
queue<pair<int, int>> q;
bool loop = false, on_stack[N], visited[N];
void dfs(int v) {
  visited[v] = true;
  on_stack[v] = true;
  for (int u : adj[v]) {
    if (!visited[u]) {
      dfs(u);
    } else if (on_stack[u]) {
      loop = true;
    }
  }
  on_stack[v] = false;
}
void bfs() {
  while (!q.empty()) {
    auto [v, idx] = q.front();
    q.pop();
    ans = max(ans, idx);
    visited[v] = true;
    for (int u : adj[v]) {
      if (visited[u]) {
        continue;
      }
      in[u].erase(v);
      if (in[u].empty()) {
        int new_idx = idx;
        if (u < v) {
          new_idx++;
        }
        q.push({u, new_idx});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    loop = false;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      in[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      int m;
      cin >> m;
      for (int j = 0; j < m; j++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
        in[i].insert(u);
      }
    }
    memset(visited, false, sizeof visited);
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    if (loop) {
      cout << -1 << '\n';
      continue;
    }
    ans = INT_MIN;
    memset(visited, false, sizeof visited);
    for (int i = 1; i <= n; i++) {
      if (in[i].empty()) {
        q.push({i, 1});
      }
    }
    bfs();
    cout << ans << '\n';
  }
  return 0;
}
