#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> players(n);
    for (auto& it : players) {
      cin >> it.first.first;
    }
    for (auto& it : players) {
      cin >> it.first.second;
    }
    for (int i = 0; i < n; i++) {
      players[i].second = i;
    }
    sort(players.begin(), players.end());
    vector<vector<int>> graph(n);
    queue<int> q;
    vector<char> visited(n);
    for (int i = 1; i < n; i++) {
      graph[players[i - 1].second].push_back(players[i].second);
    }
    visited[players[n - 1].second] = true;
    q.push(players[n - 1].second);
    for (int i = 0; i < n; i++) {
      swap(players[i].first.first, players[i].first.second);
    }
    sort(players.begin(), players.end());
    for (int i = 1; i < n; i++) {
      graph[players[i - 1].second].push_back(players[i].second);
    }
    if (!visited[players[n - 1].second]) {
      visited[players[n - 1].second] = true;
      q.push(players[n - 1].second);
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : graph[v]) {
        if (!visited[u]) {
          q.push(u);
          visited[u] = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << !!visited[i];
    }
    cout << '\n';
  }
}
