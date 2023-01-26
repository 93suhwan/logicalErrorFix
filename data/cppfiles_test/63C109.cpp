#include <bits/stdc++.h>
using namespace std;
int cs = 0;
void dfs(int v, int vis[], int c[], vector<int> adj[], int cc) {
  vis[v] = 1;
  c[v] = cc;
  cs++;
  for (auto j : adj[v]) {
    if (vis[j] == 0) {
      dfs(j, vis, c, adj, v);
    }
  }
}
int parent(int c[], int v) {
  while (c[v] != v) {
    v = c[v];
  }
  return v;
}
void uni(int x, int y, int rank[], int c[]) {
  if (rank[x] > rank[y]) {
    c[y] = x;
  } else {
    c[x] = y;
  }
  if (rank[x] == rank[y]) {
    rank[y]++;
  }
}
int main() {
  int n;
  int m1;
  int m2;
  cin >> n >> m1 >> m2;
  vector<int> adj1[n + 1];
  vector<int> adj2[n + 1];
  int u;
  int v;
  for (int i = 0; i < m1; i = i + 1) {
    cin >> u >> v;
    adj1[u].push_back(v);
    adj1[v].push_back(u);
  }
  for (int i = 0; i < m2; i = i + 1) {
    cin >> u >> v;
    adj2[u].push_back(v);
    adj2[v].push_back(u);
  }
  int c1[n + 1];
  int c2[n + 1];
  int rank1[n + 1];
  int rank2[n + 1];
  int vis1[n + 1];
  int vis2[n + 1];
  for (int i = 0; i <= n; i = i + 1) {
    c1[i] = -1;
    c2[i] = -1;
    vis1[i] = 0;
    vis2[i] = 0;
    rank1[i] = 1;
    rank2[i] = 1;
  }
  for (int i = 1; i <= n; i = i + 1) {
    if (vis1[i] == 0) {
      dfs(i, vis1, c1, adj1, i);
      rank1[i] = cs;
      cs = 0;
    }
  }
  for (int i = 1; i <= n; i = i + 1) {
    if (vis2[i] == 0) {
      dfs(i, vis2, c2, adj2, i);
      rank2[i] = cs;
      cs = 0;
    }
  }
  vector<vector<int>> ans;
  int s = 0;
  for (int i = 1; i <= n; i = i + 1) {
    for (int j = i + 1; j <= n; j = j + 1) {
      int x = parent(c1, i);
      int y = parent(c1, j);
      int a = parent(c2, i);
      int b = parent(c2, j);
      if (parent(c1, i) != parent(c1, j) && parent(c2, i) != parent(c2, j)) {
        uni(x, y, rank1, c1);
        uni(a, b, rank2, c2);
        s++;
        ans.push_back({i, j});
      }
    }
  }
  cout << s << endl;
  for (int i = 0; i < s; i = i + 1) {
    cout << ans[i][0] << " " << ans[i][1] << endl;
  }
  return 0;
}
