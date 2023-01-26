#include <bits/stdc++.h>
using namespace std;
int visited[10005];
void dfs(int n, vector<vector<int>> &adj) {
  if (visited[n] == true) {
    return;
  }
  visited[n] = true;
  cout << n << " ";
  for (auto u : adj[n]) {
    dfs(u, adj);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 10005; i++) {
      visited[i] = 0;
    }
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 4);
    for (int i = 1; i < n; i++) {
      adj[i].push_back(i + 1);
    }
    for (int i = 1; i <= n; i++) {
      int direction;
      cin >> direction;
      direction == 0 ? adj[i].push_back(n + 1) : adj[n + 1].push_back(i);
    }
    int start;
    for (int i = 1; i < n + 2; i++) {
      if (adj[i].size() != 0) {
        start = i;
        break;
      }
    }
    dfs(start, adj);
    for (int i = 0; i < 10005; i++) {
      visited[i] = 0;
    }
    cout << endl;
  }
}
