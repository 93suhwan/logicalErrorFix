#include <bits/stdc++.h>
using namespace std;
void bfs(list<int> adj[], bool visited[], int parent[], int src, int n) {
  queue<int> q;
  q.push(src);
  int tmp;
  while (!q.empty()) {
    tmp = q.front();
    parent[tmp] = src;
    q.pop();
    for (auto g : adj[tmp]) {
      if (!visited[g]) {
        visited[g] = true;
        q.push(g);
      }
    }
  }
}
int getPar(int par[], int i) {
  if (i == par[i]) {
    return i;
  }
  return par[i] = getPar(par, par[i]);
}
int main() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  list<int> adj1[n + 1];
  list<int> adj2[n + 1];
  int x, y;
  for (int i = 0; i < m1; i++) {
    cin >> x >> y;
    adj1[y].push_back(x);
    adj1[x].push_back(y);
  }
  for (int i = 0; i < m2; i++) {
    cin >> x >> y;
    adj2[x].push_back(y);
    adj2[y].push_back(x);
  }
  int parent1[n + 1];
  int parent2[n + 1];
  bool visited[n + 1];
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= n; i++) {
    parent1[i] = i;
    parent2[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      bfs(adj1, visited, parent1, i, n);
    }
  }
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      bfs(adj2, visited, parent2, i, n);
    }
  }
  vector<pair<int, int> > v;
  int par1;
  int par2, par3, par4;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      par1 = getPar(parent1, i);
      par2 = getPar(parent1, j);
      if (par1 != par2) {
        par3 = getPar(parent2, i);
        par4 = getPar(parent2, j);
        if (par3 != par4) {
          v.push_back({i, j});
          parent1[par1] = par2;
          parent2[par3] = par4;
        }
      }
    }
  }
  int ans = v.size();
  cout << ans << "\n";
  for (int i = 0; i < ans; i++) {
    cout << v[i].first << " " << v[i].second << "\n";
  }
  return 0;
}
