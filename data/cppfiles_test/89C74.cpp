#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200009];
int child[200009];
void DFS(int u, int p) {
  child[u] = 0;
  for (auto v : adj[u])
    if (v != p) {
      DFS(v, u);
      if (!child[v]) child[u]++;
    }
}
void Solve() {
  int ans = 0, n, u, v, pos = 0, ck = 0, p;
  cin >> n;
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1, 0);
  for (int i = 2; i <= n; i++)
    if (child[i]) ans++;
  for (auto i : adj[1])
    if (child[i])
      pos++;
    else
      ck++;
  p = n - ans - 1;
  if (ck)
    cout << p - ans;
  else
    cout << p - ans + 1;
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) Solve();
}
