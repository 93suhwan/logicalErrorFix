#include <bits/stdc++.h>
void dfs(int32_t v, bool* vis, std::vector<std::pair<int32_t, bool> >* graph,
         bool& ok, bool* status, std::vector<int32_t>& indices, int32_t& inc) {
  vis[v] = true;
  indices.push_back(v);
  if (!status[v]) inc++;
  for (int32_t i = 0; i < graph[v].size(); i++) {
    if (!vis[graph[v][i].first]) {
      status[graph[v][i].first] = status[v] == graph[v][i].second;
      dfs(graph[v][i].first, vis, graph, ok, status, indices, inc);
    } else if ((status[v] == graph[v][i].second) != status[graph[v][i].first])
      ok = false;
  }
}
void solve() {
  int32_t n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int32_t, bool> >* graph =
      new std::vector<std::pair<int32_t, bool> >[n];
  for (int32_t i = 0; i < m; i++) {
    int32_t v1, v2;
    std::string type;
    std::cin >> v1 >> v2 >> type;
    v1--;
    v2--;
    graph[v1].emplace_back(v2, type == "crewmate");
    graph[v2].emplace_back(v1, type == "crewmate");
  }
  int32_t ans = 0;
  bool* vis = new bool[n];
  for (int32_t i = 0; i < n; i++) vis[i] = false;
  bool* status = new bool[n];
  for (int32_t i = 0; i < n; i++) {
    if (vis[i]) continue;
    status[i] = false;
    bool ok = true;
    std::vector<int32_t> indices;
    int32_t inc = 0;
    dfs(i, vis, graph, ok, status, indices, inc);
    for (int32_t j : indices) {
      vis[j] = false;
      status[j] = false;
    }
    indices.clear();
    ok = true;
    int32_t inc2 = 0;
    status[i] = true;
    dfs(i, vis, graph, ok, status, indices, inc2);
    if (!ok) {
      std::cout << -1 << "\n";
      return;
    }
    ans += std::max(inc, inc2);
  }
  std::cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int32_t num_tests;
  std::cin >> num_tests;
  for (int32_t t = 0; t < num_tests; t++) {
    solve();
  }
  return 0;
}
