#include <bits/stdc++.h>
using namespace std;
vector<int> res;
bool isCyclic_util(vector<int> adj[], vector<bool> visited, int curr,
                   vector<int> &temp) {
  visited[curr] = true;
  if (find(next(visited.begin(), 1), visited.end(), false) == visited.end()) {
    res = temp;
    return true;
  }
  bool FLAG = false;
  for (int i = 0; i < adj[curr].size(); ++i) {
    if (not visited[adj[curr][i]]) {
      temp.push_back(adj[curr][i]);
      FLAG = isCyclic_util(adj, visited, adj[curr][i], temp);
      if (FLAG == true) return true;
      temp.pop_back();
    }
  }
  return false;
}
bool isCyclic(int V, vector<int> adj[]) {
  vector<bool> visited(V, false);
  bool FLAG = false;
  vector<int> temp;
  for (int i = 1; i <= V; ++i) {
    temp.push_back(i);
    visited[i] = true;
    for (int j = 0; j < adj[i].size(); ++j) {
      temp.push_back(adj[i][j]);
      FLAG = isCyclic_util(adj, visited, adj[i][j], temp);
      if (FLAG == true) return true;
    }
    temp.clear();
    visited[i] = false;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    res.clear();
    cin >> n;
    vector<int> v[n + 2];
    for (int i = 1; i < n; i++) {
      v[i].push_back(i + 1);
    }
    vector<int> a(n);
    for (int &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        v[i + 1].push_back(n + 1);
      } else
        v[n + 1].push_back(i + 1);
    }
    if (isCyclic(n + 2, v)) {
      for (int i : res) cout << i << " ";
      cout << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
