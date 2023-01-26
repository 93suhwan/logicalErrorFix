#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<long long int> graph[], long long int node, bool visited[]) {
  if (visited[node] == true) return false;
  visited[node] = true;
  for (auto i : graph[node]) {
    if (dfs(graph, i, visited) == false) return false;
  }
  visited[node] = false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int x24e;
  cin >> x24e;
  while (x24e--) {
    long long int n;
    cin >> n;
    vector<long long int> graph[n];
    for (long long int i = 0; i < n; i++) {
      long long int size;
      cin >> size;
      while (size--) {
        long long int x;
        cin >> x;
        x--;
        graph[x].push_back(i);
      }
    }
    bool visited[n];
    memset(visited, false, sizeof visited);
    bool dag = true;
    for (long long int i = 0; i < n; i++) {
      if (dfs(graph, i, visited) == false) {
        dag = false;
      }
    }
    if (dag == false) {
      cout << "-1\n";
      continue;
    }
    long long int indeg[n];
    memset(indeg, 0, sizeof indeg);
    for (long long int i = 0; i < n; i++) {
      for (auto j : graph[i]) indeg[j]++;
    }
    long long int ans[n];
    queue<pair<long long int, long long int>> q;
    for (long long int i = 0; i < n; i++) {
      if (indeg[i] == 0) {
        q.push({i, 1});
      }
    }
    long long int maxi = 1;
    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      maxi = max(maxi, top.second);
      for (auto i : graph[top.first]) {
        indeg[i]--;
        if (indeg[i] == 0) {
          if (i > top.first)
            q.push({i, top.second});
          else
            q.push({i, top.second + 1});
        }
      }
    }
    cout << maxi << endl;
  }
  return 0;
}
