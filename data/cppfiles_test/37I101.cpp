#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
void dfs(vector<vector<long long>>& graph, vector<bool>& visited, long long i) {
  visited[i] = true;
  for (auto f : graph[i]) {
    if (!visited[f]) {
      dfs(graph, visited, f);
    }
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[m][3];
  set<long long> added;
  vector<vector<long long>> graph(n + 1);
  set<pair<long long, long long>> ans;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < 3; j++) cin >> a[i][j];
    if (added.count(a[i][0]) == 0 || added.count(a[i][2]) == 0) {
      graph[a[i][0]].push_back(a[i][2]);
      graph[a[i][2]].push_back(a[i][0]);
      ans.insert({a[i][0], a[i][2]});
    }
    added.insert(a[i][0]);
    added.insert(a[i][2]);
  }
  vector<long long> nodes;
  vector<bool> visited(n + 1, false);
  for (long long i = 1; i <= n; i++) {
    if (!visited[i]) {
      nodes.push_back(i);
      dfs(graph, visited, i);
    }
  }
  for (long long i = 1; i < nodes.size(); i++) {
    ans.insert({nodes[0], nodes[i]});
  }
  assert(ans.size() == n - 1);
  for (auto f : ans) {
    cout << f.first << " " << f.second << endl;
  }
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
