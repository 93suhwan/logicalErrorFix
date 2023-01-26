#include <bits/stdc++.h>
using namespace std;
bool checked[200005];
bool dfs(vector<long long int> graph[], long long int node, bool visited[]) {
  if (visited[node] == true) return false;
  visited[node] = true;
  checked[node] = true;
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
    memset(checked, false, sizeof checked);
    long long int indeg[n];
    memset(indeg, 0, sizeof indeg);
    for (long long int i = 0; i < n; i++) {
      for (auto j : graph[i]) indeg[j]++;
    }
    queue<pair<long long int, long long int>> q;
    long long int count = 0;
    for (long long int i = 0; i < n; i++) {
      if (indeg[i] == 0) {
        q.push({i, 1});
        count++;
      }
    }
    vector<long long int> order(n, 1);
    long long int maxi = 1;
    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      maxi = max(maxi, top.second);
      for (auto i : graph[top.first]) {
        indeg[i]--;
        if (i > top.first)
          order[i] = max(order[i], top.second);
        else
          order[i] = max(order[i], top.second + 1);
        if (indeg[i] == 0) {
          q.push({i, order[i]});
          count++;
        }
      }
    }
    if (count != n)
      cout << "-1\n";
    else
      cout << *max_element(order.begin(), order.end()) << endl;
  }
  return 0;
}
